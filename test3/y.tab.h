/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COLON = 1,
    LCIRCLE = 2,
    RCIRCLE = 3,
    LCUBE = 4,
    RCUBE = 5,
    SEMICOLON = 6,
    POINT = 7,
    COMMA = 8,
    DIGIT = 9,
    PROGRAM = 201,
    CONST = 202,
    VAR = 203,
    FUNCTION = 204,
    PROCEDURE = 205,
    BEGIN = 206,
    END = 207,
    FOR = 208,
    IF = 209,
    THEN = 210,
    ELSE = 211,
    WHILE = 212,
    TO = 213,
    DO = 214,
    OF = 215,
    CALL = 216,
    READ = 217,
    WRITE = 218,
    INTEGER = 219,
    REAL = 220,
    BOOLEAN = 221,
    CHAR = 222,
    OR = 223,
    AND = 224,
    DIV = 225,
    ID = 226,
    CHARA = 229,
    RELOP = 230,
    ADDOP = 231,
    MULOP = 232,
    ASSIGNOP = 233,
    MOD = 234,
    ARRAY = 235,
    NOT = 236
  };
#endif
/* Tokens.  */
#define COLON 1
#define LCIRCLE 2
#define RCIRCLE 3
#define LCUBE 4
#define RCUBE 5
#define SEMICOLON 6
#define POINT 7
#define COMMA 8
#define DIGIT 9
#define PROGRAM 201
#define CONST 202
#define VAR 203
#define FUNCTION 204
#define PROCEDURE 205
#define BEGIN 206
#define END 207
#define FOR 208
#define IF 209
#define THEN 210
#define ELSE 211
#define WHILE 212
#define TO 213
#define DO 214
#define OF 215
#define CALL 216
#define READ 217
#define WRITE 218
#define INTEGER 219
#define REAL 220
#define BOOLEAN 221
#define CHAR 222
#define OR 223
#define AND 224
#define DIV 225
#define ID 226
#define CHARA 229
#define RELOP 230
#define ADDOP 231
#define MULOP 232
#define ASSIGNOP 233
#define MOD 234
#define ARRAY 235
#define NOT 236

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
