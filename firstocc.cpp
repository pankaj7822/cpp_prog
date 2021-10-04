// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
    int l=0,h=n-1,res=-1,mid;
    while(l<=h){
        mid=l+(h-l)/2;
        cout<<mid<<endl;
        if(arr[mid]==x){
            cout<<mid<<"h"<<endl;
            res=mid;
            h=mid-1;
        }
        else if(x>arr[mid])
        l=mid+1;
        else
        h=mid-1;
    }
    vector<int> v(2,0);
    v[0]=res;
    v[1]=x;
    return v;
}