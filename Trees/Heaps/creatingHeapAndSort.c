#include <stdio.h>

void swap(int * p, int * q){
    int temp  = *p;
    *p = *q;
    *q = temp;
}

void insert( int a[], int n){
    int i = n;
    while( i != 1 && a[i] > a[i/2] ){
        swap(&a[i], &a[i/2]);
        i = i / 2;
    }
}

void delete( int a[], int n){
    int temp = a[1];
    a[1] = a[n];
    int i = 1, j = 2;
    while( j < n - 1 ){
        if ( a[j] < a[j+1])
            j++;
        if( a[i] < a[j]){
            swap(&a[i], &a[j]);
        i = j;
        j = 2 * j;
        }
        else      
            break;  
    }
    a[n] = temp;
}

int main(){
    int heap[] = { 0,5,18,19,2,45,12,4,1,22,6};
    for( int i = 2; i < 10; i++){
        insert(heap, i);
    }
    for( int i = 1; i < 10; i++){
        delete(heap,10-i);
    }
    for( int i = 1; i < 10; i++){
        printf("%d ", heap[i]);
    }
}