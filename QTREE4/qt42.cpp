#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define C ch=getchar()
#define INF 0x3f3f3f3f
#define N 200100
using namespace std;

int n,m,yun,bd,first[N],size[N],bb,so[N],dep[N],dz[N],top[N],fz[N],a[N],b[N],c[N],zx,deep[N];
bool vis[N],bla[N];
P sd[N],sb[N];
char ch;
struct Bn
{
    int to,next,quan;
} bn[N<<1];

struct Pq
{
    int s;
    priority_queue<int>a,b;
    void cle()
    {
        for(; !a.empty()&&!b.empty()&&a.top()==b.top(); a.pop(),b.pop());
    }
    void push(int u)
    {
        a.push(u);
        s++;
    }
    void del(int u)
    {
        b.push(u);
        s--;
    }
    int top()
    {
        cle();
        return a.top();
    }
    bool empty()
    {
        return !s;
    }
};
Pq pq[N][2],all;
vector<int>son[N],qn[N];

inline void add(int u,int v,int w)
{
    bb++;
    bn[bb].to=v;
    bn[bb].next=first[u];
    bn[bb].quan=w;
    first[u]=bb;
}

inline void ad(int u,int v,int w)
{
    add(u,v,w);
    add(v,u,w);
}

inline int ask(int u)
{
    if(pq[u][0].empty() || pq[u][1].empty()) return -INF;
    return pq[u][0].top()+pq[u][1].top()+c[u];
}

void dfs(int now,int last)
{
    int p,q;
    for(p=first[now]; p!=-1; p=bn[p].next)
    {
        if(bn[p].to==last) continue;
        son[now].push_back(bn[p].to);
        qn[now].push_back(bn[p].quan);
        dfs(bn[p].to,now);
    }
}

inline void rb()
{
    memset(first,-1,sizeof(first)),bb=1;
    int i,j,p,q;
    for(i=1; i<=n; i++)
    {
        if(son[i].size()<=2)
        {
            for(j=0; j<son[i].size(); j++)
            {
                ad(i,son[i][j],qn[i][j]);
            }
        }
        else
        {
            p=++n,q=++n;
            for(j=0; j<son[i].size(); j++)
            {
                if(j&1) son[p].push_back(son[i][j]),qn[p].push_back(qn[i][j]);
                else son[q].push_back(son[i][j]),qn[q].push_back(qn[i][j]);
            }
            son[i].clear(),qn[i].clear();
            son[i].push_back(p),son[i].push_back(q);
            qn[i].push_back(0),qn[i].push_back(0);
            ad(i,p,0),ad(i,q,0);
        }
    }
}

void gs(int now,int last)
{
    int p,q;
    size[now]=1;
    for(p=first[now]; p!=-1; p=bn[p].next)
    {
        if(vis[p>>1] || bn[p].to==last) continue;
        gs(bn[p].to,now);
        size[now]+=size[bn[p].to];
    }
}

P gr(int now,int last,int tot)
{
    int p,q;
    P res=mp(tot,0);
    for(p=first[now]; p!=-1; p=bn[p].next)
    {
        if(vis[p>>1] || bn[p].to==last) continue;
        res=min(res,gr(bn[p].to,now,tot));
        res=min(res,mp((int)abs(tot-size[bn[p].to]*2),(int)(p>>1)));
    }
    return res;
}

int d1(int now,int last)
{
    int p,q,res=1,mx=0,tmp;
    for(p=first[now]; p!=-1; p=bn[p].next)
    {
        if(bn[p].to==last) continue;
        fz[bn[p].to]=now;
        dz[bn[p].to]=dz[now]+1;
        dep[bn[p].to]=dep[now]+bn[p].quan;
        tmp=d1(bn[p].to,now);
        res+=tmp;
        if(tmp>mx)
        {
            mx=tmp;
            so[now]=bn[p].to;
        }
    }
    return res;
}

