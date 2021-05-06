// https://codeforces.com/contest/1520/problem/C

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

	if (n == 1) {
		cout<<1<<endl;
		return;
	}

	if (n == 2) {
		cout<<-1<<endl;
		return;
	}

	vector<vector<int>> arr(n, vector<int> (n));
	arr[0][0] = 1;
	arr[n-1][n-1] = n*n;
	int temp = n*n;
	temp--;
	
	for (int i = 1; i < n; i++) {
		
		int it = i;
		for (int j = 0; j <= it; j++) {
			arr[j][i] = temp;
			temp--;
			i--;
		}
		i = it;
	}


	int ite = n-1;
	int time = n-1;
	int ij = 1;
	while (time > 0) {
		ite = n-1;
		for (int j = ij; j < n; j++) {
			arr[j][ite] = temp;
			temp--;
			ite--;
		}
		ij++;
		time--;
	}

	arr[n-1][n-1] = n*n;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}