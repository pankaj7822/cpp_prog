// The space complexity of adjacency list is O(V + E) 

#include<bits/stdc++.h>
using namespace std;

int main(){
int nodes,edges,p1,p2,i;
cin>>nodes>>edges;
vector<vector<int>> v(nodes+1,vector<int>());
for(i=0;i<edges;i++){
	cin>>p1>>p2;
	v[p1].push_back(p2);
}	
i=0;
for(auto x:v){
cout<<i<<": ";	
for(auto y:x){
cout<<y<<" ";
}
cout<<endl;	
i++;
}	
}