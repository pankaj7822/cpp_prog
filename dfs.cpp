#include<bits/stdc++.h>
using namespace std;

void dfs(int s,vector<int> &visited,map<int,vector<int>> &mp)
{
	cout<<s<<" ";
	visited[s]=true;
	for(auto x:mp[s]){
		if(!visited[x])
		dfs(x,visited,mp);
	}
	
}
int main(){
	int nodes,edges,p1,p2,i,cc=0;
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
	for(i=1;i<=nodes;i++){
		if(!visited[i]){
		dfs(i,visited,mp);
		cout<<endl;
		cc++;
		}
	}
	cout<<"No of Connected Components: "<<cc;
}