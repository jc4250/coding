//https://codeforces.com/contest/1526/problem/B

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;
vector<int> arr(1100);

void solve();

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	#endif

	arr[0] = 1;

	for (int i = 11; i < 1100; i++) {
		arr[i] = arr[i-11];
		if (i >= 111) {
			arr[i] |= arr[i-111];
		}
	}

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}


void solve() {
	int t;
	cin>>t;
	
	if (t <= 1099) {
		if (arr[t]) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	} else {
		cout<<"YES"<<endl;
	}
}