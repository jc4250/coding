//https://codeforces.com/contest/1529/problem/A

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

	int mmin = INT_MAX;

	vector<int> arr(n);

	for(int i = 0; i <n; i++ ) {
		cin>>arr[i];

		if (arr[i] < mmin) {
			mmin = arr[i];
		}
	}

	int count = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] != mmin) count++;
	}

	cout<<count<<endl;
}