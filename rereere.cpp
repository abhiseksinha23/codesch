#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>v(n);
		vector<int>a(n);
		for(int i=0; i<n; i++)cin>>v[i];
		
		for(int i=0; i<n; i++){
			int l,r,x=0,y=0;
			for(l=i; l>=0; l--){
				if(v[l]>v[i]){
					x++;
				}
			}
			for(r=i; r<n; r++){
				if(v[r]<v[i]){
					y++;
				}
			}
			a[i] = x+y;
		}
		int mini=a[0],maxi=a[0];
		for(int i=1; i<n; i++){
			mini = min(mini,a[i]);
			maxi = max(maxi,a[i]);
		}
		mini++;
		maxi++;
		cout<<mini<<" "<<maxi<<"\n";
	}
	
	
	return 0;
}
