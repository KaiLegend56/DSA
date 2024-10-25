#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Node * root = NULL;

void createTree(){
    struct Node *p, *t;
    int x;
    struct Queue q;

    createQ(&q, 100);

    printf("enter the val of the root");
    scanf("%d", &x);

    root = ( Node * ) malloc( sizeof( Node ));
    root -> val = x;
    root -> lchild = root -> rchild = NULL;

    enqueue(&q, root);

    while( ! isEmpty( q ) ){
        p = dequeue(&q);
        printf("enter the left child of the %d", p -> val);
        scanf("%d", &x);
        if( x != -1){
        t = ( Node * ) malloc (sizeof( Node ));
        t -> val = x;
        t -> rchild = t -> lchild = NULL;
        p -> lchild = t;
        enqueue(&q, t);
        }

        printf("enter the right child of the %d", p -> val);
        scanf("%d", &x);
        if( x != -1){
        t = ( Node * ) malloc (sizeof( Node ));
        t -> val = x;
        t -> rchild = t -> lchild = NULL;
        p -> rchild = t;
        enqueue(&q, t);
        }

    }

}
void preOrder( Node * p ){
        if(p){
        printf("%d", p -> val);
        preOrder(p -> lchild);
        preOrder( p -> rchild);
        }
}
void inOrder( Node * p){
    if( p ){
    inOrder( p -> lchild);
    printf("%d", p -> val);
    inOrder( p -> rchild);
    }
}
void postOrder( Node * p){
    if( p ){
        postOrder( p -> lchild);
        postOrder( p -> rchild);
        printf("%d", p -> val);
    }
}

int main (){
    createTree();

    preOrder(root);
     printf("\n");
    inOrder(root);
     printf("\n");
    postOrder(root);

    return 0;
}