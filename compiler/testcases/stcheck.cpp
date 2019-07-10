#include "datastruct.h"
extern SymbolTable st;

void Brief(){
	printf("----------\n");
}

int main(){
	add_variable("x", "int");
	add_variable("y", "int");
	add_function("gcd", "int", 2);
	InsertBlock();
	add_para("gcd", "a", "int");
	add_para("gcd", "b", "int");
	symboltable_print(st);
	Brief();
	PopBlock();
	symboltable_print(st);
	Brief();
	InsertBlock();
	add_procedure("read", 2);
	add_procedure("write", 1);
	symboltable_print(st);
	Brief();
	PopBlock();
	symboltable_print(st);
	Brief();
	vector<string> s;
	s.clear();
	s.push_back("int");
	//s.push_back("int");
	int flag = CheckType("gccd", s);
	cout << "!!!!" << flag << endl;
	return 0;
}