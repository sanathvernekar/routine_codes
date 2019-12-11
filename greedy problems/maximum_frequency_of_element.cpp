#include <vector>
#include <map>
#include<bits/stdc++.h>
using namespace std;
long long int max_frequency(vector<long long int> const& v)
{   
    map<long long int, long long int> frequencyMap;
    long long int maxFrequency = 0;
    long long int mostFrequentElement = 0;
    for (long long int x : v)
    {
        long long int f = ++frequencyMap[x];
        if (f > maxFrequency)
        {
            maxFrequency = f;
            mostFrequentElement = x;
        }
    }

    return maxFrequency;
}

int main()
{
    long long int t,n,i,j,temp;
    cin>>t;
    while(t--){
        cin>>n;
        vector<long long int >v;
        for(i=0;i<n;i++){
            cin>>temp;
            v.push_back(temp);
        }
        cout<<max_frequency(v)<<endl;
    }
}