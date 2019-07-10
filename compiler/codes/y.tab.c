/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

#include "common.h"
#include "datastruct.h"

extern Position * pos;
extern SymbolTable st;

#line 74 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 215 "y.tab.c" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 57 "yacc.y" /* yacc.c:359  */


int err_cnt = 0;
void Statistics();
void yerror(const char *);

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



#line 257 "y.tab.c" /* yacc.c:359  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     2,     2,    38,
      39,    40,    41,    42,    43,    44,    45,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   108,   112,   120,   124,   131,   138,   141,
     144,   147,   154,   161,   173,   177,   185,   199,   216,   228,
     233,   245,   251,   258,   277,   299,   311,   327,   332,   337,
     342,   350,   361,   375,   381,   386,   395,   418,   441,   445,
     451,   456,   462,   466,   471,   485,   509,   514,   519,   523,
     529,   566,   570,   574,   582,   601,   605,   609,   613,   620,
     625,   632,   661,   665,   670,   683,   705,   710,   716,   721,
     728,   751,   757,   780,   786,   806,   812,   817,   822,   847,
     852,   857,   863,   868,   874,   879,   885
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COLON", "LCIRCLE", "RCIRCLE", "LCUBE",
  "RCUBE", "SEMICOLON", "POINT", "COMMA", "DIGIT", "PROGRAM", "CONST",
  "VAR", "FUNCTION", "PROCEDURE", "BEGIN", "END", "FOR", "IF", "THEN",
  "ELSE", "WHILE", "TO", "DO", "OF", "CALL", "READ", "WRITE", "INTEGER",
  "REAL", "BOOLEAN", "CHAR", "OR", "AND", "DIV", "ID", "CHARA", "RELOP",
  "ADDOP", "MULOP", "ASSIGNOP", "MOD", "ARRAY", "NOT", "$accept",
  "programstruct", "program_head", "program_body", "idlist",
  "const_declarations", "const_declaration", "const_value",
  "var_declarations", "var_declaration", "type", "basic_type", "period",
  "subprogram_declarations", "subprogram", "subprogram_head",
  "formal_parameter", "parameter_list", "parameter", "var_parameter",
  "value_parameter", "subprogram_body", "compound_statement",
  "statement_list", "statement", "variable_list", "variable", "id_varpart",
  "procedure_call", "else_part", "expression_list", "expression",
  "simple_expression", "term", "factor", "digits", "optional_fraction",
  "num", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   229,   230,
     231,   232,   233,   234,   235,   236
};
# endif

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -64

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,    86,   -14,    82,    90,    91,    79,   108,    63,   136,
    -110,    86,   104,  -110,   111,   138,  -110,  -110,    95,   104,
      44,  -110,    58,   139,   107,     6,   114,   107,   131,   112,
      80,  -110,  -110,     8,   116,   104,   117,   118,    46,   141,
     144,  -110,  -110,  -110,   145,  -110,    25,  -110,   119,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,   151,  -110,
    -110,  -110,    78,   155,   155,   123,    10,    10,   157,   158,
      18,  -110,    12,  -110,   122,  -110,  -110,   150,  -110,   145,
    -110,  -110,     6,   145,     8,    -4,   162,  -110,   124,    10,
      53,    10,    10,  -110,   146,    33,   127,  -110,  -110,   147,
     133,    10,    10,    10,  -110,    46,  -110,    10,    91,  -110,
     160,  -110,    41,    83,  -110,   104,    81,    99,  -110,  -110,
    -110,   105,    10,   164,    10,  -110,  -110,    46,    10,    10,
      10,    46,   167,   109,  -110,   110,  -110,   120,   132,  -110,
    -110,   131,   148,   145,   166,  -110,   105,  -110,    -4,  -110,
     152,  -110,   121,   156,   137,   127,  -110,  -110,  -110,   133,
    -110,    10,  -110,  -110,  -110,   105,   134,   145,  -110,  -110,
      10,  -110,    46,  -110,  -110,  -110,  -110,   170,   160,   159,
    -110,   145,    46,   160,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    22,     0,     0,     0,     5,
       1,     0,     0,    34,     0,     0,     3,    34,     0,     0,
       0,    13,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     4,     2,     0,     0,    21,     0,     0,    58,     0,
       0,     8,    83,    20,     0,    17,    85,    19,     0,     9,
      10,    11,     7,     6,    27,    28,    29,    30,     0,    24,
      25,    12,     0,    39,    39,     0,     0,     0,     0,     0,
      64,    52,     0,    49,     0,    51,    33,    15,    18,     0,
      82,    86,     0,     0,     0,     0,     0,    36,     0,     0,
      63,     0,     0,    77,     0,    71,    73,    75,    76,     0,
       0,     0,     0,     0,    61,    58,    47,     0,    22,    35,
      84,    16,     0,     0,    23,     0,     0,     0,    41,    42,
      43,     0,     0,     0,     0,    81,    80,    58,     0,     0,
       0,    58,    63,     0,    60,     0,    69,     0,     0,    48,
      50,     0,     0,     0,     0,    44,     0,    38,     0,    37,
       0,    79,     0,    67,    70,    72,    74,    57,    55,     0,
      56,     0,    65,    62,    46,     0,     0,     0,    45,    40,
       0,    78,    58,    53,    59,    68,    26,     0,    32,     0,
      66,     0,    58,    31,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,   169,     7,   106,  -110,   100,     0,  -110,
      97,  -109,  -110,   115,  -110,  -110,   125,  -110,    37,  -110,
      71,  -110,   -23,  -110,   -96,  -110,   -38,  -110,  -110,  -110,
     -75,   -64,    59,    61,   -76,   -72,  -110,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     7,   116,     8,    15,    45,    13,    23,
      59,    60,   112,    24,    39,    40,    86,   117,   118,   119,
     120,   109,    71,    72,    73,   133,    93,   104,    75,   173,
     135,   136,    95,    96,    97,    46,    81,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,    41,    94,    99,    49,    50,    52,   110,    18,   139,
     115,   113,   149,    47,    89,   125,   126,    42,     1,    22,
     105,    42,   102,     9,   103,   123,    30,   137,   138,     2,
     106,   153,    78,    21,    79,   157,    80,   168,    54,    55,
      56,    57,    62,   140,    43,    31,    44,    90,   142,   152,
      91,   143,    58,    32,   156,    92,   176,   124,   150,   103,
     -63,    33,   134,    38,    17,    65,    66,    74,    34,    67,
      47,   166,   128,   129,    68,    69,   180,    12,   -22,   -22,
     -22,    84,    10,    70,   146,    53,   184,     5,    34,    74,
      34,    34,   144,    74,    80,   178,    28,   175,    11,     6,
     -15,   -15,   -15,   -15,   147,    12,   179,   148,   141,   183,
     -34,   -34,   -34,    51,   158,   160,    14,    16,   164,   159,
     161,   174,    36,    37,    38,   162,   171,    36,    37,    38,
     161,   161,    27,    29,    74,    54,    55,    56,    57,   163,
      19,    21,   161,   177,    74,    80,    26,    35,    38,    76,
      25,    48,    77,    61,    63,    64,    42,    83,    82,    85,
      88,   100,   101,     6,   107,   121,   122,   127,   130,   151,
     132,    80,   131,   103,   165,   167,   170,   129,   172,   181,
      20,   114,   111,   108,   182,   169,   145,   154,     0,    87,
     155
};

