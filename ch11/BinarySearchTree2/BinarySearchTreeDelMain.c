#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree2.h"
#include "BinarySearchTree2.c"

int main(void){
    BTreeNode * bstRoot;
    BTreeNode * sNode;
    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 5);     BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 1);     BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 4);     BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 3);     BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 7);
        
    BSTShowALl(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 3);
    free(sNode);

    BSTShowALl(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 8);
    free(sNode);

    BSTShowALl(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 1);
    free(sNode);

    BSTShowALl(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 6);
    free(sNode);

    BSTShowALl(bstRoot); printf("\n");
    return 0;
}