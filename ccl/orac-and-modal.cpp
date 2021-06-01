//https://codeforces.com/problemset/problem/1350/B

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;

vector<int> dp(100005, INT_MIN);

int size;
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

int compute(vector<int> &arr, int i) {

	if (i > size) return 0;

	int ans = 0;
	int temp = 0;

	if (dp[i] != INT_MIN) return dp[i];

	for (int j = 2; j <= size/i; j++) {
		if (arr[j*i] > arr[i]) {
			temp = 1 + compute(arr, i*j);
			ans = max(ans, temp);
		}
	}
	dp[i] = ans;

	return ans;
}


void solve() {
	int n;
	cin>>n;

	size = n;
	dp = vector<int> (100005, INT_MIN);
	vector<int> arr(n+1);

	for (int i = 1; i <=n; i++) {
		cin>>arr[i];
	}

	for (int i = 1; i < n; i++) {
		compute(arr, i);	
	}
	// cout<<compute(arr, 1)+1<<endl;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		// cout<<i<<" "<<dp[i]<<endl;
		ans = max(ans, dp[i]);
	}
	cout<<ans+1<<endl;
}