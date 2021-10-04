// Adjacency matrix provides constant time access (O(1) ) to determine if there is an edge between two nodes.
 //Space complexity of the adjacency matrix is O(V^2).

#include<bits/stdc++.h>
using namespace std;

int main(){
int nodes,edges,p1,p2,i;
cin>>nodes>>edges;
vector<vector<bool>> v(nodes+1,vector<bool>(nodes+1,false));
for(i=0;i<edges;i++){
	cin>>p1>>p2;
	v[p1][p2]=true;
}
for(auto x:v){
for(auto y:x)
cout<<y<<" ";
cout<<endl;	
}

}	
