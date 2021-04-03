#include <bits/stdc++.h>
#define pb push_back
#define MOD 1000000009
#define CHOR 300100

int fibx[CHOR], psfib[CHOR], v[CHOR];
int Z;

struct sq
{	
	int sum,a,b;
	bool upd;
};

struct qy
{
	int x,l,r;
};

sq block[550];

inline int add(int x, int y)
{
	int z = x + y;
	if(z > MOD)
	z -= MOD;
	return z;	
}

inline int sub(int x, int y)
{
	int z = x - y;
	if(z > MOD)
	z -= MOD;
	if(z < 0)
	z += MOD;
	return z;	
}

class sqrtdec
{
	public: void build(int n);
			void update(int l, int r);
			int query(int l, int r);
};

void sqrtdec::build(int n)
{
	for(int i=1;i<=n;i++)
	{	
		int t = i/Z;
		block[t].sum = add(block[t].sum, v[i]);
		block[t].a = 0;
		block[t].b = 0;
		block[t].upd = 0;
	}	
	return;	
}

void sqrtdec::update(int l, int r)
{
	int c_l = l/Z;
	int c_r = r/Z;
	if(c_l == c_r)
	{
		for(int i=l;i<=r;i++)
		{
			v[i] = add(v[i], fibx[i-l+1]);
			block[c_l].sum = add(block[c_l].sum, fibx[i-l+1]);
		}	
	}
	else 
	{
		for(int i=l,j=(c_l+1)*Z;i<j;i++)
		{
			v[i] = add(v[i], fibx[i-l+1]);
			block[c_l].sum = add(block[c_l].sum, fibx[i-l+1]);
		}	
		for(int i=c_l+1;i<c_r;i++)
		{
			block[i].sum = add(block[i].sum, sub(psfib[(i+1)*Z-l], psfib[i*Z-l]));
			block[i].a = add(block[i].a, fibx[i*Z-l+1]);
			block[i].b = add(block[i].b, fibx[i*Z-l+2]);
			block[i].upd = 1;
		}	
		for(int i=c_r*Z;i<=r;i++)
		{
			v[i] = add(v[i], fibx[i-l+1]);
			block[c_r].sum = add(block[c_r].sum, fibx[i-l+1]);
		}	
	}
	return;	
}

int sqrtdec::query(int l, int r)
{
	int c_l = l/Z;
	int c_r = r/Z;
	int sum = 0;
	if(c_l == c_r)
	{
		if(block[c_l].upd)
		{
			for(int i=c_l*Z,j=(c_l+1)*Z;i<j;i++)
			{	
				v[i] = add(v[i], block[c_l].a);
				int temp = block[c_l].b;
				block[c_l].b = add(block[c_l].b, block[c_l].a);
				block[c_l].a = temp;
			}	
			block[c_l].a = 0;
			block[c_l].b = 0;
			block[c_l].upd = 0;
		}	
		for(int i=l;i<=r;i++)
		sum = add(sum, v[i]);
	}
	else 
	{
		if(block[c_l].upd)
		{
			for(int i=c_l*Z,j=(c_l+1)*Z;i<j;i++)
			{	
				v[i] = add(v[i], block[c_l].a);
				int temp = block[c_l].b;
				block[c_l].b = add(block[c_l].b, block[c_l].a);
				block[c_l].a = temp;
			}	
			block[c_l].a = 0;
			block[c_l].b = 0;
			block[c_l].upd = 0;
		}	
		if(block[c_r].upd)
		{
			for(int i=c_r*Z,j=(c_r+1)*Z;i<j;i++)
			{	
				v[i] = add(v[i], block[c_r].a);
				int temp = block[c_r].b;
				block[c_r].b = add(block[c_r].b, block[c_r].a);
				block[c_r].a = temp;
			}	
			block[c_r].a = 0;
			block[c_r].b = 0;
			block[c_r].upd = 0;
		}	
		for(int i=l,j=(c_l+1)*Z;i<j;i++)
		sum = add(sum, v[i]);
		for(int i=c_l+1;i<c_r;i++)
		sum = add(sum, block[i].sum);
		for(int i=c_r*Z;i<=r;i++)
		sum = add(sum, v[i]);	
	}
	return sum;	
}

void fib()
{
	int a = 0;
	int b = 1;
	for(int i=1;i<CHOR;i++)
	{
		int temp = b;
		b = add(b, a);
		a = temp;
		fibx[i] = a;
		psfib[i] = add(psfib[i-1], fibx[i]);
	}	
	return;
}

int main(void)
{
	fib();
	sqrtdec T;
	int m,n;
	scanf("%d %d", &n, &m);
	Z = (int)floor(sqrt(CHOR));
	for (int i=1;i<=n;i++)
	scanf("%d", &v[i]);
	T.build(n);
	std::vector<qy> Q;
	while(m--) 	
	{
		int x,l,r;
		scanf("%d %d %d", &x, &l, &r);
		Q.pb({x, l, r});		
	}	
	for(int i=0,j=(int)Q.size();i<j;i++)
	{
		int x = Q[i].x;
		int l = Q[i].l;
		int r = Q[i].r;
		if(--x)
		printf("%d\n", T.query(l, r));
		else T.update(l, r);	
	}	
	return 0;
}
