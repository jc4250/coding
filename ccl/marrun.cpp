//https://www.codechef.com/COOK129C/problems/MARARUN

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
	int d, D, A, B, C;
	cin>>d>>D>>A>>B>>C;

	int dis = d*D;

	if (dis >= 42) {
		cout<<C<<endl;
	} else if (dis >= 21) {
		cout<<B<<endl;
	}else if(dis>= 10) {
		cout<<A<<endl;
	} else {
		cout<<0<<endl;
	}
}