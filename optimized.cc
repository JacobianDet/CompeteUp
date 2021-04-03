#include <bits/stdc++.h>
#define exist(s, e) s.find(e) != s.end()
using namespace std;

const int NN=4e7;
int dp[NN];
int main() {
	memset(dp, 0x7f, sizeof(dp));
	int n; cin>>n;
	dp[0]=0; dp[1]=1;
	for(int i=2;i<=n;++i){
		dp[i]=min(dp[i], dp[i-1]+1);
		for(int j=i;j<=n && j<=1LL*i*i;j+=i)
			dp[j]=min(dp[j], dp[i]+1);
	}
	cout<<dp[n]<<endl;
}
