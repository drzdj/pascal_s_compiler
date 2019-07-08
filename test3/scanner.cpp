/*符号表
	program program
	const const
	var var
	function function
	procedure procedure
	begin begin
	end end
	if if
	then then
	else else
	while while
	do do
	call call
	read read
	write write
	integer integer
	real real
	char char
	boolean boolean
	or or 
	and and
	div div
	非关键字的标识符 id
	常数 num
	字符 char
	= relop EQ
	<> relop NE
	<= relop LE
	< relop LT
	>= relop GE
	> relop GT
	- addop -
	+ addop +
	* mulop *
	/ mulop /
	:= assignop 
	: COLON
	%token COLON 1 	:
%token LCIRCLE 2	(
%token RCIRCLE 3	)
%token LCUBE 4	[
%token RCUBE 5	]
%token SEMICOLON 6	；
%token POINT 7	.
%token COMMA 8	,
*/


#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "common.h"
#include "y.tab.h"
using namespace std;
//#define ILLEGAL_CHAR 0
//#define ERROR_OPERATOR 1
Position * pos = new Position();
myTYPE medret;
int errflag = 0;
FILE *fp = stdin;

string key[28] = 
{ "program","const","var","function","procedure","begin","end",
"for","if","then","else","while","to","do","of","call","read",
"write","integer","real","boolean","char","or","and","div","mod",
"not", "array"};
int getnbc(char ch);
int isDigit(char ch);
int isLetter(char ch);
int isKey(string arr);
int formatOutput(FILE* res, string s1, string s2);
void lexerror(){
	cerr<< "lexerror @ " + pos->view() << endl;
	return;
}


int yylex() {
	char ch;
	//FILE * res = fopen("lex_output.txt", "w+");
	FILE* res = stdout;
	if (res == NULL) return 1;
	//FILE * err = fopen("resulterr.txt", "w+");
	//if (err == NULL) return 1;
	//int line = 1;
	//int iswrong = 0;
	bool fflag = 0;
	while ((ch = fgetc(fp)) != EOF) {
		//fprintf(stderr, "???%c???\n", ch);
		string arr = "";
		if (ch == '\n') {
			pos->change("\n");
			continue;
		}
		else if(getnbc(ch)) {
			pos->sskip(ch);
			continue;
		}
		switch (ch) {
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':                                      //字母开头的判断
			while (isDigit(ch) || isLetter(ch)) {
				arr += ch;
				if ((ch = fgetc(fp)) == EOF)
					break;
			}
			if (ch != EOF)
				ungetc(ch, fp);
			int num;
			num = isKey(arr);
			if (num == 28) {
				pos->change(arr);
				return formatOutput(res, "id", arr);  //除关键字之外的字符串
			}
			else {
				pos->change(arr);
				return formatOutput(res, arr, arr);
			}
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':                             
			arr += ch;                    
			return formatOutput(res, "digit", arr);
			break;
		case '<':
			arr += ch;
			if ((ch = fgetc(fp)) == '=') {
				arr += ch;
				pos->change(arr);
				return formatOutput(res, "relop", "LE");
			}
			else if (ch == '>') {
				arr += ch;
				pos->change(arr);
				return formatOutput(res, "relop", "NE");
			}
			else {
				ungetc(ch, fp);
				pos->change(arr);
				return formatOutput(res, "relop", "LT");
			}
			break;
		case '>':
			arr += ch;
			if ((ch = fgetc(fp)) == '=') {
				arr += ch;
				pos->change(arr);
				return formatOutput(res, "relop", "GE");
			}
			else {
				ungetc(ch, fp);
				pos->change(arr);
				return formatOutput(res, "relop", "GT");
			}
			break;
		case ':':
			arr += ch;
			if ((ch = fgetc(fp)) == '=') {
				arr += ch;
				pos->change(arr);
				return formatOutput(res, "assignop", "AS");
			}
			else {
				ungetc(ch, fp);
				pos->change(arr);
				return formatOutput(res, ":", ":");
			}
			break;
		case ';':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, ";", ";");
			break;
		case '=':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, "relop", "=");
			break;
		case '\'':                                           //字符
			arr += ch;
			ch = fgetc(fp);
			arr += ch;
			ch = fgetc(fp);
			//arr += ch;
			if (ch == '\'') {
				arr += ch;
				pos->change(arr);
				return formatOutput(res, "chara", arr);
			}
			else {
				errflag = 1;
				while ((ch != ' ') && (ch != '\t') && (ch != '\n')) {
					arr += ch;
					ch = fgetc(fp);
				}
				ungetc(ch, fp);
				pos->change(arr);
				return formatOutput(res, "wrong", arr);
			}
				//error(ILLEGAL_CHAR, line, err);
			break;
		case '-':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, "addop", "-");
			break;
		case '*':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, "mulop", "*");
			break;
		case '(':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, "(", "(");
			break;
		case ')':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, ")", ")");
			break;
		case '[':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, "[", "[");
			break;
		case ']':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, "]", "]");
			break;
		case '{':
			arr += ch;
			ch = fgetc(fp);
			while (ch != '}') {
				arr += ch;
				ch = fgetc(fp);
			}
			arr += ch;
			pos->change(arr);
			break;
		case '.':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, ".", ".");
			break;
		case ',':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, ",", ",");
			break;
		case '+':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, "addop", "+");
			break;
		case '/':
			arr += ch;
			pos->change(arr);
			return formatOutput(res, "mulop", "/");
			break;
		default:
			arr += ch;
			pos->change(arr);
			return formatOutput(res, "wrong", arr);
			//error(ILLEGAL_CHAR, line, err);
			break;
		}
	}
	//fclose(res);
	//fclose(err);
	return 0;
}

