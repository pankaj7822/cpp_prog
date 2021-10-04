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
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main() {
int nodes,edges,i,n1,n2,w;
cin>>nodes>>edges;
vector<pair<int,int>> v[nodes+1];
vector<int> visited(nodes+1,0);
for(i=0;i<edges;i++){
	cin>>n1>>n2>>w;
	v[n1].push_back(make_pair(n2,w));
	// v[n2].push_back(make_pair(n1,w));
}
for(i=1;i<=nodes;i++){
	cout<<i<<": ";
	for(auto x: v[i]){
		cout<<x.first<<" "<<x.second<<", ";
	}
	cout<<endl;
}
cout<<endl;
//Djistra Algorithm

multiset<pair<int,int>> minh;
vector<int> distance(nodes+1,INT_MAX);
distance[1]=0;
minh.insert(make_pair(0,1));
while(!minh.empty()){
	auto p1=*minh.begin();
	minh.erase(minh.begin());
	if(visited[p1.second])
	continue;
	visited[p1.second]=1;
	for(auto x: v[p1.second]){
		if(distance[x.first]>distance[p1.second]+x.second){
			distance[x.first]=distance[p1.second]+x.second;
			minh.insert(make_pair(distance[x.first],x.first));
		}
	}
}

for(i=2;i<=nodes;i++)
cout<<distance[i]<<" ";

}