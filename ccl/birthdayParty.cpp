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
	ll k, c;

	cin>>k>>c;

	vector<ll> arrk(k), arrc(c);
	for (ll i = 0; i < k; i++) {
		cin>>arrk[i];
	}

	for (ll i = 0; i < c; i++) {
		cin>>arrc[i];
	}

	sort(arrk.begin(), arrk.end(), greater<>());

	ll j = 0;

	ll sum = 0;
	for (ll i = 0; i < arrk.size(); i++) {
		if (arrc[arrk[i]-1] < arrc[j]) {
			sum += arrc[arrk[i]-1];
		} else {
			sum += arrc[j];
			j++;
		}
	}
	cout<<sum<<endl;
}