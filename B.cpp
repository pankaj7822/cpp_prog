// Problem: B. Ternary String
// Contest: Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1354/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

bool isvalid(string &s, int k){
	int i=0,j=0,n;
	n=s.length();
	vector<int> arr(4,0);
	while(j<n){
		arr[s[j]-'0']+=1;
		if(j-i+1<k)
		j++;
		else if(j-i+1==k){
			if(arr[1]>0 && arr[2]>0 && arr[3]>0)
			return true;
			arr[s[i]-'0']-=1;
			i++;
			j++;                                      
		}
	}
	return false;
}
int getans(string &s){
	int l,r,mid,res=INT_MAX;
	l=3;
	r=s.size();
	while(l<=r){
		mid=(l+r)/2;
		if(isvalid(s,mid)){
			res=min(res,mid);
			r=mid-1;
		}
		else
		l=mid+1;
	}
	if(res==INT_MAX)
	res=0;
	return res;
}
int main(){
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		cout<<getans(s)<<endl;
	}
}