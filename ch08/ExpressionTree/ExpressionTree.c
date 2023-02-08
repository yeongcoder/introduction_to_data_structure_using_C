#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "ListBaseStack.c"
#include "BinaryTree2.h"
#include "BinaryTree2.c"

BTreeNode * MakeExpTree(char exp[]){
    Stack stack;
    BTreeNode * pnode;

    int expLen = strlen(exp);
    int i;
    for(i=0; i<expLen; i++){
        pnode = MakeBTreeNode();

        if(isdigit(exp[i])){
            SetData(pnode, exp[i] - '0');
        } else {
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);
        }

        SPush(&stack, pnode);
    }

    return SPop(&stack);
}

// int EvaluateExpTree(BTreeNode * bt){        // 수식 트리 계산

// }        

void ShowPrefixTypeExp(int data){
    if(0<=data && data<=9)
        printf("%d", data);
    else 
        printf("%c", data);
}

void ShowPrefixTypeExp(BTreeNode * bt){     // 전위 표기법 기반 출력
    PreorderTraverse(bt, ShowPrefixTypeExp);
}    
void ShowInfixTypeExp(BTreeNode * bt){      // 중위 표기법 기반 출력    
    InorderTraverse(bt, ShowPrefixTypeExp);
}     
void ShowPostfixTypeExp(BTreeNode * bt){    // 후위 표기법 기반 출력
    PostorderTraverse(bt, ShowPrefixTypeExp);
}   