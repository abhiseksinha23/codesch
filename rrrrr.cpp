#include<bits/stdc++.h>
using namespace std;
#define  ll long long int

long long  pos(long long sm){
	long double  a = sqrtl(1ul + 4*(sm));
	a = a-1.0;
	a = a/2.0;
	long long  fs = a;
	return fs;  
}
int main(){
	long long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		if(n==0 || n==1 || n==2){
			cout<<"0"<<endl;
			continue;
		}
		long long t1 = (n*(n+1))/2;
		if(t1%2!=0){
			cout<<"0"<<endl;
			continue;
		}
		long long indx = pos(t1);
		long long ss = indx*(indx+1)/2;
		if(t1/2==ss){
			long long ans = (indx*(indx-1ul))/2l + ((n-indx) * (n-indx-1ul))/2l + (n -indx);
			cout<<ans<<endl;
		}else{
			cout<<n-indx<<endl;
		}
	}
	
	
	return 0;
}
