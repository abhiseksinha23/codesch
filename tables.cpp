#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		unordered_map<int,int>m;
		unordered_set<int>s;
		vector<int>arr(n);
		int maxm = INT_MIN;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			m[arr[i]]++;
			s.insert(arr[i]);
			maxm = max(maxm,m[arr[i]]);
		}
		long ans = 1000000007;
		for(int i=1; i<=maxm; i++){
			long cost = (k*i);
			for(auto it = s.begin(); it!=s.end(); it++){
				cost += (m[*it]-i);
			}
			ans = min(cost,ans);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
