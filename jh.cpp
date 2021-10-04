#include <bits/stdc++.h>

using namespace std;

 vector<int> valueEqualToIndex(int arr[], int n) {
	    // code here
	    vector<int> v;
	    int i;
	    for(i=0;i<n;i++){
	        cout<<arr[i]<<endl;
	        if(arr[i]==i+1)
	        {
	            v.push_back(i+1);
	        }
	        else if(arr[i]>i+1){
	            i=arr[i]-2;
	        }
	    }
	    return v;
	}

int main() {
	vector<int> v;
	int n,i,ele;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>ele;
		arr[i]=ele;
	}
	v=valueEqualToIndex(arr,n);
  for(i=0;i<v.size();i++){
  	cout<<v[i]<<" ";
  }
}