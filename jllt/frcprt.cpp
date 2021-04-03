#include <bits/stdc++.h>

int R[100], C[100];
std::string s[100];

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

int main(void)
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--)
    {
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));
        int n,m;
        std::cin>>n>>m;
        for(int i=0;i<n;i++)
        std::cin>>s[i];
        std::string Z;
        std::cin>>Z;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j] == '1')
                {
                    R[i]++;
                    C[j]++;
                }
            }
        }
        bool f = 0;
        if(Z[0] == 'L' || Z[0] == 'R')
        f = 1;
        char z1 = '#', z2 = '#';
        for(int i=0,j=(int)Z.size();i<j;i++)
        {
            if(Z[i] == 'L')
            z1 = 'L';
            else if(Z[i] == 'R')
            z1 = 'R';
            if(Z[i] == 'U')
            z2 = 'U';
            else if(Z[i] == 'D')
            z2 = 'D';
        }
        if(!f)
        {
            if(z2 == 'U')
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(C[j])
                        {
                            s[i][j] = '1';
                            C[j]--;
                        }
                        else s[i][j] = '0';
                    }
                }
                for(int i=0;i<n;i++)
                R[i] = 0;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(s[i][j] == '1')
                        R[i]++;
                    }
                }
                if(z1 != '#')
                {
                    if(z1 == 'L')
                    {
                        for(int j=0;j<m;j++)
                        {
                            for(int i=0;i<n;i++)
                            {
                                if(R[i])
                                {
                                    s[i][j] = '1';
                                    R[i]--;
                                }
                                else s[i][j] = '0';
                            }
                        }
                    }
                    else
                    {
                        for(int j=m-1;j>=0;j--)
                        {
                            for(int i=0;i<n;i++)
                            {
                                if(R[i])
                                {
                                    s[i][j] = '1';
                                    R[i]--;
                                }
                                else s[i][j] = '0';
                            }
                        }
                    }
                }
            }
            else
            {
                for(int i=n-1;i>=0;i--)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(C[j])
                        {
                            s[i][j] = '1';
                            C[j]--;
                        }
                        else s[i][j] = '0';
                    }
                }
                for(int i=0;i<n;i++)
                R[i] = 0;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(s[i][j] == '1')
                        R[i]++;
                    }
                }
                if(z1 != '#')
                {
                    if(z1 == 'L')
                    {
                        for(int j=0;j<m;j++)
                        {
                            for(int i=0;i<n;i++)
                            {
                                if(R[i])
                                {
                                    s[i][j] = '1';
                                    R[i]--;
                                }
                                else s[i][j] = '0';
                            }
                        }
                    }
                    else
                    {
                        for(int j=m-1;j>=0;j--)
                        {
                            for(int i=0;i<n;i++)
                            {
                                if(R[i])
                                {
                                    s[i][j] = '1';
                                    R[i]--;
                                }
                                else s[i][j] = '0';
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if(z1 == 'L')
            {
                for(int j=0;j<m;j++)
                {
                    for(int i=0;i<n;i++)
                    {
                        if(R[i])
                        {
                            s[i][j] = '1';
                            R[i]--;
                        }
                        else s[i][j] = '0';
                    }
                }
                for(int i=0;i<m;i++)
                C[i] = 0;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(s[i][j] == '1')
                        C[j]++;
                    }
                }
                if(z2 != '#')
                {
                    if(z2 == 'D')
                    {
                        for(int i=n-1;i>=0;i--)
                        {
                            for(int j=0;j<m;j++)
                            {
                                if(C[j])
                                {
                                    s[i][j] = '1';
                                    C[j]--;
                                }
                                else s[i][j] = '0';
                            }
                        }
                    }
                    else
                    {
                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<m;j++)
                            {
                                if(C[j])
                                {
                                    s[i][j] = '1';
                                    C[j]--;
                                }
                                else s[i][j] = '0';
                            }
                        }
                    }
                }
            }
            else
            {
                for(int j=m-1;j>=0;j--)
                {
                    for(int i=0;i<n;i++)
                    {
                        if(R[i])
                        {
                            s[i][j] = '1';
                            R[i]--;
                        }
                        else s[i][j] = '0';
                    }
                }
                for(int i=0;i<m;i++)
                C[i] = 0;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(s[i][j] == '1')
                        C[j]++;
                    }
                }
                if(z2 != '#')
                {
                    if(z2 == 'D')
                    {
                        for(int i=n-1;i>=0;i--)
                        {
                            for(int j=0;j<m;j++)
                            {
                                if(C[j])
                                {
                                    s[i][j] = '1';
                                    C[j]--;
                                }
                                else s[i][j] = '0';
                            }
                        }
                    }
                    else
                    {
                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<m;j++)
                            {
                                if(C[j])
                                {
                                    s[i][j] = '1';
                                    C[j]--;
                                }
                                else s[i][j] = '0';
                            }
                        }
                    }
                }
            }    
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            std::cout<<s[i][j];
            std::cout<<"\n";
        }
    }
    return 0;
}