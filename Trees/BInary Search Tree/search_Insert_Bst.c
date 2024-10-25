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

TreeNode * search( TreeNode * root, int key){
    if(root){
        if( root -> val == key){
            return  root;
        }
        if( root -> val > key){
            search(root -> lchild, key);
        }
        if( root -> val < key ){
            search( root -> rchild, key );
        }
    }
    return NULL;
}

TreeNode * insertSorted( TreeNode * root, int key){

    if( root ){

        if( root -> val > key ){
            root -> lchild = insertSorted(root -> lchild, key);
             
        }

        if( root -> val < key ){
            root -> rchild = insertSorted(root -> rchild, key);
              
        }

        return root;
    }
    else{
        TreeNode * temp = (TreeNode *) malloc(sizeof(TreeNode));
        temp -> val = key;
        temp -> rchild = temp -> lchild = NULL;
        return temp;
    }
} // recursive insert 

int main(){
    TreeNode * root = NULL;
    int x;
    printf("enter root of the tree");
    scanf("%d", &x);

    root = (TreeNode *) malloc ( sizeof( TreeNode ) );
    root -> lchild = NULL;
    root -> rchild = NULL;
    root -> val = x;

    while( 1 ){
        printf("enter number ");
        scanf("%d", &x);    
        if(x != -1)
        insertNode(root, x);
        else
        break;
    }

    inorder(root);
}