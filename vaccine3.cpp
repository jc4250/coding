//https://www.codechef.com/COOK129C/problems/VACCINE3

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
	int g, p;
	cin>>g>>p;

	vector<int> age(11);

	for (int i = 1; i < 11; i++) {
		cin>>age[i];
	}

	int ans = 0;

	for (int i = 10; i > g; i--) {
		ans += age[i];
	}

	// cout<<ans<<" "<<ans+age[g]<<endl;
	int mind;
	if (ans % p != 0) {
		mind = ceil((ans*1.0)/p);
	}

	if (ans % p == 0) {
		mind = ceil((ans*1.0)/p) + 1;
	} 

	int maxd = ceil(((ans+age[g])*1.0)/p);

	cout<<mind<<" "<<maxd<<endl;
}