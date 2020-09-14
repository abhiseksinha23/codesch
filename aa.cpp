#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>arr(n);
		for(int i=0; i<n; i++)cin>>arr[i];
		
		unordered_map<int, unordered_set<pair<int,int>>>m;
		for(int i=0; i<=100; i++){	
			for(int j=0; j<n; j++){
				m[i].insert({j + (arr[j]*i), j}); 
			}
		}
		int mini = n, maxi = 0;
		for(int i=0; i<n; i++){
			unordered_set<int>s;
			s.insert(i);
			for(int t=0; t<=100; t++){
				unordered_set<pair<int,int>>p = m[t];
				unordered_set<int>holder;
				for(auto x : s){
					int pos = (x + arr[x]*t);
					for(auto pp : p){
						if(pp.first == pos){
							holder.insert(pp.second);
						}
					}
				}
				for(auto h: holder){
					s.insert(h);
				}		
			}
			int x = s.size();
			mini = min(mini,x);
			maxi = max(maxi,x);
		}
		cout<<mini<<" "<<maxi<<"\n";	
	}
	return 0;
}
