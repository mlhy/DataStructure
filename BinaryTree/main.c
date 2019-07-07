#include <stdio.h>
#include <stdlib.h>

typedef struct TNode{
    int data;
    struct TNode *lchild, *rchild;
}TNode;

void InsertTNode(TNode * root, TNode * node){
    if(root!=NULL&&node!=NULL){
        if(node->data<root->data){
            if(root->lchild!=NULL)InsertTNode(root->lchild, node);
            else root->lchild = node;
        } else{
            if(root->rchild!=NULL)InsertTNode(root->rchild, node);
            else root->rchild = node;
        }
    }
}

TNode * CreatBinaryTree(const int * a, int n){
    TNode * root = (TNode*)malloc(sizeof(TNode));
    root->lchild = NULL;
    root->rchild = NULL;
    root->data = a[0];
    for(int i=1;i<n;i++){
        TNode * node = (TNode*)malloc(sizeof(TNode));
        node->lchild = NULL;
        node->rchild = NULL;
        node->data = a[i];
        InsertTNode(root, node);
    }
    return root;
}

void InOrder(TNode * root){
    if(root!=NULL){
        InOrder(root->lchild);
        printf("%d,", root->data);
        InOrder(root->rchild);
    }
}

void PreOrder(TNode * root){
    if(root!=NULL){
        printf("%d,", root->data);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

void PostOrder(TNode * root){
    if(root!=NULL){
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        printf("%d,", root->data);
    }
}

int main() {
    int a[6] = {3, 2, 1, 5, 6, 4};
    TNode * root = CreatBinaryTree(a, 6);
    InOrder(root);
    printf("\n");
    PreOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");
    printf("Hello, World!\n");
    return 0;
}