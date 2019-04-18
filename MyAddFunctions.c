
//***************************************
//* This is where I will be writing my  *
//* portion of the code                 *
//***************************************

#include "Header.h"


//*******************************************************
//* This function is where we append to the end of the  *
//* list to add new customers.                          *
//*******************************************************

void addToList(Node** list, char *name, int burgers,
               int salads, boolean inRestaurant){
    
    struct Node *newCust;
    struct Node *tail = *list;
    
    //*******************************************************
    //* I made a new node to store the information of       *
    //* the customer. I have two cases where the list       *
    //* is empty and the list has at least one customer     *
    //* and the new customers are added to the end of the   *
    //* list, therefore making it a queue.                  *
    //*******************************************************
    
    if(*list == NULL){
        newCust = (struct Node *) malloc (sizeof(Node));
        newCust->name = name;
        newCust->numBurgers = burgers;
        newCust->numSalads = salads;
        newCust->inRestaurant = inRestaurant;
        newCust->pNext = NULL;
        newCust->pPrev = NULL;
        
        *list = newCust;
    }
    
    else{
        newCust = (struct Node *) malloc (sizeof(Node));
        newCust->name = name;
        newCust->numBurgers = burgers;
        newCust->numSalads = salads;
        newCust->inRestaurant = inRestaurant;
        newCust->pNext = NULL;
        
        while(tail->pNext != NULL){
            tail = tail->pNext;
        }
        
        newCust->pPrev = tail;
        tail->pNext = newCust;
        
    }
    
}

