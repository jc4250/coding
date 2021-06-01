//https://cses.fi/problemset/task/1633/

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

	vector<int> arr(n+1);

	arr[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int t = 1; t<=6 && i-t>=0; t++) {
			arr[i] = (arr[i] + arr[i-t])%MOD;
		}
	}

	cout<<arr[n]<<endl;
}