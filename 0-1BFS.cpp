#include<bits/stdc++.h>
using namespace std;


void BFS01(int start,vector<int> &distance,map<int,vector< pair<int,int>> > &mp){
	deque<int> dq;
	distance[start]=0;
	dq.push_front(start);
	while(!dq.empty()){
		auto data=dq.front();
		dq.pop_front();
		for(auto x: mp[data]){
			if(distance[x.first]>distance[data]+x.second){
				distance[x.first]=distance[data]+x.second;
				if(x.second==0)
				dq.push_front(x.first);
				else 
				dq.push_back(x.first);
			}
		}
	}
}

int main(){
int nodes,edges,p1,p2,p3,i;
cin>>nodes>>edges;
map<int,vector< pair<int,int> > > mp;
for(i=0;i<edges;i++){
	cin>>p1>>p2>>p3;
	mp[p1].push_back(make_pair(p2,p3));
	mp[p2].push_back(make_pair(p1,p3));
}

for(auto it=mp.begin();it!=mp.end();it++){
	cout<<it->first<<": ";
	for(auto x: it->second){
		cout<<x.first<<" "<<x.second<<",";
	}
	cout<<endl;
}

vector<int> distance(nodes,INT_MAX-1);
BFS01(mp.begin()->first,distance,mp);
cout<<endl;
for(auto z:distance)
cout<<z<<" ";
return 0;
}