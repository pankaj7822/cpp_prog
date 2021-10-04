// Problem: Distorted Palindrome
// Contest: CodeChef - Practice(Extcontest)
// URL: https://www.codechef.com/problems/ENCD12
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

bool ispossible(string &s){
	int i,n,cnt=0;
	n=s.length();
	map<char,int> mp;
	for(i=0;i<n;i++){
		mp[s[i]]+=1;
	}
	for(auto it: mp){
		if(it.second%2==1)
		cnt++;
	}
	return (cnt<=1);
}

int getresult(string &s){
	int n=s.length(),l,r,k,cnt=0;
	if(ispossible(s)){
		l=0;
		r=n-1;
		while(l<r){
			if(s[l]==s[r]){
				l++;
				r--;
			}
			else{
				k=r;
				while(l<k && s[l]!=s[k]){
					k--;
				}
				if(l==k){
					swap(s[l],s[l+1]);
					cnt++;
				}
				else{
					while(k<r){
					swap(s[k],s[k+1]);
					k++;
					cnt++;
					}
					l++;
					r--;
				}
				
			}
		}
	}
	else
	return -1;
	
	return cnt;
}

int main(){
	int ans;
	string s;
	// cin>>s;
	// ans=getresult(s);
	// cout<<ans<<endl;
	while(true){
		cin>>s;
		if(s=="0")
		break;
		ans=getresult(s);
		if(ans!=-1)
		cout<<ans<<endl;
		else
		cout<<"Impossible"<<endl;
	}
}