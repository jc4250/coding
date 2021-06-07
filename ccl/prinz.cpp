//https://codeforces.com/contest/1536/problem/B

#include<bits/stdc++.h>
using namespace std;

#define cerr if(false)	cerr
#define ll long long
const int MOD = 1e9 + 7;

set<string> key;
void solve();

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	#endif


	for (char i = 'a'; i <= 'z'; i++) {
		string ans = "";
		ans += i;
		key.insert(ans);
		// cout<<i<<endl;
		for (char j = 'a'; j <= 'z'; j++) {
			string mid = "";
			mid += ans;
			mid += j;
			key.insert(mid);
			for (char k = 'a'; k <= 'z'; k++) {
				string submid = "";
				submid += mid;
				submid += k;
				key.insert(submid);
			}
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
	int n;
	cin>>n;

	string s;
	cin>>s;

	map<string, int> mp;
	// map<int, int> count;

	for (int i = 1; i < 4; i++) {
		int count = 0;
		// for (int j = 0; j < s.length()-i; j++) {
			for (int k = 0; k < s.length(); k+=1) {
				string temp = s.substr(k, i);
				// cout<<k<<" "<<k+i<<endl;
				// cout<<temp<<endl;
				mp[temp] = 1;
				count++;
			}

			int nas = 1 ;
			for (int k = 1; k <= i; k++) {
				nas *= 26;
			}

			int falg = 0;
			if (nas != count) {
				for (auto str = key.begin(); str != key.end(); str++) {
					// cout<<*str<<endl;
					if ((*str).length() == i) {
						if (mp[*str] <= 0) {
							cout<<*str<<endl;
							falg = 1;
							break;
						} 
					}
				}
			}

			if (falg) break;
		// }
	}
}