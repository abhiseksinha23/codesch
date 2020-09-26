#include<bits/stdc++.h>
using namespace std;
void sorting(vector<vector<int>>&arr, int s, vector<vector<int>>g){
	vector<pair<int,int>>arp;
	for(int i=0; i<n; i++){
		arp.push_back(make_pair(arr[s][i],i));
	}
	sort(arp.begin(),arp.end());
	
	for(int i=0; i<n; i++){
		int x = arp[i].second;
		
		for(int  j=0; j<3; j++){
			arr[j][i] = g[j][x];
		}
	}
}
void sorting1(vector<vector<int>>&arr, int s, vector<vector<int>>g){
	vector<pair<int,int>>arp;
	for(int i=0; i<n; i++){
		arp.push_back(make_pair(arr[s][i],i));
	}
	sort(arp.begin(),arp.end(),greater<int>);
	
	for(int i=0; i<n; i++){
		int x = arp[i].second;
		
		for(int  j=0; j<3; j++){
			arr[j][i] = g[j][x];
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>>arr(3,vector<int>(n));
		for(int i=0; i<3; i++){
			for(int j=0; j<n; j++)
				cin>>arr[i][j];
		}
		sorting(arr,0,arr);
		sorting(arr,0,arr);
		sorting(arr,0,arr);
		for(int i=0; i<3; i++){
			for(int j=0; j<n; j++)
				cout<<arr[i][j]<<" ";
		}cout<<"\n";
	}
	
	return 0;
}
