%{
#include "common.h"
#include "datastruct.h"

extern Position * pos;
extern SymbolTable st;
%}

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

%code{

/*chenrui*/
int dimen = 0; //变量的维度
string array_num; //数组变量的范围，如 a[10][10]

int id_num = 0;//存储需要加入符号表的变量数量
string id_nam[100]; //存储需要加入符号表的变量名称
int array_flag = 0; //是否有数组变量
string var_name;//变量名称

string const_id;//常量变量的名称
vector<string> period_list;

/*chenrui*/


/*part2*/
string ReadToScanf(string in);
string WriteToPrintf(string in);
vector<Symbol> paraList2;
vector<Symbol> paraList;
bool isVarPara;
/*part2*/


/*part3*/
string err_info;
vector<myTYPE > expr_list;
vector<myTYPE > vari_list;
vector<string> typ_list;
/*part3*/


}

%%
//rules >>

programstruct:
program_head SEMICOLON program_body POINT {
/* 1. programstruct -> program_head; program_body. */
		$$.val = "#include <stdio.h>\n" + $3.val;
		cout << $$.val;
		//cout << $$.val;
		cerr << "compile complete ^^" << endl;
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
		$$.val = $1.val + $2.val + $3.val + "int main()\n{\n" + $4.val + "return 0;\n}\n";
	}
	;

idlist:	
/*5. idlist -> idlist, id*/
	idlist COMMA ID {

		id_nam[id_num] = $3.val;
		id_num++;
		var_name.append(",");
		var_name.append($3.val);
	}
	|ID {
/*6. idlist -> id*/

		id_num = 0;
		id_nam[id_num] = $1.val;
		id_num++;
		var_name = $1.val;
	}
	;

/*常量定义*/
const_declarations:	
	CONST const_declaration SEMICOLON{
/*7. const_declarations -> const const_declaration; */
		$$.val = string("const") + " " + $2.val + ";";
	}
	|{

/*8. const_declarations -> 空*/
		$$.val = "";
	}
	;	

const_declaration:	
	const_declaration SEMICOLON ID RELOP const_value { 
// 只有relop为=时才可以归约
/*9. const_declaration -> const_declaration; id = const_value*/
		if($4.val == "="){
			const_id = $3.val;
			if (add_const(const_id, $5.typ) == FAILED )
				yyerror(($3.val + "already exists!").c_str());
			else $$.val = $1.val + "const " + $5.typ + " " + $3.val + "=" + $5.val + ";\n";
		}
		else{
			yyerror("syntax error(EQ)!!!");
		}
		
	}
	|ID RELOP const_value { 
//同上
/*10. const_declaration -> id = const_value*/
		if($2.val == "="){
			const_id = $1.val;
			if (add_const(const_id, $3.typ) == FAILED){
				yyerror(($3.val + "already exists!").c_str());
			}
			else $$.val = string("const ") + $3.typ + "" + $1.val + "=" + $3.val + ";\n";
		}
		else{
			yyerror("syntax error(EQ)!!!");
		}
	}
	;

const_value:	
	ADDOP num{ 
/*11. const_value -> ADDOP num*/
		if ($$.val == "-"){
			$$.typ = $2.typ;
			$$.val = "-" + $2.val;
		}

		if ($$.val == "+"){
			$$.typ = $2.typ;
			$$.val = "+" + $2.val;
		}
	}
	|num {
/*12. const_value -> num*/
		$$.typ = $1.typ;
		$$.val = $1.val;
	}
	|CHARA { 
/*13. const_value -> 'letter'*/
// 单个字符，注意在翻译时加上两侧的单引号
		$$.typ = "char";
		$$.val = "\'" + $1.val + "\'";
	}
	;


//变量定义
var_declarations:	
	
	VAR var_declaration SEMICOLON
	{
/*14. var_declarations -> var var_declaration; */
		$$.val = $2.val;
		//cerr << "????" << $2.val << endl;
	}
	|{
/*15. var_declarations -> 空*/
		$$.val = "";
	}
	;

