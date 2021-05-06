//https://codeforces.com/contest/1520/problem/A

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
	
	string s;
	cin>>s;

	unordered_map<char, int> mp;

	mp[s[0]] = 1;
	bool ans = true;

	for (int i = 1; i < s.length(); i++) {
		if (s[i-1] != s[i]) {
			if (mp.count(s[i]) > 0) {
				ans = false;
				break;
			}
			mp[s[i]] = 1;
		}
	}

	if (ans) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}