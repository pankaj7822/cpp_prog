#include<bits/stdc++.h>
using namespace std;

vector<int> NGL(vector<int> &v,int n){
stack<int> s;
vector<int> w;
for(auto i=0;i<n;i++){
while(!s.empty() && s.top()<v[i])	
s.pop();
if(s.empty())
w.push_back(-1);
else
w.push_back(s.top());
s.push(v[i]);
}
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
	w=NGL(v,n);
	for(auto x:w)
	cout<<x<<" ";
	return 0;
}