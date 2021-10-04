#include<bits/stdc++.h>
using namespace std;

void dfs(int start,vector<int> &visited,map<int,vector<int>> &mp){
	stack<int> s;
	s.push(start);
	while(!s.empty()){
		auto temp=s.top();
		cout<<temp<<" ";
		visited[temp]=1;
		s.pop();
		for(auto x:mp[temp]){
			if(!visited[x])
			s.push(x);
		}
		
	}
}

int main(){
	int nodes,edges,p1,p2,i;
	cin>>nodes>>edges;
	map<int,vector<int>> mp;
	for(i=0;i<edges;i++){
		cin>>p1>>p2;
		mp[p1].push_back(p2);
		mp[p2].push_back(p1);
	}
	for(auto x: mp){
		cout<<x.first<<": ";
		for(auto y: x.second){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	vector<int> visited(nodes+1,0);
	dfs(mp.begin()->first,visited,mp);
	
}