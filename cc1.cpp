#include<bits/stdc++.h>
using namespace std;
struct pair1{
	int connection;
	double time;
	pair1(int c, double t){
		connection = c;
		time  = t;
	}
};

int BFS(vector<vector<pair1>>&connections, unordered_map<int,int>&visited, queue<pair1> &q){
	int count 1=0;
	while(!q.empty()){
		pair1 x = q.front();q.pop();
		for(int j=0; j<connections[x.connection].size(); j++){
			if(visited.count(connections[x.connection][j].connection)==0){
				if(x.time<(connections[x.connection][j].time)){
					visited[connections[x.connection][j].connection]++;
					q.push(connections[x.connection][j]);
					count1++;
				}
			}
		}
	}
	return count1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>arr(n+1);
		for(int i=1; i<=n; i++)cin>>arr[i];
		vector<vector<pair1>>connections(n+1);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i!=j){
					if(i-j>0 && arr[i]-arr[j]<0)
						connections[i].push_back(pair1(j, (double) (i-j)/(arr[j]-arr[i])));
					if(i-j<0 && arr[i]-arr[j]>0)
						connections[i].push_back(pair1(j, (double) (j-i)/(arr[i]-arr[j])));
				}
			}
		}
		int min = INT_MAX, max = INT_MIN;
		for(int i=1; i<=n; i++){
			unordered_map<int,int>visited;
			queue<pair1>q;
			int count1 =1;
			visited[i]++;
			for(int j=0;j<connections[i].size(); j++){
				visited[connections[i][j].connection]++;
				q.push(connections[i][j]);
				count1++;
			}
			count1 += BFS(connections, visited, q);
			if(count1>max){
				max = count1;
			}if(count<min){
				min = count1;
			}
		}
		cout<<min<<" "<<max<<endl;
	}
	return 0;
}

