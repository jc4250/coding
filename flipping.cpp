//https://codeforces.com/problemset/problem/327/A

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
	int n;
	cin>>n;

	vector<int> arr(n), arr1(n);

	int temp = 0;
	for (int i = 0; i < n; i++) {
		cin>>arr[i];

		if (arr[i]) {
			arr1[i] = -1;
			temp++;
		} else {
			arr1[i] = 1;
		}
	}

	int ans = 0, lc = 0;
	for (int i = 0; i < n; i++) {
		lc += arr1[i];
		if (lc < 0) {
			lc = 0;
		}

		ans = max(ans, lc);
	}

	if (temp == n) {
		cout<<n-1<<endl;
	} else {
		cout<<ans+temp<<endl;
	}
}