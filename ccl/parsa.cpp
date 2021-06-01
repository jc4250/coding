//https://codeforces.com/contest/1529/problem/C

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

ll dfs(ll i, ll j, ll par, vector<vector<int>> &arr, vector<vector<int>> &edges, map<pair<ll, ll>, ll> &dp) {

	ll temp = 0;
	ll temp1 = 0;

	if (dp.count({i, j}) > 0) return dp[{i, j}]; 

	ll ans = 0;
	for (ll k = 0; k < edges[i].size(); k++) {
		if (edges[i][k] != i && edges[i][k] != par) {
			temp = abs(j - arr[edges[i][k]][0]) + dfs(edges[i][k], arr[edges[i][k]][0], i,arr, edges, dp);
			temp1 = abs(j - arr[edges[i][k]][1]) + dfs(edges[i][k], arr[edges[i][k]][1], i,arr, edges, dp);
			ans += max(temp, temp1);
		}
	}

	dp[{i, j}] = ans;
	return dp[{i, j}];
}
void solve() {
	int n;
	cin>>n;
	vector<vector<int>> arr(n+1);
	vector<vector<int>> edges(n+1);

	for (int i = 1; i <= n; i++) {
		vector<int> pair;
		int temp;
		cin>>temp;
		pair.push_back(temp);

		cin>>temp;
		pair.push_back(temp);

		arr[i] = pair;
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		cin>>u>>v;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	vector<int> vis(n+1);

	map<pair<ll, ll>, ll> dp;
	// cout<<"d"<<endl;
	cout<<max(dfs(1, arr[1][0], 1,arr, edges, dp), dfs(1, arr[1][1], 1,arr, edges, dp))<<endl;
}