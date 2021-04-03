#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define whoami(x) cerr<<#x<<" "<<x<<"\n";
#define mp make_pair
#define ins insert
#define sz size

void FLASH() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
void SETF() {cout.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV];
ll arr[MV];

void solve(int T)
{
  int n;
  cin>>n;
  string s = to_string(n);
  stack<int> S;
  int z = (int)s.sz();
  int ct = 1;
  for(int i=0;i<z;i++)
  {
    if(S.empty())
    S.push(i);
    else
    {
      if(!S.empty() && (ct > 0) && (s[S.top()] > s[i]))
      {
        ct--;
        S.pop();
      }
      S.push(i);
    }  
  }
  string res = "";
  while(ct)
  {
    ct--;
    S.pop();
  }  
  while(!S.empty())
  {
    res += s[S.top()];
    S.pop();
  }  
  while(!res.empty() and res.back() == '0'){
    res.pop_back();
  }
  reverse(res.begin(), res.end());
  if(res.sz() == 0)
  cout<<"0\n";	
  else cout<<res<<"\n";
  return;
}

int main(void)
{
  FLASH();
  int T;
  cin>>T;



  while(T--)
  solve(T);


  return 0;
}