#include <iostream>
using namespace std;
 
// A function will return number of pair
// whose XOR is odd
long long  countXorPair(long long  arr[], int  n)
{
    // To store count of odd and even
    // numbers
    long long  odd = 0, even = 0;
 
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
 
    // Return number of pairs
    return odd * even;
}
 
// Driver program to test countXorPair()
int main()
{
    int n;
    long long  t;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n;
        long long  arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << countXorPair(arr, n)<<endl;
    }
    
    
    
 
    return 0;
}
