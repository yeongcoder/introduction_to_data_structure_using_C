#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "DLinkedList.c"
#include "Point.h"
#include "Point.c"

int WhoIsPrecede(LData d1, LData d2){
    if(d1->xpos < d2->xpos){
        return 0; // d1이 정렬 순서상 앞선다.
    } else if(d1->xpos == d2->xpos){
        if(d1->ypos < d2->ypos){
            return 0;
        } else {
            return 1;
        }
    } else {
        return 1;
    }
}

int main(void){
    List list;
    Point compPos;
    Point * ppos;

    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede);   // 정렬의 기준을 등록한다!

    // 4개의 데이터 저장 //////
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    // 저장된 데이터의 출력 //////
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &ppos)){
        ShowPointPos(ppos);

        while(LNext(&list, &ppos)){
            ShowPointPos(ppos);
        }
    }
    printf("\n");

    return 0;
}