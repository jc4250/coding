#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;
vector<ll> arr;

void solve();

void buildSegmentTree(int n, int ss, int se, int nums);

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

void buildSegmentTree(int i, int ss, int se, vector<int> &nums) {

	if (ss == se) {
		arr[i] = nums[ss];
	} else {
		int mid = ss + (se - ss) / 2;

		buildSegmentTree(i*2, ss, mid, nums);
		buildSegmentTree(i*2+1, mid+1, se, nums);

		arr[i] = min(arr[i*2], arr[i*2 + 1]);
	}
}

ll querySegmentTree(int i, int ss, int se, int qs, int qe) {


	if (qs > se || qe < ss) return INT_MAX;

	if (qs <= ss && qe >= se) return arr[i];

	int mid = ss + (se - ss) / 2;

	return min(querySegmentTree(i*2, ss, mid, qs, qe), querySegmentTree(i*2+1, mid+1, se, qs, qe));

}

void solve() {
	int n;
	cin >> n;

	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin>>nums[i];
	}

	arr = vector<ll> (4*n);

	buildSegmentTree(1, 0, n-1, nums);

	int q;
	cin>>q;

	while(q--) {
		int qs, qe;
		cin>>qs>>qe;

		cout<<querySegmentTree(1, 0, n-1, qs, qe)<<endl;
	}
}