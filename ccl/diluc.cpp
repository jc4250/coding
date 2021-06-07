//https://codeforces.com/contest/1536/problem/C

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

	string s;
	cin>>s;

	vector<int> d(n), k(n);

	map<pair<int, int>, int> mp;

	int tempd = 0, tempk = 0;
	for (int i = 0; i < n; i++) {

		if (s[i] == 'D') tempd++;

		if (s[i] == 'K') tempk++;

		int gcd = __gcd(tempd, tempk);
		int d = tempd/gcd;
		int k = tempk/gcd;
		mp[{d, k}]++;
		cout<<mp[{d, k}]<<" ";
	}
	cout<<endl;
}