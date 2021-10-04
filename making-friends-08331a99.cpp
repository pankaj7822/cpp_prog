// Problem: Making friends
// Contest: HackerEarth - Algorithms - Graphs - Graph Representation
// URL: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/making-friends-08331a99/
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using namespace std;

int main(){
	int i, t,n,m;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n>>m;
	        if(n%2==0 && m<=n/2)
              cout<<"Yes\n";
        else if(m==0)
               cout<<"Yes\n";

        else
               cout<<"No\n";
	}
	return 0;
}