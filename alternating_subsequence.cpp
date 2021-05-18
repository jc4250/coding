//https://codeforces.com/problemset/problem/1343/C

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

	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	int temp = 0;
	ll ans = 0;

	for (int i = 0; i < n; i) {
		
		temp = arr[i];
		
		if (temp > 0) {

			while(i<n && arr[i] > 0) {
				temp = max(temp, arr[i]);
				i++;
			}
		} else {

			while(i<n && arr[i] < 0) {
				temp = max(temp, arr[i]);
				i++;
			}
		}

		// cout<<temp<<" "<<i<<endl;
		ans += temp;
	}

	cout<<ans<<endl;
}