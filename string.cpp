#include<bits/stdc++.h>
using namespace std;
bool isvowel(char a){
	if(a=='A' || a=='E' || a=='I' || a=='O' || a=='U')return true;
	return false; 
}
int main(){
	string s;
	cin>>s;
	int n = s.length();
	vector<bool>arr(26,false);
	vector<int>c(n,0);
	for(int i=0; i<n; i++){
		arr[s[i]-'A'] = true;
		c[i] = i>0?c[i-1]:0;
		if(isvowel(s[i])){
			c[i]++;
		}
	}
	int cons = 0;
	for(int i=0; i<26; i++){
		if(i!=('A'-'A') && i!=('E'-'A') && i!=('I'-'A') && i!=('O'-'A') && i!=('U'-'A') && arr[i]){
			cons++;
		}
	}
	
	if(cons<5){
		cout<<"-1\n";
		return 0;
	}
	bool f = false;
	int j = -1;
	for(int i=2; i<n; i++){
		if(j>=0){
			int cc = c[i] - c[j];
			if(cc==3){
				f = true;
				break;
			}
		}else{
			int cc = c[i];
			if(cc==3){
				f = true;
				break;
			}
		}
		j++;
	}
	if(f){
		cout<<"GOOD\n";
	}else{
		cout<<"-1\n";
	}
	return 0;
}

