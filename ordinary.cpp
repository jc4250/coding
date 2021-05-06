//https://codeforces.com/contest/1520/problem/B

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long

vector<int> vc;
void solve();

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	#endif

	queue<int> arr;
	
	for (int i = 1; i < 10; i++) {
		vc.push_back(i);
		arr.push(i);
	}
	
	for (int i = 1; i <= 73; i++) {
		int temp = arr.front();
		arr.pop();
		int nt = temp*10 + temp%10;
		arr.push(nt);
		vc.push_back(nt);
	}
	
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}


void solve() {
	ll n;
	cin>>n;

	for (int i = 0; i < vc.size(); i++) {
		if (vc[i] > n) {
			cout<<i<<endl;
			break;
		}
	}
}