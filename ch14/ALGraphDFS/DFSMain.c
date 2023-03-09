#include <stdio.h>
#include "ALGraphDFS.h"
#include "ALGraphDFS.c"

int main(void){
    ALGraph graph;              // 그래프의 생성
    GraphInit(&graph, 7);       // 그래프의 초기화

    AddEdge(&graph, A, B);      // 정점 A와 B를 연결
    AddEdge(&graph, A, D);      // 정점 A와 D를 연결
    AddEdge(&graph, B, C);      // 정점 B와 C를 연결
    AddEdge(&graph, D, C);      // 정점 D와 C를 연결
    AddEdge(&graph, D, E);      // 정점 D와 E를 연결
    AddEdge(&graph, E, F);      // 정점 E와 F를 연결
    AddEdge(&graph, E, G);      // 정점 E와 G를 연결

    ShowGraphEdgeInfo(&graph);  // 그래프의 간성정보 출력

    DFShowGraphVertex(&graph, A); printf("\n");
    DFShowGraphVertex(&graph, C); printf("\n");
    DFShowGraphVertex(&graph, E); printf("\n");
    DFShowGraphVertex(&graph, G); printf("\n");

    GraphDetroy(&graph);
    
    return 0;
}

