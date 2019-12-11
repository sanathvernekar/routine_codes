#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,i,j;
    int arr[10][10];
    int count=0;
    max_count=0;
    int max_sum=0;
    int *p,*q;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j])
                max_count+=1;
        }
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            
            
            if(arr[i][j]==1){
                max_sum=arr[i-1][j-1]+
                
                
                
                
            }
            
        }
    }
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

