/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>
using namespace std;
void topologicalsort(int start,vector<vector<int>> &adj, vector<int> &vis,stack<int> &s,int nodes ){
set<int> st;
int i;
vector<int> ind(nodes+1,0);
ind[0]=-1;
for(i=1;i<=nodes;i++){
for(auto x:adj[i]){
	ind[x]++;
}
}
// cout<<endl;
for(i=1;i<=nodes;i++){
	// cout<<ind[i]<<" ";
	if(ind[i]==0){
		st.insert(i);
		vis[i]=1;
	}
	
}
// cout<<endl;
while(!st.empty()){
	int data=*st.begin();
	st.erase(st.begin());
	s.push(data);
	// cout<<"d"<<s.size()<<endl;
	for(auto y:adj[data]){
		vis[y]=1;
		ind[y]--;
		if(ind[y]==0)
		st.insert(y);
	}
}

return;
}


int main(){
int i,nodes,edges,e1,e2;
cin>>nodes>>edges;
vector<vector<int>> adj(nodes+1,vector<int>());
stack<int> s;
vector<int> visited(nodes+1,0),ans;
for(i=0;i<edges;i++){
	cin>>e1>>e2;
	adj[e1].push_back(e2);
}
// i=0;
// for(auto y: adj){
	// cout<<i<<": ";
	// for(auto x: y){
		// cout<<x<<" ";
	// }
	// i++;
	// cout<<endl;
// }

for(i=1;i<=nodes;i++){
	if(!visited[i])
	topologicalsort(i,adj,visited,s,nodes);
}
while(!s.empty()){
	ans.push_back(s.top());
	s.pop();
}
reverse(ans.begin(),ans.end());
// cout<<ans.size()<<endl;
for(auto x:ans)
cout<<x<<" ";
}