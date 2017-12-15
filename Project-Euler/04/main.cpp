#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkPalin(int x) {
	vector<int> num;
	while(x!=0)
	{
		num.push_back(x%10);
		x/=10;
	}
	
	for(int i=0;i<num.size()/2;++i)
		if(num[i]!=num[num.size()-i-1])
			return false;

	return true;
}

bool mark[1000000];

int main() {
	vector<int> palin;

	for(int i=100;i<=999;++i)
		for(int j=100;j<=999;++j) {
			int n=i*j;
			if(mark[n]==false) {
				mark[n]=true;
				if(checkPalin(n))
					palin.push_back(n);
			}
		}
		
	sort(palin.begin(),palin.end());
	int t;
	cin>>t;
	palin.push_back(1000000);
	
	for(int k=1;k<=t;++k) {
		int n;
		cin>>n;

		for(int i=0;i<palin.size();++i)		
			if(n<palin[i]) {
				cout<<palin[i-1]<<endl;
				break;
			}
	}
 
	return 0;
}
