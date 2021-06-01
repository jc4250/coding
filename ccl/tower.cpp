//https://codeforces.com/contest/1515/problem/C
#include<bits/stdc++.h>
using namespace std;

// #define cerr if(false)cerr
#define ll long long

typedef pair<ll, ll> pi;
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
	ll n, m, x;
  cin>>n>>m>>x;

  unordered_map<ll, ll> mp;
  vector<pair<ll, ll>> arr;

  ll temp;

  for (int i = 0; i < n; i++) {
    cin>>temp;
    arr.push_back(make_pair(temp, i));
  }

  if (n<m) {
    cout<<"NO"<<endl;
    return;
  }

  sort(arr.begin(), arr.end());

  reverse(arr.begin(), arr.end());

   priority_queue<pi, vector<pi>, greater<pi> > pq;

   for (ll i = 0; i < m; i++) {
    pq.push({0, i+1});
   }

   for (ll i = 0; i < arr.size(); i++) {
   		// cout<<i<<endl;
      auto par = pq.top();
      pq.pop();
      mp[arr[i].second] = par.second;
      pq.push({par.first+arr[i].first, par.second});
   }

   ll mini = pq.top().first;

   ll impos = 0;
   while(!pq.empty()) {
    ll temp = pq.top().first;
    pq.pop();
    if (abs(temp - mini) > x) {
      impos = 1;
    }
   }

   if (impos) {
    cout<<"NO"<<endl;

   } else {
    cout<<"YES"<<endl;
    for (ll i = 0; i < n; i++) {
      cout<<mp[i]<<" ";
    }
    cout<<endl;
   }
}	