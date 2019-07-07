#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
    int data;
    struct DNode * prior;
    struct DNode * next;
}DNode, * DLinkList;

// 创建双链表
DLinkList CreatLinkList(){
    DNode * s;
    int x;
    DLinkList L = (DLinkList)malloc(sizeof(DNode));
    L->next = NULL;
    scanf("%d",&x);
    while(x!=999){
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;
        s->next = L->next;
        if(L->next)
            L->next->prior = s;
        s->prior = L;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}


//按序号查找节点值
DNode * GetElem(DLinkList L, int i){
    DNode *p = L;
    if(i<0) return NULL;
    for(int j=0; j<i && p; j++){
        p=p->next;
    }
    return p;
}

DNode * InsertElem(DLinkList L, int i, int e){
    DNode * p, * s;

    p = GetElem(L,i-1);
    if(p!=NULL)
        s = (DNode*)malloc(sizeof(DNode));
        s->data = e;
        s->next = p->next;
        p->next->prior = s;
        s->prior = p;
        p->next = s;
    return p;
}


DNode * DeleteElem(DLinkList L, int i){
    DNode * p, * q;
    p = GetElem(L,i-1);

    if(p!=NULL)
        q = p->next;
        p->next = q->next;
        q->next->prior = p;
        free(q);
    return p;
}


int main() {
    DLinkList L = CreatLinkList();
    DNode * p = L->next;
    while(p){
        printf("%d\n", p->data);
        p = p->next;
    }

//  测试：按序号查找节点值
    DNode *p2 = GetElem(L, 3);
    if(p2 == NULL)
        printf("bad\n");
    else
        printf("%d\n",p2->data);


//  测试：删除结点
    DeleteElem(L, 3);
    p = L->next;
    while(p){
        printf("%p %d\n", p, p->data);
        p = p->next;
   }

//  测试：在位置 i 插入节点：后插操作
//
//    InsertElem(L, 3, 9);
//    p = L->next;
//    while(p) {
//        printf("%p %d\n", p, p->data);
//        p = p->next;
//    }
    return 0;
}

