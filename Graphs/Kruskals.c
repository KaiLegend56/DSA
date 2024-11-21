#include <stdio.h>
#define I __INT_MAX__
int edge[9][3]={{1,2,25},{1,6,5},{2,3,12},{2,7,10},{3,4,8},
                    {4,5,16},{4,7,14},{5,6,20},{5,7,18}};

int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};

int included[9]={0,0,0,0,0,0,0,0,0};

int find(int u){
    int x = u, v = 0;
    while( set[x] > 0 ){
        x = set[x];
    }
    return x;
}

int Union(int u, int v){
   if( u > v ){
        set[u] += set[v];
        set[v] = u;
   }
   else
   {
        set[v] += set[u];
        set[u] = v;
   }
   
}
int main(){
    int t [2][7];
    int u  = 0, v = 0 , j = 0 , k = 0, min;  
    while(j < 6){
        min = I;
        for ( int i = 0; i < 9; i++ ){
            if( min > edge[i][2] && included[i] != 1 ){
                min = edge[i][2];
                k = i;
                u = edge[i][0];
                v = edge[i][1];
            }
        }
        if( find(u) != find(v)){
            Union(find(u),find(v));
           t[0][j]=u;t[1][j]=v; 
            included[k] = 1;
            j++;
            printf("%d %d %d %d\n",u,v,find(u),find(v));
        }
        else{
            included[k] = 1;
        }
    }
    for( int i = 0; i < 6; i++){
        printf("%d -> %d \n", t[0][i], t[1][i]);
    }
}