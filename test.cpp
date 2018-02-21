#include <iostream>
#include <cmath>
using namespace std;

int main() {
int a[ 10 ]; // a is an array.
int i,j,t;
for(i=0;i<10;i++)
	cin>>a[ i ];
cout<<endl;
for(i=0;i<9;i++)
{
for(j=i+1;j<10;j++)
{
if(a[ i ]<  a[j])
{
t=a[ i ];
a[i]=a[j];
a[j]=t;
}
}
}
cout<<"the sorted array is:"<<endl;
for(i=0;i<10;i++)
{
cout<<a[ i ]<<" ";
}
cout<<endl;
return 0;
}
