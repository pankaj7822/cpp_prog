// Problem: Dice Combinations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1633
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

// long long int getchances(long long int n, vector<long long int> &v){
	// long long int M=1e9+7;
	// if(n==1 || n==0)
	// return 1;
	// else if(n<0)
	// return 0;
	// else if(v[n]!=0){
		// return v[n];
	// }	
	// else {
		// v[n]=(getchances(n-1,v)%M+getchances(n-2,v)%M+getchances(n-3,v)%M+getchances(n-4,v)%M+getchances(n-5,v)%M+getchances(n-6,v)%M)%M;
		// return v[n];
	// }
// }
// 
long long int getchances(long long int n){
	long long int ans,i,m=1e9+7,p=min(6,(int)n);
	vector<long long int> v(n+1,0);
	v[0]=1;
	v[1]=1;
	for(i=2;i<=p;i++){
		v[i]=accumulate(v.begin(),v.begin()+i,0);
	}
	for(i=7;i<n+1;i++){
		v[i]=(accumulate(v.begin()+i-6,v.begin()+i,0))%m;
	}
	return v[n];
	return ans;
}


int main(){
	long long int n,ans;
	cin>>n;
	ans=getchances(n);
	cout<<ans;
	return 0;
}