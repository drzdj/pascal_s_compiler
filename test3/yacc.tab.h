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

#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */