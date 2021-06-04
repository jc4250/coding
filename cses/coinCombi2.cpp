//https://cses.fi/problemset/task/1636

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
	int n, sum;
	cin>>n>>sum;

	vector<int> arr(sum+1), coin(n);

	for (int i = 0; i < n; i++) {
		cin>>coin[i];
	} 

	arr[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j>=coin[i]) {
				arr[j] = (arr[j] + arr[j-coin[i]])%MOD;
			}
		}
	}

	cout<<arr[sum]<<endl;
}