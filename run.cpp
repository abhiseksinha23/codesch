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
		unordered_map<int, vector<int>>m;
		for(int i=0; i<n; i++){
			//m[i].push_back(i+1);
			m[i+1].push_back(i);
			if(arr[i]>0){
				for(int j=1; j<=100; j++){
					m[i+1 + (arr[i]*j)].push_back(i);
				}
			}
		}
		
		int mini = n,maxi = 0;
		for(int i=0; i<n; i++){
			int curr = 0;
			if(arr[i]>0){
				unordered_set<int>s;
				for(int j=0; j<=100; j++){
					vector<int>a = m[i+1 + (arr[i]*j)];
					for(int k=0; k<a.size(); k++)s.insert(a[i]);
				}
				curr = s.size();
			}else{
				curr = m[i+1].size();
			}
			mini = min(mini,curr);
			maxi = max(maxi,curr);
		}
		cout<<mini<<" "<<maxi<<"\n";
	}
	return 0;
}
