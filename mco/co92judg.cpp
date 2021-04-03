#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		int A[n],B[n];
		for(int i=0;i<n;i++)
		std::cin>>A[i];
		for(int i=0;i<n;i++)
		std::cin>>B[i];
		std::sort(A, A+n);
		std::sort(B, B+n);
		int sa=0,sb=0;
		for(int i=0;i<n-1;i++)
		{
			sa += A[i];
			sb += B[i];
		}	
		if(sa < sb)
		std::cout<<"Alice\n";
		else if(sb < sa)
		std::cout<<"Bob\n";
		else std::cout<<"Draw\n";	
	}	
	return 0;
}