int i=0;
int n = s.length();
int d=0;
int ans =0; 
while(i<n){
	int j =i+1;
	int total =0;
	int m = c[i];
	while(j<n && s[i]==s[j]){
		j++;
		m = max(m,c[j]);
		total += c[j];
	}
	if(j-i>1)
	ans += (total - m);
	i = j;
}

return ans;
