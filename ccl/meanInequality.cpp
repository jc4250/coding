//https://codeforces.com/contest/1526/problem/A

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

	int len = 2*n;
	vector<int> arr(len);
	
	for (int i = 0; i < len; i++) {
		cin>>arr[i];
	}

	sort(arr.begin(), arr.end());

	vector<int> ans(len);

	int j = 0;
	for (int i = 0; i < len; i++) {
		ans[j] = arr[i];
		j+=2;
		if (j >= len) {
			// if (len & 1) {
				j = 1;
			// }
		}
	}

	for (int i = 0; i < len; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}