#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,e,cnt,ans=0,n;
	vector<int> v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>e;
		v.push_back(e);
	}
	sort(v.begin(),v.end());
	cnt=0;
	for(i=1;i<n;i++){
		if(v[i]==v[i-1]){
			ans+=cnt;
		}
		else{
			cnt++;
			ans+=cnt;
		}
	}
	cout<<ans<<endl;
}