int getnbc(char ch) {
	if (ch == ' ' || ch == '\t' || ch == '\r')
		return 1;
	else
		return 0;
}

int isDigit(char ch) {
	if (ch >= '0' && ch <= '9')
		return 1;
	else
		return 0;
}

int isLetter(char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return 1;
	else
		return 0;
}

int isKey(string arr) {
	int i;
	for (i = 0; i < 28; i++) {
		if (arr.compare(key[i]) == 0)
			break;
	}
	return i;
}

int formatOutput(FILE * res, string s1, string s2) {
	//if (code == 16 || code == 17) {
	//	fprintf(res, "%16s %2d\n", arr.c_str(), code);
	//}
	yylval.typ = s1;
	yylval.val = s2;
	fprintf(stderr, ">>>%s %s\n", s1.c_str(), s2.c_str());
	
	
	if (s1 == "program") {
		return PROGRAM;
	}
	else if (s1 == "const") {
		return CONST;
	}
	else if (s1 == "var") {
		return VAR;
	}
	else if (s1 == "function") {
		return FUNCTION;
	}
	else if (s1 == "procedure") {
		return PROCEDURE;
	}
	else if (s1 == "begin") {
		return BEGIN;
	}
	else if (s1 == "end") {
		return END;
	}
	else if (s1 == "for") {
		return FOR;
	}
	else if (s1 == "if") {
		return IF;
	}
	else if (s1 == "then") {
		return THEN;
	}
	else if (s1 == "else") {
		return ELSE;
	}
	else if (s1 == "while") {
		return WHILE;
	}
	else if (s1 == "to") {
		return TO;
	}
	else if (s1 == "do") {
		return DO;
	}
	else if (s1 == "of") {
		return OF;
	}
	else if (s1 == "call") {
		return CALL;
	}
	else if (s1 == "read") {
		return READ;
	}
	else if (s1 == "write") {
		return WRITE;
	}
	else if (s1 == "integer") {
		return INTEGER;
	}
	else if (s1 == "real") {
		return REAL;
	}
	else if (s1 == "boolean") {
		return (BOOLEAN);
	}
	else if (s1 == "char") {
		return CHAR;
	}
	else if (s1 == "or") {
		return RELOP;
	}
	else if (s1 == "and") {
		return RELOP;
	}
	else if (s1 == "div") {
		return MULOP;
	}
	else if (s1 == "id") {
		return ID;
	}
	else if (s1 == "digit") {
		return DIGIT;
	}
	else if (s1 == "chara") {
		return CHARA;
	}
	else if (s1 == "relop") {                    //??
		return RELOP;
	}
	else if (s1 == "addop") {                  //??
		return ADDOP;
	}
	else if (s1 == "mulop") {                       //
		return MULOP;
	}
	else if (s1 == "assignop") {                   //
		return ASSIGNOP;
	}
	else if (s1 == "relop") {
		return RELOP;
	}
	else if (s1 == ":") {
		return COLON;
	}
	else if (s1 == ";") {
		return SEMICOLON;
	}
	else if (s1 == "(") {
		return LCIRCLE;
	}
	else if (s1 == ")") {
		return RCIRCLE;
	}
	else if (s1 == "[") {
		return LCUBE;
	}
	else if (s1 == "]") {
		return RCUBE;
	}
	else if (s1 == ",") {
		return COMMA;
	}
	else if (s1 == ".") {
		return POINT;
	}
	else if (s1 == "mod") {
		return MULOP;
	}
	else if (s1 == "array"){
		return ARRAY;
	}
	else if (s1 == "not") {
		return NOT;
	}
	else{
		lexerror();
		return 0;
	}
}