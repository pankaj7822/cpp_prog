#include<bits/stdc++.h>
using namespace std;


int isScramble(const string A, const string B) {
    int n=A.length(),m=B.length();
    if(n!=m)
    return 0;
    else if(n==0 && m==0)
    return 1;
    else if(A==B)
    return 1;
    else if(n==1){
        if(A==B)
        return 1;
        else 
        return 0;
    }
    int flag=0;
    for(auto i=1;i<n-1;i++){
        if( isScramble(A.substr(0,i+1),B.substr(n-i-1,i+1)) && isScramble(A.substr(i+1,n-i-1),B.substr(0,n-i-1))  )
        {
            flag=1;
            break;
        }
        if(isScramble(A.substr(0,i+1),B.substr(0,i+1)) && isScramble(A.substr(i+1,n-i-1),B.substr(i+1,n-i-1)) )
        {
            flag=1;
            break;
        }
    }
    return flag;
}



int main(){
	string A,B;
	cin>>A>>B;
	auto ans=isScramble(A,B);
	cout<<ans<<endl;
}