var_declaration:	
	var_declaration SEMICOLON idlist COLON type 
	{
/*16. var_declaration -> var_declaration; idlist : type*/

		$$.val = $1.val;	
		if (array_flag == 0){
			$$.val += $5.val + " " + var_name + ";\n";
		}
		else {
			for(int i = 0; i < id_num; i ++){
				$$.val += $5.typ + " " + id_nam[i];
				for(auto p: period_list)
					$$.val += "[" + p + "]";
				if(i != id_num - 1) $$.val += ",";
				else $$.val += ";\n";
			}
			array_flag = 0;
		}
	}
	|idlist COLON type 
	{
/*17. var_declaration -> idlist : type*/
//是否存在数组元素，不存在则较为方便，存在数组元素则需要转换顺序的语义动作
		if (array_flag == 0){
			$$.val = $3.val + " " + var_name + ";\n";
		}
		else {
			$$.val = "";
			for(int i = 0; i < id_num; i ++){
				$$.val += $3.typ + " " + id_nam[i];
				for(auto p: period_list)
					$$.val += "[" + p + "]";
				if(i != id_num - 1) $$.val += ",";
				else $$.val += ";\n";
			}
			array_flag = 0;
		}
	}
	;

type:	
	basic_type {
/*18. type -> basic_type*/
		$$.typ = $1.typ;
		if (array_flag == 0){
			for (int i = 0; i < id_num; i++){
				if (add_variable(id_nam[i], $$.typ) == FAILED){
					yyerror((id_nam[i] + " already exists").c_str());
				}
			}
		}
		dimen = 0;
	}
	|ARRAY LCUBE period RCUBE OF basic_type {
/*19. type -> array [period] of basic_types*/
		$$.typ = $6.typ;
		array_flag = 1;
		dimen = period_list.size();
		for (int i = 0; i < id_num; i++){
			if (add_array(id_nam[i], $6.typ, dimen) == FAILED){
				yyerror((id_nam[i] + " already exists").c_str());
			}
		}
		dimen = 0;
	}
	;

/*basic_type没有语义动作，直接规约即可*/
basic_type:	
	INTEGER {
/*20. basic_type -> integer*/
		$$.typ = "int";
		$$.val = "int";
	}
	|REAL {
/*21. basic_type -> real*/
		$$.typ = "float";
		$$.val = "float";
	}
	|BOOLEAN {
/*22. basic_type -> boolean*/
		$$.typ = "boolean";
		$$.val = "boolean";
	}
	|CHAR {
/*23. basic_type -> char */
		$$.typ = "char";
		$$.val = "char";
	}
	;

period:	
	period COMMA digits POINT POINT digits 
	{ 
/*24. period -> period, num .. num */
/*将period, num .. num转换为period[num2-num1+1]*/
		int x = atoi($6.val.c_str()) - atoi($3.val.c_str()) + 1;
		if(x <= 0) {
			yyerror("period error!");
		}
		else
			period_list.push_back(to_string(x));
	}
	|digits POINT POINT digits {
/*25. period -> num .. num*/
		period_list.clear();
		int x = atoi($4.val.c_str()) - atoi($1.val.c_str()) + 1;
		if(x <= 0) {
			yyerror("period error!");
		}
		else
			period_list.push_back(to_string(x));
	}
	;
//by chenrui	

//xzc
subprogram_declarations	:	subprogram_declarations	subprogram SEMICOLON {
						/* 26.	subprogram_declarations -> subprogram_declarations   subprogram  ;*/
								
								$$.val = $1.val + $2.val;
								
							}
						|	{
						/* 27.	subprogram_declarations ->  ε */
								$$.val = "";
						}
						;
subprogram 				:		subprogram_head SEMICOLON subprogram_body {
						/* 28.	subprogram -> subprogram_head   ;  subprogram_body */
								//symboltable_print(st);
								if(PopBlock() == FAILED){yyerror("pop block error.");}
								$$.val = $1.val + $3.val;

							}
						;
