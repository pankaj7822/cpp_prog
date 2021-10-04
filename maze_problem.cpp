#include<bits/stdc++.h>
using namespace std;
int cost(vector<vector<int>> &v,int r, int c,int n, int m,vector<vector<int>> &dp){
	int r_min, b_min;
	if(r>=n || c>=m)
	return 0;
	if(dp[r][c+1]!=-1)
	r_min=dp[r][c+1];
	else
	r_min=cost(v,r,c+1,n,m,dp);
	if(dp[r+1][c]!=-1)
	b_min=dp[r+1][c];
	else
	b_min=cost(v,r+1,c,n,m,dp);
	dp[r][c]= min(r_min+v[r][c],b_min+v[r][c]);
	return min(r_min+v[r][c],b_min+v[r][c]);
}

int main(){
	int rows,cols,ele;
	cin>>rows>>cols;
	int i,j;
	vector<vector<int>> v(rows,vector<int>(cols,0));
	vector<vector<int> > dp(rows+1,vector<int>(cols+1,-1));
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			cin>>ele;
			v[i][j]=ele;
		}
	}
	auto ans=cost(v,0,0,rows,cols,dp);
	cout<<ans<<endl;
	return 0;	
}