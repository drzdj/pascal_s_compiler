#ifndef DATASTRUCT
#define DATASTRUCT
#include "common.h"
//类型变量为string型, 合法值有 char, int, float, boolean, array, function, procedure
#define FAILED -1
#define NOT_MATCH -2
#define DIMENSION_ERROR -3
#define RIGHT 1
#define WRONG 0

struct Symbol{
	string name; //名字
	string type; //类型名
	string subtype; //数组元素类型 或 返回值类型
	int dimension; //维度
	bool isconst; //是否为常量
	bool isref; //是否为引用
	vector <Symbol> paralist; //函数的参数列表
	Symbol(){paralist.clear();}
	Symbol(string nam, string typ, string subtyp, int dim, bool isc, bool isr) : \
	name(nam), type(typ), subtype(subtyp), dimension(dim), isconst(isc), isref(isr){
		paralist.clear();
	}
};

struct SymbolTable{
	vector <int> Bstack; //块栈，存每个块起始符号的位置
	vector <Symbol> Sstack; //符号栈， 存储每个符号的信息
	SymbolTable(){
		Sstack.clear();
		Bstack.clear();
	}
};

string isValidType(string typ); 
//检查类型字符串是否合法, 非法类型返回 "null"
int FindSymbol(string name);
//在整个符号表中找符号Name的位置，不存在返回FAILED
int CheckSymbol(string name); 
//在当前域中检查是否存在name符号，返回在栈中位置，不存在为FAILED
int InsertSymbol(string name, string type, string subtype, int dimension, bool isconst, bool isref);
//插入符号，参数为对应属性值,成功时返回在符号栈中的位置，否则返回FAILED
int PopSymbol(); 
//弹出栈顶符号元素，成功弹出返回栈中剩余元素数，否则返回FAILED
int InsertBlock();
//定位,插入块,成功时返回插入后块的数量，否则返回FAILED
int PopBlock();
//重定位,删除块,会调用PopSymbol，成功时返回剩余块的数量，否则返回FAILED
int InsertParaSymbol(string funcname, string name ,string type, bool isconst, bool isref);
//插入参数符号，成功时返回在对应函数参数列表的位置, 若函数不存在返回FAILED，若参数超过限制返回NOT_MATCH
string GetType(string name);
//获得符号name的类型信息, 符号不存在返回"FAILED"
string GetSubType(string name);
//获得函数返回值或者数组元素的类型，符号不存在返回"FAILED"
int GetDimension(string name);
//获得函数或者数组的维度，符号不存在返回FAILED
int CheckConst(string name);
//判别符号name是否为const, 是常量时返回RIGHT，不是返回WRONG，不存在返回FAILED
int CheckReference(string funcname, string paraname);
//判别funcname函数中的paraname参数是否为引用类型, RIGHT代表是,WRONG代表不是，FAILED表示函数不存在， NOT_MATCH表示参数不存在
int CheckType(string funcame, vector<string> _type);
//判别funcname中的参数类型和给定的_type中的类型是否一一匹配，成功时返回RIGHT,维度不一样返回DIMENSION_ERROR，函数不存在返回FAILED，不匹配返回NOT_MATCH

#define add_variable(name, type) InsertSymbol(name, type, "null", 0, 0, 0);
#define add_const(name, type) InsertSymbol(name, type, "null", 0, 1, 0);
#define add_array(name, element_type, n) InsertSymbol(name, "array", element_type, n, 0, 0);
#define add_procedure(name, n) InsertSymbol(name, "procedure", "null", n, 0, 0);
#define add_function(name, return_type, n) InsertSymbol(name, "function", return_type, n, 0, 0);
#define add_para(funcname, name, type) InsertParaSymbol(funcname, name, type, 0, 0);
#define add_refpara(funcname, name, type) InsertParaSymbol(funcname, name, type, 1, 0);

//调试函数
void symbol_print(Symbol t);
void symboltable_print(SymbolTable t);
#endif