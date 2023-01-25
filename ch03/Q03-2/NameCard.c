#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone){
    NameCard * ncd;
    ncd = (NameCard *)malloc(sizeof(NameCard));
    strcpy(ncd->name, name);
    strcpy(ncd->phone, phone);
    return ncd;
}

void ShowNameCardInfo(NameCard * pcard){
    printf("[%s, %s]\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard * pcard, char * name){
    return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, char * phone){
    strcpy(pcard->phone, phone);
}