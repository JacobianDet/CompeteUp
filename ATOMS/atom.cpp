#include <bits/stdc++.h>

typedef long ln;

int ma[2000], ka[2000], na[2000], axe[2000], res[2000], c[2000];
int md, kd, nd, lv;

ln readL (void) {
	bool minus = false;
	ln result = 0;
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

void NMUL(int a[2000], int& as, int b[2000], int& bs)
{
    int cs=0;
	memset(c, 0, sizeof(c));
	int temp = 0;
	for(int i=0;i<bs;i++)
	{
		for(int j=0;j<as;j++)
		{
			int x = b[i]*a[j] + c[i+j] + temp;
			c[i+j] = x%10;
			temp = x/10;
		}
        int d = 0;
        while(temp)
        {
            int x = c[i+as+d] + temp;
            c[i+as+d] = x%10;
            temp = x/10;
            d++;
        }
        temp = 0;
	}
	cs = 2000;
	for(int i=1999;i>=0;i--)
	{
		if(c[i])
		break;
		else cs--;
	}
	as = cs;
	for(int i=0;i<2000;i++)
	a[i] = c[i];
	return;
}

void BNEXP(int a[2000], int& an, int n)
{
    memset(res, 0, sizeof(res));
    res[0] = 1;
    int rsz = 1;
    while(n)
    {
        if(n & 1)
        NMUL(res, rsz, a, an);
        NMUL(a, an, a, an);
        n >>= 1;
    }
    for(int i=0;i<2000;i++)
    a[i] = res[i];
    an = rsz;
    return;
}

bool cmpx(int axe[2000], int an, int mid)
{
    bool v = 0;
    BNEXP(axe, an, mid);
    NMUL(axe, an, na, nd);
    for(int i=std::max(an-1, md-1);i>=0;i--)
    {
        if(axe[i] > ma[i])
        {
            v = 1;
            break;
        }
        else if(axe[i] < ma[i])
        {
            v = 0;
            break;
        }
    }
    return v;
}

int bs2(void)
{
    int lo = 0;
    int hi = lv;
    int an = 0;
    while(lo < hi)
    {
        for(int i=0;i<2000;i++)
        axe[i] = ka[i];
        an = kd;
        int mid = lo + (hi - lo + 1)/2;
        if(cmpx(axe, an, mid))
        hi = mid - 1;
        else lo = mid;
    }
    return lo;
}

int main(void)
{
    ln T;
    T = readL();
    while(T--)
    {
        memset(ma, 0, sizeof(ma));
        memset(ka, 0, sizeof(ka));
        memset(na, 0, sizeof(na));
        ln n,k,m;
        n = readL();
        k = readL();
        m = readL();
        lv = (log((long double)m/n)/log((long double)k));
        md = 0, kd = 0, nd = 0;
        ln temp = m;
        while(temp)
        {
            ma[md] = (temp%10);
            temp /= 10;
            md++;
        }
        temp = k;
        while(temp)
        {
            ka[kd] = (temp%10);
            temp /= 10;
            kd++;
        }
        temp = n;
        while(temp)
        {
            na[nd] = (temp%10);
            temp /= 10;
            nd++;
        }
        int tx = bs2();
        printf("%d\n", tx);
    }
    return 0;
}
