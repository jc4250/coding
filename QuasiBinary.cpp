//https://codeforces.com/problemset/problem/538/B

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
	string s;
	cin>>s;

	vector<string> arr;

	while (1) {

		string num;
		int flag = 0;
		for (int i = 0; i < s.length(); i++) {

			if (s[i] - '0' > 0) {

				num += '1';
				int temp = s[i] - '0';
				temp--;
				s[i] = temp+'0';
				flag = 1;
			
			} else {
				
				if (num.length() > 0) {
					num += '0';
				}

			}

		}

		if (flag == 0) break;

		arr.push_back(num);
	}

	cout<<arr.size()<<endl;

	for (int i = 0; i < arr.size(); ++i) {
		cout<<arr[i]<<" ";
	}
}