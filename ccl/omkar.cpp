//https://codeforces.com/contest/1536/problem/A

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

	vector<ll> arr(n);

	map<ll, int> mp;
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
		mp[arr[i]] = 1;
	}

	for (int i = 0; i < arr.size() && i<302; i++) {
		for (int j = 0; j < arr.size(); j++) {

			if (i == j) continue;
			if (arr.size() > 303) {
				break;
			}

			if (mp.count(1LL*abs(arr[j] - arr[i])) <= 0) {
				arr.push_back(1LL*abs(arr[j]-arr[i]));
				mp[1LL*abs(arr[i] - arr[j])] = 1;
			}
		}
	}

	if (arr.size() >= 301) {
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;

		cout<<arr.size()<<endl;

		for (int i = 0; i < arr.size(); i++) {
			cout<<arr[i]<<" ";
		}

		cout<<endl;
	}
}