//https://cses.fi/problemset/task/1634/

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;
const int NMAX = 1e7 + 7;

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

	vector<int> coin(n), reqCoin(sum+1,NMAX);

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin.begin(), coin.end());

	for (int i = 0; i <= sum; i++) {
		if (i%coin[0] == 0) {
			reqCoin[i] = i / coin[0];
		}
	}

	reqCoin[0] = 0;

	for (int j = 1; j < coin.size(); j++) {

		for (int i = coin[j]; i <= sum; i++) {
			if (reqCoin[i-coin[j]] < NMAX) {
				reqCoin[i] = min(reqCoin[i], reqCoin[i-coin[j]]+1);
			}
		}
	}

	if (reqCoin[sum] >= NMAX) {
		cout<<-1<<endl;
		return;
	}

	cout<<reqCoin[sum]<<endl;
}