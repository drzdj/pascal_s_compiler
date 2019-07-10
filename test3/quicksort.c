#include <stdio.h>
const char bk=' ';
int a[101];
int n,i;
int partition(int l, int r)
{
int pivotkey,ll,rr;
pivotkey=a[l];
ll=l;
rr=r;
while(ll<rr)
{
while((a[rr]>pivotkey)&&(ll<rr))
{
rr=rr-1;
}
a[ll]=a[rr];
while((a[ll]<=pivotkey)&&(ll<rr))
{
ll=ll+1;
}
a[rr]=a[ll];
}
a[ll]=pivotkey;
return ll;
}
void quicksort(int l, int r)
{
int p;
if(l<r)
{
p=partition(l,r);
quicksort(l,p);
quicksort(p+1,r);
}
}
int main()
{
scanf("%d", &n);
for(i=1; i<=n; i++)
{
scanf("%d", &a[i]);
}
quicksort(1,n);
for(i=1; i<=n; i++)
{
printf("%d%c", a[i], bk);
}
return 0;
}
