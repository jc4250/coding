//https://codeforces.com/problemset/problem/1285/B

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
	ll total = 0;

	for (ll i = 0; i < n; i++) {
		cin>>arr[i];
		total += arr[i];
	}

	ll temp1 = 0;
	ll tasty = 0;

	for (ll i = 1; i < n; i++) {
		temp1 += arr[i];

		if (temp1<0) {
			temp1 = 0;
		}
		tasty = max(tasty, temp1);
	}

	temp1 = 0;
	for (ll i = 0; i < n-1; i++) {
		temp1 += arr[i];

		if (temp1<0) {
			temp1 = 0;
		}
		tasty = max(tasty, temp1);
	}

	if (total > tasty) {
		cout<<"Yes"<<endl;
		return;
	}
	cout<<"No"<<endl;
}