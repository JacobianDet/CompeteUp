#include <iostream>
using namespace std;

long long GCD(long long a,long long b)
{
	if(b == 0)
	return a;
	else return GCD(b, a%b);
}

int main() {
	long long T;
	cin>>T;
	for(long long i=0;i<T;i++)
	{
		long long a,b,c;
		cin>>a>>b>>c;
		if(GCD(a,b) != 1)
		{
			if(c % GCD(a,b) == 0)
			cout<<"Case "<<i+1<<": Yes"<<endl;
			else cout<<"Case "<<i+1<<": No"<<endl;
		}
		else cout<<"Case "<<i+1<<": Yes"<<endl;
	}
	return 0;
}
