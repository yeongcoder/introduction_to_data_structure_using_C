#include <stdio.h>
#include "CLLBaseStack.h"

void StackInit(Stack * pstack){
    pstack->plist = (List*)malloc(sizeof(List));
    ListInit(&pstack->plist);
}
void SIsEmpty(Stack * pstack){
    if(LCount(pstack->plist) == 0){
        return TRUE;
    } else {
        return FALSE;
    }
}

void SPush(Stack * pstack, Data data){
    LInsertFront(pstack->plist, data);
}
Data SPop(Stack * pstack){
    Data * data;
    LFirst(pstack->plist, data);
    LRemove(pstack);
    return data;
}
Data SPeek(Stack * pstack){
    Data * data;
    LFirst(pstack->plist, data);
    return data;
}