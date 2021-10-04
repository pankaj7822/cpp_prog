// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n,i,ind=0,ans=0,cnt=1;
        n=nums.size();
        for(i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])
                cnt++;
            else if(nums[i]!=nums[i+1]){
                ans+=cnt*ind;
                cnt=1;
                ind++;
            }
        }
        ans+=cnt*ind;
        return ans;
        
    }
};
// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends