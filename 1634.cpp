// Problem: Minimizing Coins
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1634/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

int getcoins(int n, int profit,vector<int> &coins){
	int dp[n+1][profit+1];
	memset(dp,-1,sizeof(dp));
	for(auto i=0;i<=n;i++){
		for(auto j=0;j<=profit;j++){
		if(j==0)
		dp[i][j]=0;
		else if(i==0){
			dp[i][j]=(INT_MAX-1);
		}
		else if(coins[i-1]<=j){
			dp[i][j]= min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
		}
		else{
			dp[i][j]=dp[i-1][j];
		} 
		}
	}
 return dp[n][profit];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,profit,ele,i;
	cin>>n>>profit;
	vector<int> coins;
	for(i=0;i<n;i++){
		cin>>ele;
		coins.push_back(ele);
	}
	int ans=getcoins(n,profit,coins);
	int res=ans>=INT_MAX-1?-1:ans;
	cout<<res<<endl;
}