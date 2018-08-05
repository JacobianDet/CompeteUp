#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long T,n;
	cin>>T;
	for(long long i=0;i<T;i++)
	{
	    if(i != 0)
        cout<<endl;
		cin>>n;
		vector<long long> a(n);
		for(long long j=0;j<n;j++)
		cin>>a[j];
		long long tot = 0;
		for(long long j=0;j<n;j++)
		tot = (tot%n + a[j]%n)%n;
		if(tot == 0)
		cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
