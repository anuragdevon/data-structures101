#include<iostream>
#include<math.h>
using namespace std;
int main()
{
 long long int n,num,sum=0,i=0;
 cin>>n;
 num=n;
 for(;n;i++)
  n/=10;
 n=num;
 while(n)
 {
  long long int x=n%10;
  n/=10;
  x=pow(x, i);
  sum+=x;
 }
 if(sum==num)
  cout<<"It's is a Armstrong Number\n";
 else
  cout<<"It's is a not Armstrong Number\n";
}
