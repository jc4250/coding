//https://codeforces.com/contest/1521/problem/A

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
	ll a, b;
	cin>>a>>b;

	if (b == 1) {
		cout<<"NO"<<endl;
		return;
	}

	if (b == 2) {
		cout<<"YES"<<endl;
		cout<<a*3<<" "<<a<<" "<<a*b*2<<endl;
		return;
	}

	cout<<"YES"<<endl;
	cout<<a*(b-1)<<" "<<a<<" "<<a*b<<endl;
}