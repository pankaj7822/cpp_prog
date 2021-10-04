// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
    int i,j,m;
    i=0;
    j=0;
    deque<int> dq;
    vector<int> ans;
    if(k>=n){
    ans.push_back(*max_element(arr,arr+n));
    return ans;
    }
    while(j<n){
        while(!dq.empty() && dq.back()<arr[j])
        dq.pop_back();
        
        dq.push_back(arr[j]);
        if(j-i+1<k)
        j++;
        else if(j-i+1==k){
            m=dq.front();
            if(m==arr[i])
            dq.pop_front();
            
            ans.push_back(m);
            i++;
            j++;
        }
    }
    return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends