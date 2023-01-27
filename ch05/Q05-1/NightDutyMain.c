#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "CLinkedList.c"
#include "Employee.h"

Employee * WhosNightDuty(List * plist, char * name, int day);
void ShowEmployeeInfo(Employee * emp);

int main(void)
{
	int i;
	Employee * pemp;

	List list;
	ListInit(&list);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 11111;
	strcpy(pemp->name, "Tery");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2222;
	strcpy(pemp->name, "Jery");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3333;
	strcpy(pemp->name, "Hary");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4444;
	strcpy(pemp->name, "Sunny");
	LInsert(&list, pemp);

	pemp = WhosNightDuty(&list, "Tery", 3);
	printf("Employee name: %s \n", pemp->name);
	// ShowEmployeeInfo(pemp);

	pemp = WhosNightDuty(&list, "Sunny", 15);
	printf("Employee name: %s \n", pemp->name);
	// ShowEmployeeInfo(pemp);

	if(LFirst(&list, &pemp))
	{
		free(pemp);
		
		for(i=0; i<LCount(&list)-1; i++)
		{
			if(LNext(&list, &pemp))
				free(pemp);
		}
	}

	return 0;
}

Employee * WhosNightDuty(List * plist, char * name, int day)
{
	int i, num;
	Employee *ret;

	num = LCount(plist);
	LFirst(plist, &ret);

	while(strcmp(ret->name, name) != 0){
		LNext(plist, &ret);
	}

	for(i=0; i<day; i++){
		LNext(plist, &ret);
	}

	return ret;
}

// void ShowEmployeeInfo(Employee * emp)
// {
// 	printf("Employee name: %s \n", emp->name);
// 	printf("Employee number: %d \n\n", emp->empNum);
// }