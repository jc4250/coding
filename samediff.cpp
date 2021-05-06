//https://codeforces.com/contest/1520/problem/D

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
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
	ll ans = 0, n;
	cin>>n;

	unordered_map<ll, ll> mp;
	vector<ll> arr(n);

	for (ll i = 0; i < n; i++) {
		cin>>arr[i];
		if (mp.count(arr[i]-i) > 0) {
			ans += mp[arr[i]-i];
		}
		mp[arr[i]-i]++;
	}

	cout<<ans<<endl;
}