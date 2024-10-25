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

int count( Node * root ){
    int x, y = 0;
    if( root ){
        x = count(root -> lchild);
        y = count( root -> rchild);

        return x+y+1;
    }
    return 0;
}

int height( Node * root){
    int x = 0;
    int y = 0;
        if( root == 0)
            return 0;
        x = height(root -> lchild);
        y = height(root -> rchild);
        
        if( x > y )
            return x+1;
        else
            return y+1;
   

}
int post(Node * root, int* c){
    if(root){
    post(root -> lchild,c);
    post( root -> rchild,c);
    (*c)++;
    }
}
int main(){

    createTree();
    Node * p = root;
    printf("heigth = %d", height(root));
    printf("count = %d", count(root));
    int c = 0;
    post(root, &c);
    printf("%d",c);
    // count leaf nodes and non leaf nodes
    
    
}