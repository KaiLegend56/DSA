#ifndef Queue_h
#define Queue_h
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node *lchild;
    int val;
    struct Node *rchild;
}Node;

typedef struct Queue{
    int size;
    int front;
    int rear;
    Node ** Q;
}Queue;

void createQ(struct Queue * q, int size){
    q -> size = size;
    q -> front = q -> rear = 0;
    q -> Q = (Node **) malloc ( q -> size * sizeof(Node *) );
}

void enqueue(struct Queue * q, struct Node * x ){
    if( ( q -> rear + 1 ) % q -> size == q -> front ){
        printf("Queue is full");
    }
    else{
        q -> rear = ( q -> rear + 1) % q -> size;
        q -> Q[q -> rear] = x;
    }
}

struct Node * dequeue(struct Queue * q){
    struct Node * x  = NULL;
    if( q -> front == q -> rear )
        printf("Queue is empty");
    else{
        q -> front = ( q -> front + 1) % q -> size;
        x = q -> Q[ q -> front ];
    }    
    return x;
}

int isEmpty(struct Queue q){
    return  q.front == q.rear ;
}

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

#endif
