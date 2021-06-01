//https://codeforces.com/problemset/problem/1195/C

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

	vector<ll> a(n+1, 0), b(n+1, 0);

	for (ll i = 0; i < n; i++) {
		cin>>a[i];
	}

	for (ll i = 0; i < n; i++) {
		cin>>b[i];
	}

	for (ll i = n-1; i >= 0; i--) {
		a[i] = max(b[i+1] + a[i], a[i+1]);
		b[i] = max(a[i+1] + b[i], b[i+1]);
	}

	cout<<max(a[0], b[0])<<endl;
}