#include <stdio.h>
int x,y;
char t,z;
int gcd(int &a, int &b)
{
if(b==0)
{
return a;
}
else
{
return gcd(b,a%b);
}
}
int main()
{
scanf("%d%d", &x, &y);
printf("%d", gcd(x,y));
while(x==1){
x=x+1;
}
return 0;
}
