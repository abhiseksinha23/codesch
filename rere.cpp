#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<long>arr(n);
		for(int i=0; i<n; i++)cin>>arr[i];
		sort(arr.begin(),arr.end(),greater<int>);
		int i=0;
		int ans=0;
		while(i<n){
			if(i!=n-1){
				if(arr[i]>arr[i-1]){
					ans++;
				}
				i++;
			}else{
				if(arr[i]>0)ans++;
				i++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
