#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#include "NameCard.c"
#include "ArrayList.h"
#include "ArrayList.c"

int main(void){
    // 1.총 3명의 전화번호 정보를, 앞서 구현한 리스트에 저장.
    List list;
    NameCard * ncd;
    
    ListInit(&list);

    ncd = MakeNameCard("AA", "123");
    LInsert(&list, ncd);
    
    ncd = MakeNameCard("BB", "456");
    LInsert(&list, ncd);

    ncd = MakeNameCard("CC", "789");
    LInsert(&list, ncd);

    // 저장된 데이터의 출력 //////
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &ncd)){
        ShowNameCardInfo(ncd);

        while(LNext(&list, &ncd)){
            ShowNameCardInfo(ncd);
        }
    }
    printf("\n");


    // 2.특정 이름을 대상으로 탐색진행 그 사람의 정보 출력
    if(LFirst(&list, &ncd)){
        if(NameCompare(ncd, "BB")){

            while(LNext(&list, &ncd)){
                if(!NameCompare(ncd, "BB")){
                    ShowNameCardInfo(ncd);
                    break;
                }
            }

        } else {
            ShowNameCardInfo(ncd);
        }
    }

    // 3.특정 이름을 대상으로 탐색진행 그 사람의 전화번호 변경
    if(LFirst(&list, &ncd)){
        if(NameCompare(ncd, "BB")){
            while(LNext(&list, &ncd)){
                if(!NameCompare(ncd, "BB")){
                    ChangePhoneNum(ncd, "999");
                }
            }
        } else {
            ChangePhoneNum(ncd, "999");
        }
    }

    // 4.특정 이름을 대상으로 탐색진행 그 사람의 정보 삭제
     LFirst(&list, &ncd);

    if(NameCompare(ncd, "AA")){
        while(LNext(&list, &ncd)){
            if(!NameCompare(ncd, "AA")){
                ncd = LRemove(&list);
                free(ncd);
            }
        }
    } else {
        ncd = LRemove(&list);
        free(ncd);
    }


    // 5.남아 있는 모든 사람의 정보 출력
    printf("남아 있는 모든 사람: %d \n", LCount(&list));

    if(LFirst(&list, &ncd)){
        ShowNameCardInfo(ncd);

        while(LNext(&list, &ncd)){
            ShowNameCardInfo(ncd);
        }
    }
    printf("\n");

    return 0;
}