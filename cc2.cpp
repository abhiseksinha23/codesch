#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long powerll(long long x, long long n){
	long long res = 1;
	while(n){
		if(n&1){
			res = res*x %mod;
		}
		n = n/2;
		x = x*x %mod;
	}
	return res;
}
long long div1(long long a, long long b){
	return(a%mod * (powerll(b,mod-2)%mod))%mod;
}
long long sol1(long long n, long long r){
	long long ans = 1;
	long long k = min(r,n-r);
	for(long long i=0; i<k; i++){
		ans = (ans%mod *(n-i)%mod)%mod;
		ans = div1(ans, i+1);
	}
	return ans%mod;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		vector<long long>arr(n);
		long long ans;
		for(int i=0; i<n; i++)cin>>arr[i];
		long long max=0,max_value = 0;
		for(int i=0; i<n; i++){
			if(max<arr[i])max = arr[i];
		}
		for(int i=0; i<n; i++){
			if(max==arr[i])max_value++;
		}
		if(n==1){
			cout<<"2\n";
			continue;
		}
		if(max_value%2!=0){
			ans = powerll(2,n) %mod;
		}else{
			ans = powerll(2,n)%mod - ((powerll(2,n-max_value)%mod)* sol1(max_value,max_value/2)%mod)%mod;
		}
		if(ans<0){
			ans = (ans+mod)%mod;
		}
		cout<<ans%mod<<endl;
	}
	
	return 0;
}
