#include <bits/stdc++.h>
#define MOD 998244353

/* 0 = <
   1 = =
   2 = >
*/   

typedef long long ll;

int arr[100002];
int memo[100002][201][3];
int pmemo[100002][201][3];

int n;

int jacobian(int i, int val, int sg);

int pjacobian(int i, int val, int sg)
{
	if(pmemo[i][val][sg] != -1)
	return pmemo[i][val][sg];
	int ans = 0;
	if(val >= 1)
	{	
		ans = ((ans%MOD) + (jacobian(i, val, sg)%MOD))%MOD;
		if(val > 1)
		ans = ((ans%MOD) + (pjacobian(i, val-1, sg)%MOD))%MOD;
	}	
	pmemo[i][val][sg] = ans;
	return ans;	
}

int jacobian(int i, int val, int sg)
{
	if(i == n+1)
	return 1;	
	if(memo[i][val][sg] != -1)
	return memo[i][val][sg];
	int ans = 0;
	if(arr[i] != -1)
	{
		if(i == 1)
		{	
			if(n != 1)
			ans = ((jacobian(i+1, arr[i], 0)%MOD) + (jacobian(i+1, arr[i], 1)%MOD))%MOD;
			else ans = jacobian(i+1, arr[i], 1)%MOD;
		}	
		else if((i > 1) && (i < n))
		{
			if(((val < arr[i]) && ((sg == 1) || (sg == 2))) || ((val == arr[i]) && ((sg == 0) || (sg == 2))) || ((val > arr[i]) && ((sg == 0) || (sg == 1))))
			ans = 0;
			else
			{
				if(!sg)
				ans = ((jacobian(i+1, arr[i], 0)%MOD) + (jacobian(i+1, arr[i], 1)%MOD))%MOD;
				else ans = ((((jacobian(i+1, arr[i], 0)%MOD) + (jacobian(i+1, arr[i], 1)%MOD))%MOD) + (jacobian(i+1, arr[i], 2)%MOD))%MOD;
			}			
		}
		else 
		{
			if((((val < arr[i]) && ((sg == 1) || (sg == 2))) || ((val == arr[i]) && ((sg == 0) || (sg == 2))) || ((val > arr[i]) && ((sg == 0) || (sg == 1)))) || (!sg))
			ans = 0;	
			else ans = jacobian(i+1, arr[i], 1)%MOD;
		}	
	}
	else
	{	
		if(i == 1)
		{	
			if(n != 1)
			ans = ((ans%MOD) + (((pjacobian(i+1, 200, 0)%MOD) + (pjacobian(i+1, 200, 1)%MOD))%MOD))%MOD;
			else ans = ((ans%MOD) + (pjacobian(i+1, 200, 1)%MOD))%MOD;
		}	
		else if((i > 1) && (i < n))
		{
			if(!sg)
			ans = ((ans%MOD) + (((((pjacobian(i+1, 200, 0)%MOD) - (pjacobian(i+1, val, 0)%MOD) + MOD)%MOD) + (((pjacobian(i+1, 200, 1)%MOD) - (pjacobian(i+1, val, 1)%MOD) + MOD)%MOD))%MOD))%MOD;
			else if(sg == 1)
			ans = ((ans%MOD) + (((((jacobian(i+1, val, 0)%MOD) + (jacobian(i+1, val, 1)%MOD))%MOD) + (jacobian(i+1, val, 2)%MOD))%MOD))%MOD;
			else ans = ((ans%MOD) + ((((pjacobian(i+1, val-1, 0)%MOD) + (pjacobian(i+1, val-1, 1)%MOD))%MOD) + (pjacobian(i+1, val-1, 2)%MOD))%MOD)%MOD;		
		}
		else 
		{
			if(!sg)
			ans = 0;	
			else if(sg == 1)
			ans = ((ans%MOD) + (jacobian(i+1, val, 1)%MOD))%MOD;
			else ans = ((ans%MOD) + (pjacobian(i+1, val-1, 1)%MOD))%MOD;
		}	
	}
	memo[i][val][sg] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	memset(pmemo, -1, sizeof(pmemo));
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	int ans = jacobian(1, 0, 1)%MOD;	
	std::cout<<ans<<"\n";
	return 0;	
}