subprogram_head			:	PROCEDURE ID formal_parameter {
						/* 29.	subprogram_head -> procedure  id  formal_parameter    */
								{ 
								if(FindSymbol($2.val) == FAILED){
									add_procedure($2.val, paraList.size());
									if(InsertBlock() == FAILED){yyerror("insert block error.");} 
									$$.val = "void " + $2.val + "(" + $3.val + ")\n";
									for(int i = 0; i < paraList.size(); i++){
											Symbol tmp = paraList.at(i);
											if(tmp.isref){
												add_refpara($2.val, tmp.name, tmp.type);
											}
											else{
												add_para($2.val, tmp.name, tmp.type);
											}
									}
								}
								else{
									yyerror("function declared implicitly.");
								}
								paraList.clear();
								}
							}
						|	FUNCTION ID formal_parameter COLON basic_type {
						/* 30.	subprogram_head -> function  id  formal_parameter  :  simple_type     */
								if(FindSymbol($2.val) == FAILED){
									add_function($2.val, $5.val, paraList.size());
									if(InsertBlock() == FAILED){yyerror("insert block error.");}
									$$.val = $5.val + " " + $2.val + "(" + $3.val + ")\n";
									for(int i = 0; i < paraList.size(); i++){
											Symbol tmp = paraList.at(i);
											if(tmp.isref){
												add_refpara($2.val, tmp.name, tmp.type);
											}
											else{
												add_para($2.val, tmp.name, tmp.type);
											}
									}
								}
								else{
									yyerror("function declared implicitly.");
								}
								paraList.clear();
								//symboltable_print(st);
							}
						;
formal_parameter 		:	LCIRCLE parameter_list RCIRCLE {
						/* 31.	formal_parameter -> (  parameter_list  )    */
								$$.val = $2.val;
							}
						|	{
						/* 32.	formal_parameter ->  ε */
								$$.val = "";
						}
						;
parameter_list			:   
							parameter_list SEMICOLON parameter {
						/* 33.	parameter_list -> parameter_list  ;  parameter     */
								$$.val = $1.val + ", " + $3.val;
								paraList2.clear();
							}
						|	parameter {
						/* 34.	parameter_list -> parameter*/
								$$.val = $1.val;
								paraList2.clear();
							}
						;
parameter 				: 	var_parameter {
						/* 35.	parameter -> var_parameter   */
								$$.val = $1.val;
							}
						|	value_parameter {
						/* 36.	parameter -> value_parameter */
								$$.val = $1.val;
							}
						;
var_parameter			:	VAR value_parameter {
						/* 37.	var_parameter -> var  value_parameter  */
								for(int i = (int)paraList.size() - 1; i >= (int)paraList.size() - (int)paraList.size(); i --)
									paraList[i].isref = 1;
								int num = paraList2.size();
								string out = "";
								for(int i = 0; i < num; i++){
									out = out + $2.typ + " ";
									out +="&";
									out = out + paraList2.at(i).name + ", ";
								}
								$$.val = out.substr(0, out.size()-2);
							}
						;
value_parameter			:	idlist COLON basic_type {
						/* 38.	value_parameter -> idlist  :  simple_type  */
								for(int i = 0; i < id_num; i ++){
									Symbol tmp;
									tmp.name = id_nam[i];
									tmp.isref = 0;
									tmp.type = $3.typ;
									paraList.push_back(tmp);
									paraList2.push_back(tmp);
								}

								
								int num = paraList2.size();
								string out = "";
								for(int i = 0; i < num; i++){
									out = out + $3.val + " ";
									if(paraList2.at(i).isref){out +="&";}
									out = out + paraList2.at(i).name + ", ";
								}
								$$.val = out.substr(0, out.size()-2);
								$$.typ = $3.typ;
								//cerr << $$.val << endl;
							}
						;
subprogram_body			: 	const_declarations var_declarations compound_statement {
						/* 39.	subprogram_body  -> const_declarations  var_declarations  compound_statement */
								$$.val = "{\n" + $1.val + $2.val + $3.val + "}\n";
							}
						;
compound_statement		: 	BEGIN statement_list END {
						/* 40.	compound_statement -> begin  statement_list  end  */
								$$.val = $2.val;
							}
						;
statement_list			: 	statement_list SEMICOLON statement {
						/* 41.	statement_list -> statement_list  ;  statement */    
								$$.val = $1.val + $3.val;
							}
						|	statement {
						/* 42.	statement_list -> statement */
								$$.val = $1.val;

							}
						;
