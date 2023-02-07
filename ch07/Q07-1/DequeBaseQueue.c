#include <stdio.h>
#include <stdlib.h>
#include "DequeBaseQueue.h"


void QueueInit(Queue * pq){
    DequeInit(pq);
}
int QIsEmpty(Queue * pq){
    return DQIsEmpty(pq);
}
void Enqueue(Queue * pq, Data data){
    DQAddLast(pq, data);
}
Data Dequeue(Queue * pq){
    return DQRemoveFirst(pq);
}
Data QPeek(Queue * pq){
    return DQGetFisrt(pq);
}