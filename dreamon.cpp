//https://codeforces.com/problemset/problem/476/B

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;
int num, pro, lc;

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

void recur(int i, int ans) {
	if (i == 0) {
		pro++;
		if (ans == num) {
			lc++;
		}
		return;
	}

	recur(i-1, ans+1);
	recur(i-1, ans-1);
}

void solve() {
	string s, t;

	cin>>s;
	cin>>t;

	num = 0;
	pro = 0;
	lc = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+') {
			num++;
		} else {
			num--;
		}
	}

	int tot = 0, siz=0;
	for (int i = 0; i < t.length(); i++) {
		if (t[i] == '+') {
			tot++;
		}

		if (t[i] == '-') {
			tot--;
		}

		if (t[i] == '?') {
			siz++;
		}
	}

	recur(siz, tot);
	// cout<<lc<<" "<<pro<<endl;
	cout<<setprecision(10)<<(lc*1.0)/pro<<endl;
}