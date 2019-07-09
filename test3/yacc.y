/*说明部分*/
/*
%{
头文件表
宏定义
数据类型定义
全局变量定义	
}
*/
%code{
#include "common.h"
#include "datastruct.h"
extern Position * pos;

/*chenrui*/
int dimen = 0; //变量的维度
string array_num; //数组变量的范围，如 a[10][10]

int id_num = 0;//存储需要加入符号表的变量数量
string[] id_name = new string[100];//存储需要加入符号表的变量名称
int array_flag = 0;//是否有数组变量
string var_name;//变量名称

string const_id;//常量变量的名称

/*chenrui*/

%}

/*
语法开始符定义：没有设定，默认为语法规则第一条的programstruct
语义值类型定义：
终结符定义
运算符优先级及结合性定义
*/
%token COLON 1
%token LCIRCLE 2
%token RCIRCLE 3
%token LCUBE 4
%token RCUBE 5
%token SEMICOLON 6
%token POINT 7
%token COMMA 8
%token DIGIT 9
%token PROGRAM 201
%token CONST 202
%token VAR 203
%token FUNCTION 204
%token PROCEDURE 205
%token BEGIN 206
%token END 207
%token FOR 208
%token IF 209
%token THEN 210
%token ELSE 211
%token WHILE 212
%token TO 213
%token DO 214
%token OF 215
%token CALL 216
%token READ 217
%token WRITE 218
%token INTEGER 219
%token REAL 220
%token BOOLEAN 221
%token CHAR 222
%token OR 223
%token AND 224
%token DIV 225
%token ID 226
%token CHARA 229
%token RELOP 230
%token ADDOP 231
%token MULOP 232
%token ASSIGNOP 233
%token MOD 234
%token ARRAY 235
%token NOT 236

%left RELOP
%left ADDOP
%left MULOP

%%

/*语法规则部分*/

programstruct:

/*程序总体*/
program_head SEMICOLON program_body POINT {
/* 1. programstruct -> program_head; program_body. */
		cout << $$.val;
		cout << "compile complete" << endl;
	}
	;

program_head:
/*2. program_head -> program id 无参数*/
	PROGRAM ID {
//pascal中的program无实际含义
	} 
	| 	
	PROGRAM ID LCIRCLE idlist RCIRCLE {
/*3. program_head -> program id(idlist) 有参数*/
//pascal中的program无实际含义
	}
	;

program_body:	
	const_declarations 
	var_declarations 
	subprogram_declarations 
	compound_statement {
/*4. program_body -> const_declarations var_declarations subprogram_declarations compound_statement*/
		$$.val = $1.val + $2.val + $3.val + $4.val;
	}
	;

idlist:	
/*5. idlist -> idlist, id*/
	idlist COMMA ID {
		id_name[id_num] = $3.val;
		id_num++;
		var_name.append(",");
		var_name.append($3.val);
	}
	|ID {
/*6. idlist -> id*/
		id_name[id_num] = $1.val;
		id_num++;
		var_name = $1;
	}
	;

/*常量定义*/
const_declarations:	
	CONST const_declaration SEMICOLON{
/*7. const_declarations -> const const_declaration; */
		$$.val = "const" + " " + $2.val + ";";
	}
	|{

/*8. const_declarations -> 空*/
	}
	;	

const_declaration:	
	const_declaration SEMICOLON ID RELOP const_value { 
// 只有relop为=时才可以归约
/*9. const_declaration -> const_declaration; id = const_value*/
		const_id = $3.val;
		if (add_const(const_id, $5.type) == FAILED){
			yyerror($3);
		}
		$$.val = $1.val + "," + $5.type + " " + $3.val + "=" + $5.val;
	}
	|ID RELOP const_value { 
//同上
/*10. const_declaration -> id = const_value*/
		const_id = $1.val;
		if (add_const(const_id, $3.type) == FAILED){
			yyerror($3);
		}
		$$.val = $3.type + ' ' + $1.val + "=" + $3.val;
	}
	;

const_value:	
	ADDOP num{ 
/*11. const_value -> ADDOP num*/
		if ($$.val == "-"){
			$$.type = $2.type;
			$$.val = "-" + $2.val;
		}

		if ($$.val == "+"){
			$$.type = $2.type;
			$$.val = "+" + $2.val;
		}
	}
	|num {
/*12. const_value -> num*/
		$$.type = $1.type;
		$$.val = $1.val;
	}
	|CHARA { 
/*13. const_value -> 'letter'*/
// 单个字符，注意在翻译时加上两侧的单引号
		$$.type = "char";
		$$.val = "\'" + $1.val + "\'";
	}
	;


//变量定义
var_declarations:	
	
	VAR var_declaration SEMICOLON
	{
/*14. var_declarations -> var var_declaration; */
		$$.val = $2.val + ";/n";
	}
	|{
/*15. var_declarations -> 空*/
	}
	;

var_declaration:	
	var_declaration SEMICOLON idlist COLON type 
	{
/*16. var_declaration -> var_declaration; idlist : type*/
		$$.val = $1.val;	
		if (array_flag == 0){
			$$.val = $5.val + " " + var_name;
		}
		else {
			string[] tmp = var_name.split(",");
			for (int i = 0; i < tmp.length; i++){
				$$.val = $5.type + " " + tmp[i] + array_num;
			}
			array_flag = 0;
		}
	}
	|idlist COLON type 
	{
/*17. var_declaration -> idlist : type*/
//是否存在数组元素，不存在则较为方便，存在数组元素则需要转换顺序的语义动作
		if (array_flag == 0){
			$$.val = $3.val + " " + var_name;
		}
		else {
			string[] tmp = var_name.split(",");
			for (int i = 0; i < tmp.length; i++){
				$$.val = $3.type + " " + tmp[i] + array_num;
			}
			array_flag = 0;
		}
	}
	;

