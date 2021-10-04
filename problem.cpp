// Problem: KJ and street lights
// Contest: HackerRank - Ab yeh kar ke Dikhao!!!
// URL: https://www.hackerrank.com/contests/ab-yeh-kar-ke-dikhao/challenges/kj-and-street-lights/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,p,e1,e2,i,cnt=0,ans=0;
    cin>>n>>p;
    vector<int> v(p+1,0);
    while(n>0){
    	cin>>e1>>e2;
    	v[max(0,e1-e2)]+=1;
    	v[min(p,e1+e2+1)]-=1;
    	n--;
    }
    for(i=1;i<p+2;i++){
    	v[i]=v[i]+v[i-1];
    }
    for(i=0;i<p+1;i++){
    	if(v[i]!=1)
    	cnt++;
    	else
    	{
    		ans=max(cnt,ans);
    		cnt=0;
    	}
    }
    ans=max(cnt,ans);
    cout<<ans<<endl;
}