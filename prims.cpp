#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int nodes,edges,n1,n2,w,i;
	cin>>nodes>>edges;
	vector<pair<int,int>> v[nodes+1];
	for(i=0;i<edges;i++){
		cin>>n1>>n2>>w;
		v[n1].push_back(make_pair(n2,w));
		v[n2].push_back(make_pair(n1,w));
	}
	
	priority_queue<pii,vector<pii>,greater<pii>> minh;
	vector<int> visited(nodes+1,0);
	vector<int> parent(nodes+1,-1);
	vector<int> distance(nodes+1,INT_MAX);
	minh.push(make_pair(0,1));
	distance[1]=0;
	int cost=0;
	while(!minh.empty()){
		auto p=minh.top();
		minh.pop();
		if(visited[p.second]==1)
		continue;
		visited[p.second]=1;
		cost+=p.first;
		for(auto y:v[p.second]){
			if(visited[y.first]==0 && distance[y.first]>y.second){
				distance[y.first]=y.second;
				minh.push({distance[y.first],y.first});
				parent[y.first]=p.second;
			}
		}
		
	}
	cout<<"cost is\n";
	cout<<cost<<endl;
	cout<<"parent-child"<<endl;
	for(i=1;i<=nodes;i++){
		cout<<parent[i]<<"-"<<i<<endl;
	}
}