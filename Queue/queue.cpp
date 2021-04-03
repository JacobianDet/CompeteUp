#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct node
{
    int adno;
    string name;
    node *next;
}*f,*r;

class queueman
{
  public: queueman()
          {
             f=r=nullptr;
          }
          void ins_node(int,string);
          void del_node();
          void traverse();

};
int main(void)
{
    system("cls");
    queueman z;
    char ch;
    int t,x;
    string y;
    do
    {
      system("cls");
      cout<<"Welcome to instant queue area. Select your choices:\n1. Insert node\n2. Delete node\n3. Traversal\n4. Exit\n";
      cin>>t;
      switch(t)
      {
         case 1:cout<<"Enter info\n";
                cin>>x;
                cin.ignore();
                getline(cin,y,'\n');
                z.ins_node(x,y);
                break;
         case 2:z.del_node();
                break;
         case 3:z.traverse();
                break;
         case 4:return 0;
      }
      cout<<"Do you wish to continue(Y/y)?";
      cin>>ch;
    }while(ch=='y'||ch=='Y');
    system("pause");
    return 0;
}
void queueman::ins_node(int x,string y)
{
    node *ptr=new node;
    ptr->adno=x;
    ptr->name=y;
    ptr->next=nullptr;
    if(f==nullptr)
    f=r=ptr;
    else
    {
        r->next=ptr;
        r=ptr;
    }
}
void queueman::del_node()
{
   if(f==nullptr)
   {
       cout<<"Underflow";
       return;
   }
   node *ptr=f;
   cout<<"Node to be deleted=";
   cout<<"\nAdmission no= "<<ptr->adno<<endl<<"Name= "<<ptr->name<<endl;
   if(f==r)
   f=r=nullptr;
   else f=ptr->next;
   delete ptr;
}
void queueman::traverse()
{
   if(f==nullptr)
   {
       cout<<"Underflow";
       return;
   }
   node *ptr=f;
   while(ptr!=nullptr)
   {
       cout<<"\nAdmission no= "<<ptr->adno<<endl<<"Name= "<<ptr->name<<endl;
       ptr=ptr->next;
   }
}


