#include<bits/stdc++.h>
using namespace std;

int modified_search(vector<int> &v,int n,int target){
	int l=0,h=n-1,mid,next,prev;
	while(l<=h){
		mid=l+(h-l)/2;
		next=(mid+1)%n;
		prev=(mid-1+n)%n;
		if(v[mid]==target)
		return mid;
		else if(v[next]==target)
		return next;
		else if(v[prev]==target)
		return prev;
		else if(target>v[mid])
			l=mid+2;
		else if(target<v[mid])
			h=mid-2;
	}
	return -1;
}

int main(){
	int ele,n,i,target,ans;
	vector<int>v;
	cin>>n>>target;
	for(i=0;i<n;i++){
	cin>>ele;
	v.push_back(ele);
	}
	ans=modified_search(v,n,target);
	cout<<ans<<endl;
}