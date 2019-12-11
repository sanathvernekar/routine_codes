#include <bits/stdc++.h>

using namespace std;

int lonelyinteger(vector <int> a) {
    return accumulate(a.begin(), a.end(), 0, [](int k, int i){ return k = k ^ i;});
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = lonelyinteger(a);
    cout << result << endl;
    return 0;
}

