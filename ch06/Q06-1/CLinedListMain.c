#include <stdio.h>
#include "CLinkedList.h"
#include "CLinkedList.c"

int main(void){
    // 원형 연결리스트의 생성 및 초기화 ////
    List list;
    int data, i, nodeNum;
    ListInit(&list);

    // 리스트 5개의 데이터를 저장 /////
    LInsertFront(&list, 1);
    LInsertFront(&list, 2);
    LInsertFront(&list, 3);
    LInsertFront(&list, 4);
    LInsertFront(&list, 5);

    // 전체 데이터 1회 출력 /////
    if(LFirst(&list, &data)){
        printf("%d", data);

        for(i = 0; i < LCount(&list); i++){
            if(LNext(&list, &data)){
                printf("%d", data);
            }
        }
    }

    printf("\n");

    return 0;
}