// 2019.4.7
// 线性表的基本操作
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int * data;
    int Maxsize,length;
}SeqList;

// InitList(&L):
// 初始化表。构造一个空的线性表。
SeqList * InitList(int n){
    SeqList * L = (SeqList *)malloc(sizeof(SeqList));
    L->data = (int *)malloc(n*sizeof(int));
    L->Maxsize = n;
    L->length = 0;
    return L;
}

// Length(L):求表长。返回线性表 L 的长深度，即 L 中数据元素的个数。
int Length(SeqList * L){
    return L->length;
}

// LocateElem(L,e):按值查找，返回对应的值 e 的位置。
int LocateElem(SeqList * L,int e){
    for(int i=0;i<L->length;i++){
        if(L->data[i] == e)
        //L->data 的其它表示 *(L->data + i)
            return i+1;
    }
    return 0;
}

// GetElem(L,i):按位查找。获取表 L 中第 i 个位置的元素。
// i 从1开始,i 的范围是[1,length]。
int GetElem(SeqList * L,int i){
    if((i<1)||(i>L->length))
        return 0;
    return L->data[i-1];
}

// ListInsert(&L,i,e):插入操作。在表 L 的第 i 个位置插入指定元素 e。
// 因为是插入操作 i 的范围是[1,length+1]

bool ListInsert(SeqList * L,int i,int e){
    if((i>0)&&(i<(L->length+2))&&(L->length<L->Maxsize)){
        for(int j=L->length+1;j>i-1;j--){
            L->data[j] = L->data[j-1];
        }
        L->data[i-1] = e;
        L->length += 1;
        return true;
    }
    else
        return false;
}

// ListDelete(&L,i,&e):删除操作。删除表 L 中第 i 个位置的元素。
// i 从1开始,i 的范围是[1,length]。

bool ListDelete(SeqList * L,int i){
    if((i>0)&&(i<(L->length+1))){
        for (int j=i-1; j<(L->length-1); j++) {
            L->data[j] = L->data[j+1];
        };
        L->length -= 1;
        return true;
    }
    else
        return false;
}

// PrintList(L):输出操作。按照前后顺序，输出线性表 L 中所有的值。
void PrintList(SeqList * L){
    for(int i=0;i<L->length;i++)
        printf("%d,",L->data[i]);
    printf("\n");
}

// Empty(L):判空操作。若 L 为空表，则返回 true，否则返回 false。
bool Empty(SeqList * L){
    return (L->length==0);
}

// DestroyList(&L):销毁线性表，并释放线性表 L 所占用的内存空间。
void DestroyList(SeqList *L){
    if(L){
        free(L->data);
        free(L);
    }
}

int main() {
    printf("运行开始\n");
    SeqList * L = InitList(100);

    printf("创建一个线性表，长度为");
    for(int i=0;i<10;i++){
        L->data[i] = i+1;
        L->length += 1;
    }
    printf("%d\n", Length(L));

    printf("线性表的内容是：");
    PrintList(L);

    printf("测试 LocateElem(L,e)。按值查找。返回对应的值 e=3 的位置。期望输出3，实际输出");
    printf("%d\n", LocateElem(L,3));

    printf("测试 GetElem(L,e)。按位查找。获取表 L 中第 i=4 位置的元素。期望输出4，实际输出");
    printf("%d\n", GetElem(L,4));

    printf("测试 ListInsert(&L,i,e)。插入操作。在表 L 的第 i=0 个位置插入指定元素 e=0。期望输出1，实际输出");
    printf("%d\n", ListInsert(L,1,0));
    printf("期望输出：0,1,2,3,4,5,6,7,8,9,10,\n实际输出：");
    PrintList(L);

    printf("测试 ListDelete(&L,i,&e)。删除操作。删除表 L 中第 i=1 个位置的元素。期望输出1，实际输出");
    printf("%d\n", ListDelete(L,1));
    printf("期望输出：1,2,3,4,5,6,7,8,9,10,\n实际输出：");
    PrintList(L);

    printf("测试 Empty(L)。若 L 为空表，则返回 true，否则返回 false。期望输出0，实际输出");
    printf("%d\n", Empty(L));
    return 0;
}