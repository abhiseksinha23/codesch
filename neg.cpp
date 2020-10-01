#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = s.length();
		string ans="";
		int i=0;
		while(i<n){
			if(s[i]>='0' && s[i]<='9'){
			int c =0;
			int j= i;
			while(j<n && (s[j]>='0' && s[j]<='9')){
					c = c*10 + (s[j]-'0');
					j++;
				}
				j++;
				string p ="";
			while(j<n && s[j]!='-'){
					p += s[j];
					j++;
				}
				int xx= 1;
			while(xx<c){
				ans +=p;
				xx++;
			}	
			}else{
				int j= i;
				while(j<n && (s[j]>='a' && s[j]<='y')){
					ans += s[j];
					j++;
				}
				i = j;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
