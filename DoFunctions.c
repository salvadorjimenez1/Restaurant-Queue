//
//  SourceFile1.c
//  Project 4
//
//  Created by Broke Boy on 3/12/19.
//  Copyright © 2019 BrokeBoy. All rights reserved.
//

#include "Header.h"


void doAdd (Node** list)
{
    /* get number of burgers ordered from input */
    int NumBurgers = getPosInt();
    if (NumBurgers < 0)
    {
        printf ("Error: Add command requires an integer value of at least 0\n");
        printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    /* get number of salads ordered from input */
    int NumSalads = getPosInt();
    if (NumSalads < 0)
    {
        printf ("Error: Add command requires an integer value of at least 0\n");
        printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Add command requires a name to be given\n");
        printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    printf ("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
    
    // add code to perform this operation here
    if(doesNameExist(list, name) == FALSE){
        addToList(list, name, NumBurgers, NumSalads, TRUE);
    }
    else{
        printf("This name already exists!\n");
    }
 
}


void doCallAhead (Node** list)
{
    /* get number of burgers ordered from input */
    int NumBurgers = getPosInt();
    if (NumBurgers < 0)
    {
        printf ("Error: Call-ahead command requires an integer value of at least 0\n");
        printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    /* get number of salads ordered from input */
    int NumSalads = getPosInt();
    if (NumSalads < 0)
    {
        printf ("Error: Call-ahead command requires an integer value of at least 0\n");
        printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Call-ahead command requires a name to be given\n");
        printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf ("  where:<# burgers> is the number of ordered burgers\n");
        printf ("        <# salads> is the number of ordered salads\n");
        printf ("        <name> is the name of the person putting the order\n");
        return;
    }
    
    printf ("Adding Call-ahead order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);
    
    // add code to perform this operation here
    if(doesNameExist(list, name) == FALSE){
        addToList(list, name, NumBurgers, NumSalads, FALSE);
    }
    else{
        printf("This name already exists!\n");
    }
}

void doWaiting (Node** list)
{
    /* get order name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Waiting command requires a name to be given\n");
        printf ("Waiting command is of form: w <name>\n");
        printf ("  where: <name> is the name of the group that is now waiting\n");
        return;
    }
    
    printf ("Call-ahead order \"%s\" is now waiting in the restaurant\n", name);
    
    // add code to perform this operation here
    updateStatus(list, name);
}

void doRetrieve (Node** list)
{
    /* get info of prepared food ready on the counter from input */
    int PreparedBurgers = getPosInt();
    if (PreparedBurgers < 0)
    {
        printf ("Error: Retrieve command requires an integer value of at least 0\n");
        printf ("Retrieve command is of form: r <# burgers> <# salads>\n");
        printf ("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
        printf ("         <# saladss> is the number of salads waiting on the counter for pick up\n");
        return;
    }
    
    int PreparedSalads = getPosInt();
    if (PreparedSalads < 0)
    {
        printf ("Error: Retrieve command requires an integer value of at least 0\n");
        printf ("Retrieve command is of form: r <# burgers> <# salads>\n");
        printf ("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
        printf ("         <# saladss> is the number of salads waiting on the counter for pick up\n");
        return;
    }
    
    clearToEoln();
    printf ("Retrieve (and remove) the first group that can pick up the order of %d burgers and %d salads\n", PreparedBurgers ,PreparedSalads);
    
    // add code to perform this operation here
    retrieveAndRemove(list, PreparedBurgers, PreparedSalads);
}

void doList (Node** list)
{
    /* get order name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: List command requires a name to be given\n");
        printf ("List command is of form: l <name>\n");
        printf ("  where: <name> is the name of the order to inquire about\n");
        return;
    }
    
    printf ("Order for \"%s\" is behind the following orders\n", name);
    
    // add code to perform this operation here
    printf("There are %d orders ahead of %s\n",
           countOrdersAhead(list, name), name);
    
    displaysOrdersAhead(list, name);
}

void doDisplay (Node** list)
{
    clearToEoln();
    printf ("Display information about all orders\n");
    
    // add code to perform this operation here
    displayListInformation(list);
}


void doEstimateTime(Node** list)
{
    /* get order name from input */
    
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: List command requires a name to be given\n");
        printf ("List command is of form: t <name>\n");
        printf ("  where: <name> is the name of the order to inquire about\n");
        return;
    }
    
    
    // add code to perform this operation here
    printf("Estimated waiting time for %s is about: %d minutes\n",
           name, displayWaitingTime(list, name));
    
}
