#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string w;
        cin>>w;
        if(w.size() == 1)
        {
            cout<<"no answer"<<endl;
            continue;
        }
        int j=-1;
        for(int k=0,z=(int)w.size(); k<z-1; k++)
        {
            if(w[k] < w[k+1])
            j = k;
        }
        if(j == -1)
        {
            cout<<"no answer"<<endl;
            continue;
        }
        int m=j+1;
        for(int k=j+1,z=(int)w.size(); k<z; k++)
        {
            if(w[k] > w[j])
            m = k;
        }
        char temp = w[j];
        w[j] = w[m];
        w[m] = temp;
        sort(w.begin() + j + 1, w.end());
        cout<<w<<endl;
    }
    return 0;
}

