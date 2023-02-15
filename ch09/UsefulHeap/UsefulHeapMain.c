#include <stdio.h>
#include "UsefulHeap.h"
#include "UsefulHeap.c"

int DataPriorityComp(char ch1, char ch2){   // 우선순위 비교함수
    return ch2-ch1;                         // 양수면 ch2가  ch1보다 크다는 의미, 음수면 반대, 0이면 둘의 우선순위가 같음
//  return ch1-ch2;
}

int main(void){
    Heap heap;
    HeapInit(&heap, DataPriorityComp);      // 우선순위 비교함수 등록

    HInsert(&heap, 'A');                    // 문자 'A'를 최고의 우선순위로 저장
    HInsert(&heap, 'B');                    // 문자 'B'를 최고의 우선순위로 저장
    HInsert(&heap, 'C');                    // 문자 'C'를 최고의 우선순위로 저장
    printf("%c \n", HDelete(&heap));

    HInsert(&heap, 'A');                    // 문자 'A' 한 번 더 저장!
    HInsert(&heap, 'B');                    // 문자 'B' 한 번 더 저장!
    HInsert(&heap, 'C');                    // 문자 'C' 한 번 더 저장!
    printf("%c \n", HDelete(&heap));

    while(!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));
    
    return 0;
}