static const yytype_int16 yycheck[] =
{
      38,    24,    66,    67,    27,    28,    29,    79,     8,   105,
      14,    83,   121,    25,     4,    91,    92,    11,     1,    12,
       8,    11,     4,    37,     6,    89,    19,   102,   103,    12,
      18,   127,    44,    37,     9,   131,    11,   146,    30,    31,
      32,    33,    35,   107,    38,     1,    40,    37,     7,   124,
      40,    10,    44,     9,   130,    45,   165,     4,   122,     6,
      42,     3,   100,    17,     1,    19,    20,   105,    10,    23,
      82,   143,    39,    40,    28,    29,   172,    14,    15,    16,
      17,     3,     0,    37,     3,     5,   182,     1,    10,   127,
      10,    10,     9,   131,    11,   167,     1,   161,     8,    13,
      14,    15,    16,    17,     5,    14,   170,     8,   108,   181,
      15,    16,    17,     1,     5,     5,    37,     9,   141,    10,
      10,   159,    15,    16,    17,     5,     5,    15,    16,    17,
      10,    10,    17,    18,   172,    30,    31,    32,    33,     7,
       4,    37,    10,     9,   182,    11,     8,     8,    17,     8,
      39,    37,     8,    37,    37,    37,    11,     6,    39,     4,
      37,     4,     4,    13,    42,     3,    42,    21,    41,     5,
      37,    11,    25,     6,    26,     9,    24,    40,    22,     9,
      11,    84,    82,    77,    25,   148,   115,   128,    -1,    64,
     129
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    12,    47,    48,     1,    13,    49,    51,    37,
       0,     8,    14,    54,    37,    52,     9,     1,    54,     4,
      49,    37,    50,    55,    59,    39,     8,    59,     1,    59,
      50,     1,     9,     3,    10,     8,    15,    16,    17,    60,
      61,    68,    11,    38,    40,    53,    81,    83,    37,    68,
      68,     1,    68,     5,    30,    31,    32,    33,    44,    56,
      57,    37,    50,    37,    37,    19,    20,    23,    28,    29,
      37,    68,    69,    70,    72,    74,     8,     8,    83,     9,
      11,    82,    39,     6,     3,     4,    62,    62,    37,     4,
      37,    40,    45,    72,    77,    78,    79,    80,    83,    77,
       4,     4,     4,     6,    73,     8,    18,    42,    51,    67,
      81,    53,    58,    81,    56,    14,    50,    63,    64,    65,
      66,     3,    42,    77,     4,    80,    80,    21,    39,    40,
      41,    25,    37,    71,    72,    76,    77,    76,    76,    70,
      77,    54,     7,    10,     9,    66,     3,     5,     8,    57,
      77,     5,    76,    70,    78,    79,    80,    70,     5,    10,
       5,    10,     5,     7,    68,    26,    81,     9,    57,    64,
      24,     5,    22,    75,    72,    77,    57,     9,    81,    77,
      70,     9,    25,    81,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    47,    48,    48,    49,    49,    49,
      49,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    58,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    66,    67,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     4,     2,     5,     4,     4,     4,
       4,     4,     3,     1,     3,     0,     5,     3,     2,     1,
       1,     3,     0,     5,     3,     1,     6,     1,     1,     1,
       1,     6,     4,     3,     0,     3,     3,     5,     3,     0,
       3,     1,     1,     1,     2,     3,     3,     3,     3,     1,
       3,     1,     1,     5,     8,     4,     4,     4,     0,     3,
       1,     2,     3,     0,     1,     4,     2,     0,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     4,     3,
       2,     2,     2,     1,     2,     0,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 101 "yacc.y" /* yacc.c:1646  */
    {
/* 1. programstruct -> program_head; program_body. */
		(yyval).val = "#include <stdio.h>\n" + (yyvsp[-1]).val;
		Statistics();
		cout << (yyval).val;

	}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 108 "yacc.y" /* yacc.c:1646  */
    {
		yerror("Error in program head.");

	}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 112 "yacc.y" /* yacc.c:1646  */
    {
		yerror("Compile error.");
	}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 120 "yacc.y" /* yacc.c:1646  */
    {
//pascal中的program无实际含义
	}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 124 "yacc.y" /* yacc.c:1646  */
    {
/*3. program_head -> program id(idlist) 有参数*/
//pascal中的program无实际含义
	}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 134 "yacc.y" /* yacc.c:1646  */
    {
/*4. program_body -> const_declarations var_declarations subprogram_declarations compound_statement*/
		(yyval).val = (yyvsp[-3]).val + (yyvsp[-2]).val + (yyvsp[-1]).val + "int main()\n{\n" + (yyvsp[0]).val + "return 0;\n}\n";
	}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 138 "yacc.y" /* yacc.c:1646  */
    {
		yerror("Error in const_declarations.");
	}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 141 "yacc.y" /* yacc.c:1646  */
    {
		yerror("Error in var_declarations.");
	}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "yacc.y" /* yacc.c:1646  */
    {
		yerror("Error in subprogram_declarations.");
	}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 147 "yacc.y" /* yacc.c:1646  */
    {
		yerror("Error in compound_statement");
	}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 154 "yacc.y" /* yacc.c:1646  */
    {

		id_nam[id_num] = (yyvsp[0]).val;
		id_num++;
		var_name.append(",");
		var_name.append((yyvsp[0]).val);
	}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "yacc.y" /* yacc.c:1646  */
    {
/*6. idlist -> id*/

		id_num = 0;
		id_nam[id_num] = (yyvsp[0]).val;
		id_num++;
		var_name = (yyvsp[0]).val;
	}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 173 "yacc.y" /* yacc.c:1646  */
    {
/*7. const_declarations -> const const_declaration; */
		(yyval).val = (yyvsp[-1]).val;
	}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 177 "yacc.y" /* yacc.c:1646  */
    {

/*8. const_declarations -> 空*/
		(yyval).val = "";
	}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 185 "yacc.y" /* yacc.c:1646  */
    { 
// 只有relop为=时才可以归约
/*9. const_declaration -> const_declaration; id = const_value*/
		if((yyvsp[-1]).val == "="){
			const_id = (yyvsp[-2]).val;
			if (add_const(const_id, (yyvsp[0]).typ) == FAILED )
				yyerror(((yyvsp[-2]).val + "already exists!").c_str());
			else (yyval).val = (yyvsp[-4]).val + "const " + (yyvsp[0]).typ + " " + (yyvsp[-2]).val + "=" + (yyvsp[0]).val + ";\n";
		}
		else{
			yyerror("syntax error(EQ)!!!");
		}
		
	}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 199 "yacc.y" /* yacc.c:1646  */
    { 
//同上
/*10. const_declaration -> id = const_value*/
		if((yyvsp[-1]).val == "="){
			const_id = (yyvsp[-2]).val;
			if (add_const(const_id, (yyvsp[0]).typ) == FAILED){
				yyerror(((yyvsp[0]).val + "already exists!").c_str());
			}
			else (yyval).val = string("const ") + (yyvsp[0]).typ + " " + (yyvsp[-2]).val + "=" + (yyvsp[0]).val + ";\n";
		}
		else{
			yyerror("syntax error(EQ)!!!");
		}
	}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 216 "yacc.y" /* yacc.c:1646  */
    { 
/*11. const_value -> ADDOP num*/
		if ((yyval).val == "-"){
			(yyval).typ = (yyvsp[0]).typ;
			(yyval).val = "-" + (yyvsp[0]).val;
		}

		if ((yyval).val == "+"){
			(yyval).typ = (yyvsp[0]).typ;
			(yyval).val = "+" + (yyvsp[0]).val;
		}
	}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 228 "yacc.y" /* yacc.c:1646  */
    {
/*12. const_value -> num*/
		(yyval).typ = (yyvsp[0]).typ;
		(yyval).val = (yyvsp[0]).val;
	}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 233 "yacc.y" /* yacc.c:1646  */
    { 
/*13. const_value -> 'letter'*/
// 单个字符，注意在翻译时加上两侧的单引号
		(yyval).typ = "char";
		(yyval).val =  (yyvsp[0]).val;
	}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 246 "yacc.y" /* yacc.c:1646  */
    {
/*14. var_declarations -> var var_declaration; */
		(yyval).val = (yyvsp[-1]).val;
		//cerr << "????" << $2.val << endl;
	}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 251 "yacc.y" /* yacc.c:1646  */
    {
/*15. var_declarations -> 空*/
		(yyval).val = "";
	}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 259 "yacc.y" /* yacc.c:1646  */
    {
/*16. var_declaration -> var_declaration; idlist : type*/

		(yyval).val = (yyvsp[-4]).val;	
		if (array_flag == 0){
			(yyval).val += (yyvsp[0]).val + " " + var_name + ";\n";
		}
		else {
			for(int i = 0; i < id_num; i ++){
				(yyval).val += (yyvsp[0]).typ + " " + id_nam[i];
				for(auto p: period_list)
					(yyval).val += "[" + p + "]";
				if(i != id_num - 1) (yyval).val += ",";
				else (yyval).val += ";\n";
			}
			array_flag = 0;
		}
	}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 278 "yacc.y" /* yacc.c:1646  */
    {
/*17. var_declaration -> idlist : type*/
//是否存在数组元素，不存在则较为方便，存在数组元素则需要转换顺序的语义动作
		if (array_flag == 0){
			(yyval).val = (yyvsp[0]).val + " " + var_name + ";\n";
		}
		else {
			(yyval).val = "";
			for(int i = 0; i < id_num; i ++){
				(yyval).val += (yyvsp[0]).typ + " " + id_nam[i];
				for(auto p: period_list)
					(yyval).val += "[" + p + "]";
				if(i != id_num - 1) (yyval).val += ",";
				else (yyval).val += ";\n";
			}
			array_flag = 0;
		}
	}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 299 "yacc.y" /* yacc.c:1646  */
    {
/*18. type -> basic_type*/
		(yyval).typ = (yyvsp[0]).typ;
		if (array_flag == 0){
			for (int i = 0; i < id_num; i++){
				if (add_variable(id_nam[i], (yyval).typ) == FAILED){
					yyerror((id_nam[i] + " already exists").c_str());
				}
			}
		}
		dimen = 0;
	}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 311 "yacc.y" /* yacc.c:1646  */
    {
/*19. type -> array [period] of basic_types*/
		(yyval).typ = (yyvsp[0]).typ;
		array_flag = 1;
		dimen = period_list.size();
		for (int i = 0; i < id_num; i++){
			if (add_array(id_nam[i], (yyvsp[0]).typ, dimen) == FAILED){
				yyerror((id_nam[i] + " already exists").c_str());
			}
		}
		dimen = 0;
	}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 327 "yacc.y" /* yacc.c:1646  */
    {
/*20. basic_type -> integer*/
		(yyval).typ = "int";
		(yyval).val = "int";
	}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 332 "yacc.y" /* yacc.c:1646  */
    {
/*21. basic_type -> real*/
		(yyval).typ = "float";
		(yyval).val = "float";
	}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 337 "yacc.y" /* yacc.c:1646  */
    {
/*22. basic_type -> boolean*/
		(yyval).typ = "boolean";
		(yyval).val = "boolean";
	}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 342 "yacc.y" /* yacc.c:1646  */
    {
/*23. basic_type -> char */
		(yyval).typ = "char";
		(yyval).val = "char";
	}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 351 "yacc.y" /* yacc.c:1646  */
    { 
/*24. period -> period, num .. num */
/*将period, num .. num转换为period[num2-num1+1]*/
		int x = atoi((yyvsp[0]).val.c_str()) - atoi((yyvsp[-3]).val.c_str()) + 1;
		if(x <= 0) {
			yyerror("period error!");
		}
		else
			period_list.push_back(to_string(x));
	}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 361 "yacc.y" /* yacc.c:1646  */
    {
/*25. period -> num .. num*/
		period_list.clear();
		int x = atoi((yyvsp[0]).val.c_str()) - atoi((yyvsp[-3]).val.c_str()) + 1;
		if(x <= 0) {
			yyerror("period error!");
		}
		else
			period_list.push_back(to_string(x));
	}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 375 "yacc.y" /* yacc.c:1646  */
    {
						/* 26.	subprogram_declarations -> subprogram_declarations   subprogram  ;*/
								
								(yyval).val = (yyvsp[-2]).val + (yyvsp[-1]).val;
								
							}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 381 "yacc.y" /* yacc.c:1646  */
    {
						/* 27.	subprogram_declarations ->  ε */
								(yyval).val = "";
						}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 386 "yacc.y" /* yacc.c:1646  */
    {
						/* 28.	subprogram -> subprogram_head   ;  subprogram_body */
								//symboltable_print(st);
								if(PopBlock() == FAILED){//yyerror("pop block error.");
								}
								(yyval).val = (yyvsp[-2]).val + (yyvsp[0]).val;

							}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 395 "yacc.y" /* yacc.c:1646  */
    {
						/* 29.	subprogram_head -> procedure  id  formal_parameter    */
								{ 
								if(FindSymbol((yyvsp[-1]).val) == FAILED){
									add_procedure((yyvsp[-1]).val, paraList.size());
									if(InsertBlock() == FAILED){yyerror("insert block error.");} 
									(yyval).val = "void " + (yyvsp[-1]).val + "(" + (yyvsp[0]).val + ")\n";
									for(int i = 0; i < paraList.size(); i++){
											Symbol tmp = paraList.at(i);
											if(tmp.isref){
												add_refpara((yyvsp[-1]).val, tmp.name, tmp.type);
											}
											else{
												add_para((yyvsp[-1]).val, tmp.name, tmp.type);
											}
									}
								}
								else{
									yyerror(("function "+ (yyvsp[-1]).val + " declared implicitly.").c_str());
								}
								paraList.clear();
								}
							}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 418 "yacc.y" /* yacc.c:1646  */
    {
						/* 30.	subprogram_head -> function  id  formal_parameter  :  simple_type     */
								if(FindSymbol((yyvsp[-3]).val) == FAILED){
									add_function((yyvsp[-3]).val, (yyvsp[0]).val, paraList.size());
									if(InsertBlock() == FAILED){yyerror("insert block error.");}
									(yyval).val = (yyvsp[0]).val + " " + (yyvsp[-3]).val + "(" + (yyvsp[-2]).val + ")\n";
									for(int i = 0; i < paraList.size(); i++){
											Symbol tmp = paraList.at(i);
											if(tmp.isref){
												add_refpara((yyvsp[-3]).val, tmp.name, tmp.type);
											}
											else{
												add_para((yyvsp[-3]).val, tmp.name, tmp.type);
											}
									}
								}
								else{
									yyerror(("function "+ (yyvsp[-3]).val + " declared implicitly.").c_str());
								}
								paraList.clear();
								//symboltable_print(st);
							}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 441 "yacc.y" /* yacc.c:1646  */
    {
						/* 31.	formal_parameter -> (  parameter_list  )    */
								(yyval).val = (yyvsp[-1]).val;
							}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 445 "yacc.y" /* yacc.c:1646  */
    {
						/* 32.	formal_parameter ->  ε */
								(yyval).val = "";
						}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 451 "yacc.y" /* yacc.c:1646  */
    {
						/* 33.	parameter_list -> parameter_list  ;  parameter     */
								(yyval).val = (yyvsp[-2]).val + ", " + (yyvsp[0]).val;
								paraList2.clear();
							}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 456 "yacc.y" /* yacc.c:1646  */
    {
						/* 34.	parameter_list -> parameter*/
								(yyval).val = (yyvsp[0]).val;
								paraList2.clear();
							}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 462 "yacc.y" /* yacc.c:1646  */
    {
						/* 35.	parameter -> var_parameter   */
								(yyval).val = (yyvsp[0]).val;
							}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 466 "yacc.y" /* yacc.c:1646  */
    {
						/* 36.	parameter -> value_parameter */
								(yyval).val = (yyvsp[0]).val;
							}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 471 "yacc.y" /* yacc.c:1646  */
    {
						/* 37.	var_parameter -> var  value_parameter  */
								for(int i = (int)paraList.size() - 1; i >= (int)paraList.size() - (int)paraList.size(); i --)
									paraList[i].isref = 1;
								int num = paraList2.size();
								string out = "";
								for(int i = 0; i < num; i++){
									out = out + (yyvsp[0]).typ + " ";
									out +="&";
									out = out + paraList2.at(i).name + ", ";
								}
								(yyval).val = out.substr(0, out.size()-2);
							}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 485 "yacc.y" /* yacc.c:1646  */
    {
						/* 38.	value_parameter -> idlist  :  simple_type  */
								for(int i = 0; i < id_num; i ++){
									Symbol tmp;
									tmp.name = id_nam[i];
									tmp.isref = 0;
									tmp.type = (yyvsp[0]).typ;
									paraList.push_back(tmp);
									paraList2.push_back(tmp);
								}

								
								int num = paraList2.size();
								string out = "";
								for(int i = 0; i < num; i++){
									out = out + (yyvsp[0]).val + " ";
									if(paraList2.at(i).isref){out +="&";}
									out = out + paraList2.at(i).name + ", ";
								}
								(yyval).val = out.substr(0, out.size()-2);
								(yyval).typ = (yyvsp[0]).typ;
								//cerr << $$.val << endl;
							}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 509 "yacc.y" /* yacc.c:1646  */
    {
						/* 39.	subprogram_body  -> const_declarations  var_declarations  compound_statement */
								(yyval).val = "{\n" + (yyvsp[-2]).val + (yyvsp[-1]).val + (yyvsp[0]).val + "}\n";
							}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 514 "yacc.y" /* yacc.c:1646  */
    {
						/* 40.	compound_statement -> begin  statement_list  end  */
								(yyval).val = (yyvsp[-1]).val;
							}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 519 "yacc.y" /* yacc.c:1646  */
    {
						/* 41.	statement_list -> statement_list  ;  statement */    
								(yyval).val = (yyvsp[-2]).val + (yyvsp[0]).val;
							}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 523 "yacc.y" /* yacc.c:1646  */
    {
						/* 42.	statement_list -> statement */
								(yyval).val = (yyvsp[0]).val;

							}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 529 "yacc.y" /* yacc.c:1646  */
    {
						/* 43.	statement -> variable  assignop  expression  */
								//43
								// check return statement
								if(GetType((yyvsp[-2]).val) == "function"){
									if(GetSubType((yyvsp[-2]).val) == (yyvsp[0]).typ){
										(yyval).val = "return " + (yyvsp[0]).val + ";\n";
									}
									else{
										yyerror("Wrong return statement.");
									}
								}
								else{
									string a = GetType((yyvsp[-2]).val);
									if(a == "FAILED") {
										int cpos = 0;
										for(; cpos < (yyvsp[-2]).val.size(); cpos ++) if((yyvsp[-2]).val[cpos] == '[') break;
										if(cpos == (yyvsp[-2]).val.size()){
											err_info = string("no such variable ") + (yyvsp[-2]).val;
											yyerror(err_info.c_str());
										}
										else{
											string aname = (yyvsp[-2]).val.substr(0, cpos);
											a = GetSubType(aname);
											if(a == "FAILED") {
												err_info = string("no such variable ") + (yyvsp[-2]).val;
												yyerror(err_info.c_str());
											} 
											else (yyval).val = (yyvsp[-2]).val + "=" + (yyvsp[0]).val + ";\n";
										}
									}
									else{
										(yyval).val = (yyvsp[-2]).val + "=" + (yyvsp[0]).val + ";\n";
									}	
								}

							}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 566 "yacc.y" /* yacc.c:1646  */
    {
						/* 44.	statement ->  procedure_call */
								(yyval).val = (yyvsp[0]).val + ";\n";
							}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 570 "yacc.y" /* yacc.c:1646  */
    {
						/* 45.	statement ->  compound_statement  */
								(yyval).val + (yyvsp[0]).val;
							}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 574 "yacc.y" /* yacc.c:1646  */
    {
						/* 46.	statement ->  if  expression  then statement  else_part  */
								(yyval).val = "if(" + (yyvsp[-3]).val + ")\n{\n" + (yyvsp[-1]).val + "}\n" + (yyvsp[0]).val;

								if((yyvsp[-3]).typ != "boolean"){
									yyerror("error in if expression type");
								}
							}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 582 "yacc.y" /* yacc.c:1646  */
    {
						/* 47.	statement ->  for  id  assignop  expression   to  expression  do  statement */
								string ret = GetType((yyvsp[-6]).val);
								
								if(ret == "FAILED"){
									yyerror(("variable " + (yyvsp[-6]).val + " not declared.").c_str());
								}
								else {
									if(ret != "int" || (yyvsp[-4]).typ != "int" || (yyvsp[-2]).typ != "int"){
										yyerror("Wrong type");
									}
									else if((yyvsp[-4]).val > (yyvsp[-2]).val){
										yyerror("Range error.");
									}
									else{
										(yyval).val = "for(" + (yyvsp[-6]).val + "=" + (yyvsp[-4]).val + "; " + (yyvsp[-6]).val + "<=" + (yyvsp[-2]).val + "; " + (yyvsp[-6]).val + "++)\n{\n" + (yyvsp[0]).val + "}\n";
									}
								}
							}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 601 "yacc.y" /* yacc.c:1646  */
    {
						/* 48.	statement -> read ( variable_list  )  */
								(yyval).val = ReadToScanf((yyvsp[-1]).val);
							}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 605 "yacc.y" /* yacc.c:1646  */
    {
						/* 49.	statement -> write ( expression_list )  */
								(yyval).val = WriteToPrintf((yyvsp[-1]).val);
							}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 609 "yacc.y" /* yacc.c:1646  */
    {
						/* extra. statement -> while expr do statement*/
								(yyval).val = "while(" + (yyvsp[-2]).val + ")\n{\n" + (yyvsp[0]).val + "}\n";
							}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 613 "yacc.y" /* yacc.c:1646  */
    {
						/* 50.	statement -> ε */ 
								(yyval).val = "";
						}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 620 "yacc.y" /* yacc.c:1646  */
    {
						/* 51.	variable_list -> variable_list , variable    */
								(yyval).val = (yyvsp[-2]).val + "," + (yyvsp[0]).val;
								vari_list.push_back((yyvsp[0]));
							}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 625 "yacc.y" /* yacc.c:1646  */
    {
						/* 52.	variable_list ->  variable */
								vari_list.clear();
								vari_list.push_back((yyvsp[0]));
								(yyval).val = (yyvsp[0]).val;
							}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 632 "yacc.y" /* yacc.c:1646  */
    {
						/* 53.	variable -> id  id_varpart */
								string flag = GetType((yyvsp[-1]).val);
								int did = FindSymbol((yyvsp[-1]).val);
								//symbol_print(st.Sstack[did]);
								
								if(flag == "FAILED") err_info = "id " + (yyvsp[-1]).val + " doesn't exist.", yyerror(err_info.c_str());
								else if(flag == "array"){
									int d = GetDimension((yyvsp[-1]).val);
									if(expr_list.size() != d) yyerror("array dimenssion error!");
									else{
										(yyval).typ = GetSubType((yyvsp[-1]).val);
										(yyval).val = (yyvsp[-1]).val;
										for(auto p: expr_list)
											(yyval).val = (yyval).val + '[' + p.val + ']';
									}
								}
								else if(flag == "functuon" || flag == "procedure"){
									if(GetDimension((yyvsp[-1]).val) != 0) yyerror("parameter number error"); //函数或者过程参数个数错误
									else{
										(yyval).typ = flag;
										(yyval).val = (yyvsp[-1]).val;
									}
								}
								else{
									(yyval).typ = flag;
									(yyval).val = (yyvsp[-1]).val;
								}
							}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 661 "yacc.y" /* yacc.c:1646  */
    {
						/* 54.	id_varpart -> [ expression_list ]   */
								(yyval).val = '[' + (yyvsp[-1]).val + ']';
							}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 665 "yacc.y" /* yacc.c:1646  */
    {
						/* 55.	id_varpart -> ??*/
								(yyval).val = (yyval).typ = "";
							}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 670 "yacc.y" /* yacc.c:1646  */
    {
						/* 56.	procedure_call -> id  */
								string flag = GetType((yyvsp[0]).val);
								if(flag == "FAILED") err_info = "id " + (yyvsp[0]).val + " doesn't exist.", yyerror(err_info.c_str());
								else if(flag != "procedure") {
									err_info = "id:" + (yyvsp[0]).val + " is not a procedure";
									yyerror(err_info.c_str());
								}
								else{
									(yyval).typ = flag;
									(yyval).val = (yyvsp[0]).val;
								}
							}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 683 "yacc.y" /* yacc.c:1646  */
    {
						/* 57.	procedure_call -> id ( expression_list ) */
								string flag = GetType((yyvsp[-3]).val);
								if(flag == "FAILED") err_info = "id " + (yyvsp[-3]).val + " doesn't exist.", yyerror(err_info.c_str());
								else if(flag != "procedure") {
									err_info = "id:" + (yyvsp[-3]).val + " is not a procedure";
									yyerror(err_info.c_str());
								}
								else{
									typ_list.clear();
									for(auto p: expr_list)
										typ_list.push_back(p.typ);
									int fflag = CheckType((yyvsp[-3]).val, typ_list);
									if(fflag == DIMENSION_ERROR) yyerror("DIMENSION_ERROR!"); //维度不匹配
									else if(fflag == NOT_MATCH) yyerror("parameters don't match!"); // 类型不匹配
									else{
										(yyval).typ = "procedure";
										(yyval).val = (yyvsp[-3]).val + "(" + (yyvsp[-1]).val + ")";
									}
								}
							}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 705 "yacc.y" /* yacc.c:1646  */
    {
						/* 58.	else_part -> else statement   */
								(yyval).typ = (yyvsp[0]).typ;
								(yyval).val = "else\n{\n" + (yyvsp[0]).val + "}\n";
							}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 710 "yacc.y" /* yacc.c:1646  */
    {
						/* 59.	else_part ->  ??*/
								(yyval).typ = "int";
								(yyval).val = "";
						}
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 716 "yacc.y" /* yacc.c:1646  */
    {
						/* 60.	expression_list -> expression_list  ,  expression   */
								(yyval).val = (yyvsp[-2]).val + "," + (yyvsp[0]).val;
								expr_list.push_back((yyvsp[0]));
							}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 721 "yacc.y" /* yacc.c:1646  */
    {
						/* 61.	expression_list ->  expression  */
								expr_list.clear();
								expr_list.push_back((yyvsp[0]));
								(yyval) = (yyvsp[0]);
							}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 728 "yacc.y" /* yacc.c:1646  */
    {
						/* 62.	expression -> simple_expression  relop  simple_expression */
								if((yyvsp[0]).typ == "string"){
									yyerror("string is not expected here.");
								}
								if((yyvsp[-2]).typ != (yyvsp[0]).typ){
									yyerror("The expression type should be same on both sides.");
								}

 								if((yyvsp[-1]).val == "="){
									(yyval).val = (yyvsp[-2]).val + "==" + (yyvsp[0]).val;
								}
								else if((yyvsp[-1]).val == "and"){
									(yyval).val = (yyvsp[-2]).val + "&&" + (yyvsp[0]).val;
								}
								else if((yyvsp[-1]).val == "or"){
									(yyval).val = (yyvsp[-2]).val + "||" + (yyvsp[0]).val;
								}
								else{
									(yyval).val = (yyvsp[-2]).val + (yyvsp[-1]).val + (yyvsp[0]).val;
								}
								(yyval).typ = "boolean";
							}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 751 "yacc.y" /* yacc.c:1646  */
    {
						/* 63.	expression ->  simple_expression */
								(yyval).typ = (yyvsp[0]).typ;
								(yyval).val = (yyvsp[0]).val;
							}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 757 "yacc.y" /* yacc.c:1646  */
    {
						/* 64.	simple_expression -> simple_expression  addop term   */
								if(((yyvsp[-1]).val=="+")||((yyvsp[-1]).val=="-")){
									if(((yyvsp[-2]).typ == "float")||((yyvsp[0]).typ == "float")){
										(yyval).typ = "float";
										(yyval).val = (yyvsp[-2]).val + (yyvsp[-1]).val + (yyvsp[0]).val;
									}
									else if(((yyvsp[-2]).typ == "int")&&((yyvsp[0]).typ == "int")){
										(yyval).typ = "int";
										(yyval).val = (yyvsp[-2]).val + (yyvsp[-1]).val + (yyvsp[0]).val;
									}
									else
										yyerror("The addop is wrong.");
								}
								else{
									if(((yyvsp[-2]).typ == "boolean")&&((yyvsp[-1]).typ == "boolean")){
										(yyval).typ = "boolean";
										(yyval).val = (yyvsp[-2]).val + (yyvsp[-1]).val + (yyvsp[0]).val;
									}
									else
										yyerror("The addop is wrong.");
								}
							}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 780 "yacc.y" /* yacc.c:1646  */
    {
						/* 65.	simple_expression -> term */
								(yyval).typ = (yyvsp[0]).typ;
								(yyval).val = (yyvsp[0]).val;
							}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 786 "yacc.y" /* yacc.c:1646  */
    {
						/* 66.	term -> term  mulop  factor */
								if(((yyvsp[-1]).val=="*")||((yyvsp[-1]).val=="/")){
									if(((yyvsp[-2]).typ == "float")||((yyvsp[0]).typ == "float"))
										(yyval).typ = "float";
									else
										(yyval).typ = "int";
									if(((yyvsp[-1]).val=="/")&&((yyvsp[0]).val== "0" ))
										yyerror("/0");
									(yyval).val = (yyvsp[-2]).val + (yyvsp[-1]).val + (yyvsp[0]).val; 
								}
								else if((yyvsp[-1]).val == "div" || (yyvsp[-1]).val == "mod"){
									if((yyvsp[-2]).typ != "int" || (yyvsp[0]).typ != "int") yyerror("type error!");
									else{
										(yyval).typ = "int";
										if((yyvsp[-1]).val == "div") (yyval).val = (yyvsp[-2]).val + "/" + (yyvsp[0]).val;
										else (yyval).val = (yyvsp[-2]).val + "%" + (yyvsp[0]).val;
									}
								}
							}
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 806 "yacc.y" /* yacc.c:1646  */
    {
						/* 67.	term -> factor */
								(yyval).typ = (yyvsp[0]).typ;
								(yyval).val = (yyvsp[0]).val;
							}
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 812 "yacc.y" /* yacc.c:1646  */
    {
						/* 68.	factor -> num  */
								(yyval).typ = (yyvsp[0]).typ;
								(yyval).val = (yyvsp[0]).val;
							}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 817 "yacc.y" /* yacc.c:1646  */
    {
						/* 69.	factor -> variable      */
								(yyval).typ = (yyvsp[0]).typ;
								(yyval).val = (yyvsp[0]).val;
							}
#line 2481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 822 "yacc.y" /* yacc.c:1646  */
    {
						/* 70.	factor ->  id  ( expression_list ) */
								string flag = GetType((yyvsp[-3]).val);
								if(flag == "FAILED") {
									//symboltable_print(st);
									err_info = "id " + (yyvsp[-3]).val + " doesn't exist.", yyerror(err_info.c_str()); //标识符不存在
								}
								else if(flag != "function"){
									err_info = "id:" + (yyvsp[-3]).val + " is not a procedure";
									yyerror(err_info.c_str());
								}
								else{
									typ_list.clear();
									for(auto p: expr_list)
										typ_list.push_back(p.typ);
									int fflag = CheckType((yyvsp[-3]).val, typ_list);
									if(fflag == DIMENSION_ERROR) yyerror("DIMENSION_ERROR!"); //维度不匹配
									else if(fflag == NOT_MATCH) yyerror("parameters don't match!"); // 类型不匹配
									else{
										//sssssssss
										(yyval).typ = GetSubType((yyvsp[-3]).val);
										(yyval).val = (yyvsp[-3]).val + "(" + (yyvsp[-1]).val + ")";
									}
								}
							}
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 847 "yacc.y" /* yacc.c:1646  */
    {
						/* 71.	factor -> ( expression )   */
								(yyval).typ = (yyvsp[-1]).typ;
								(yyval).val = "(" + (yyvsp[-1]).val + ")";
							}
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 852 "yacc.y" /* yacc.c:1646  */
    {
						/* 72.	factor ->  not  factor  */
								(yyval).typ = (yyvsp[-1]).typ;
								(yyval).val = "!" + (yyvsp[0]).val;
							}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 857 "yacc.y" /* yacc.c:1646  */
    { //ֻ???addopΪ-ʱ?ſ?Թ??
						/* 73.	factor -> uminus  factor*/
								(yyval).typ = (yyvsp[-1]).typ;
								(yyval).val = "-" + (yyvsp[0]).val;
							}
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 863 "yacc.y" /* yacc.c:1646  */
    {
						/* 74.	digits -> digits DIGIT */
								(yyval).typ = (yyvsp[-1]).typ;
								(yyval).val = (yyvsp[-1]).val + (yyvsp[0]).val;
							}
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 868 "yacc.y" /* yacc.c:1646  */
    {
						/* 75.	digits -> DIGIT */
								(yyval).typ = "int";
								(yyval).val = (yyvsp[0]).val;
							}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 874 "yacc.y" /* yacc.c:1646  */
    {
						/* 76.	optional_fraction -> POINT digits*/
								(yyval).typ = "float";
								(yyval).val = "." + (yyvsp[0]).val;
							}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 879 "yacc.y" /* yacc.c:1646  */
    {
						/* 77.		optional_fraction -> ??*/ 
								(yyval).typ = "int";
								(yyval).val = "";
						}
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 885 "yacc.y" /* yacc.c:1646  */
    {
						/* 78.	Num -> digits optional_fraction */
								if((yyvsp[0]).typ == "int") (yyval).typ = "int";
								else (yyval).typ = "float";
								(yyval).val = (yyvsp[-1]).val + (yyvsp[0]).val;
								//cerr << "num:" << $$.val << " " + pos->view() << endl; 
							}
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2597 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 893 "yacc.y" /* yacc.c:1906  */

void yerror(const char * s){
	cerr << s << endl;
	return;
}

void Statistics(){
	if(!err_cnt) cerr << "0 error found" << endl;
	else cerr << err_cnt << " error(s) detected" << endl;
	cerr << "compile complete ^^" << endl;
	cerr << "----------------------" << endl;
	return;
}

void yyerror(const char * s){
	err_cnt ++;
	cerr << s << " @ " << pos -> view2() << endl;
	return;
}

//xzc
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
		if(i != expr_list.size()-1) {out += "";}
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
//xzc
