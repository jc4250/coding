//https://codeforces.com/contest/1525/problem/A

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

	if (n == 0 || n == 100) {
		cout<<1<<endl;
		return;
	}

	int ans = 0;
	double sat = 0;
	int poi = 0;
	int wat = 0;
	while(abs(sat - n) > 0.00001) {
		if (sat > n) {
			wat++;
			ans++;
		}
		if (sat < n) {
			poi++;
			ans++;
		}
		sat = ((1.0*poi)/(poi+wat))*100;
	}
	cout<<ans<<endl;
}