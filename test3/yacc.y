%{
#include "common.h"
#include "datastruct.h"

extern Position * pos;
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

%%
//rules >>

programstruct 	:	program_head SEMICOLON program_body POINT {
						/* 1.	programstruct -> program_head  ；program_body . */
						cout << "compile complete" << endl;
					}
				;
program_head	:	PROGRAM ID LCIRCLE idlist RCIRCLE  {
						/* 2.	program_head -> program id ( idlist ) */
	
					} 
				| 	PROGRAM ID {
						/* 3.	program_head -> program id */
		
					}
				;
program_body	:	const_declarations var_declarations subprogram_declarations compound_statement {
						/* 4.	program_body -> const_declarations   var_declarations   subprogram_declarations     compound_statement */

	
					}
				;
idlist			:	idlist COMMA ID {
						/* 5.	idlist -> idlist , id */
						
					}
				|	ID {
						/* 6.	idlist -> id */
					}
				;
const_declarations	:	CONST const_declaration SEMICOLON{
						/* 7.	const_declarations -> const const_declaration  ;  */

	
						}
					|	{
						/* 8.	const_declarations -> ε */
					}
					;	
const_declaration 	:	const_declaration SEMICOLON ID RELOP const_value { // 只有relop为=时才可以归约
						/* 9.	const_declaration -> const_declaration ;  id = const_value  */

	
						}
					|	ID RELOP const_value { //同上
						/* 10.	const_declaration -> id = const_value  */

						}
					;
const_value			:	ADDOP num{ // '+'或者'-'
						/* 11.	const_value -> ADDOP num   */
						
						}
					|	num {
						/* 12.	const_value -> num */

						}
					|	CHARA { // 单个字符，注意在翻译时加上两侧的单引号
						/* 13.	const_value -> ′ letter ′  */
						}
					;
var_declarations	:	VAR var_declaration SEMICOLON{
						/* 14.	var_declarations -> var  var_declaration ;  */
	
						}
					|	{
						/* 15.	var_declarations -> ε */
					}
					;
var_declaration 	:	var_declaration SEMICOLON idlist COLON type {
						/* 16.	var_declaration -> var_declaration  ;  idlist  :  type  */
	
						}
					| 	idlist COLON type {
						/* 17.	var_declaration -> idlist  :  type */

						}
					;
type				:	basic_type {
						/* 18.	type -> basic_type      */
	
						}
					|	ARRAY LCUBE period RCUBE OF basic_type {
						/* 19.	type -> array [  period  ]  of  basic_type */

						}
					;
basic_type			:	INTEGER {
						/* 20.	basic_type -> integer  */
	
						}
					|	REAL {
						/* 21.	basic_type ->   real  */

						}
					|	BOOLEAN {
						/* 22.	basic_type ->   boolean  */

						}
					|	CHAR {
						/* 23.	basic_type ->   char */

						}
					;
period				:	period COMMA digits POINT POINT digits { //num needs to be Integer
						/* 24.	period -> period ， digits .. digits   */
	
						}
					|	digits POINT POINT digits {
						/* 25.	period -> digits .. digits */

						}
					;
subprogram_declarations	:	subprogram_declarations	subprogram SEMICOLON {
						/* 26.	subprogram_declarations -> subprogram_declarations   subprogram  ;*/
							}
						|	{
						/* 27.	subprogram_declarations ->  ε */
						}
						;
subprogram 				:	subprogram_head SEMICOLON subprogram_body {
						/* 28.	subprogram -> subprogram_head   ;  subprogram_body */
	
							}
						;
subprogram_head			:	PROCEDURE ID formal_parameter {
						/* 29.	subprogram_head -> procedure  id  formal_parameter    */

	
							}
						|	FUNCTION ID formal_parameter COLON basic_type {
						/* 30.	subprogram_head -> function  id  formal_parameter  :  simple_type     */

							}
						;
formal_parameter 		:	LCIRCLE parameter_list RCIRCLE {
						/* 31.	formal_parameter -> (  parameter_list  )    */
	
							}
						|	{
						/* 32.	formal_parameter ->  ε */
						}
						;
parameter_list			:	parameter_list SEMICOLON parameter {
						/* 33.	parameter_list -> parameter_list  ;  parameter     */
	
							}
						|	parameter {
						/* 34.	parameter_list -> parameter*/

							}
						;
parameter 				: 	var_parameter {
						/* 35.	parameter -> var_parameter   */
	
							}
						|	value_parameter {
						/* 36.	parameter -> value_parameter */

							}
						;
var_parameter			:	VAR value_parameter {
						/* 37.	var_parameter -> var  value_parameter  */
	
							}
						;
value_parameter			:	idlist COLON basic_type {
						/* 38.	value_parameter -> idlist  :  simple_type  */
	
							}
						;
subprogram_body			: 	const_declarations var_declarations compound_statement {
						/* 39.	subprogram_body  -> const_declarations  var_declarations  compound_statement */
	
							}
						;
compound_statement		: 	BEGIN statement_list END {
						/* 40.	compound_statement -> begin  statement_list  end  */
	
							}
						;
statement_list			: 	statement_list SEMICOLON statement {
						/* 41.	statement_list -> statement_list  ;  statement */    
	
							}
						|	statement {
						/* 42.	statement_list -> statement */

							}
						;
statement 				:	variable ASSIGNOP expression {
						/* 43.	statement -> variable  assignop  expression  */
	
							}
						|	procedure_call {
						/* 44.	statement ->  procedure_call */

							}
						|	compound_statement {
						/* 45.	statement ->  compound_statement  */

							}
						|	IF expression THEN statement else_part {
						/* 46.	statement ->  if  expression  then statement  else_part  */

							}
						|	FOR ID ASSIGNOP expression TO expression DO statement {
						/* 47.	statement ->  for  id  assignop  expression   to  expression  do  statement */

							}
						|	READ LCIRCLE variable_list RCIRCLE {
						/* 48.	statement -> read ( variable_list  )  */

							}
						|	WRITE LCIRCLE expression_list RCIRCLE {
						/* 49.	statement -> write ( expression_list )  */

							}
						|	{
						/* 50.	statement -> ε */ 
						}
						;
variable_list			:	variable_list COMMA variable {
						/* 51.	variable_list -> variable_list , variable    */
	
							}
						|	variable {
						/* 52.	variable_list ->  variable */

							}
						;
variable 				:	ID id_varpart {
						/* 53.	variable -> id  id_varpart */
	
							}
id_varpart 				:	LCUBE expression_list RCUBE {
						/* 54.	id_varpart -> [ expression_list ]   */
	
							}
						|  	{
						/* 55.	id_varpart -> ε */
						;
procedure_call 			:	ID {
						/* 56.	procedure_call -> id  */
							}
						|	ID LCIRCLE expression_list RCIRCLE {
						/* 57.	procedure_call -> id ( expression_list ) */

							}
						;
else_part 				:	ELSE statement {
						/* 58.	else_part -> else statement   */
	
							}
						|	{
						/* 59.	else_part ->  ε */
						}
						;
expression_list 		:	expression_list COMMA expression {
						/* 60.	expression_list -> expression_list  ,  expression   */
	
							}
						|	expression {
						/* 61.	expression_list ->  expression  */

							}
						;
expression 				:	simple_expression RELOP simple_expression {
						/* 62.	expression -> simple_expression  relop  simple_expression */
	
							}
						|	simple_expression {
						/* 63.	expression ->  simple_expression */

							}
						;
simple_expression		:	simple_expression ADDOP term {
						/* 64.	simple_expression -> simple_expression  addop term   */
	
							}
						|	term {
						/* 65.	simple_expression -> term */

							}
						;
term					:	term MULOP factor {
						/* 66.	term -> term  mulop  factor */
	
							}
						|	factor {
						/* 67.	term -> factor */

							}
						;
factor					:	num {
						/* 68.	factor -> num  */
	
							}
						|	variable {
						/* 69.	factor -> variable      */

							}
						|	ID LCIRCLE expression_list RCIRCLE {
						/* 70.	factor ->  id  ( expression_list ) */

							}
						|	LCIRCLE expression RCIRCLE {
						/* 71.	factor -> ( expression )   */

							}
						|	NOT factor {
						/* 72.	factor ->  not  factor  */

							}
						|	ADDOP factor { //只有当addop为-时才可以归约
						/* 73.	factor -> uminus  factor*/
							}
						;
digits					:	digits DIGIT {
						/* 74.	digits -> digits DIGIT */
	
							}
						|	DIGIT {
						/* 75.	digits -> DIGIT */

							}
						;
optional_fraction		:	POINT digits {
						/* 76.	optional_fraction -> POINT digits*/
	
							}
						|	{
						/* 77.		optional_fraction -> ε */ 
						}
						;
num 					: 	digits optional_fraction {
						/* 78.	Num -> digits optional_fraction */
	
							}
						;
%%
void yyerror(const char * s){
	cerr << s << " @ " << pos -> view() << endl;
	return;
}