void d2(int now,int last)
{
    int p,q;
    if(!so[now]) return;
    else
    {
        top[so[now]]=top[now];
        d2(so[now],now);
    }
    for(p=first[now]; p!=-1; p=bn[p].next)
    {
        if(bn[p].to==last || bn[p].to==so[now]) continue;
        top[bn[p].to]=bn[p].to;
        d2(bn[p].to,now);
    }
}

inline int lca(int u,int v)
{
    for(; top[u]!=top[v];)
    {
        if(dz[top[u]]<dz[top[v]]) swap(u,v);
        u=fz[top[u]];
    }
    return dz[u]>dz[v]?v:u;
}

inline int len(int u,int v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}

void Dfs(int now,int last,bool bj)
{
    int p,q;
    if(now<=yun) pq[zx][bj].push(deep[now]),sd[now]=mp(zx,bj);
    for(p=first[now]; p!=-1; p=bn[p].next)
    {
        if(bn[p].to==last || vis[p>>1]) continue;
        deep[bn[p].to]=deep[now]+bn[p].quan;
        Dfs(bn[p].to,now,bj);
    }
}

void work(int now)
{
    int p,q;
    vis[now]=1;
    zx=now;
    deep[a[now]]=deep[b[now]]=0;
    Dfs(a[now],-1,0);
    Dfs(b[now],-1,1);

    gs(a[now],-1);
    p=gr(a[now],-1,size[a[now]]).se;
    if(p)
    {
        sb[p]=mp(now,0);
        work(p);
    }

    gs(b[now],-1);
    p=gr(b[now],-1,size[b[now]]).se;
    if(p)
    {
        sb[p]=mp(now,1);
        work(p);
    }
}

inline void xa(int u)
{
    P tmp;
    for(tmp=sd[u]; tmp.fi; tmp=sb[tmp.fi])
    {
        all.del(ask(tmp.fi));
        pq[tmp.fi][tmp.se].push(len(u,tmp.se?b[tmp.fi]:a[tmp.fi]));
    }
    for(tmp=sd[u]; tmp.fi; tmp=sb[tmp.fi])
    {
        all.push(ask(tmp.fi));
    }
}

inline void xd(int u)
{
    P tmp;
    for(tmp=sd[u]; tmp.fi; tmp=sb[tmp.fi])
    {
        all.del(ask(tmp.fi));
        pq[tmp.fi][tmp.se].del(len(u,tmp.se?b[tmp.fi]:a[tmp.fi]));
    }
    for(tmp=sd[u]; tmp.fi; tmp=sb[tmp.fi])
    {
        all.push(ask(tmp.fi));
    }
}

int main()
{
    memset(first,-1,sizeof(first));
    int i,j,p,q,o;
    cin>>n;
    yun=bd=n;
    for(i=1; i<n; i++)
    {
        scanf("%d%d%d",&p,&q,&o);
        ad(p,q,o);
    }
    for(i=1; i<=n; i++) son[i].clear();
    dz[1]=top[1]=1;
    dfs(1,-1);
    rb();
    d1(1,-1);
    d2(1,-1);
    for(i=2; i<=bb; i+=2)
    {
        a[i>>1]=bn[i].to;
        b[i>>1]=bn[i+1].to;
        c[i>>1]=bn[i].quan;
    }
    gs(1,-1);
    p=gr(1,-1,size[1]).se;
    work(p);
    for(i=2; i<=bb; i+=2)
    {
        all.push(ask(i>>1));
    }

    cin>>m;
    for(i=1; i<=m; i++)
    {
        for(C; ch!='A'&&ch!='C'; C);
        if(ch=='A')
        {
            if(!bd) puts("They have disappeared.");
            else if(bd==1) puts("0");
            else printf("%d\n",max(0,all.top()));
        }
        else
        {
            scanf("%d",&o);
            if(bla[o])
            {
                bd++;
                bla[o]=0;
                xa(o);
            }
            else
            {
                bd--;
                bla[o]=1;
                xd(o);
            }
        }
    }
}