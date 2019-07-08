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
						cout << "compile complete" << endl;
					}
				;
program_head	:	PROGRAM ID {
	
					} 
				| 	PROGRAM ID LCIRCLE idlist RCIRCLE {
		
					}
				;
program_body	:	const_declarations var_declarations subprogram_declarations compound_statement {
	
					}
				;
idlist			:	idlist COMMA ID {
						
					}
				|	ID {
					}
				;
const_declarations	:	CONST const_declaration SEMICOLON{
	
						}
					|	{}
					;	
const_declaration 	:	const_declaration SEMICOLON ID RELOP const_value { // 只有relop为=时才可以归约
	
						}
					|	ID RELOP const_value { //同上

						}
					;
const_value			:	ADDOP num{ // '+'或者'-'
						
						}
					|	num {

						}
					|	CHARA { // 单个字符，注意在翻译时加上两侧的单引号

						}
					;
var_declarations	:	VAR var_declaration SEMICOLON{
	
						}
					|	{}
					;
var_declaration 	:	var_declaration SEMICOLON idlist COLON type {
	
						}
					| 	idlist COLON type {

						}
					;
type				:	basic_type {
	
						}
					|	ARRAY LCUBE period RCUBE OF basic_type {

						}
					;
basic_type			:	INTEGER {
	
						}
					|	REAL {

						}
					|	BOOLEAN {

						}
					|	CHAR {

						}
					;
period				:	period COMMA digits POINT POINT digits { //num needs to be Integer
	
						}
					|	digits POINT POINT digits {

						}
					;
subprogram_declarations	:	subprogram_declarations	subprogram SEMICOLON {
	
							}
						|	{}
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
simple_expression		:	simple_expression ADDOP term {
	
							}
						|	term {

							}
						;
term					:	term MULOP factor {
	
							}
						|	factor {

							}
						;
factor					:	num {
	
							}
						|	variable {

							}
						|	ID LCIRCLE expression_list RCIRCLE {

							}
						|	LCIRCLE expression RCIRCLE {

							}
						|	NOT factor {

							}
						|	ADDOP factor { //只有当addop为-时才可以归约

							}
						;
digits					:	digits DIGIT {
	
							}
						|	DIGIT {

							}
						;
optional_fraction		:	POINT digits {
	
							}
						|	{}
						;
num 					: 	digits optional_fraction {
	
							}
						;
%%
void yyerror(const char * s){
	cerr << s << " @ " << pos -> view() << endl;
	return;
}