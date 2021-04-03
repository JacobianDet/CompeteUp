#include <bits/stdc++.h>

bool bs1(int A, int B)
{
	bool ok = 1;
	int lo = A+1;
	int hi = B;
	while(lo <= hi)
	{
		int mid = lo + (hi - lo)/2;
		std::cout<<mid<<std::endl;
		std::string s;
		std::cin>>s;
		if(s == "CORRECT")
		break;
		else if(s == "TOO_SMALL")
		lo = mid + 1;
		else if(s == "TOO_BIG")
		hi = mid - 1;
		else 
		{
			ok = 0;
			break;
		}	
	}
	return ok;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int A,B,N;
		std::cin>>A>>B>>N;
		if(!bs1(A, B))
		break;	
	}
	return 0;
}