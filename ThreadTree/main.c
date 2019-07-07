#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode;

void InsertThreadNode(ThreadNode * root, ThreadNode * node){
    if(root!=NULL&&node!=NULL){
        if(node->data<root->data){
            if(root->lchild!=NULL)InsertThreadNode(root->lchild, node);
            else root->lchild = node;
        } else{
            if(root->rchild!=NULL)InsertThreadNode(root->rchild, node);
            else root->rchild = node;
        }
    }
}

ThreadNode * MakeNode(int data){
    ThreadNode * root = (ThreadNode*)malloc(sizeof(ThreadNode));
    root->lchild = NULL;
    root->rchild = NULL;
    root->ltag = 0;
    root->rtag = 0;
    root->data = data;
    return root;
}

ThreadNode * CreatBinaryTree(const int * a, int n){
    ThreadNode * root = MakeNode(a[0]);
    for(int i=1;i<n;i++){
        ThreadNode * node = MakeNode(a[i]);
        InsertThreadNode(root, node);
    }
    return root;
}

//遍历线索二叉树
ThreadNode* FirstNode(ThreadNode* p){
    while(p->ltag == 0) p = p->lchild;
    return p;
}

ThreadNode* NextNode(ThreadNode* p){
    if(p->rtag == 1) return p->rchild;
    else return FirstNode(p->rchild);
}

void InOrder(ThreadNode * root){
    if(root!=NULL){
        for(ThreadNode* p = FirstNode(root); p != NULL; p = NextNode(p)){
            printf("%d,", p->data);
        }
        printf("\n");
    }
}

//通过中序遍历线索化二叉树
void InThread(ThreadNode * root, ThreadNode ** pre){
    if(root!=NULL){
        InThread(root->lchild, pre);

        if(root->lchild==NULL){
            root->lchild = *pre;
            root->ltag = 1;
        }

        if((*pre)!=NULL&&(*pre)->rchild==NULL){
            (*pre)->rchild = root;
            (*pre)->rtag = 1;
        }
        *pre = root;

        InThread(root->rchild, pre);
    }
}

void CreateInThread(ThreadNode * root){
    ThreadNode * pre = NULL;
    if(root != NULL){
        InThread(root, &pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

int main() {
    int a[6] = {3, 2, 1, 5, 6, 4};
    ThreadNode * root = CreatBinaryTree(a, 6);
    CreateInThread(root);
    InOrder(root);

    printf("Hello, World!\n");
    return 0;
}