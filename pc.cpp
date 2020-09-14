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
		
		vector<int>ans(n,0);
		for(int i=0; i<n; i++){
			queue<pair<int,double>>q;
			q.push({i,0.0});
			vector<bool>vis(n,false);
			vis[i] = true;
			while(!q.empty()){
				pair<int,double>p = q.front();q.pop();
				for(int j=0; j<n; j++){
					if(!vis[j]){
						int d = arr[j] - arr[i];
						if(d!=0){
							double t = (i-j)/(d);
							if(t>0 && t>=p.second){
								vis[j] = true;
								q.push({j,t});
							} 
						}
					}
				}
			}
			int c=0;
			for(int j=0; j<n; j++){
				if(vis[j])c++;
			}
			ans[i] = c;
		}
		for(int i=0; i<n; i++)cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
