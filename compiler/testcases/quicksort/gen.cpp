#include<bits/stdc++.h>
using namespace std;
int n;
double r(){return 1.0 * rand()/ RAND_MAX;}
int R(int x) {return r() * x;}
int main(){
    srand(time(0));
    n = 100;
    printf("%d\n", n);
    for(int i = 0; i < n; i++)
            printf("%d ", R(100));
    return 0;
}
