// Problem: Removing Digits
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1637
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using namespace std;
vector<int> getdigits(int temp){
	vector<int> digits;
		while(temp!=0){
		digits.push_back(temp%10);
		temp=temp/10;
	}
	return digits;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,i,ans=0,s;
	cin>>n;
	vector<int> digits;
	while(n!=0){
		digits=getdigits(n);
		sort(digits.begin(),digits.end(),greater<int>());
		s=digits.size();
		for(i=0;i<s;i++){
			if(digits[i]<=n){
				n=n-digits[i];
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
}