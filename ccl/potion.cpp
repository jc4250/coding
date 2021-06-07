// https://codeforces.com/contest/1526/problem/C1
// https://codeforces.com/contest/1526/problem/C2


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
	int n;
	cin>>n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	// map<pair<ll, ll>, int> mp;
	// cout<<recur(0, arr, 0, mp)<<endl;
	ll maxi = 0;
	priority_queue<int> mp;
	ll ans = 0;
	ll sum = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			mp.push(abs(arr[i]));
		}

		sum+=arr[i];
		ans+=1;
		while (sum < 0 && mp.size() > 0) {
			sum += abs(mp.top());
			ans-=1;
			mp.pop();
		}

		maxi = max(maxi, ans);
	}

	cout<<maxi<<endl;
}