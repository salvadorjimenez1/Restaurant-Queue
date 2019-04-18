//
//  Header.h
//  Project 4
//
//  Created by Broke Boy on 3/12/19.
//  Copyright © 2019 BrokeBoy. All rights reserved.
//

#ifndef Header_h
#define Header_h


//*******************************
//* Libraries we will be using  *
//* throughout the program      *
//*******************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//***************
//* DEBUG MODE  *
//***************
extern int DEBUGMODE;

//*******************************
//* Definitions we have created *
//*******************************
typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

typedef struct Node{
    char *name;
    int numBurgers;
    int numSalads;
    boolean inRestaurant;
    struct Node *pNext;
    struct Node *pPrev;
} Node;


//***********************
//* Function prototypes *
//***********************
void clearToEoln(void);
int getNextNWSChar (void);
int getPosInt (void);
char *getName(void);
void printCommands(void);

void doList (Node** list);
void doAdd(Node** list);
void doCallAhead(Node** list);
void doWaiting(Node** list);
void doRetrieve(Node** list);
void doDisplay(Node** list);
void doEstimateTime(Node** list);


void addToList(Node** list, char *name, int burgers,
               int salads, boolean inRestaurant);
boolean doesNameExist(Node** list, char* name);
void updateStatus(Node** list, char* name);
void retrieveAndRemove(Node** list, int burgers, int salads);
int countOrdersAhead(Node** list, char* name);
void displaysOrdersAhead(Node** list, char* name);
void displayListInformation(Node** list);
int displayWaitingTime(Node** list, char* name);


#endif /* Header_h */
