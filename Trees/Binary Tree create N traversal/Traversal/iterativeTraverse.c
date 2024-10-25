#include <stdio.h>
#include <stdlib.h>
#include "treeGenerate.h"

int top = -1;

void push( Node * stack [], Node * p ){
    if( top == 100)
    printf("stack is full");
    else{
        top++;
        stack[top] = p;
    }
}

Node * pop( Node * stack []){
    if( top == -1)
    printf("empty ");
    else{
       return stack[top--];
    }
}

int isStackEmpty(){
    if( top == -1)
    return 0;
    return 1;
}

int main(){
    createTree();
    Node * stack[100];
    Node * p = root;
    printf("Preorder");
    while( p != NULL || isStackEmpty() != 0 ){
        if( p != NULL){
            push(stack, p);
            printf(" %d", p -> val); // preorder
            p = p -> lchild;
        }
        else{
           p = pop(stack);
        //   printf(" %d", p -> val); // inorder
           p = p -> rchild;
        }
    }
    p = root;
    printf("Inorder /n");
    while( p != NULL || isStackEmpty() != 0 ){
        if( p != NULL){
            push(stack, p);
            p = p -> lchild;
        }
        else{
           p = pop(stack);
           printf(" %d", p -> val); // inorder
           p = p -> rchild;
        }
    }
    p = root;
     while( p != NULL || isStackEmpty() != 0 ){
        if( p != NULL){
            push(stack, p);
            p = p -> lchild;
        }
        else{
           if( t < 0){
           p = pop(stack);
           printf(" %d", p -> val); 
           p = p -> rchild;
           }
           else{
            
           }
        }
    }
    
}