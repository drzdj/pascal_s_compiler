#include "common.h"
#include "y.tab.h"

int main(int argc, char ** argv){
	if(argc > 1) freopen(argv[1], "r", stdin);
	if(argc > 2) freopen(argv[1], "r", stdin);
	int tmp = 1;
	while(tmp){
		tmp = yylex();
		cout << yylval.typ << ' ' << yylval.val << ' ';
		printf("%d\n", tmp);
	}
	return 0;
}