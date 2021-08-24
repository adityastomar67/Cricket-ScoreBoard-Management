#include<iostream>
#include<string>

using namespace std;

int main()
{
   string name[3];
   for (int i = 0; i < 3; i++)
   {
       cin>>name[i];
   }
   for (int i = 0; i < 3; i++)
   {
       cout<<name[i]<<endl;
   }
   
   return 0;
}