statement 				:	variable ASSIGNOP expression {
						/* 43.	statement -> variable  assignop  expression  */
								//43
								// check return statement
								if(GetType($1.val) == "function"){
									if(GetSubType($1.val) == $3.typ){
										$$.val = "return " + $3.val + ";\n";
									}
									else{
										yyerror("Wrong return statement.");
									}
								}

							}
						|	procedure_call {
						/* 44.	statement ->  procedure_call */
								$$.val = $1.val + ";\n";
							}
						|	compound_statement {
						/* 45.	statement ->  compound_statement  */
								$$.val + $1.val;
							}
						|	IF expression THEN statement else_part {
						/* 46.	statement ->  if  expression  then statement  else_part  */
								$$.val = "if(" + $2.val + ")\n{\n" + $4.val + "}\n" + $5.val;

								if($2.typ != "boolean"){
									yyerror("error in if expression type");
								}
							}
						|	FOR ID ASSIGNOP expression TO expression DO statement {
						/* 47.	statement ->  for  id  assignop  expression   to  expression  do  statement */
								string ret = GetType($2.val);
								if(ret == "FAILED"){
									yyerror("variable not declared.");
								}
								else {
									if(ret != "int" || $4.typ != "int" || $6.typ != "int"){
										yyerror("Wrong type");
									}
									else if($4.val > $6.val){
										yyerror("Range error.");
									}
									else{
										$$.val = "for(" + $2.val + "=" + $4.val + "; " + $2.val + "<=" + $6.val + "; " + $2.val + "++)\n{\n" + $8.val + "}\n";
									}
								}
							}
						|	READ LCIRCLE variable_list RCIRCLE {
						/* 48.	statement -> read ( variable_list  )  */
								$$.val = ReadToScanf($3.val);
							}
						|	WRITE LCIRCLE expression_list RCIRCLE {
						/* 49.	statement -> write ( expression_list )  */
								$$.val = WriteToPrintf($3.val);
							}
						|	{
						/* 50.	statement -> ε */ 
								$$.val = "";
						}
						;
//by xzc

variable_list			:	variable_list COMMA variable {
						/* 51.	variable_list -> variable_list , variable    */
								$$.val = $1.val + "," + $3.val;
								vari_list.push_back($3);
							}
						|	variable {
						/* 52.	variable_list ->  variable */
								vari_list.clear();
								vari_list.push_back($1);
								$$.val = $1.val;
							}
						;
variable 				:	ID id_varpart {
						/* 53.	variable -> id  id_varpart */
								string flag = GetType($1.val);
								int did = FindSymbol($1.val);
								//symbol_print(st.Sstack[did]);
								

								if(flag == "FAILED") cerr << $1.val << endl, yyerror("id doesn't exist");
								else if(flag == "array"){
									int d = GetDimension($1.val);
									if(expr_list.size() != d) yyerror("array dimenssion error!");
									else{
										$$.typ = GetSubType($1.val);
										$$.val = $1.val;
										for(auto p: expr_list)
											$$.val = $$.val + '[' + p.val + ']';
									}
								}
								else if(flag == "functuon" || flag == "procedure"){
									if(GetDimension($1.val) != 0) yyerror("parameter number error"); //函数或者过程参数个数错误
									else{
										$$.typ = flag;
										$$.val = $1.val;
									}
								}
								else{
									$$.typ = flag;
									$$.val = $1.val;
								}
							}
id_varpart 				:	LCUBE expression_list RCUBE {
						/* 54.	id_varpart -> [ expression_list ]   */
								$$.val = '[' + $2.val + ']';
							}
						|  	{
						/* 55.	id_varpart -> ??*/
								$$.val = $$.typ = "";
							} 
						;
