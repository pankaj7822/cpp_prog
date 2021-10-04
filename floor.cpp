#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,ele,i,max_val,result;
	set<int> s;
	cin>>n;
	for(i=0;i<n;i++)
	{
	cin>>ele;
	s.insert(ele);
	}
	cin>>max_val;
	if(lower_bound(s.begin(), s.end(), max_val)!=s.begin())
	result=*max_element(s.begin(),lower_bound(s.begin(), s.end(), max_val));
	else
	result=-1;
    cout<<result<<endl;
}