#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    struct TreeNode * lchild;
    int val;
    struct TreeNode * rchild;
}TreeNode;

TreeNode * createNode( int data ){
    TreeNode * p = ( TreeNode *) malloc( sizeof( TreeNode ));
    p -> lchild = p -> rchild = NULL;
    p -> val = data;
    return p;
}

void insertNode( TreeNode * p ,  int data){
    if( p ){
        if( data > p -> val ){
            if( p -> rchild == NULL){
                p -> rchild = createNode(data);
            }
            else
                insertNode( p -> rchild, data );
        }
        if( data < p -> val ){
            if( p -> lchild == NULL){
                p -> lchild = createNode(data);
            }
            else
                insertNode( p -> lchild, data );
        }
    }
}
void inorder( TreeNode * p ){
    if( p ){
        inorder( p -> lchild );
        printf("%d ", p -> val);
        inorder( p -> rchild );
    }
}
