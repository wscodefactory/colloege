//
// postfix 수식 계산하기
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STACK_SIZE 100 //스택의 최대 크기 '100'으로 지정

typedef int element;    // 피연산자가 스택에 들어가므로 int 형

// (스택 구조체)
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;
// (스택 초기화 함수)
void init_stack(StackType *s) {
    s->top = -1; // 공백 상태로 초기화
}
// (공백 상태 확인 함수)
int is_empty(StackType *s) {
    return (s->top == -1); // 공백 상태일 경우 TRUE 반환
}
// (포화 상태 확인 함수)
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1)); // 포화 상태일 경우 TRUE 반환
}
// (데이터 삽입 함수)
void push(StackType *s, element item) {
    if (is_full(s)) {
        printf("스택 포화 오류");
        return;
    } 
    else s->data[++(s->top)] = item;
}
// (데이터 삭제 함수)
element pop(StackType *s) {
    if(is_empty(s)) {
        printf("스택 공백 오류");
        return 0;
    }
    else return s->data[(s->top)--]; // 공백 상태가 아닐 경우 스택 삭제
}
// (TOP 확인 함수)
element peek(StackType *s) {
    if (is_empty(s)) {
        printf("스택 공백 오류");
        return 0;
    }
    else return s->data[s->top]; // 공백 상태가 아닐 경우 Top값 반환
}

// (후위 표기 수식 계산 함수) 
int eval(char exp[])
{
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;
    
    init_stack(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        // ch가 피연산자이면 push. ch는 문자이므로 값으로 변환하여 push
        if (ch!='+' && ch!='-' && ch!='*' && ch!='/' )
        {
            value = ch - '0';
            push(&s,value);
        }

        // 그렇지 않으면(연산자이면), pop 두 번 후 연산 수행. 결과값 push
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch){
                case '+' : push(&s, op1+op2); break;
                case '-' : push(&s, op1-op2); break;
                case '*' : push(&s, op1*op2); break;
                case '/' : push(&s, op1/op2); break;
            }
        }
        
        
    }
    return pop(&s);
}

void main()
{
    char    postfix[100];

    scanf("%s", postfix);
    printf("%d\n", eval(postfix)); // 수식 결과값 출력
}
