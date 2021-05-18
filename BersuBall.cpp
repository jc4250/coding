//https://codeforces.com/problemset/problem/489/B

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
	// cin >> t;?
	while (t--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}


void solve() {
	int b, g;
	cin>>b;

	vector<int> boy(b);

	for(int i = 0; i < b; i++) {
		cin>>boy[i];
	}

	cin>>g;
	vector<int> girl(g);
	
	for(int i = 0; i < g; i++) {
		cin>>girl[i];
	}

	sort(boy.begin(), boy.end());
	sort(girl.begin(), girl.end());

	int i = 0, j = 0;
	int ans = 0;

	while(i < boy.size() && j < girl.size()) {
		if (abs(boy[i]-girl[j]) <= 1) {
			i++;
			j++;
			ans++;
			continue;
		}

		if (boy[i] > girl[j]) {
			j++;
		} else {
			i++;
		}
	}

	cout<<ans<<endl;
}