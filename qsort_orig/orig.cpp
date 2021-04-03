#include <iostream>
#include <cstdlib>
void quicksort(int *,int,int);
int main(void)
{
  system("cls");
  int a[100],n;
  std::cout<<"Enter n\n";
  std::cin>>n;
  for(int i=0;i<n;i++)
  {
    std::cout<<"Enter element\n";
    std::cin>>a[i];
    std::cout<<std::endl;
  }
  quicksort(a,0,n-1);
  std::cout<<"Sorted array\n";
  for(int i=0;i<n;i++)
  std::cout<<a[i]<<" ";
  std::cout<<std::endl;
  system("pause");
  return 0;
}

void quicksort(int *a,int beg,int las)
{
  int piv,p,t;
  if(beg>=las)
  {
    return;
  }
    p=beg+(las-beg)/2;
    piv=a[p];
    t=a[las];
    a[las]=a[p];
    a[p]=t;
    p=beg-1;
    for(int j=beg;j<las;j++)
    {
      if(a[j]<=piv)
      {
        p++;
        t=a[p];
        a[p]=a[j];
        a[j]=t;
      }
    }
    p++;
    t=a[las];
    a[las]=a[p];
    a[p]=t;
    quicksort(a,beg,p-1);
    quicksort(a,p+1,las);
}
