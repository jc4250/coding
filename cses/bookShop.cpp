//https://cses.fi/problemset/task/1158

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

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
	int n, x;
	cin>>n>>x;

	vector<int> price(n), book(n);

	for (int i = 0; i < n; i++) {
		cin>>price[i];
	}

	for (int i = 0; i < n; i++) {
		cin>>book[i];
	}

	// map<pair<int, int>, int> mp;
	vector<int> arr(N, 0);

	// arr[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = x; j >= price[i]; j--) {
				arr[j] = max(book[i] + arr[j-price[i]], arr[j]);
		}
	}

	cout<<arr[x]<<endl;
}