#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int r,g,b,w,o;
		cin>>r>>g>>b>>w>>o;
		
		double rt,gt,bt,wt,ot;
		rt = 100.0/r;	
		gt = 100.0/g;
		bt = 100.0/b;
		wt = 100.0/w;
		ot = 100.0/o;
		
		double m = min(rt,min(gt,min(bt,min(wt,ot))));
		if(m==rt){
			cout<<"Champions\n";
		} else{
			cout<<"-1\n";
		}	
	}

}
