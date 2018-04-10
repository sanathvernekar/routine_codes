#include <bits/stdc++.h>

using namespace std;

int flipbits(int n) {
int res=n^((1<<32)-1);
return res;   
}

int main() {
    int n;
    cin >> n;
    int result = flipbits(n);
    cout << result << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        unsigned   N;
        cin >> N;
        
        cout <<~N<< endl;
    }
    return 0;
}

