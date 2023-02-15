#include <stdio.h>
#include "PriorityQueue.h"
#include "PriorityQueue.c"

int DataPriorityComp(char ch1, char ch2){
    return ch2-ch1;                         
}

int main(void){
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);      // 우선순위 비교함수 등록

    PEnqueue(&pq, 'A');                    // 문자 'A'를 최고의 우선순위로 저장
    PEnqueue(&pq, 'B');                    // 문자 'B'를 최고의 우선순위로 저장
    PEnqueue(&pq, 'C');                    // 문자 'C'를 최고의 우선순위로 저장
    printf("%c \n", PDequeue(&pq));

    PEnqueue(&pq, 'A');                    // 문자 'A' 한 번 더 저장!
    PEnqueue(&pq, 'B');                    // 문자 'B' 한 번 더 저장!
    PEnqueue(&pq, 'C');                    // 문자 'C' 한 번 더 저장!
    printf("%c \n", PDequeue(&pq));

    while(!PQIsEmpty(&pq))
        printf("%c \n", PDequeue(&pq));
    
    return 0;
}