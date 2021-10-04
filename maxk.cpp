#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,i,e,ans=INT_MIN;
	cin>>n;
	unordered_set<int> s;
	for(i=0;i<n;i++){
		cin>>e;
		s.insert(e);
	}
	for(auto it=s.begin();it!=s.end();it++){
		auto it2=s.find((*it)*-1);
		if(it2!=s.end())
		ans=max(ans,*it);
	}
	ans=ans>0?ans:0;
	cout<<ans<<endl;
}