#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		if(b.length()==0){
			sort(a.begin(),a.end());
			cout<<a<<"\n";
			continue;
		}
		vector<long>arr(26,0);
		string ans = b;
		for(int i=0; i<a.length(); i++){
			arr[a[i]-'a']++;
		}
		for(int i=0; i<b.length(); i++){
			arr[b[i]-'a']--;
		}
		char s = b[0], e = b[b.length()-1];
		for(int i=25; i>=0; i--){
			if((s-'a')>=i){
				ans = to_string('a'+ i) + ans;
			}
		}
		for(int i=0; i<26; i++){
			if((s-'a')<i){
				ans = ans + to_string('a'+ i);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
