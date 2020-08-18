#include<bits/stdc++.h>
using namespace std;
void findprime(int n, vector<int>&prime){
	vector<bool>arr(n+1,true);
	for(int i=2; i*i<=n; i++){
		if(arr[i]){
			for(int j=i+i; j<=n; j+=i){
				arr[j] = false;
			}
		}
	}
	for(int i=2; i<=n; i++){
		if(arr[i]){
			prime.push_back(i);
		}
	}
}
int main(){
	vector<int>prime;
	findprime(1000, prime);
	long m,n;
	cin>>m>>n;
	if(m==n){
		cout<<"0\n";
		return 0;
	}
	long maxi = max(m,n);
	long mini = min(m,n);
	int count=0,i=0;
	bool f = false;
	while(maxi>1){
		if(maxi==mini){
			f = true;
			break;
		}
		cout<<maxi<<" ";
		if(maxi%prime[i]==0){
			maxi = maxi/prime[i];
			i=0;
			count++;
		}else{
			i++;
		}
	}
	if(f){
		cout<<n<<"\n";
		return 0;
	}
	i=0;	
	while(mini>1){
		if(maxi==mini){
			f = true;
			break;
		}
		if(mini%prime[i]==0){
			mini = mini/prime[i];
			i=0;
			count++;
		}else{
			i++;
		}
	}
	cout<<count<<"\n";
	return 0;
}

