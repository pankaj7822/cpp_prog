#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int nodes,edges,p1,p2,w,i,j,k;
cin>>nodes>>edges;
vector<vector<int>> v(nodes+1,vector<int>(nodes+1,INT_MAX));
for(i=0;i<edges;i++){
	cin>>p1>>p2>>w;
v[p1][p2]=w;
v[p2][p1]=w;
}
for(i=0;i<=nodes;i++)
v[i][i]=0;

for(k=1;k<=nodes;k++){
	for(i=1;i<=nodes;i++){
		for(j=1;j<=nodes;j++){
			v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
		}
	}
}

for(i=1;i<=nodes;i++){
	for(j=1;j<=nodes;j++)
	cout<<v[i][j]<<" ";
	cout<<endl;
}

	
}