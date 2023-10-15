#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;		// ��ü!
							// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�.
							// ===== ���� �ڵ��� ���� =====
#define MAX_STACK_SIZE 100
#define MAX_STR_SIZE   4096


typedef struct {
    element stack [MAX_STACK_SIZE];
    int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
    s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
    return (s->top==-1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
    return(s->top==(MAX_STACK_SIZE-1));
}
// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	    // push 
	s->stack[++(s->top)]=item;
}
// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else 
	    // pop
	    return s->stack[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	    // peek
	    return s->stack[s->top];
}
// ===== ���� �ڵ��� �� =====
int check_matching(const char *in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);  	// n= ���ڿ��� ����
	init_stack(&s);			// ������ �ʱ�ȭ

	for (i = 0; i < n; i++) {
		ch = in[i];		// ch = ���� ����
		switch (ch) {
		case '(':   case '[':    case '{':
            // push
            push(&s,ch);
            break;
		case ')':   case ']':    case '}':
            // pop �Ͽ� ��. unmatch�̸� 0�� return
            if (is_empty(&s)!=0) return 0;
            open_ch = pop(&s);
            if(ch!='(' && ch!=')' ||ch!='[' && ch!=']'|| ch!='{' && ch!='}')
            {
                return 0;
            }
            
            break;
		}
	}
	if (!is_empty(&s)) return 0; // ���ÿ� ���������� unmatch
	return 1;   // match�̸� 1�� return
}

int main(void)
{
	char    *line = NULL;
	size_t     size;
	getline(&line, &size, stdin);
	if (check_matching(line) == 1)
		printf("%s ��ȣ�˻缺��!\n", line);
	else
		printf("%s ��ȣ�˻����!\n", line);
	return 0;
}