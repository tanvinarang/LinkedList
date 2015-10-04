#include<iostream>
using namespace std;
void check(int n);
int main()
{
int n;
//cin>>n;
check(16);

return 0;

}

void check(int n)
{

if(n<=0)
{
cout<<n<<" ";
return;
}
 else{
cout<<n<<" ";
check(n-5);

cout<<n<<" ";
}

}

