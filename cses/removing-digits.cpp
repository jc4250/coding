//https://cses.fi/problemset/task/1637

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
	// cin >> t;
	while (t--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}


void solve() {
	int n;
	cin>>n;

	int ans = 0;
	while(n > 0) {
		int sub = 0;
		int temp = n;

		while(temp > 0) {
			sub = max(sub, temp%10);
			temp /= 10;
		}

		n -= sub;
		ans++;
	}

	cout<<ans<<endl;
}