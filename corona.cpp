#include<bits/stdc++.h>
using namespace std;

int main(){
	
	vector<vector<char > >arr(9,vector<char>(20));
	int safe =0;
	for(int i=0; i<9; i++){
		for(int j=0; j<20; j++){
			cin>>arr[i][j];
			if(arr[i][j]=='a'|| arr[i][j]=='c')safe++;
		}
	}
	vector<pair<int,int > >p;
	p.push_back(make_pair(0,0));
	int first = 0,count=0;
//	int x=1,y=7;
//	int currenty=-1, currentx=1;
//	while(first<2){
//		if(arr[y][x]=='.'){
//			p.push_back(make_pair(x,8-y));
//		}else if(arr[y][x]=='*'){
//			first++;
//			if(first==2)break;
//			int newx1,newx2,newy1,newy2;
//			newx1 = (-1)*currenty;
//			newy1 = currentx;
//			newx2 = currenty;
//			newy2 = (-1)*currentx;
//			if(x+newx1>=0 && x+newx1<20 && y+newy1>=0 && y+newy1<9){
//				currenty=newx1;
//				currentx = newy1;
//			}else if(x+newx2>=0 && x+newx2<9 && y+newy2>=0 && y+newy2<9){
//				currenty=newx2;
//				currentx = newy2;		
//			}
//			p.push_back(make_pair(x,8-y));
//		}else if(arr[y][x]=='a'){
//			count++;
//			arr[y][x] = '-';
//			int temp = currentx;
//			currentx = (-1)*currenty;
//			currenty = temp;
//			p.push_back(make_pair(x,8-y));
//		}else if(arr[y][x]=='c'){
//			p.push_back(make_pair(x,8-y));
//			arr[y][x] = '-';
//			count++;
//			int temp = currenty;
//			currenty = (-1)*currentx;
//			currentx = temp;
//		}	
//		y+=currenty;
//	`x+=currentx;
//	}
	int i=7,j=1;
//	int count=0;
	int currenty=-1, currentx=1;
	while(first<2){
		if(arr[i][j]=='.'){
			p.push_back(make_pair(j,8-i));
		}else if(arr[i][j]=='*'){
			first++;
			p.push_back(make_pair(j,8-i));
			//	break;
			if(first==2)break;
			int newx1,newx2,newy1,newy2;
			newx1 = (-1)*currentx;
			newy1 = currenty;
			newx2 = currentx;
			newy2 = (-1)*currenty;
			if(i+newx1>=0 && i+newx1<9 && j+newy1>=0 && j+newy1<20){
				currenty=newx1;
				currentx = newy1;
			}else if(i+newx2>=0 && i+newx2<9 && j+newy2>=0 && j+newy2<20){
				currenty=newx2;
				currentx = newy2;		
			}
		}else if(arr[i][j]=='a'){
			arr[i][j] = '-';
			count++;
			int temp = currenty;
			currenty = (-1)*currentx;
			currentx = temp;
			p.push_back(make_pair(j,8-i));
		}else if(arr[i][j]=='c'){
			arr[i][j] = '-';
			count++;
			int temp = currentx;
			currentx = (-1)*currenty;
			currenty = temp;
			p.push_back(make_pair(j,8-i));
		}
			i+=currenty;
			j+=currentx;
	}
	
	for(int i=0; i<p.size(); i++){
		cout<<p[i].first<<" "<<p[i].second<<"\n";
	}

	for(int i=0; i<9; i++){
		for(int j=0; j<20; j++){
			cout<<arr[i][j];
		}cout<<"\n";
	}
	cout<<"safe="<<(safe-count)<<"\n";
	cout<<"infected="<<(count);
	return 0;
}
