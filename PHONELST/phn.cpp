#include <bits/stdc++.h>
#define DG 10

std::string P[10000];

struct trieman
{
	trieman *next[DG];
	bool ex;
};

class trie
{
	public: trieman* create(void);
			void insert(trieman* root, std::string key);
			bool search(trieman* root, std::string key);
			void delx(trieman* root, std::string key, int i);
			bool dfs_visit(trieman* root);
			void freex(trieman* root);
};

trieman* trie::create(void)
{
	trieman *vfx = new trieman;
	vfx->ex = 0;
	for(int i=0;i<DG;i++)
	vfx->next[i] = NULL;
	return vfx;
}

void trie::insert(trieman* root, std::string key)
{
	trieman *vfx = root;	
	for(int i=0,j=(int)key.size();i<j;i++)
	{
		int ind = key[i] - '0';
		if(!vfx->next[ind])
		vfx->next[ind] = create();
		vfx = vfx->next[ind];
	}	
	vfx->ex = 1;
	return;
}

bool trie::search(trieman* root, std::string key)
{	
	trieman *vfx = root;
	for(int i=0,j=(int)key.size();i<j;i++)
	{
		int ind = key[i] - '0';
		if(!vfx->next[ind])
		return 0;
		vfx = vfx->next[ind];	
	}
	return (vfx->ex);
}

bool trie::dfs_visit(trieman* root)
{
	int ctx = 0;
	bool ok = 1;
	for(int i=0;i<DG;i++)
	{
		if(root && root->next[i])
		{	
			ctx++;
			ok &= dfs_visit(root->next[i]);
		}		
	}	
	if(ok && root && root->ex && ctx)
	ok = 0;	
	return ok;
}

void trie::delx(trieman* root, std::string key, int i)
{
	if(i == (int)key.size())
	root->ex = 0;
	else if(root->next[key[i] - '0'])
	delx(root->next[key[i] - '0'], key, i+1);
	int ctx = 0;
	for(int j=0;j<DG;j++)
	{
		if(!root->next[i])
		ctx++;
	}	
	if(ctx == DG)
	delete root;	
	return;
}

void trie::freex(trieman* root)
{	
	for(int i=0;i<DG;i++)
	{	
		if(root->next[i])
		freex(root->next[i]);
	}
	delete root;
	return;	
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		std::cin>>P[i];
		trie D;
		trieman *root = D.create();
		for(int i=0;i<n;i++)
		D.insert(root, P[i]);
		bool ok = D.dfs_visit(root);
		if(ok)
		std::cout<<"YES\n";
		else std::cout<<"NO\n";
		D.freex(root);			
	}
	return 0;
}