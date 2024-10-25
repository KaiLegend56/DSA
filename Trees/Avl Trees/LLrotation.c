#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    struct TreeNode * lchild;
    int val;
    int height;
    struct TreeNode * rchild;
} TreeNode;

TreeNode * root = NULL;

int NodeHeight( TreeNode * root){
    int hl, hr;
    hl = root && root -> lchild ? root -> lchild -> height : 0;
    hr = root && root -> rchild ? root -> rchild -> height : 0;

    return hl>hr ? hl+1 : hr + 1;

}

int balanceFactor( TreeNode * root){
    int hl, hr;
    hl = root && root -> lchild ? root -> lchild -> height : 0;
    hr = root && root -> rchild ? root -> rchild -> height : 0;
    

    return hl-hr;
}

TreeNode * LLrotation ( TreeNode * p ){
    TreeNode * pl = p -> lchild;
    TreeNode * plr = pl -> rchild;

    pl -> rchild = p;
    p -> lchild = plr;

    p -> height = NodeHeight(p);
    pl -> height = NodeHeight(pl);

    if( root == p )
        root = pl;
    return pl;    
}

TreeNode * LRrotation ( TreeNode * p ){
    TreeNode * pl = p -> lchild;
    TreeNode * plr = pl -> rchild;

    p -> lchild = plr -> rchild;
    pl -> rchild =  plr ->  lchild;
    plr -> rchild = p;
    plr -> lchild = pl;

    p ->  height = NodeHeight(p);

    if( p == root)
        root = plr;

    return plr;    

}

TreeNode * RLrotation ( TreeNode * p ){
    return  NULL;
}

TreeNode * RRrotation ( TreeNode * p ){
    TreeNode * pr = p -> rchild;
    TreeNode * prl = pr -> lchild;

    pr -> lchild = p;
    p -> rchild = prl;

    pr -> height = NodeHeight(pr);
    p -> height = NodeHeight(p);

    if( root == p){
        root = pr;
    }
    return pr;
}

TreeNode * insertSorted( TreeNode * root, int key){

    if( root ){

        if( root -> val > key ){
            root -> lchild = insertSorted(root -> lchild, key);
             
        }

        if( root -> val < key ){
            root -> rchild = insertSorted(root -> rchild, key);
              
        }

       root -> height = NodeHeight( root );

       if( balanceFactor(root) == 2 && balanceFactor( root -> lchild ) == 1)
            return LLrotation(root);
       else if( balanceFactor( root ) == 2 && balanceFactor( root -> lchild ) == -1)
            return LRrotation(root);
       else if( balanceFactor( root ) == -2 && balanceFactor( root -> rchild ) == -1)
            return RRrotation(root);
       else if( balanceFactor( root ) == -2 && balanceFactor( root -> rchild ) == 1)
            return RLrotation(root);  

        return root;

    }
    else{
        TreeNode * temp = (TreeNode *) malloc(sizeof(TreeNode));
        temp -> val = key;
        temp -> height = 1;
        temp -> rchild = temp -> lchild = NULL;
        return temp;
    }
}

int main(){
    root = insertSorted(root,15);
    insertSorted(root,10);
    insertSorted(root,13);
    printf("%d %d %d", root -> val, root -> lchild -> val, root -> rchild -> val);
}