#include <bits/stdc++.h>
#define MOD 1000000007

/*  0 = NONE
	1 = A
	2 = G
	3 = AC
	4 = AG
	5 = GA
	6 = AT
	7 = ATG
	8 = AGT
	9 = AGG
	10 = ATGC
	11 = AGTC
	12 = AGGC
	13 = AGC
	14 = ACG
	15 = GAC
*/	

typedef long long ll;

int n;
ll memo[101][16];

ll MR0X(int i, int st)
{
	if(st == 10 || st == 11 || st == 12 || st == 13 || st == 14 || st == 15)
	return 0;
	if(i == n+1)
	return 1;
	if(memo[i][st] != -1)
	return memo[i][st];
	ll ans = 0;
	if(!st)
	ans = ((((((((ans%MOD) + (MR0X(i+1, 0)%MOD)%MOD)%MOD) + (MR0X(i+1, 0)%MOD))%MOD) + (MR0X(i+1, 1)%MOD))%MOD) + (MR0X(i+1, 2)%MOD))%MOD;
	else if(st == 1)
	ans = ((((((((ans%MOD) + (MR0X(i+1, 3)%MOD)%MOD)%MOD) + (MR0X(i+1, 4)%MOD))%MOD) + (MR0X(i+1, 6)%MOD))%MOD) + (MR0X(i+1, 1)%MOD))%MOD;
	else if(st == 2)
	ans = ((((((((ans%MOD) + (MR0X(i+1, 5)%MOD)%MOD)%MOD) + (MR0X(i+1, 0)%MOD))%MOD) + (MR0X(i+1, 0)%MOD))%MOD) + (MR0X(i+1, 2)%MOD))%MOD;
	else if(st == 3)
	ans = ((((((((ans%MOD) + (MR0X(i+1, 1)%MOD)%MOD)%MOD) + (MR0X(i+1, 0)%MOD))%MOD) + (MR0X(i+1, 0)%MOD))%MOD) + (MR0X(i+1, 14)%MOD))%MOD;
	else if(st == 4)
	ans = ((((((((ans%MOD) + (MR0X(i+1, 5)%MOD)%MOD)%MOD) + (MR0X(i+1, 8)%MOD))%MOD) + (MR0X(i+1, 13)%MOD))%MOD) + (MR0X(i+1, 9)%MOD))%MOD;
	else if(st == 5)
	ans = ((((((((ans%MOD) + (MR0X(i+1, 1)%MOD)%MOD)%MOD) + (MR0X(i+1, 6)%MOD))%MOD) + (MR0X(i+1, 15)%MOD))%MOD) + (MR0X(i+1, 4)%MOD))%MOD;	
	else if(st == 6)
	ans = ((((((((ans%MOD) + (MR0X(i+1, 0)%MOD)%MOD)%MOD) + (MR0X(i+1, 1)%MOD))%MOD) + (MR0X(i+1, 0)%MOD))%MOD) + (MR0X(i+1, 7)%MOD))%MOD;
	else if(st == 7)
	ans = ((((((((ans%MOD) + (MR0X(i+1, 0)%MOD)%MOD)%MOD) + (MR0X(i+1, 2)%MOD))%MOD) + (MR0X(i+1, 10)%MOD))%MOD) + (MR0X(i+1, 5)%MOD))%MOD;
	else if(st == 8)
	ans = ((((((((ans%MOD) + (MR0X(i+1, 11)%MOD)%MOD)%MOD) + (MR0X(i+1, 2)%MOD))%MOD) + (MR0X(i+1, 0)%MOD))%MOD) + (MR0X(i+1, 1)%MOD))%MOD;
	else if(st == 9)
	ans = ((((((((ans%MOD) + (MR0X(i+1, 2)%MOD)%MOD)%MOD) + (MR0X(i+1, 0)%MOD))%MOD) + (MR0X(i+1, 12)%MOD))%MOD) + (MR0X(i+1, 5)%MOD))%MOD;
	memo[i][st] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>n;
	ll ans = MR0X(1, 0)%MOD;
	std::cout<<ans<<"\n";
	return 0;
}