#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
// get next greater element of a given number in a sorted array

ll next_highest_number(ll arr[], ll low, ll high, ll key,ll size){
    if (low>high){
        if(high<(size-1))return arr[high+1];
        else return -1;
    }
    ll mid = (low+high)/2;
    if(arr[mid]==key){
        if(mid<(size-1))return arr[mid+1];
        else return -1;
    }
    else if(arr[mid]>key)next_highest_number(arr,low,mid-1,key,size);
    else next_highest_number(arr,mid+1,high,key,size);
}
int main() {
    ll arr[12]={2,6,9,12,18,24,36,42,44,49,60,74};
    ll key;
    cin>>key;
    ll size=sizeof(arr)/sizeof(ll);
    cout<<next_highest_number(arr,0,size-1,key,size);
	return 0;
}
