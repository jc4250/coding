// https://codeforces.com/contest/1521/problem/B

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
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

	vector<ll> arr(n);

	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	vector<ll> pr = {1000000007, 1000000009, 1000000021};

	vector<vector<ll>> ans;

	int j = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i-1] >= arr[i]) {
			arr[i-1] = pr[j];
			j++;
			j %=3;
			ans.push_back({i-1, i, arr[i-1], arr[i]});
		} else {
			arr[i] = pr[j];
			j++;
			j %= 3;
			ans.push_back({i-1, i, arr[i-1], arr[i]});
		}
	}

	cout<<n-1<<endl;

	for (int i = 0; i < n-1; i++) {
		cout<<ans[i][0]+1<<" "<<ans[i][1]+1<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
	}
}