type:	
	basic_type {
/*18. type -> basic_type*/
		$$.type = $1.type;
		if (array_flag == 0){
			for (int i = 0; i < id_num; i++){
				if (add_variable(id_name[i], $$.type) == FAILED){
					yyerror(id_name[i]);
				}
			}
		}
		dimen = 0;
	}
	|ARRAY LCUBE period RCUBE OF basic_type {
/*19. type -> array [period] of basic_types*/
		$$.type = $6.type;
		array_flag = 1;
		for (int i = 0; i < id_num; i++){
			if (add_array(id_name[i], $6.type, dimen) == FAILED){
				yyerror(id_name[i]);
			}
		}
		dimen = 0;
	}
	;

/*basic_type没有语义动作，直接规约即可*/
basic_type:	
	INTEGER {
/*20. basic_type -> integer*/
		$$.type = "int";
	}
	|REAL {
/*21. basic_type -> real*/
		$$.type = "float";
	}
	|BOOLEAN {
/*22. basic_type -> boolean*/
		$$.type = "bool";
	}
	|CHAR {
/*23. basic_type -> char */
		$$.type = "char";
	}
	;

period:	
	period COMMA digits POINT POINT digits 
	{ 
/*24. period -> period, num .. num */
/*将period, num .. num转换为period[num2-num1+1]*/
		dimen++; 
		int x = atoi($6.val.c_str()) - atoi($3.val.c_str()) + 1;
		string tmp = to_string(x);
		array_num.append("[");
		array_num.append(tmp);
		array_num.append("]");
	}
	|digits POINT POINT digits {
/*25. period -> num .. num*/
		dimen++;
		int x = atoi($4.val.c_str()) - atoi($1.val.c_str()) + 1;
		string tmp = to_string(x);
		array_num.append("[");
		array_num.append(tmp);
		array_num.append("]");
	}
	;
//by chenrui	

subprogram_declarations:	
	subprogram_declarations	subprogram SEMICOLON {
	
	}
	|{

	}
	;

subprogram 				:	subprogram_head SEMICOLON subprogram_body {
	
							}
						;
subprogram_head			:	PROCEDURE ID formal_parameter {
	
							}
						|	FUNCTION ID formal_parameter COLON basic_type{

							}
						;
formal_parameter 		:	LCIRCLE parameter_list RCIRCLE {
	
							}
						|	{}
						;
parameter_list			:	parameter_list SEMICOLON parameter {
	
							}
						|	parameter {

							}
						;
parameter 				: 	var_parameter {
	
							}
						|	value_parameter{

							}
						;
var_parameter			:	VAR value_parameter {
	
							}
						;
value_parameter			:	idlist COLON basic_type {
	
							}
						;
subprogram_body			: 	const_declarations var_declarations compound_statement {
	
							}
						;
compound_statement		: 	BEGIN statement_list END {
	
							}
						;
statement_list			: 	statement_list SEMICOLON statement {
	
							}
						|	statement {

							}
						;
statement 				:	variable ASSIGNOP expression {
	
							}
						|	procedure_call {

							}
						|	compound_statement {

							}
						|	IF expression THEN statement else_part {

							}
						|	FOR ID ASSIGNOP expression TO expression DO statement {

							}
						|	READ LCIRCLE variable_list RCIRCLE {

							}
						|	WRITE LCIRCLE expression_list RCIRCLE {

							}
						|	{}
						;
variable_list			:	variable_list COMMA variable {
	
							}
						|	variable {

							}
						;
variable 				:	ID id_varpart {
	
							}
id_varpart 				:	LCUBE expression_list RCUBE {
	
							}
						|  	{}
						;
procedure_call 			:	ID {
							}
						|	ID LCIRCLE expression_list RCIRCLE {

							}
						;
else_part 				:	ELSE statement {
	
							}
						|	{}
						;
expression_list 		:	expression_list COMMA expression {
	
							}
						|	expression {

							}
						;
expression 				:	simple_expression RELOP simple_expression {
	
							}
						|	simple_expression {

							}
						;
simple_expression:	
	simple_expression ADDOP term {
	
	}
	|term {

	}
	;

term:	
	term MULOP factor 
	{
	
	}
	|	
	factor 
	{

	}
	;

factor:	
	num {
		//factor -> num
		cout << $1.val;
		if (strcmp("INTEGER", $1.type) == 0){

		}
		if (strcmp("REAL", $1.type) == 0){

		}
		
	}
	|	
	variable {

	}
	|	
	ID LCIRCLE expression_list RCIRCLE {

	}
	|	
	LCIRCLE expression RCIRCLE {

	}
	|	
	NOT factor {
		//factor -> not factor 
		cout << '!' <<  $1.val;
	}
	|	
	ADDOP factor { 
	//只有当addop为-时才可以归约
						
	}
	;

//数字
digits:	
	digits DIGIT {
		
	}
	|	
	DIGIT {
		
	}
	;

optional_fraction:	
	POINT digits {
		
	}
	|{
		//无小数位
	}
	;

num:
	//浮点数
	digits optional_fraction {
	
	}
	;


%%
void yyerror(const char * s){
	cerr << s << " @ " << pos -> view() << endl;
	return;
}