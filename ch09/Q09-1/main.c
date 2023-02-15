#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"
#include "PriorityQueue.c"

int DataPriorityComp(char* ch1, char* ch2){
    return strlen(ch2) - strlen(ch1);                         
}

int main(void){
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);      // 우선순위 비교함수 등록

    PEnqueue(&pq, "aa");                    // 문자 'A'를 최고의 우선순위로 저장
    PEnqueue(&pq, "bbb");                    // 문자 'B'를 최고의 우선순위로 저장
    PEnqueue(&pq, "cccc");                    // 문자 'C'를 최고의 우선순위로 저장
    printf("%s \n", PDequeue(&pq));

    PEnqueue(&pq, "aa");                    // 문자 'A' 한 번 더 저장!
    PEnqueue(&pq, "bbb");                    // 문자 'B' 한 번 더 저장!
    PEnqueue(&pq, "cccc");                    // 문자 'C' 한 번 더 저장!
    printf("%s \n", PDequeue(&pq));

    while(!PQIsEmpty(&pq))
        printf("%s \n", PDequeue(&pq));
    
    return 0;
}