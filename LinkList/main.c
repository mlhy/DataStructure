#include <stdio.h>
#include <stdlib.h>

//单链表的插入：头插法和尾插法
typedef struct LNode{
    int data;
    struct LNode * next;
}LNode;

// 头插法
LNode * CreatList1(){
    LNode * s;int x;
    LNode * L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",&x);
    while(x!=999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}

//尾插法
LNode * CreatList2(){
    int x;
    LNode * L = (LNode *)malloc(sizeof(LNode));
    LNode * r = L;
    scanf("%d",&x);
    while(x!=999){
        LNode * s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    return L;
}

//按序号查找节点值
LNode * GetElem(LNode * L, int i){
    LNode *p = L;
    if(i<0) return NULL;
    for(int j=0; j<i && p; j++){
        p=p->next;
    }
    return p;
}

//    测试：按序号查找节点值
//    LNode *p2 = GetElem(L, 3);
//    if(p2 == NULL)
//        printf("%s","bad");
//    else
//        printf("%d",p2->data);


//按值查找节点
LNode * LocateElem(LNode * L, int e){
    LNode * p = L->next;
    while(p!=NULL&&p->data!=e)
        p=p->next;
    return p;
}


//    测试：按值查找节点
//    LNode *p3 = LocateElem(L, 3);
//    if(p3 == NULL)
//        printf("%s","not found");
//    else
//        printf("%p", p3);
//
//    p2->data;
//    (*p2).data;


//在位置 i 插入节点：后插操作
LNode * InsertElem(LNode * L, int i, int e){
    LNode * p, * s;
    p = GetElem(L,i-1);
    if(p == NULL)
        return NULL;
    s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return p;
}
//  测试：在位置 i 插入节点：后插操作
//  InsertElem(L, 3, 9);
//  p = L->next;
//  while(p){
//  printf("%p %d\n", p, p->data);
//  p = p->next;
//  }

LNode * DeleteElem(LNode * L, int i){
    LNode * p, * q;
    p = GetElem(L,i-1);
    q = p->next;
    p->next = q->next;
    free(q);
    return p;
}

//  测试：删除结点
//  DeleteElem(L, 3);
//  p = L->next;
//  while(p){
//  printf("%p %d\n", p, p->data);
//  p = p->next;
//  }

//  非循环列表求表长
int GetLenth(LNode * L){
    int i = 0;
    LNode * p = L->next;
    while(p!=NULL) {
        p = p->next;
        i++;
    }
    return i;
}

//    测试：求表长
//    printf("%d",GetLenth(L));


int main() {
//  测试：头插法、尾插法
    LNode * L = CreatList2();
    LNode *p = L->next;

    while(p){
        printf("%p %d\n", p, p->data);
        p = p->next;
        if(p == L)
            break;
    }

    printf("\n");

    return 0;
}

