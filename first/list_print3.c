#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct dlistnode{
    
    element data;
    struct dlistnode *llink;
    struct dlistnode *rlink;
    
} DlistNode;

void display(DlistNode *head)
{
    DlistNode   *p;
    p = head->rlink;
    while(p != head){
        printf("%d ", p->data);
        p = p->rlink;
    }
    printf("\n");

}

void dinsert_node(DlistNode *before, DlistNode *new_node)
{
    new_node -> llink = before;
    new_node -> rlink = before -> rlink;
    before -> rlink -> llink = new_node;
    before -> rlink = new_node;
    
}

void dremove_node(DlistNode *head, DlistNode *removed)
{
    if( removed == head ) return;
    removed -> llink -> rlink = removed -> rlink;
    removed -> rlink -> llink = removed -> llink;
    free(removed);
}

int main()
{
    DlistNode    header;
    DlistNode    *before, *new_node;
    int          data;

    // header node 구성 
    header.llink = &header;
    header.rlink = &header;

    // 사용자 입력, 노드 생성, 리스트 삽입
    before = &header;

    do {
        scanf("%d", &data);
        if (data == -1) break;
    new_node = (DlistNode*)malloc(sizeof(DlistNode));
    new_node -> data = data;
    dinsert_node(before, new_node);
    before = new_node;

    } while (1);

    // 출력
    display(&header);
    // 마지막 노드 삭제
    dremove_node(&header, header.llink);
    // 출력
    display(&header);
}