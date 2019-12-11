// Bear and Stickman
// author: Errichto
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
bool t[205][205];
int bin(int a, int b) {
	int s = 1;
	for(int i = 1; i <= b; ++i)
		s = s * (a + 1 - i) / i;
	return s;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		t[a][b] = t[b][a] = true;
	}
	int s = 0;
	for(int a = 1; a <= n; ++a)
		for(int b = 1; b <= n; ++b)
			if(t[a][b]) {
				int x = 0, y = 0, z = 0;
				for(int i = 1; i <= n; ++i) {
					if(t[a][i] && t[b][i]) ++y;
					else if(t[a][i]) ++x;
					else if(t[b][i]) ++z;
				}
				--x; --z;
				for(int two = 0; two <= 2; ++two)
					for(int three = 0; three <= 3; ++three) {
						s += (long long) bin(y, two) * bin(x, 2-two) * bin(y-two, three) * bin(z, 3-three) % mod;
						s %= mod;
					}
			}
	printf("%d\n", s);
	return 0;
}
