#include <stdio.h>
int x,y;
char t,z;
int gcd(int &a, int &b, char c, char d)
{
if(b==0)
{
return a;
}
else
{
return gcd(b,a%b,c,d);
}
}
int main()
{
scanf("%d%d", &x, &y);
printf("%d", gcd(x,y,t,z));
return 0;
}
