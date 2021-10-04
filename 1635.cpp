// Problem: Coin Combinations I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1635
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

int getways(int n, int s, vector<int> &coins){
int i,j,val,mod=1e9+7;
long long int dp[s+1];
memset(dp,0,sizeof(dp));
dp[0]=1;
for(i=1;i<=s;i++){
	for(j=0;j<n;j++){
		if(i-coins[j]<0)
		val=0;
		else 
		val=dp[i-coins[j]];
		dp[i]=(dp[i]+val)%mod;
		// cout<<i-coins[j]<<" "<<val<<endl;
	}
	// cout<<"i\n";
	// cout<<i<<" "<<dp[i]<<endl;
}
	return dp[s];
}

int main(){
	int n,s,ele,i;
	cin>>n>>s;
	vector<int> coins;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		coins.push_back(ele);
	}
	int ans=getways(n,s,coins);
	cout<<ans<<endl;
}