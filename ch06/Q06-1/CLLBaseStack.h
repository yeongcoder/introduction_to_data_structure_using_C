#ifndef _CLL_BASE_STACK_H__
#define _CLL_BASE_STACK_H__

#include "CLinkedList.h"

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct _listStack{
    List * plist;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);
void SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif