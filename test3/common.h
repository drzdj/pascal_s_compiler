#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <algorithm>                     
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

struct Position {
	int row, col;
	Position() { row = 1, col = 0; }
	void change(string s) {
		for(int len = s.size(), i = 0; i < len; i ++){
			if(s[i] == '\n') row ++, col = 0;
			else col ++;
		}
		return;
	}
	void sskip(char c) {
		if (c == ' ') col++;
		else if (c == '\t') col += 4;
		return;
	}
	string view(){
		return to_string(row) + ":" + to_string(col);
	}
	string view2(){
		return string("line: ") + to_string(row);
	}
};

struct myTYPE {
	string typ; //类型
	string val; //值
};
int yylex(void);
void yyerror(const char * s);

#define YYSTYPE myTYPE
#endif