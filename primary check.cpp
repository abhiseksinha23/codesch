#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long power(long x, long y)  
{  
    long long res = 1;     // Initialize result  
  
    x = x % mod; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % mod;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % mod;  
    }  
    return res%mod;  
}  
long long calculate(int n, int r) 
{ 
  
    long long p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            long long m = __gcd(p, k);
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    } 
  
    else
        p = 1; 
    return p%mod;
} 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n;
		vector<int>arr(n);
		for(int i=0; i<n; i++){
		cin>>arr[i];	
		}
		sort(arr.begin(),arr.end());
		bool repeat = false;
		vector<int>ans(n,0);
		for(int i=0; i<n-1; i++){
			if(arr[i]==arr[i+1]){
				repeat= true;
				break;
			}
		}
		if(!repeat){
			int x = n-1;
			for(int i=0; i<n; i++){
				long long y = (power(2,x));
				cout<<y%mod<<" ";
				x--;
			}cout<<"\n";
			continue;
		}
		vector<int>count(n+1,0);
		//map<int,int>m;
		for(int i=0; i<n; i++){
			count[arr[i]]++;
		}
		for(int i=1; i<=n; i++){
			if(count[i]!=0){
				long long total = (power(2,count[i])-1)%mod;		
				for(int j=i+1;j<=n; j++){
					if(count[j]!=0){
						for(int l=1; l<=count[i];l++){
							long long x = calculate(count[i],l)%mod;
							for(int k=1; k<=min(count[i],count[j]); k++)
							total = (total+ (x*(calculate((count[j]),k)%mod))%mod)%mod;
						}
					}
				}
				for(int j=i-1; j>=0; j--){
					if(count[j]!=0 && count[i]>count[j]){
						for(int l=count[j]+1; l<=count[i];l++){
							total =  (total+ (calculate(count[i],l)%mod))%mod;
						}
					}	
				}
				cout<<total%mod<<" ";
			}else{
				cout<<"0 ";
				
			}
		}
		cout<<"\n";
	}
	return 0;
}
