#include<bits/stdc++.h>
using namespace std;

int solution(string &s, int st, int e) {
    
    string ans ="";
    int n = s.length();
    int i=0; 
    int c=0;
	while(i<n){
		if(i==st){
			i = e+1;
			continue;	
		}
		c = 1;
		int j = i+1;
		while(j<n && s[i]==s[j]){
			c++;
			j++;
		}
		
		if(c>1){
			//cout<<c;
			ans += to_string(c);
		}
		//cout<<s[i];
		//ans += to_string(c);
		ans += s[i];
		i = j;
	}
	
	
	//cout<<ans<<"\n";
	return ans.length();
}

int answer(string s, int k){
	
	int n =s.length();
	int ans =0 ;
	for(int i=; i<n-k+1; i++){
		int x = solution(s,i,i+k);
		ans = max(x,ans);
	}
	return ans;
}
int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	int x = solution(s,k);
	cout<<x<<"\n";
	return 0;
}
