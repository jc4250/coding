// https://codeforces.com/contest/1520/problem/E

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
	int n;
	cin>>n;

	string s;
	cin>>s;


	int len = s.length();

	if (len == 1) {
		cout<<0<<endl;
		return;
	}
	vector<ll> arr(len), rev(len);

	ll count = 0;
	for (ll i = 0; i < len; i++) {
		if (s[i] == '*') count++;
		if (i > 0) arr[i] = arr[i-1];
		if (s[i] == '.') {
			arr[i] += count;
		}
	}

	count = 0;
	for (ll i = len - 1; i >= 0; i--) {
		if (s[i] == '*') count++;
		if (i != len-1) rev[i] = rev[i+1];
		if (s[i] == '.') {
			rev[i] += count;
		}
	}

	ll ans = LLONG_MAX;
	for (ll i = 1; i < len; i++) {
		ans = min(ans, rev[i]+arr[i-1]);
	}

	cout<<ans<<endl;
}