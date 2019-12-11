#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    int count=0;
    for(int j =0;j<n-1;j++){
        for(int k=j+1;k<n;k++){
            if(a[j]>a[k]){
                count=count+1;
                //cout<<a[j]<<" "<<a[j+1]<<endl;
                a[j]=a[j]^a[k];
                a[k]=a[k]^a[j];
                a[j]=a[j]^a[k];
                //cout<<a[j]<<" "<<a[j+1]<<endl;
            }
        }
    }
    cout<<"Array is sorted in "<<count<<" swaps."<<endl;
    cout<<"First Element: "<<a[0]<<endl;
    cout<<"Last Element: "<<a[n-1]<<endl;
    return 0;
}

