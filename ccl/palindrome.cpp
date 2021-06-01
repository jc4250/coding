// https://codeforces.com/contest/1527/problem/B1

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

	string arr;
	cin>>arr;

	int zer = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == '0') {
			zer++;
		}
	}

	if (zer == 1) {
		cout<<"BOB"<<endl;
		return;
	}

	if (zer & 1) {
			cout<<"ALICE"<<endl;
	} else {
		int ans = zer/2;

		cout<<"BOB"<<endl;
	}
}