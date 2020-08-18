#include<bits/stdc++.h>
using namespace std;
long long factorial(int n){
	long long f = 1;
	for(int i=1; i<=n; i++){
		f = f*i;
	}
	return f;
}
int main(){
	int n;
	cin>>n;
	vector<long>arr(n);
	for(int i=0; i<n; i++)cin>>arr[i];
	long long facn = factorial(n);
	double g=0;
	if(n%2==0){
		g = (2*facn) +2;
	}else{
		g = (2*facn)  -1;
	}
	
		cout<<fixed<<setprecision(6)<<(double)(g/facn)<<"\n";
		return 0;
}
//	double g=0;
//	long long per = 1;
//	for(int i=0; i<n; i++){
//		per*=i;
//		int m = 1;
//		for(int j=1; j<=i;m *=++j){
//			g += (per/m);
//			//m = m*(j+1);
//		} 
//	}
//	if(n%2==0) g--;
//	g-=n;
//	
////	cout<<g<<"\n";
//	cout<<fixed<<setprecision(6)<<(g/per)<<"\n";
//	return 0;
//}
