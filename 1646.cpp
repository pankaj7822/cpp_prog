// Problem: Static Range Sum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1646
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n,q,ele,p1,p2;
	cin>>n>>q;
	vector<long long int> v,prefx_sum{0};
	while(n--){
		cin>>ele;
		v.push_back(ele);
	}
	partial_sum(v.begin(),v.end(),back_inserter(prefx_sum));
	while(q--){
		cin>>p1>>p2;
		cout<<prefx_sum[p2]-prefx_sum[p1-1]<<endl;
	}
}