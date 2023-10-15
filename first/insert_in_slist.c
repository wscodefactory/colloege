#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode
{
    int data;
    struct Listnode *link;
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
    // 수업자료 참고
    if (*phead == NULL){
        new_node->link = NULL;
        *phead = new_node;
    }
    else if ( p == NULL){
        new_node->link = *phead;
        *phead = new_node;
    }
    else{
        new_node->link = p->link;
        p->link = new_node;
    }

}
int main()
{
    ListNode    *head = NULL;
    ListNode    *p, *new_node;
    int         data;

    p = head;   // 최초에는 리스트가 비어 있으므로 NULL
    do {
        scanf("%d", &data);
        if (data == -1) break; // -1을 입력하면 입력 종료
        // 1) 동적으로 노드 생성 2) data를 노드에 저장 3) 노드를 리스트에 삽입
        new_node = (ListNode*) malloc(sizeof(ListNode));
        new_node -> data =  data;
        insert_node(&head,p,new_node);
        p = new_node;
    
    } while (1);

    // 리스트 출력 
    display(head);
}