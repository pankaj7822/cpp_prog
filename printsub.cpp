#include<bits/stdc++.h>
using namespace std;
 
void lcs(char *X,char *Y,int m,int n){
    vector<vector<int>> v(m+1,vector<int>(n+1,-1));
    int i,j;
    string s="";
    for(i=0;i<=m;i++){
        for(j=0;j<=m;j++){
            if(i==0 || j==0)
            v[i][j]=0;
            else if(X[i-1]==Y[j-1])
            v[i][j]=1+v[i-1][j-1];
            else 
            v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    i=m;
    j=n;
	while(i>=0 && j>=0){
		if(X[i-1]==Y[j-1]){
			s+=X[i-1];
			i--;
			j--;
		}
		else if(v[i-1][j]>v[i][j-1]){
			i--;
		}
		else
		j--;
	}
    // cout<<s<<endl;
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
 
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  int m = strlen(X);
  int n = strlen(Y);
  lcs(X, Y, m, n);
  return 0;
}
