//顺序栈

#include <stdio.h>
#include <stdbool.h>

#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int top;
}SqStack;

//初始化栈顶指针
void InitStack(SqStack * s){
    s->top = -1;
}

//判栈空
bool StackEmpty(SqStack * s){
    if(s->top==-1)
        return true;
    else
        return false;
}

bool Push(SqStack * s, int x){
    if(s->top==MaxSize-1)
        return false;
    s->data[++s->top] = x;
    return true;
}

bool Pop(SqStack * s, int x){
    if(s->top==-1)
        return false;
    x = s->data[s->top--];
    return true;
}

bool GetTop(SqStack S, )
int main() {
    printf("Hello, World!\n");
    return 0;
}