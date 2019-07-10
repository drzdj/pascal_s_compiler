#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
int main(){
	cin >> n;
	for(int x, i = 1; i <= n; i ++)
		scanf("%d", &x), a.push_back(x);
	sort(a.begin(), a.end());
	for(auto p: a)
		printf("%d ", p);
	return 0;
}