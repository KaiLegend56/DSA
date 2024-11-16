#include <stdio.h>
#include "Queue.h"

void BFS( int G[][7], int start, int n ){
    int i = start, j;
    int visited[7] = {0};

    printf("%d", i);
    enqueue(i);
    visited[i] = 1;

    while( !isEmpty() ) {
        i = dequeue();
        for( int j = 1; j < 7; j++){
            if( G[i][j] == 1 && visited[j] == 0){
                printf("%d", j);
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
}

void DFS( int G[][7], int start, int end){
    int i = start, j;
    static int visited[7] = {0};

    if( visited[start] == 0){
        printf("%d", start);
        visited[start]=1;
        for( j = 1; j < 7; j++){
           if( G[i][j] == 1 && visited[j] == 0)
             DFS( G, j, 7);
        }
    }

}

int main(){
            int G[7][7]={{0,0,0,0,0,0,0},
            {0,0,1,1,0,0,0},
            {0,1,0,0,1,0,0},
            {0,1,0,0,1,0,0},
            {0,0,1,1,0,1,1},
            {0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0}};
            BFS(G,5,7);
            printf("\n");
            DFS(G,1,7);
}