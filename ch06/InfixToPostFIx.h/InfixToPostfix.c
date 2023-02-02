#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"
#include "ListBaseStack.c"

/*인자로 받은 연산자의 우선순위를 반환하는 함수. 우선순위가 높을수록 큰 수를 반환*/
int GetOpPrec(char op){
    switch (op)
    {
    case '*':
    case '/':
        return 5;
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;
    
    default:
        return -1;
    }
}

/*인자로 받은 두 문자중 누가 우선순위가 더 높은지 숫자로 반환 첫번째 인자가 우선순위가 높으면 1, 두번쨰 인자가 높으면 -1, 둘다 같으면 0*/
int WhoPrecOp(char op1, char op2){
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec > op2Prec){
        return 1;
    } else if(op1Prec < op2Prec){
        return -1;
    } else {
        return 0;
    }
}

/*중위표기법을 후위표기법으로 바꾸는 함수*/
void ConvToRPNExp(char exp[]){
    Stack stack;                                            // 연산자의 우선순위를 결정하기 위해 쓰일 스택공간 정의
    StackInit(&stack);                                      // 스택공간 초기화
    int expLen = strlen(exp);                               // 인자로 받은 문자열의 길이 구함
    char * convExp = (char*)malloc(expLen+1);               // 후위표기식을 저장할 문자열 공간 할당

    int i, idx = 0;                                         // 문자열을 순회할떄 쓰일 인덱스 변수 i와 convExp를 참조할때 쓰일 인덱스변수 idx선언
    char tok, popOp;                                        // 현재 문자열을 의미하는 tok값과 스택에서 꺼낸 문자를 임시로 저장할 popOp변수 저장

    memset(convExp, 0, sizeof(char)*expLen+1);              // 후위표기식 문자가 저장될 공간을 0값으로 초기화

    for(i=0; i<expLen; i++){                                // 인자로 받은 문자열 길이만큼 반복
        tok = exp[i];                                       // 문자하나를 tok에 저장
        if(isdigit(tok)){                                   // 현재문자가 숫자면
            convExp[idx++] = tok;                           // 후위표기식 문자열에 저장
        } else {                                            // 현재문자가 연산자라면
            switch (tok)
            {
            case '(':                                       // 문자가 열림소괄호라면
                SPush(&stack, tok);                         // 스택에 삽입
                break;
            case ')':                                       // 문자가 닫힘소괄호라면
                while(1){
                    popOp = SPop(&stack);                   // 스택에서 탑요소를 꺼내 popOp에 저장
                    if(popOp == '('){                       // 현재 스택에서 꺼낸 요소가 열림소괄호라면 반복문 종료
                        break;
                    }
                    convExp[idx++] = popOp;                 // 스택에서 꺼낸 요소를 후위표기식으로 저장
                }
                break;
            case '+': case '-':                             // 연산자가 사칙연산자 중 하나라면
            case '*': case '/':
                while(!SIsEmpty(&stack) &&                  // 스택이 비어있지 안을떄, 
                    WhoPrecOp(SPeek(&stack), tok) >= 0){    // 스택의탑요소가 현재문자보다 우선순위가 높거나 둘의 우선순위가 같다면
                    convExp[idx++] = SPop(&stack);          // 스택에서 탑요소를 뽑아 후위표기식에 저장
                }
                SPush(&stack, tok);                         // 현재연산자를 스택에 삽입
                break;
            }
        }
    }

    while(!SIsEmpty(&stack)){                               // 스택에 연산자가 남아있으면
        convExp[idx++] = SPop(&stack);                      // 스택에서 탑요소를 뽑아 후위표기식에 저장
    }

    strcpy(exp, convExp);                                   // exp에 convExp를 복사
    free(convExp);                                          // convExp메모리 해제
}