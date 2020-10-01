int check(int f, vector<int>&time, int &x, int &y, int &z){
	vector<int>tt;
	int tt = 100000;
	int ff = 0;
	if(x>=f){
		ff = 1;
		tt = min(tt,time[0]);
	}
	if(y>=f){
		ff = 1;
			tt = min(tt,time10]);
	}if(z>=f){
		ff = 1;
		tt = min(tt,time[2]);
	}
	
	if(ff==0)return -1;
	if(x>=f && tt==time[0]){
		x -=f;
		time[0] += f;
	}else if(y>=f && tt==time[1]){
		y -=f;
		time[1] += f;
	}else if(z>=f && tt==time[2]){
		z -=f;
		time[2] += f;
	}
	return tt;
	
}

int solution(vector<int>&A){
	int n = A.size();
	vector<int>time(3,0);
	int ans =0;
	for(int i=0; i<n; i++){
		int t = check(A[i],time, x,y,z);
		if(t==-1){
			return -1;
		}
		ans = max(ans,t);
	}
	return ans;
}
