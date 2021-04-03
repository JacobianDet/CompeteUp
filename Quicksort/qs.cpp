#include <iostream>
#include <cstdlib>
void quicksort(int *,int,int);
int main(void)
{
  system("cls");
  int a[100],n;
  std::cout<<"Enter n\n";
  std::cin>>n;
  for(auto i=0;i<n;i++)
  {
    std::cout<<"Enter element\n";
    std::cin>>a[i];
    std::cout<<std::endl;
  }
  quicksort(a,0,n-1);
  std::cout<<"Sorted array\n";
  for(auto i=0;i<n;i++)
  std::cout<<a[i]<<" ";
  system("pause");
  return 0;
}

void quicksort(int *a,int beg,int las)
{
  int piv,p;
  p=beg+(las-beg)/2;
  piv=a[p];
  if(beg<las)
  {
    for(auto i=p+1;i<=las;i++)
    {
      if(a[i]<=piv)
      for(auto j=i;j>p;j--)
      {
        a[j]=a[j]+a[j-1];
        a[j-1]=a[j]-a[j-1];
        a[j]=a[j]-a[j-1];
        if(j-1==p)
        p=j;
      }
    }
    for(auto i=p-1;i>=beg;i--)
    {
      if(a[i]>piv)
      for(auto j=i;j<p;j++)
      {
        a[j]=a[j]+a[j+1];
        a[j+1]=a[j]-a[j+1];
        a[j]=a[j]-a[j+1];
        if(j+1==p)
        p=j;
      }
    }
    quicksort(a,beg,p-1);
    quicksort(a,p+1,las);
  }
}
