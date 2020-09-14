#include<bits/stdc++.h>
using namespace std;

int main(){
	long t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long total = n*(n+1)/2;
		long long ans=0;
		long long curr=0,left;
		for(long long i=1; i<=n; i++){
			curr+= i;
			left = total - curr;
			if(left==curr){
			    cout<<i<<" ";
				ans += (i*(i-1)/2);
				long long ll = n-i;
				ans += (ll*(ll-1)/2);
			}else if(left>curr){
				long long d = left-curr;
				if(d%2==0){
				    d = d/2;
				    long long e = (n-d);
				    long long s = (i+1-d);
				    long long h = ans;
				    if(s>=1 && s<=i && e>=1 && e<=i){
				        ans += e-s+1;
				    }else if(s>=1 && s<=i && e>i){
				        ans += (i+1-s);
				    }else if(s<1 && e>=1 && e<=i){
				        ans += e;
				    }else if(s<1 && e>i){
				        ans +=i;
				    }
				    if(h<ans)
				        cout<<i<<" ";
				    
				}
		}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