procedure_call 			:	ID {
						/* 56.	procedure_call -> id  */
								string flag = GetType($1.val);
								if(flag == "FAILED") yyerror("id doesn't exitst");
								else if(flag != "procedure") {
									err_info = "id:" + $1.val + " is not a procedure";
									yyerror(err_info.c_str());
								}
								else{
									$$.typ = flag;
									$$.val = $1.val;
								}
							}
						|	ID LCIRCLE expression_list RCIRCLE {
						/* 57.	procedure_call -> id ( expression_list ) */
								string flag = GetType($1.val);
								if(flag == "FAILED") yyerror("id doesn't exitst");
								else if(flag != "procedure") {
									err_info = "id:" + $1.val + " is not a procedure";
									yyerror(err_info.c_str());
								}
								else{
									typ_list.clear();
									for(auto p: expr_list)
										typ_list.push_back(p.typ);
									int fflag = CheckType($1.val, typ_list);
									if(fflag == DIMENSION_ERROR) yyerror("DIMENSION_ERROR!"); //维度不匹配
									else if(fflag == NOT_MATCH) yyerror("parameters don't match!"); // 类型不匹配
									else{
										$$.typ = "procedure";
										$$.val = $1.val + "(" + $3.val + ")";
									}
								}
							}
						;
else_part 				:	ELSE statement {
						/* 58.	else_part -> else statement   */
								$$.typ = $2.typ;
								$$.val = "else\n{\n" + $2.val + "}\n";
							}
						|	{
						/* 59.	else_part ->  ??*/
								$$.typ = "int";
								$$.val = "";
						}
						;
expression_list 		:	expression_list COMMA expression {
						/* 60.	expression_list -> expression_list  ,  expression   */
								$$.val = $1.val + "," + $3.val;
								expr_list.push_back($3);
							}
						|	expression {
						/* 61.	expression_list ->  expression  */
								expr_list.clear();
								expr_list.push_back($1);
								$$ = $1;
							}
						;
expression 				:	simple_expression RELOP simple_expression {
						/* 62.	expression -> simple_expression  relop  simple_expression */
								if($3.typ == "string"){
									yyerror("string is not expected here.");
								}
								if($1.typ != $3.typ){
									yyerror("The expression type should be same on both sides.");
								}


								

 								if($2.val == "="){
									$$.val = $1.val + "==" + $3.val;
								}
								else{
									$$.val = $1.val + $2.val + $3.val;
								}
								$$.typ = "boolean";
							}
						|	simple_expression {
						/* 63.	expression ->  simple_expression */
								$$.typ = $1.typ;
								$$.val = $1.val;
							}
						;
simple_expression		:	simple_expression ADDOP term {
						/* 64.	simple_expression -> simple_expression  addop term   */
								if(($2.val=="+")||($2.val=="-")){
									if(($1.typ == "float")||($3.typ == "float")){
										$$.typ = "float";
										$$.val = $1.val + $2.val + $3.val;
									}
									else if(($1.typ == "int")&&($3.typ == "int")){
										$$.typ = "int";
										$$.val = $1.val + $2.val + $3.val;
									}
									else
										yyerror("The addop is wrong.");
								}
								else{
									if(($1.typ == "boolean")&&($2.typ == "boolean")){
										$$.typ = "boolean";
										$$.val = $1.val + $2.val + $3.val;
									}
									else
										yyerror("The addop is wrong.");
								}
							}
						|	term {
						/* 65.	simple_expression -> term */
								$$.typ = $1.typ;
								$$.val = $1.val;
							}
						;
term					:	term MULOP factor {
						/* 66.	term -> term  mulop  factor */
								if(($2.val=="*")||($2.val=="/")){
									if(($1.typ == "float")||($3.typ == "float"))
										$$.typ = "float";
									else
										$$.typ = "int";
									if(($2.val=="/")&&($3.val== "0" ))
										yyerror("/0");
									$$.val = $1.val + $2.val + $3.val; 
								}
								else if($2.val == "div" || $2.val == "mod"){
									if($1.typ != "int" || $3.typ != "int") yyerror("type error!");
									else{
										$$.typ = "int";
										if($2.val == "div") $$.val = $1.val + "/" + $3.val;
										else $$.val = $1.val + "%" + $3.val;
									}
								}
							}
						|	factor {
						/* 67.	term -> factor */
								$$.typ = $1.typ;
								$$.val = $1.val;
							}
						;
