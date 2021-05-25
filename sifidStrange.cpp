//https://codeforces.com/contest/1529/problem/B

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

	vector<int> arr(n);
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	sort(arr.begin(), arr.end());
	int diff = INT_MAX;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= 0) {
			ans++;
		}

		if (i > 0 && arr[i] <= 0) {
			int temp = abs(arr[i]-arr[i-1]);
			diff = min(diff, temp);
		}

		if (i > 0 && arr[i] > 0 && arr[i] <= diff) {
			ans++;
		}
		if (arr[i] > 0) break;
	}

	if (ans == 0) {
		ans = 1;
	}
	cout<<ans<<endl;
}