#include "datastruct.h"

SymbolTable st; //真正使用的一个symboltable
string validtypes[] = {"int", "char", "float", "boolean", "array", "function", "procedure"};

//调试输出函数
void symbol_print(Symbol t){
	cout << t.name << ' ' << t.type << ' ' << t.subtype << ' ' << t.dimension << ' ' << t.isconst << ' ' << t.isref << endl;
	if(t.type == "function" || t.type == "procedure"){
		cout << "paralist:" << endl;
		for(auto p: t.paralist)
			cout << "<" << p.name << ", " << p.type << ", " << p.isref << "> ";
		cout << endl;
	}
	return;
}

void symboltable_print(SymbolTable t){
	cout << "SymbolStack:<<" << endl;
	for(auto p: t.Sstack)
		symbol_print(p);
	cout << "BlockStack:<<" << endl;
	for(auto p: t.Bstack)
		cout << p << ' ';
	cout << endl;
	return;
}

//检查类型字符串是否合法, 非法类型返回 "null"
string isValidType(string typ){
	for(int i = 0; i < 7; i ++)
		if(typ == validtypes[i]) return typ;
	return "null";
}

// 在整张符号表中查询是否存在符号name,存在返回位置，否则返回FAILED
int FindSymbol(string name){
	for(int i = (int)st.Sstack.size() - 1; i >= 0; i --)
		if(st.Sstack[i].name == name) return i;
	return FAILED;
}

// 检查是否存在name符号，返回在栈中位置，不存在为FAILED
int CheckSymbol(string name){
	int lb = 0;
	if(st.Bstack.size()) lb = st.Bstack[st.Bstack.size() - 1];
	for(int i = (int)st.Sstack.size() - 1; i >= lb; i --)
		if(st.Sstack[i].name == name) return i;
	return FAILED;
}

//插入符号，参数为对应属性值,成功时返回在符号栈中的位置，否则返回FAILED
int InsertSymbol(string name, string type, string subtype, int dimension, bool isconst, bool isref){
	if(CheckSymbol(name) != FAILED) return FAILED; //符号已经存在
	Symbol t = Symbol(name, type, subtype, dimension, isconst, isref);
	st.Sstack.push_back(t);
	return st.Sstack.size() - 1;
}

//弹出栈顶符号元素，成功弹出返回栈中剩余元素数，否则返回FAILED
int PopSymbol(){
	if(!st.Sstack.size()) return FAILED; //栈为空，不可再弹出
	st.Sstack.pop_back();
	return st.Sstack.size();
}

//定位,插入块, 成功时返回插入后块的数量，否则返回FAILED
int InsertBlock(){
	//if(InsertSymbol(name, type, subtype, dimension, isconst, isref) == FAILED) return FAILED; //符号已经存在
	if(st.Sstack.size() == 0) return FAILED; //符号栈空无法作为块的起点
	st.Bstack.push_back(st.Sstack.size() - 1); // 当前块的起点是刚刚插入的符号的位置
	return st.Bstack.size();
}

//重定位,删除块,会调用PopSymbol，成功时返回剩余块的数量，否则返回FAILED
int PopBlock(){
	if(!st.Bstack.size()) return FAILED; //已经没有块了无法弹出
	while(st.Sstack.size() && st.Sstack.size() - 1 != st.Bstack[st.Bstack.size() - 1]) PopSymbol();
	st.Bstack.pop_back();
	return st.Bstack.size();
}

//插入参数符号，成功时返回在对应函数参数列表的位置, 若失败返回FAILED
int InsertParaSymbol(string funcname, string name ,string type, bool isconst, bool isref){
	int func_pos = CheckSymbol(funcname), pos; 
	if(func_pos == FAILED) return FAILED; //函数不存在
	if(st.Sstack[func_pos].paralist.size() == st.Sstack[func_pos].dimension) return NOT_MATCH;//函数参数已经足够，无法再添加元素
	pos = InsertSymbol(name, type, "null", 0, isconst, isref); //尝试插入参数到符号表
	if(pos == FAILED) return FAILED; //参数已经存在了
	st.Sstack[func_pos].paralist.push_back(st.Sstack[pos]);
	return st.Sstack[func_pos].paralist.size() - 1;
}

//获得符号name的类型信息, 符号不存在返回"FAILED"
string GetType(string name){
	int pos = FindSymbol(name);
	if(pos == FAILED) return "FAILED";
	return st.Sstack[pos].type;
}

//获得函数返回值或者数组元素的类型，符号不存在返回"FAILED"
string GetSubType(string name){
	int pos = FindSymbol(name);
	if(pos == FAILED) return "FAILED";
	return st.Sstack[pos].subtype;
}

//获得函数或者数组的维度，符号不存在返回FAILED
int GetDimension(string name){
	int pos = FindSymbol(name);
	if(pos == FAILED) return FAILED;
	return st.Sstack[pos].dimension;
}

//判别符号name是否为const, 是常量时返回RIGHT，不是返回WRONG，不存在返回FAILED
int CheckConst(string name){
	int pos = FindSymbol(name);
	if(pos == FAILED) return FAILED;
	if(st.Sstack[pos].isconst) return RIGHT;
	return WRONG;
}

//判别funcname函数中的paraname参数是否为引用类型, RIGHT代表是,WRONG代表不是，FAILED表示函数不存在， NOT_MATCH表示参数不存在
int CheckReference(string funcname, string paraname){
	int func_pos = FindSymbol(funcname);
	if(func_pos == FAILED) return FAILED;
	int pos = -1;
	for(int i = 0; i < st.Sstack[func_pos].paralist.size(); i ++)
		if(st.Sstack[func_pos].paralist[i].name == paraname) {pos = i; break;}
	if(pos == -1) return NOT_MATCH;
	if(st.Sstack[func_pos].paralist[pos].isref) return RIGHT;
	return WRONG;
}

//判别funcname中的参数类型和给定的_type中的类型是否一一匹配，成功时返回RIGHT,维度不一样返回DIMENSION_ERROR，函数不存在返回FAILED，不匹配返回NOT_MATCH
int CheckType(string funcname, vector<string> _type){
	int func_pos = FindSymbol(funcname);
	if(func_pos == FAILED) return FAILED; //未找到对应函数
	if(st.Sstack[func_pos].paralist.size() != _type.size()) return DIMENSION_ERROR; //维度不正确
	for(int i = 0; i < _type.size(); i ++)
		if(st.Sstack[func_pos].paralist[i].type != _type[i]) return NOT_MATCH;
	return RIGHT;
}
