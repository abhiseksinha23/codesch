#include<bits/stdc++.h>
using namespace std;
bool matched(vector<int>&m1,vector<int>&m2){
	for(int i=0; i<26;i++){
		if(m1[i]!=m2[i])return false;
	}
	return true;
}
int main(){
	string s;
	int n;
	cin>>s;
	cin>>n;
	vector<string>arr(n);
	int total=0;
	for(int i=0; i<n; i++){
	cin>>arr[i];
	total += arr[i].length();	
	}
	int ll = s.length();
	if(total>ll){
	cout<<"NO";
	return 0;
	}
	string ans ="YES";
	for(int i=0; i<n; i++){
		int l = arr[i].length();
			ll = s.length();
		if(l>ll){
			ans = "NO";
			break;
		}
		vector<int>m1(26,0);
		vector<int>m2(26,0);
		for(int j=0; j<l; j++){
			if(s[j]>='a' && s[j]<='z')
				m2[s[j]-'a']++;
			m1[arr[i][j]-'a']++;
		}
	bool match = false;
		if(matched(m1,m2)){
			match = true;
		for(int j=0; j<l; j++){
			s[j] = 'A';
		}
		string news = "";
		for(int i=0; i<ll; i++){
		if(s[i]>='a' && s[i]<='z')news+=s[i];
		}
		s = news;	
		}else{				
		for(int j=l; j<ll; j++)	{
				m2[s[j]-'a']++;
				m2[s[j-l]-'a']--;
				if(matched(m1,m2)){
					match = true;
				for(int k=j-l+1; k<=j; k++){
					s[k] = 'A';
				}
				string news = "";
				for(int i=0; i<ll; i++){
				if(s[i]>='a' && s[i]<='z')news+=s[i];
				}
				s = news;
				break;		
			}
		}
	}
	//cout<<s<<"\n";
		if(match==false){
			ans = "NO";
			break;
		}
	}
	if(s.length()>0){
		ans = "NO";
	}
	cout<<ans<<"\n";
	return 0;
}
