#include <cstdio>
#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    deque <int> q  ;
    int n,k;
    cin>>n>>k;
    vector<int > arr(n,0);
    for(int j=0;j<n;j++){
        cin>>arr[j];
    }
    int max=0;
    int second_max=0;
    for(int l=0;l<k;l++)
    {
        if(arr[l]>second_max)
        {
            int temp=second_max;
            second_max=arr[l];
            if(second_max>max){
                second_max=max;
                max=temp;
            }
        }
            q.push_back(arr[l]);
        
    }
    
    for(int i=k;i<n;i++)
        {
            cout<<max<<" ";
            int temp2=arr[k];
            int x=q.back();
            int y=q.front();
            
            
            
        }
    
    return 0;
}

