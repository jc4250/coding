//https://codeforces.com/contest/1525/problem/B

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

	vector<int> arr(n+1);

	for (int i = 1; i <= n; i++) {
		cin>>arr[i];
	}

	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] != i) {
			flag = 1;
		}
	}

	if (flag == 0) {
		cout<<0<<endl;
		return;
	}

	if (arr[1] == n && arr[n] == 1) {
		cout<<3<<endl;
		return;
	}

	if (arr[1] == 1 || arr[n] == n) {
		cout<<1<<endl;
		return;
	}
	cout<<2<<endl;
}