#include "common.h"
#include "y.tab.h"

int main(){
	freopen("testcase1.txt", "r", stdin);
	int tmp = 1;
	while(tmp){
		tmp = yylex();
		printf("%d\n", tmp);
	}
	return 0;
}