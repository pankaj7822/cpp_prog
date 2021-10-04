#include<bits/stdc++.h>
using namespace std;

vector<int> NSR(vector<int> &v,int n){
 stack<int> s;
 vector<int> w;
 for(int i=n-1;i>=0;i--){
 	while(!s.empty() && s.top()>v[i]){
 		s.pop();
 	}
 	if(s.empty())
 	w.push_back(-1);
 	else if(s.top()<v[i])
 	w.push_back(s.top());
 	s.push(v[i]);
 }
 reverse(w.begin(),w.end());
 return w;
}

int main(){
	int n,ele,i;
	vector<int> v,w;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		v.push_back(ele);
	}
	w=NSR(v,n);
	for(auto x:w)
	cout<<x<<" ";
	return 0;
}