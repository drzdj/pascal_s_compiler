#include "common.h"
#include "y.tab.h"

int main(){
	int tmp = 1;
	while(tmp){
		tmp = yylex();
		printf("%d\n", tmp);
	}
	return 0;
}