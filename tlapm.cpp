//https://www.codechef.com/COOK129C/problems/TLAPM

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;
vector<vector<int>> arr(2500, vector<int> (2500));


void solve();

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	#endif


	int temp = 0;
	for (int i = 1; i < 2500; i++) {
		int k = 1;
		for (int j = i; j > 0 && k < 2500; j--) {
			arr[j][k++] = ++temp;
		}
	}

	for (int i = 2; i < 2500; i++) {
		int k = i;
		for (int j = 2499; j > 0 && k < 2500; j--) {
			arr[j][k++] = ++temp;
		}
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
	int x, y, x1, y1;

	cin>>x>>y>>x1>>y1;

	int sum = 0;

	for (int i = x; i <= x1; i++) {
		sum+=arr[y][i];
	}

	for (int i = y+1; i <= y1; i++) {
		sum+=arr[i][x1];
	}

	cout<<sum<<endl;
}