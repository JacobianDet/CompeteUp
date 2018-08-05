#include <bits/stdc++.h>
#define mp std::make_pair
#define MV 90001
#define LM 20

int readInt (void) {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar_unlocked();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

struct trip
{
    int x,y,id;
}L[MV];

bool cmp(trip a, trip b)
{
    return (a.x == b.x) ? ((a.y < b.y) ? 1 : 0) : ((a.x < b.x) ? 1 : 0);
}

int cord[26];
std::map<int, int> tz;
std::set<char> Z;
std::string s;
int SA[LM][MV];
int noz[MV];
int x;

class SAX
{
    public: void SA_build(int n);
            int LCP_find(int a, int b);
};

void counting_sort(int n)
{
    int count[MV+9];
    trip temp[n + 9];
    memset(count , 0 , sizeof count);

    for(int i = 0 ;i < n ; i++)
        count[L[i].y + 1]++;

    for(int i = 1 ; i  < MV ; i++)
        count[i] += count[i-1];

    for(int i = 0 ; i<n ; i++)
    {
        temp[count[L[i].y +1] - 1] = L[i];
        count[L[i].y + 1]--;
    }

    memset(count , 0 , sizeof count);

    for(int i = 0 ; i < n ; i ++)
        count[L[i].x + 1] ++;

    for(int i = 1 ; i<MV ; i++)
        count[i] += count[i-1];

    for(int i = n- 1; i>=0 ; i--)
    {
        L[count[temp[i].x + 1] - 1] = temp[i];
        count[temp[i].x + 1]--;
    }
}

void SAX::SA_build(int n)
{
    for(int i=0;i<n;i++)
    SA[0][i] = cord[s[i] - 'a'];
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            L[j].x = SA[i-1][j];
            L[j].y = (j + (1<<(i-1))) < n ? SA[i-1][j + (1<<(i-1))] : -1;
            L[j].id = j;
        }
        //std::sort(L, L+n, cmp);
        counting_sort(n);
        int u = 0;
        for(int j=0;j<n;j++)
        SA[i][L[j].id] = (j && (L[j].x == L[j-1].x) && (L[j].y == L[j-1].y)) ? SA[i][L[j-1].id] : u++;
    }
    return;
}

int SAX::LCP_find(int a, int b)
{
    int ans = 0;
    for(int k=x;k>=0;k--)
    {
        if(SA[k][a] == SA[k][b])
        {
            ans += (1<<k);
            a += (1<<k);
            b += (1<<k);
        }
    }
    return ans;
}

int bs1(int v, int n)
{
    int lo = 0;
    int hi = n-1;
    while(lo < hi)
    {
        int mid = lo + (hi - lo)/2;
        if(noz[mid] < v)
        lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main(void)
{
    memset(SA, -1, sizeof(SA));
    s = "";
    char c = getchar_unlocked();
    while(true)
    {
        if(c < 'a' || c > 'z')
        break;
        s += c;
        c = getchar_unlocked();
    }
    int n = (int)s.size();
    for(int i=0;i<n;i++)
    Z.insert(s[i]);
    int u = 0;
    for(std::set<char>::iterator it = Z.begin();it != Z.end();it++)
    cord[(*it) - 'a'] = u++;
    for(x=0;(1<<x)<=n;x++);
    SAX T;
    T.SA_build(n);
    std::set<std::pair<int, int> > V;
    for(int i=0;i<n;i++)
    V.insert(mp(SA[x][i], i));
    std::vector<std::pair<int, int> > VT(V.begin(), V.end());
    for(int i=0,j=(int)VT.size();i<j;i++)
    {
        if(i)
        noz[i] = noz[i-1] + (n - VT[i].second) - T.LCP_find(VT[i].second, VT[i-1].second);
        else noz[i] = (n - VT[i].second);
    }
    int m = (int)VT.size();
    int q;
    q = readInt();
    while(q--)
    {
        int v;
        v = readInt();
        if(v > 0 && v < (1LL<<31))
        {
            if(tz[v])
            {
                int p = tz[v];
                for(int i=0;i<((n - VT[p].second) - (noz[p] - v));i++)
                printf("%c", s[VT[p].second + i]);
                printf("\n");
            }
            else
            {
                int p = bs1(v, m);
                for(int i=0;i<((n - VT[p].second) - (noz[p] - v));i++)
                printf("%c", s[VT[p].second + i]);
                printf("\n");
                tz[v] = p;
            }
        }
    }
    return 0;
}
