#include "datastruct.h"
extern SymbolTable st;

void Brief(){
	printf("----------\n");
}

int main(){
	add_variable("x", "int"); //插入整型x
	add_variable("y", "int");//插入整型y
	add_function("gcd", "int", 2); //插入int函数 gcd 参数个数为2
	InsertBlock(); //定位
	add_para("gcd", "a", "int"); //添加整型参数a
	add_para("gcd", "b", "int");//添加整型参数b
	symboltable_print(st);//打印符号表
	Brief();
	PopBlock();//重定位
	symboltable_print(st); //打印符号表
	Brief(); 
	InsertBlock(); //定位
	add_procedure("read", 2); //加入过程read 参数个数为2
	add_procedure("write", 1);//加入过程write 参数个数为 1
	symboltable_print(st); //打印符号表
	Brief(); 
	PopBlock(); //重定向
	symboltable_print(st); //打印符号表
	Brief();
	vector<string> s;
	s.clear();
	s.push_back("int");
	//s.push_back("int");
	int flag = CheckType("gccd", s); //尝试检查ggcd函数和s是否匹配
	cout << "!!!!" << flag << endl;
	return 0;
}
