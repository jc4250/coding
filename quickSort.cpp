#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;

int partition(vector<int> &arr, int l, int r) {
	int pivot = arr[l];

	int i = l;
	int j = r+1;
	
	while(i < j) {
		
		while (i <= r && pivot >= arr[++i]);
		
		while (j >= l && pivot < arr[--j]);
		
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[j]);
	return j;
}

void quicksort(vector<int> &arr, int l, int r) {
	
	if (l < r) {
		int mid = partition(arr, l, r);
		
		quicksort(arr, l, mid-1);
		quicksort(arr, mid+1, r);
	}
}

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
	int n;
	cin>>n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	quicksort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}	
}