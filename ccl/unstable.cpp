//https://codeforces.com/contest/1535/problem/C

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
	string s;
	cin>>s;

	int n = s.length();

	vector<vector<ll>> dp(n+1, vector<ll>(2));

	dp[0][0] = 0;
	dp[0][1] = 0;
	ll ans = 0;

	for (int i = 0; i < n; i++) {
		
		if (s[i] == '?') {
			
			dp[i+1][0] = 1LL + dp[i][1];
			dp[i+1][1] = 1LL + dp[i][0];
		
		} else if (s[i] == '0') {

			dp[i+1][0] = 1LL+dp[i][1];
			// dp[i+1][1] = dp[i][1];
		} else {

			dp[i+1][1] = 1LL + dp[i][0];
		}

		ans += max(dp[i+1][1], dp[i+1][0]);
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout<<i-1<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
	// }

	cout<<ans<<endl;
}