//********************************************************
//* We check if the name is already in line by using     *
//* the strcmp() function and iterating through the list *
//********************************************************
boolean doesNameExist(Node** list, char *name){
    struct Node *temp = *list;
    int check = -1;
    
    if(DEBUGMODE == 1){
        printf("Debug Mode is ON.\n");
    }
    while(temp != NULL){
        if(DEBUGMODE == 1){
            printf("Name: %s, Burgers: %d, Salads: %d\n",
                   temp->name, temp->numBurgers, temp->numSalads);
        }
        check = strcmp(temp->name, name);
        
        if(check == 0){
            return TRUE;
        }
        
        temp = temp->pNext;
    }
    
    return FALSE;

}
//*******************************************************
//* Updates the status of someone who calls ahead to    *
//* order. First we do the basic checks of, empty list, *
//* name not on the list, and if the name is already in *
//* line. If it passes all those checks then we update  *
//* the status of the customer.                         *
//*******************************************************
void updateStatus(Node** list, char* name){
    struct Node* temp = *list;
    
    if(DEBUGMODE == TRUE){
        printf("Debug Mode is ON.\n");
    }
    while(temp != NULL){
        if(DEBUGMODE == TRUE){
            printf("Name: %s, Burgers: %d, Salads: %d\n",
                   temp->name, temp->numBurgers, temp->numSalads);
        }
        if(strcmp(temp->name, name) == 0){
            break;
        }
        else{
            temp = temp->pNext;
        }
    }
    
    if(temp == NULL){
        printf("There is no one in line.\n");
        return;
    }
    else if(doesNameExist(&temp, name) == FALSE){
        printf("Sorry that name doesn't exist.\n");
        return;
    }
    else if(doesNameExist(&temp, name) == TRUE && temp->inRestaurant == TRUE){
        printf("That name is already in line.\n");
    }
    else{
        temp->inRestaurant = TRUE;
    }
    
}
//*******************************************************
//* In this function this is where we will find the     *
//* order that has less than or equal to the number of  *
//* prepared burgers and salads. We do the normal check *
//* to see if the list is empty.                        *
//*******************************************************
void retrieveAndRemove(Node** list, int prepedBurgers, int prepedSalads){
    
    if(*list == NULL){
        printf("There is no one in line\n");
        return;
    }
    struct Node* temp = *list;
    struct Node* prev = *list;
    
    //*******************************************************
    //* We just check the first node to see if it meets the *
    //* requirements to remove it from the list.            *
    //*******************************************************
    if(temp != NULL){
        if((temp->numBurgers <= prepedBurgers) &&
           (temp->numSalads <= prepedSalads) && (temp->inRestaurant == TRUE)){
            *list = temp->pNext;
            free(temp);
            return;
        }
    }
    //*******************************************************
    //* We iterate through the list until we find the node  *
    //* that matches what we are looking for, then we break *
    //*******************************************************
    if(DEBUGMODE == TRUE){
        printf("Debug Mode is ON.\n");
    }
    while(temp != NULL){
        if(DEBUGMODE == TRUE){
            printf("Name: %s, Burgers: %d, Salads: %d\n",
                   temp->name, temp->numBurgers, temp->numSalads);
        }
        if((temp->numBurgers <= prepedBurgers) &&
           (temp->numSalads <= prepedSalads) && (temp->inRestaurant == TRUE)){
            break;
        }
        else{
            prev = temp;
            temp = temp->pNext;
        }
    }
    //*******************************************************
    //* When we break out of the loop we check to see if    *
    //* we found it, if not then we return an error message.*
    //* Otherwise we will remove the node we found.         *
    //*******************************************************
    
    if(temp == NULL){
        printf("There wasn't enough food produced for anybody in line\n");
        return;
    }
    
    prev->pNext = temp->pNext;
    free(temp);
}
//*******************************************************
//* We will count how many orders are ahead of the name *
//* we are waiting for. We do the base case checks,     *
//* then iterate through the list and increase our      *
//* counter for every person ahead of the name.         *
//*******************************************************
int countOrdersAhead(Node** list, char* name){
    if(*list == NULL){
        printf("There is no one in line\n");
        return FALSE;
    }
    if (doesNameExist(list, name) == FALSE) {
        printf("Name is not in line, please"
               " enter a different name\n");
        return FALSE;
    }
    
    int counter = 0;
    struct Node *temp = *list;
    //*******************************************************
    //* This is where we iterate through the list to check  *
    //* for the name and continue to increase the counter   *
    //* until we find the name.                             *
    //*******************************************************
    if(DEBUGMODE == TRUE){
        printf("Debug Mode is ON.\n");
    }
    while(temp != NULL){
        if(DEBUGMODE == TRUE){
            printf("Name: %s, Burgers: %d, Salads: %d\n",
                   temp->name, temp->numBurgers, temp->numSalads);
        }
        if (strcmp(temp->name, name) == 0) {
            break;
        }
        counter++;
        temp = temp->pNext;
    }
    
    return counter;
}
//***********************************************************
//* We will display how many orders are ahead of the        *
//* customer and will display the orders of the other       *
//* customers. Again we begin with checking the base cases  *
//***********************************************************
void displaysOrdersAhead(Node** list, char* name){
    if(*list == NULL){
        return;
    }
    else if(doesNameExist(list, name) == FALSE){
        return;
    }
    
    int counter = 1;
    struct Node* temp = *list;
    
    //********************************************************
    //* We iterate through the list until we find the name   *
    //* the user typed in and as we go through the list we   *
    //* will display the orders in front of the name entered *
    //********************************************************
    if(DEBUGMODE == TRUE){
        printf("Debug Mode is ON.\n");
    }
    while(strcmp(temp->name, name) != 0){
        if(DEBUGMODE == TRUE){
            printf("Name: %s, Burgers: %d, Salads: %d\n",
                   temp->name, temp->numBurgers, temp->numSalads);
        }
        printf("Order #%d: %d burger(s) and %d salad(s)\n",
               counter, temp->numBurgers, temp->numSalads);
        counter++;
        temp = temp->pNext;
    }
    
    
}
//*******************************************************
//* We display everyone in line and their orders, but   *
//* first we check there is no one in line and if there *
//* isn't we return saying that there is no one in line *
//*******************************************************
void displayListInformation(Node** list){
    if(*list == NULL){
        printf("There is no one in line");
        return;
    }
    
    Node *temp = *list;
    
    while(temp != NULL){
        
        //***********************************
        //* Here we check if the customer   *
        //* is in line or not               *
        //***********************************
        if(temp->inRestaurant == TRUE){
            printf("Name: %s, %d burger(s), %d salad(s), In line\n",
                   temp->name, temp->numBurgers, temp->numSalads);
        }
        else{
            printf("Name: %s, %d burger(s), %d salad(s), Not in line\n",
                   temp->name, temp->numBurgers, temp->numSalads);
        }
        
        temp = temp->pNext;
    }
    
}
//***********************************************************
//* We will calculate the waiting time for everyone in      *
//* front of the name we put in, but first we check if      *
//* name is in line. If it is not in line we will give an   *
//* error message and return 0.                             *
//***********************************************************
int displayWaitingTime(Node** list, char* name){
    
    int totalTime = 0;
    int burgerTime = 0;
    int saladTime = 0;

    struct Node *temp = *list;
    
    if(*list == NULL){
        printf("There is no one in line\n");
    }
    else if(doesNameExist(&temp, name) == FALSE){
        printf("Name is not in line, please enter a different name\n");
    }
    else {
        //***********************************************************
        //* We iterate through the list to calculate the estimated  *
        //* waiting time for the customer if                        *
        //***********************************************************
        if(DEBUGMODE == TRUE){
            printf("Debug Mode is ON.\n");
        }
        while(temp != NULL){
            if(DEBUGMODE == TRUE){
                printf("Name: %s, Burgers: %d, Salads: %d\n",
                       temp->name, temp->numBurgers, temp->numSalads);
            }
            if(strcmp(temp->name, name) == 0){
                break;
            }
            
            burgerTime = temp->numBurgers * 10;
            saladTime = temp->numSalads * 5;
            
            totalTime = totalTime + burgerTime + saladTime;
            
            temp = temp->pNext;
        }
    }
    
    return totalTime;
}
