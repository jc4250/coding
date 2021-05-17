//https://codeforces.com/contest/1525/problem/D

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;

vector<int> peo, cha;
vector<vector<int>> dp(5009, vector<int> (5008, INT_MAX));
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

int compute(int i, int j) {
	if (i >= peo.size()) return 0;
	if (j >= cha.size()) return INT_MAX/2;
	if (dp[i][j] != INT_MAX) return dp[i][j];

	int temp1 = abs(peo[i] - cha[j]) + compute(i+1, j+1);
	int temp2 = compute(i, j+1);
	return dp[i][j] = min(temp1, temp2);
}


void solve() {
	int n;
	cin>>n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin>>arr[i];

		if (arr[i] == 1) {
			peo.push_back(i);
		} else {
			cha.push_back(i);
		}
	}

	cout<<compute(0, 0)<<endl;
}