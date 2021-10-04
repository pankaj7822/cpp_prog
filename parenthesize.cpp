// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
        int solve(string &s,int i,int j,int X,vector<vector<vector<int>>> &v){
        if(i>j)
        return 0;
        if(i==j){
            if(X==1)
            return (s[i]=='T')?1:0;
            else
            return (s[i]=='F')?1:0;
        }
        if(v[i][j][X]!=-1)
        return v[i][j][X];
        int ans=0;
        int lt,rt,rf,lf;
        for(auto k=i+1;k<=j-1;k+=2){
            if(v[i][k-1][1]!=-1)
            lt=v[i][k-1][1];
            else
            lt=solve(s,i,k-1,1,v);
            
            if(v[i][k-1][0]!=-1)
            lf=v[i][k-1][0];
            else
            lf=solve(s,i,k-1,0,v);
            
            if(v[k+1][j][1]!=-1)
            rt=v[k+1][j][1];
            else
            rt=solve(s,k+1,j,1,v);
            
            if(v[k+1][j][0]!=-1)
            rf=v[k+1][j][0];
            else
            rf=solve(s,k+1,j,0,v);
            
            
            if(s[k]=='|'){
            if(X)
            ans+=lt*rf+lt*rt+lf*rt;
            else
            ans+=lf*rf;
            }
            else if(s[k]=='&'){
            if(X)
            ans+=lt*rt;
            else
            ans+=lt*rf+lf*rf+lf*rt;
            }
            else if(s[k]=='^'){
            if(X)
            ans+=lt*rf+lf*rt;
            else
            ans+=lt*rt+lf*rf;
            }
        }
        v[i][j][X]=ans%(1003);
        return v[i][j][X];
        
    }
    
    int countWays(int N, string S){
        vector<vector<vector<int>>>v(N,vector<vector<int>>(N,vector<int>(2,-1)));
        int ans = solve(S,0,N-1,1,v);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends