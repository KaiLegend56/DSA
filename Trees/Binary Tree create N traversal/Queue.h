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

#endif
