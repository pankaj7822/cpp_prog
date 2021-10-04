// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        int i,j;
        long long int dp[m+1][n+1];
        vector<strings> paths[m+1][n+1];
        long long int mod=1e9+7;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
        if(i==1 || j==1){
        	dp[i][j]=1;
			if(j==1){
				auto s="";
				for(auto k=0;k<i;k++)
				s+="D";
				paths[i][j].push(s);
			}
			if(i==1){
				auto s="";
				for(auto k=0;k<i;k++)
				s+="D";
				paths[i][j].push(s);
			}
        }
        else if(i==0 || j==0)
        dp[i][j]=0;
        else
        dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
            }
        }
    return dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends