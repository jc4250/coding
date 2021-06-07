//https://codeforces.com/contest/1535/problem/B

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

	vector<int> arr(n), vc;

	int two = 0;
	for (int i = 0; i < n; i++) {
		cin>>arr[i];

		if (arr[i] % 2 == 0) two++;

		if (arr[i] % 2 != 0) {
			vc.push_back(arr[i]);
		}

	}

	int ans = 0;
	for (int i = 1; i <= two; i++) {
		ans += (n-i);
	}
	// cout<<ans<<endl;
	// int ans = 0;
	for (int i = 0; i < vc.size(); i++) {
		for (int j = i+1; j < vc.size(); j++) {
			if (__gcd(vc[i], vc[j]) > 1) {
				ans++;
			}
		}
	}

	cout<<ans<<endl;
}