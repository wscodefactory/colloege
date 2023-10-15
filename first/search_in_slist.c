#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
}ListNode;

// 리스트 출력 함수
void display(ListNode *h)
{
    while (h != NULL) {
        printf("%d ", h->data);
        h = h->link;
    }
    printf("\n");
}

// 삽입 함수
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) 
{
	if( *phead == NULL ) {	// 공백리스트인 경우
		new_node->link = NULL; 
		*phead = new_node; 
	} else if( p == NULL ) { // p가 NULL이면 첫번째 노드로 삽입
		new_node->link = *phead;
		*phead = new_node;
	} else {			 // p 다음에 삽입
		new_node->link = p->link; 
		p->link = new_node; 
	}
}

// 탐색 함수
ListNode *search(ListNode *head, int x)
{
// 교재 or 수업자료 참고
    ListNode *p;
    p = head;
    while(p != NULL){
        if (p->data==x) return p;
        p = p->link;
    }
    return p;
}

int main()
{
    ListNode    *head = NULL;
    ListNode    *p, *new_node, *s;
    int         data, num;

    p = head;   // 최초에는 리스트가 비어 있으므로 NULL
    do {
        scanf("%d", &data);
        if (data == -1) break; // -1을 입력하면 입력 종료
        // 노드 1개를 동적 생성한 후 data를 넣고 리스트에 삽입
        new_node = (ListNode *) malloc(sizeof(ListNode));
        new_node -> data = data;
        insert_node(&head,p,new_node);
        p = new_node;

        
    } while (1);
    scanf("%d", &num);      // 찾고자 하는 정수 num 입력
    // 리스트에서 num 탐색
    s = search(head,num);

    // 찾은 노드부터 출력 or 못 찾은 경우 -1 출력
    if (s==NULL)
        printf("-1]n");
    else
        display(s);
}