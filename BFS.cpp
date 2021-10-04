#include<bits/stdc++.h>
using namespace std;


void BFS(int start,vector<int> &visited,map<int,vector<int>> &mp,vector<int> &level){
	queue<int> q;
	q.push(start);
	cout<<start<<" ";
	level[start]=0;
	visited[start]=1;
	while(!q.empty()){
		auto data=q.front();
		q.pop();
		for(auto x: mp[data]){
			if(!visited[x]){
				cout<<x<<" ";
				level[x]=level[data]+1;
				visited[x]=1;
				q.push(x);
			}
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

for(auto it=mp.begin();it!=mp.end();it++){
	cout<<it->first<<": ";
	for(auto x: it->second){
		cout<<x<<" ";
	}
	cout<<endl;
}
vector<int> visited(nodes+1,0);
vector<int> level(nodes+1,0);
BFS(mp.begin()->first,visited,mp,level);
cout<<endl;
for(auto y: level)
cout<<y<<" ";
return 0;
}