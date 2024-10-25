#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode * root = NULL;

int Height( TreeNode * root ){
    if(root){
    int x,y;

    x = Height(root -> lchild);
    y = Height(root -> rchild);

    if( x > y)
    return x+1;
    else
    return y+1;
    }
    return 0;
}

TreeNode * inPre(TreeNode* p){
    while( p && p -> rchild != NULL ){
        p = p -> rchild;
    }
    return p;
}

TreeNode * inSuc(TreeNode* p){
    while( p && p -> lchild != NULL ){
        p = p -> lchild;
    }
    return p;
}

TreeNode* deleteNode( TreeNode * p, int val ){
    TreeNode * q;

    if( p == NULL )
    return NULL;
    
    if( p -> lchild == NULL && p -> rchild == NULL && p -> val == val){
        if( p == root ){
            root = NULL;
        }
        free(p);
        return NULL;
    } // so that any non existing node doesnt delete the last leaf node 

        if( p -> val < val ){
            p -> rchild = deleteNode(p -> rchild, val);
        }
        else if( p -> val > val ){
            p -> lchild = deleteNode(p -> lchild, val);
        }
        else{                         // the value is found copy suc or pre to the node and delete the copied further
            if( Height( p -> lchild ) > Height( p -> rchild ) ){
                q = inPre( p -> lchild); // inorder predecessor
                p -> val = q -> val;
                p -> lchild = deleteNode( p -> lchild, q -> val);
            }
            else{
                q = inSuc( p -> rchild ); // inorder successor
                p -> val = q -> val;
                p -> rchild = deleteNode ( p -> rchild, q -> val); // shifting of nodes 
            }
        }
        return p;
    }


int main(){
    
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
    printf("\n");
    deleteNode(root,30);
    inorder(root);
    printf("\n");
    deleteNode(root,10);
    printf("\n");
    inorder(root);
    deleteNode(root,60);
    inorder(root);

}