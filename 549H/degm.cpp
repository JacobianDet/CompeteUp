#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

ll arr[2][2];

ld bs1(void)
{
	ld lo = 0;
	ld hi = 1e15;
	for(int t=0;t<100;t++)
	{
		ld mid = lo + (hi - lo)/2;
	        ld mxs1 = std::min((arr[0][0] - mid) * (arr[1][1] - mid), std::min((arr[0][0] - mid) * (arr[1][1] + mid), std::min((arr[0][0] + mid) * (arr[1][1] - mid), (arr[0][0] + mid) * (arr[1][1] + mid))));
                ld mxs2 = std::max((arr[0][0] - mid) * (arr[1][1] - mid), std::max((arr[0][0] - mid) * (arr[1][1] + mid), std::max((arr[0][0] + mid) * (arr[1][1] - mid), (arr[0][0] + mid) * (arr[1][1] + mid)))); 
		ld mxd1 = std::min((arr[0][1] - mid) * (arr[1][0] - mid), std::min((arr[0][1] - mid) * (arr[1][0] + mid), std::min((arr[0][1] + mid) * (arr[1][0] - mid), (arr[0][1] + mid) * (arr[1][0] + mid)))); 
                ld mxd2 = std::max((arr[0][1] - mid) * (arr[1][0] - mid), std::max((arr[0][1] - mid) * (arr[1][0] + mid), std::max((arr[0][1] + mid) * (arr[1][0] - mid), (arr[0][1] + mid) * (arr[1][0] + mid))));
		ld r1 = std::max(mxs1, mxd1);
		ld r2 = std::min(mxs2, mxd2);
		if(r1 <= r2)
		hi = mid;
		else lo = mid;
	}
	return lo;
}	
	
int main(void)
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		std::cin>>arr[i][j];
	}
	ld ans = bs1();
	std::cout.setf(std::ios_base::fixed);
	std::cout<<std::setprecision(12)<<ans<<"\n";
	std::cout.unsetf(std::ios_base::fixed);
	return 0;
}	
