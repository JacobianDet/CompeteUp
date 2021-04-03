#include <iostream>
using namespace std;
void sort(int values[], int n)
{
    // TODO: implement an O(n) sorting algorithm
    int large,temp[n];
    large=values[0];
    for(int i=0;i<n;i++)
    {
        if(values[i]>large)
        large=values[i];
    }
    int coS[large+1];
    for(int i=0;i<large+1;i++)
    coS[i]=0;
    for(int i=0;i<n;i++)
    coS[values[i]]++;
    for(int i=1;i<large+1;i++)
    coS[i]+=coS[i-1];
    for(int i=n-1;i>=0;i--)
    {
        temp[coS[values[i]]-1]=values[i];
        coS[values[i]]--;
    }
    for(int i=0;i<n;i++)
    values[i]=temp[i];
    return;
}
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int beg,mid,las;
    beg=0;
    las=n-1;
    while(beg<=las)
    {
        mid=beg+(las-beg)/2;
        if(values[mid]==value)
        return true;
        else if(values[mid]<value)
        beg=mid+1;
        else las=mid-1;
    }
    return false;
}
int main(void)
{
    int a[100];
    cout<<"\nEnter n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter element

    }

}
