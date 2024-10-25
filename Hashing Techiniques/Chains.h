#ifndef Chains_h
#define Chains_h
#include  <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node * next;
};

void SortedInsert(struct Node **H, int x){
        struct Node * t = NULL, *q = NULL, *p = *H;
        t = (struct Node *) malloc(sizeof(struct Node));
        t -> val = x;
        t -> next = NULL;

        if(*H == NULL){
            *H = t;
        }
        else {
        while(p && p -> val < x){
            {
                q = p;
                p = p -> next;
            } 
           
        }

        if( p == *H){
            t -> next = *H;
            *H = t;
        }
        else{
            t -> next = q -> next;
            q -> next = t;
        }

        }
}

struct Node * Search(struct Node *p , int key){
    while( p != NULL){
        if(key == p -> val){
            return p;
            
            printf("yp");
        }
        p = p -> next;
    }
    return NULL;
}

#endif