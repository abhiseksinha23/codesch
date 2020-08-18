#include<bits/stdc++.h>
using namespace std;
bool checkpal(string st, int s, int e){
	if(s>e)return false;
	int l = e-s+1;
	if(l==1)return true;
	int i=s,j=e,c=0;
	while(c<(l/2)){
		if(st[i]!=st[j]){
			return false;
		}
		c++;
		i++;
		j--;
	}
	return true;
}
void print(string st, int s, int e){
	for(int i=s; i<=e; i++){
		cout<<st[i];
	}
}
int main(){
	string s;
	cin>>s;
	int n = s.length();
	if(s.length()<=2){
		cout<<"Impossible";
		return 0;
	}
	int f = false;
	for(int i=0; i<s.length()-2; i++){
		if(checkpal(s,0,i)){
			for(int j=i+1; j<s.length(); j++){
				if(checkpal(s,i+1,j) && checkpal(s,j+1,n-1)){
					print(s,0,i);
					cout<<"\n";
					print(s,i+1,j);
					cout<<"\n";
					print(s,j+1,n-1);
					f = true;
					break;
				}
			}
			if(f){
				break;
			}
		}
	}
	if(!f){
		cout<<"Impossible";	
	}
	return  0;
}
