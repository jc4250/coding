//https://codeforces.com/problemset/problem/1470/A

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;

void solve();

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	#endif


	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}


void solve() {
	int n;
	cin>>n;

	int k = 0;
	int i;
	for (i = 31; i >= 0; i--) {
		int k = n >> i;
		if (k & 1) {
			// cout<<i<<endl;
			break;
		}
	}

	int ans = 0;
	for (int j = i-1; j >= 0; j--) {
		ans |= 1<<j;
	}
	cout<<ans<<endl;
}