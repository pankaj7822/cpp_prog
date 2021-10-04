#include<bits/stdc++.h>
using namespace std;
string printShortestSuperSeq(string &s1,string &s2){
	int n,m,i,j;
	n=s1.size();
	m=s2.size();
	vector<vector<int>> v(n+1,vector<int>(m+1,-1));
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i==0 || j==0)
			v[i][j]=0;
			else if(s1[i-1]==s2[j-1])
			v[i][j]=1+v[i-1][j-1];
			else
			v[i][j]=max(v[i-1][j],v[i][j-1]);
		}
	}
	i=n;
	j=m;
	string res="";
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			res+=s1[i-1];
			i--;
			j--;
		}
		else if(v[i-1][j]>v[i][j-1]){
			res+=s1[i-1];
			i--;
		}
		else{
			res+=s2[j-1];
			j--;
		}
	}
	while(j>0){
		res+=s2[j-1];
		j--;
	}
	while(i>0){
		res+=s1[i-1];
		i--;
	}
	reverse(res.begin(),res.end());
	return res;
	
	
}
// Driver program to test above function
int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
  
    cout<< printShortestSuperSeq(X, Y)<<endl;
  
    return 0;
}