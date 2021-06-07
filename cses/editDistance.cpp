//https://cses.fi/problemset/task/1639

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
	string sor, des;
	cin>>sor>>des;

	int slen = sor.length();
	int dlen = des.length();

	vector<vector<int>> arr(slen + 1, vector<int> (dlen + 1, 0));

	for (int i = 0; i <= slen; i++) {
		arr[i][0] = i;
	}

	for (int i = 0; i <= dlen; i++) {
		arr[0][i] = i;
	}

	for (int i = 0; i < slen; i++) {
		for (int j = 0; j < dlen; j++) {
			arr[i+1][j+1] = 1 + min({arr[i+1][j], arr[i][j+1], arr[i][j]});

			if (sor[i] == des[j]) {
				arr[i+1][j+1] = min(arr[i+1][j+1], arr[i][j]);
			}
			// cout<<arr[i+1][j+1]<<" ";
		}
		// cout<<endl;
	}

	cout<<arr[slen][dlen]<<endl;	
}