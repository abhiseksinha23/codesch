#include<bits/stdc++.h>
using namespace std;

int main(){
	int k,t;
	cin>>k;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		if(n==1){
			cout<<"1"<<endl;
			cout<<"1"<<endl;
			continue;
		}
		vector<int>ans(n+1,0);
		vector<long long>arr(n+1,0);
		for(long i=1; i<=n; i++){
			arr[i] = pow(i,k);
		}
		
		long long a=arr[n],b=arr[n-1];
		ans[n]=1;
		ans[n-1]=0;
		for(long i=n-2; i>=1; i--){
			if(a<=b){
				a += arr[i];
				ans[i] = 1;
			}else{
				b += arr[i];
			}
		}
		cout<<abs(a-b)<<endl;
		for(int i=1; i<=n; i++)cout<<ans[i];
		cout<<"\n";
		if(n%2==0){
			long long a=0,b=0;
			bool ac = true;
			for(int i=n; i>=1; i-=2){
				if(ac){
					a += i;
					arr[i] =1;
					b += i-1;
				}else{
					b+=i
					a +=i-1;
					arr[i-1] =1;
				}
				ac = !ac;
			}
			cout<<abs(a-b)<<endl;
			for(int i=1; i<=n;i++){
				cout<<arr[i];
			}	cout<<endl;
		}else{
			long long a=0,b=0;
			bool ac = true;
			for(int i=n; i>1; i-=2){
				if(ac){
					a += i;
					arr[i] =1;
					b += i-1;
				}else{
					b+=i
					a +=i-1;
					arr[i-1] =1;
				}
				ac = !ac;
			}
			if(a<=b){
				a+=1;
				arr[1] = 1;
			}else{
				b+=1;
			}
			cout<<abs(a-b)<<endl;
			for(int i=1; i<=n;i++){
				cout<<arr[i];
			}	cout<<endl;
		}
	}
	return 0;
}
