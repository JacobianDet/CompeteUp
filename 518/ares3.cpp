#include <bits/stdc++.h>
#define MAXN 100000
#define INF 998244353

// SOURCE CODE BY Firastic

int n,arr[MAXN+5];
int dp[MAXN+5][205][2];
int prefix[MAXN+5][205][2];


int rekur(int now, int last, bool valid);

int get(int now, int x, bool valid){
    int &ret = prefix[now][x][valid];
    if(ret != -1)return ret;
    ret = 0;
    ret = rekur(now,x,valid);
    if(x < 200)ret += get(now,x+1,valid);
    ret %= INF;
    return ret;
}

int rekur(int now, int last, bool valid){
    if(now == n)return valid;
    if(now == n-1 and last < arr[now])return 0;
    if(!valid and arr[now] != -1 and arr[now] < last)return 0;
    int &ret = dp[now][last][valid];
    if(ret != -1)return ret;
    ret = 0;
    if(arr[now] != -1){
        if(last >= arr[now])ret = rekur(now+1,arr[now],1);
        else ret = rekur(now+1,arr[now],0);
    }
    else{
        if(!valid){
            ret += get(now+1,last+1,0)+rekur(now+1,last,1);
        } else {
            ret += get(now+1,1,1)-get(now+1,last+1,1);
            ret += get(now+1,last+1,0);
        }
    }
    ret %= INF;
    if(ret < 0)ret += INF;
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 200; j++){
            prefix[i][j][0] = -1;
            prefix[i][j][1] = -1;
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", rekur(0,0,1));
}