factor					:	num {
						/* 68.	factor -> num  */
								$$.typ = $1.typ;
								$$.val = $1.val;
							}
						|	variable {
						/* 69.	factor -> variable      */
								$$.typ = $1.typ;
								$$.val = $1.val;
							}
						|	ID LCIRCLE expression_list RCIRCLE {
						/* 70.	factor ->  id  ( expression_list ) */
								string flag = GetType($1.val);
								if(flag == "FAILED") {
									//symboltable_print(st);
									cerr << $1.val << endl, yyerror("id doesn't exist"); //标识符不存在
								}
								else if(flag != "function"){
									err_info = "id:" + $1.val + " is not a procedure";
									yyerror(err_info.c_str());
								}
								else{
									typ_list.clear();
									for(auto p: expr_list)
										typ_list.push_back(p.typ);
									int fflag = CheckType($1.val, typ_list);
									if(fflag == DIMENSION_ERROR) yyerror("DIMENSION_ERROR!"); //维度不匹配
									else if(fflag == NOT_MATCH) yyerror("parameters don't match!"); // 类型不匹配
									else{
										//sssssssss
										$$.typ = GetSubType($1.val);
										$$.val = $1.val + "(" + $3.val + ")";
									}
								}
							}
						|	LCIRCLE expression RCIRCLE {
						/* 71.	factor -> ( expression )   */
								$$.typ = $2.typ;
								$$.val = "(" + $2.val + ")";
							}
						|	NOT factor {
						/* 72.	factor ->  not  factor  */
								$$.typ = $1.typ;
								$$.val = "!" + $2.val;
							}
						|	ADDOP factor { //ֻ???addopΪ-ʱ?ſ?Թ??
						/* 73.	factor -> uminus  factor*/
								$$.typ = $1.typ;
								$$.val = "-" + $2.val;
							}
						;
digits					:	digits DIGIT {
						/* 74.	digits -> digits DIGIT */
								$$.typ = $1.typ;
								$$.val = $1.val + $2.val;
							}
						|	DIGIT {
						/* 75.	digits -> DIGIT */
								$$.typ = "int";
								$$.val = $1.val;
							}
						;
optional_fraction		:	POINT digits {
						/* 76.	optional_fraction -> POINT digits*/
								$$.typ = "float";
								$$.val = "." + $2.val;
							}
						|	{
						/* 77.		optional_fraction -> ??*/ 
								$$.typ = "int";
								$$.val = "";
						}
						;
num 					: 	digits optional_fraction {
						/* 78.	Num -> digits optional_fraction */
								if($2.typ == "int") $$.typ = "int";
								else $$.typ = "float";
								$$.val = $1.val + $2.val;
								//cerr << "num:" << $$.val << " " + pos->view() << endl; 
							}
						;
%%
void yyerror(const char * s){
	cerr << s << " @ " << pos -> view2() << endl;
	return;
}

string stdIOTypeTrans(string typ){
	if(typ == "int"){
		return "%d";
	}
	else if(typ == "char"){
		return "%c";
	}
	else if(typ == "float"){
		return "%f";
	}
	else{
		return "false";
	}
}

string ReadToScanf(string in){
	string out = "scanf(\"";
	int i;
	for(i = 0; i < vari_list.size(); i++){
		myTYPE tmp = vari_list.at(i);
		string s = stdIOTypeTrans(tmp.typ);
		if(s != "false"){
			out += s;
		}
		else{
			yyerror("type cannot read.");
			return "";
		}
		//if(i != expr_list.size()-1) {out += "";}
	}
	out += "\"";
	for(i = 0; i < vari_list.size(); i++){
		myTYPE tmp = vari_list.at(i);
		out += ", &";
		out += tmp.val;
	}
	out += ");\n";
	return out;
}

string WriteToPrintf(string in){
	string out = "printf(\"";
	int i;
	for(i = 0; i < expr_list.size(); i++){
		myTYPE tmp = expr_list.at(i);
		string s = stdIOTypeTrans(tmp.typ);
		if(s != "false"){
			out += s;
		}
		else{
			yyerror("type cannot write.");
			return "";
		}
		if(i != expr_list.size()-1) {out += ", ";}
	}
	out += "\"";
	for(i = 0; i < expr_list.size(); i++){
		myTYPE tmp = expr_list.at(i);
		out += ", ";
		out += tmp.val;
	}
	out += ");\n";
	return out;
}