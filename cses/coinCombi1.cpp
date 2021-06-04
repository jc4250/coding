//https://cses.fi/problemset/task/1635/

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
	int n, sum;
	cin>>n>>sum;

	vector<ll> arr(sum+1), coin(n);

	for (int i = 0; i < n; i++) {
		cin>>coin[i];
	}

	sort(coin.begin(), coin.end());

	arr[0] = 1;

	for (int i = 1; i <= sum; i++) {
		for (int t = 0; t<n && i-coin[t]>=0; t++) {
			arr[i] = (arr[i] + arr[i-coin[t]]) % MOD;
		}
	}

	cout<<arr[sum]<<endl;
}