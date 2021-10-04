#include<bits/stdc++.h>
using namespace std;
int main(){
	int C,L, total,days=1;
	cin>>C>>L;
	total=C;
	while(true){
		total+=L;
		if(total>C)
		total=C;
		total-=days;
		// cout<<total<<" "<<days<<endl;
		if(total<=0)
		break;
		days++;
	}
	cout<<days;
	return 0;
}