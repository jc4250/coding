//https://codeforces.com/contest/1535/problem/A

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
	vector<int> s(4);

	for (int i = 0; i < 4; i++) {
		cin>>s[i];
	}

	if ((s[0] > s[2] && s[0] > s[3]) && (s[1] > s[2] && s[1] > s[3])) {
		cout<<"NO"<<endl;
		return;
	}

	if ((s[0] < s[2] && s[0] < s[3]) && (s[1] < s[2] && s[1] < s[3])) {
		cout<<"NO"<<endl;
		return;
	}

	cout<<"YES"<<endl;
}