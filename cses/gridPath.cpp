//https://cses.fi/problemset/task/1638

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

int recur(int i, int j, vector<vector<int>> &grid, vector<vector<char>> &arr) {
	
	int n = arr.size();

	if (i >= n || j >= n) return 0;

	if (i == n-1 && j == n-1) return 1;

	if (arr[i][j] == '*') return 0;

	if (grid[i][j] != -1) return grid[i][j];

	grid[i][j] = (recur(i+1, j, grid, arr) + recur(i, j+1, grid, arr)) % MOD;

	return grid[i][j];
}


void solve() {
	int n;
	cin>>n;

	vector<vector<char>> arr(n);

	for (int i = 0; i < n; i++) {
		vector<char> v;
		char temp;
		for (int j = 0; j < n; j++) {
			cin>>temp;
			v.push_back(temp);
		}
		arr[i] = v;
	}

	vector<vector<int>> grid(n, vector<int> (n, -1));

	if (arr[0][0] == '*' || arr[n-1][n-1] == '*') {
		cout<<0<<endl;
		return;
	}

	grid[n-1][n-1] = 1;
	
	cout<<recur(0, 0, grid, arr)<<endl;
}