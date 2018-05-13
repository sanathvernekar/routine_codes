#include <iostream>
using namespace std;
long long  maxSum(long long  n)
{

    if (n == 1)
        return 1;
    else
        return (n * (n - 1) / 2) - 1 + n / 2;
}

int main()
{
    long long  t;
    cin>>t;
    long long  n;
    for(int i=0;i<t;i++){
        cin>>n;
        cout << maxSum(n)<<endl;
    }
    
    return 0;
}
