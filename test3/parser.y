%locations
%error-verbose
%debug

%token id
%token num
%token letter
%token digits
%token string
%token SYM_program SYM_function SYM_procedure SYM_array SYM_const SYM_file
    SYM_lable SYM_packed SYM_var SYM_record SYM_set SYM_type SYM_case
    SYM_of SYM_do SYM_for SYM_while SYM_repeat SYM_until SYM_if SYM_then
    SYM_else SYM_to SYM_downto SYM_goto SYM_with SYM_and SYM_or SYM_not
    SYM_div SYM_mod SYM_in SYM_begin SYM_end SYM_nil SYM_integer SYM_real
    SYM_boolean SYM_char SYM_string
%token OPR_become OPR_plus OPR_minus OPR_times OPR_slash OPR_lss OPR_leq
    OPR_gtr OPR_geq OPR_neq OPR_eql OPR_jin OPR_eval
%token BDY_lparen BDY_rparen BDY_comma BDY_semicolon BDY_lhua BDY_rhua BDY_colon
    BDY_squo BDY_lfang BDY_rfang BDY_dot BDY_ddot

%nonassoc LOWER_THAN_ELSE
%nonassoc SYM_else

%code requires{
#define YYSTYPE char*
}

%code{
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
#include <stdarg.h>
#include"code.h"
#include "parsererror.h"
#include"symtable.h"

extern FILE* yyin;
extern char* patt;
extern int yylineno;
char*  filename;
char*  sentence;
char* var_name;
char* array_num;
char* s;
unsigned int error_num = 0;
char * function_type[3];
char* function_name="";
int flag=0;
int array_flag=0;


int function_id=0;
int var_flag=0;

int const_flag=0;
char * function_type[3];
char * id_type;
int dimen = 0;
symbol_type lefttype;
int pos;
char * id_name[10]; 
int id_num;
int truble;
int var_flag;
int function_flag;
char * func_type;
char * func_name;
char * pro_name;
int procedure_flag;
int parameter_flag;
int par_num;
char * const_type;
char * const_id;
char * id_name1;
symbol_type par_type_list[10];
int var_dec_flag;

char*global_pro_name[]={"write_char","write_int","write_string","read_char","read_int"};
char*global_par_name[]={"w_c","w_i","w_s","r_c","r_i"};
int global_par_type[]={CHAR,INT,STRING,CHAR,INT};

#define MAX_SIZE 256
#define	MAX_SIZE_OF_PF 10

symbol_type stack_c[MAX_SIZE];				//分析栈存储类型
int position_c = 0;							//分析栈当前栈顶位置
int num_of_arr = 0;							//
symbol_type type_of_pf[MAX_SIZE_OF_PF];		//用来存储获取的函数或者过程的形参
char* array_of_pf[10];						//用来存储函数调用中的函数名称
int array_of_dimen[10]={0};						//用来记录每次嵌套调用时的形参进行程度
int depth_of_pf=0;							//用来记录函数当前深度
int dimension = 0;						
char* ttemp;
char* itemp;
int numa;

void into_pf(const char* name);				//进入函数或过程调用时进行的保存现场操作
void out_pf();								//完成函数或者过程调用所需要的恢复现场操作
void into_pf(const char* name)
{
	if( depth_of_pf == 0)
	{
		array_of_pf[0] = name;
		dimension = 0;
		depth_of_pf++;
	}
	else 
	{
		array_of_pf[depth_of_pf] = name;
		array_of_dimen[depth_of_pf-1] = dimension;
		depth_of_pf++;
		dimension = 0;
	}
}

void out_pf()
{
	depth_of_pf--;
	if(depth_of_pf!=0)
		dimension = array_of_dimen[depth_of_pf-1];
}




typedef struct p_list
{
    char * name;
    char * type;
	int is_var;
    char * proc_func_name;
}p_list;

int par_all_num;
p_list par_list[50];

int get_parameter(char * a)//返回第一个参数的位置
{
    int i = 0;
    for( ; i < par_all_num; i++ )
    {
        if( strcmp( par_list[i].proc_func_name, a ) )
            return i;
    }
    return -1;
}

symbol_type return_symtype(char* a)
{
    if(strcmp(a,"int")==0)
    {
        return INT;
    }
    if(strcmp(a,"char")==0)
    {
        return CHAR;
    }
    if(strcmp(a,"bool")==0)
    {
        return BOOL;
    }
    if(strcmp(a,"float")==0)
    {
        return FLOAT;
    }
	if(strcmp(a,"string")==0)
    {
        return STRING;
    }
}

char * return_chartype(symbol_type a)
{
    if(a == INT)
    {
        return "int";
    }
    if(a == CHAR)
    {
        return "char";
    }
    if(a == BOOL)
    {
        return "bool";
    }
    if(a == FLOAT)
    {
        return "float";
    }
	if(a==STRING)
    {
        return "string";
    }
}

char * get_num_type( char * a )
{
    if(strstr(a,"."))
    {
        return "float";
    }
    return "int";
}

void lyyerror(YYLTYPE t, const char *s, ...)
{
    va_list ap;
    va_start(ap, s);

    if(t.first_line)
        fprintf(stderr, "%s: line %d-%d: column %d-%d: error: ", filename,
            t.first_line, t.last_line, 
            t.first_column, t.last_column);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
    underline_code(filename, t.first_line, t.first_column, t.last_column-t.first_column);
    error_num++;
}

void yyerror(const char* str, ...)
{
    lyyerror(yylloc, str);
}

int yywrap()
{
    return 1;
}

void help(const char* command_line)
{
    printf("Pascal-S Compiler 1.0.0. Build Time: %s %s\n", __DATE__, __TIME__);
    puts("This software is written by Donggang Jia, Guoliang Tian, "
        "Yongjie Xu, Yongkang Huang, Zhaoyu Gan and Zheyuan Tian.");
    putchar('\n');
    printf("Usage: %s <filename>\n", command_line);
}

struct id_list* head;
struct id_list* ppp;
struct id_list* test;
struct id_list* test_function;
struct id_list* p1;
struct id_list* p2;



int main(int argc, char* argv[])
{
    head=(struct id_list*)malloc(sizeof(struct id_list));
    head->next=NULL;
    ppp=(struct id_list*)malloc(sizeof(struct id_list));
    ppp->next=NULL;
    if(argc == 1)
    {
        help(argv[0]);
        puts("No input file.");
        return -1;
    }

    // Call Parser
    yyin=fopen(argv[1], "r");
    if(yyin == NULL)
    {
        printf("%s: error: Can't open file.\n", argv[1]);
        exit(255);
    }
    filename = argv[1];
    file_clean();
    yyparse();
    fclose(yyin);
    printf("Finished. %u error(s).\n", error_num);
    if(error_num)
        {
            system("rm print_file.cpp");
        }
    else
    {
        system("gcc print_file.cpp -o pascal_c");
    }
    return 0;
}
}

%%
programstruct:
    program_head    { 
        /* programstruct  →  program_head ; program_body . */
        /* 翻译方案 1 */ 
		
		locate_table();
		
		for(int i = 0;i < 5; i++)
		{
		    if(!add_procedure(global_pro_name[i],1))
                yyerror(global_pro_name[i]);
            
		    if( !add_parameter(global_pro_name[i],global_par_name[i],global_par_type[i] ))
        	    yyerror(global_pro_name[i]);
		}

		
        sentence="#include<stdio.h>\n#include<stdlib.h>\n#include\"code.h\"\n";
        print(sentence);
        //print("#define out(name) printf(\"%d\",name)\n#define out(name) printf(\"%c\",name)\n#define out(name)  printf(\"%s\",name)\n#define read(name) scanf(\"%d\",&name)\n ");
    }
    BDY_semicolon program_body BDY_dot{print("\n}");relocate_table();}
    | error BDY_semicolon program_body BDY_dot
    ;
program_head:
    SYM_program id BDY_lparen idlist BDY_rparen
    { 
        /* program_head → id ( idlist ) */
        /* 翻译方案 2 */
    }
    | error BDY_rparen
    ;
program_body:
    const_declarations
    var_declarations
    subprogram_declarations
    program_compound_statement
    { 
        /* program_body */
        /* 翻译方案 3 */ 
    }
    ;
idlist:
    idlist BDY_comma id 
    {
        id_name[id_num] = $3;
        id_num++; 
		
        var_name=char_strcpy(var_name,",");
        var_name=char_strcpy(var_name,$3);
        //printf("%s\n",var_name);
        /* idlist → idlist , id */
        /* 翻译方案 4 */
    }
    |
    id 
    {   
	    id_name[id_num] = $1;
        id_num++;
		
		var_name=$1;
        /* idlist → id */ 
        /* 翻译方案 5 */
    }
    ;
function_idlist:
    function_idlist BDY_comma id 
    {
		
        p1=(struct id_list*)malloc(sizeof(struct id_list));
        p1->type="";
        p1->next=NULL;
        p1->name=$3;
        p1->id_list_id=function_id;
        ppp->next=p1;
        ppp=ppp->next;
        //printf("%s\n",var_name);
        /* idlist → idlist , id */
        /* 翻译方案 4 */
    }
    |
    id 
    {   
	    
		if(head->next==NULL)
        {
        ppp->type="";    
        ppp->name=$1;
        ppp->id_list_id=function_id;
        head->next=ppp;
        }
        else
        {
        p2=(struct id_list*)malloc(sizeof(struct id_list));
        p2->type="";
        p2->name=$1;
        p2->id_list_id=function_id;
        ppp->next=p2;
        ppp=ppp->next;
        }

        
        /* idlist → id */ 
        /* 翻译方案 5 */
    }
    ;
const_declarations:
    SYM_const{print("const ");const_flag=1;} const_declaration BDY_semicolon
    { 
        const_flag=0;
		
		print(";\n");
        /* const_declarations → const const_declaration ; */
        /* 翻译方案 6 */  
    }
    |
    {
        /* const_declarations → ε */ 
        /* 翻译方案 7 */
    }
    ;
const_declaration:
    const_declaration BDY_semicolon{print(";\nconst ");} id {const_id = $4;}OPR_eql const_value
    {
        /* const_declaration → const_declaration ; id = const_value */
        /* 翻译方案 8 */ 
    }
    |
    id{const_id = $1;} OPR_eql const_value
    {
        /* const_declaration → id = const_value */ 
        /* 翻译方案 9 */
    }
    | error BDY_semicolon id OPR_eql const_value;

    
const_value:
    OPR_plus id
    {
        const_type = return_chartype(get_type($2));
        if(!add_const(const_id,return_symtype(const_type)))           
		{	
            yyerror($2);
		}   
		
		print(const_type);
        print(" ");
        print(const_id);
        print(" = +");
        //printf("%s %s = +",const_type,const_id);
		
		print($2);
        /* const_value → + id */ 
        /* 翻译方案 10 */
    }
    |
    OPR_minus id
    {
        const_type = return_chartype(get_type($2));
        if(!add_const(const_id,return_symtype(const_type)))           
		{	
            yyerror($2);
		}
        print(const_type);
        print(" ");
        print(const_id);
        print(" = -");		
        //printf("%s %s = -",const_type,const_id);
		
		print($2);
        /* const_value → - id */ 
        /* 翻译方案 11 */
    }
    |
    id
    {
        const_type = return_chartype(get_type($1));
        if(!add_const(const_id,return_symtype(const_type)))           
		{	
            yyerror($1);
		}
        print(const_type);
        print(" ");
        print(const_id);
        print(" = ");		
        //printf("%s %s = ",const_type,const_id);
		
		print($1);
        /* const_value → id */ 
        /* 翻译方案 12 */
    }
    |
    OPR_plus num
    {
        const_type = get_num_type($2);
        if(!add_const(const_id,return_symtype(const_type)))           
		{	
            yyerror($2);
		}
		print(const_type);
        print(" ");
        print(const_id);
        print(" = +");
        //printf("%s %s = +",const_type,const_id);
		
		print($2);
        /* const_value → + num */ 
        /* 翻译方案 13 */
    }
    |
    OPR_minus num
    {
        const_type = get_num_type($2);
        if(!add_const(const_id,return_symtype(const_type)))           
		{	
            yyerror($2);
		}
		print(const_type);
        print(" ");
        print(const_id);
        print(" = -");
        //printf("%s %s = -",const_type,const_id);
		
		print($2);
        /* const_value → - num */ 
        /* 翻译方案 14 */
    }
    |
    num
    {   
	    const_type = get_num_type($1);
        if(!add_const(const_id,return_symtype(const_type)))           
		{	
            yyerror($1);
		}
		print(const_type);
        print(" ");
        print(const_id);
        print(" = ");
        //printf("%s %s = ",const_type,const_id);
		
	    print($1);
        /* const_value → num */ 
        /* 翻译方案 15 */
    }
    |
    str
    {
        if(!add_const(const_id,return_symtype(const_type)))           
		{	
            yyerror($1);
		}
		if(strcmp(const_type,"string")==0)
        {
            print("char*");
        }
        else{
            print(const_type);
        }
        print(" ");
        print(const_id);
        print(" = ");
        //printf("%s %s = ",const_type,const_id);
		s=(char*)malloc(sizeof(char)*100);
		print("\"");
		int a=strlen($1)-2;
		strncpy(s,($1)+1,a);     
        s[a]='\0'; 
		print(s);
		print("\"");
		free(s);
        /* 字符（串）翻译方案 */
        /* 在Pascal中，char和string使用的都是单引号，因此需要根据str的长度区分char和string */
    };


var_declarations:
    SYM_var
    {
	    id_num = 0;
        var_dec_flag = 1;
	}
	var_declaration BDY_semicolon
    {
        var_dec_flag = 0;
		
		print(";\n");
        /* var_declarations → var var_declaration ; */
        /* 翻译方案 17 */ 
    }
    |
    {
        /* var_declarations → ε")
        /* 翻译方案 18 */
    };


var_declaration:
	var_declaration	BDY_semicolon
	{
	    print(";\n");
		id_num = 0;
	} 
	idlist BDY_colon type
    {
	    if(array_flag==0)
       { 
           
           print(var_name);
       }
       if(array_flag==1)
       {
            char* token = strtok(var_name, ",");
            while( token != NULL )
            {
             print(token);
             print(array_num);
             
            token = strtok( NULL, ",");
            if(token!=NULL)
            {
                print(",");
            }
            }

           
           array_flag=0;
       }
        //print(var_name);
        /* var_declaration → var_declaration ; idlist : type */ 
        /* 翻译方案 19 */
    }

    |
    idlist BDY_colon type
    {
        
        if(array_flag==0)
       { 
           
           print(var_name);
       }
       if(array_flag==1)
       {
            char* token = strtok(var_name, ",");
            while( token != NULL )
            {
             print(token);
             print(array_num);
             
            token = strtok( NULL, ",");
            if(token!=NULL)
            {
                print(",");
            }
            }

           
           array_flag=0;
       }
        /* var_declaration → idlist : type */ 
        /* 翻译方案 20 */
    }
    | error BDY_semicolon idlist BDY_colon type
    ;
type:
    simple_type
    {
        if( var_dec_flag == 1 )
        {    
		    if( array_flag != 1 )
			{
			    for( int i = 0; i < id_num; i++ )
    	        {    
				    //printf("   %s  %s\n",id_name[i],code_get_type($1));
					if( !add_variable(id_name[i],return_symtype(code_get_type($1)) ))
    	            {
						yyerror(id_name[i]);
                    } 
				}
			}
		}
		
		if(strcmp(code_get_type($1),"string")==0)
        {
            print("char*");
        }
        else
        {
            print(code_get_type($1));
        }
        print(" ");
        /* type → simple_type */ 
        /* 翻译方案 21 */
    }
    |
    SYM_array
    {
        dimen = 0;
		
        array_num="";/*将array_num值清空*/
        array_flag=1;
    } 
    BDY_lfang period BDY_rfang SYM_of simple_type
    {
	    id_type = code_get_type($7);
		if( var_dec_flag )
        {    
		    if( array_flag  )
			{
			    for(int i = 0; i < id_num; i++ )
                {    
		    
		            if(!add_array(id_name[i],return_symtype(code_get_type($7)),dimen))
                    {
                        //printf("   %s  %s\n",id_name[i],code_get_type($7));
				        yyerror(id_name[i]);
                    }
			        //printf("   %s  %d\n",symbol_stack[find_element(id_name[i])].name,symbol_stack[find_element(id_name[i])].type);
		        }
			}
		}
		
        if(strcmp(code_get_type($7),"string")==0)
        {
            print("char*");
        }
        else
        {
            print(code_get_type($7));
        }

        
        print(" ");
        /* type → array [ period ] of simple_type */ 
        /* 翻译方案 22 */
    }
    ;

simple_type:
    SYM_integer
    {
        /* simple_type → integer */ 
        /* 翻译方案 23 */
    }
    |
    SYM_real
    {
        /* simple_type → real */ 
        /* 翻译方案 24 */
    }
    |
    SYM_boolean
    {
        /* simple_type → boolean */ 
        /* 翻译方案 25 */
    }
    |
    SYM_char
    {
        /* simple_type → char */ 
        /* 翻译方案 26 */
    }
    |
    SYM_string
    {

    }
    ;
period:
    period BDY_comma num BDY_ddot num
    {
        dimen++;
		int x=atoi($5)-atoi($3)+1;
        char * m;
        m=(char*)malloc(sizeof(char)*100);
        sprintf(m,"%d",x);
		array_num=char_strcpy(array_num,"[");
        array_num=char_strcpy(array_num,m);
        array_num=char_strcpy(array_num,"]");

        /* period → period , num .. num */ 
        /* 翻译方案 27 */
    }
    |
    num BDY_ddot num
    {
        dimen++;
		int x=atoi($3)-atoi($1)+1;
         char * m;
        m=(char*)malloc(sizeof(char)*100);
        sprintf(m,"%d",x);
		array_num=char_strcpy(array_num,"[");
        array_num=char_strcpy(array_num,m);
        array_num=char_strcpy(array_num,"]");
        /* period → num .. num */ 
        /* 翻译方案 28 */
    }
    ;

subprogram_declarations:
    subprogram_declarations
    subprogram BDY_semicolon
    {
        print("}\n");
		//array_flag = 0;
		//locate_table();
        /* subprogram_declarations → subprogram_declarations \\n subprogram ; */ 
        /* 翻译方案 29 */
    }
    |
    {
        /* subprogram_declarations → ε */
        /* 翻译方案 30 */
    }
    ;
subprogram:
    subprogram_head{print("{\n");} BDY_semicolon
	{
	    if( function_flag == 1 )
        {
            if(!add_function(function_name,return_symtype(func_type),par_num))
            {
                yyerror(function_name);
            }  
            function_flag = 0;
			
			locate_table();
			
			for( int i = par_all_num - par_num; i < par_all_num; i++)
			{
			    //printf("  %s \n",par_list[i].name);
				par_list[i].proc_func_name = function_name;
				if( par_list[i].is_var )
				{
				    if( !add_reference_parameter(function_name,par_list[i].name,return_symtype(par_list[i].type)) )
				    {
        	            yyerror(par_list[i].name);
                    }
				}
				else
				{
				    if( !add_parameter(function_name,par_list[i].name,return_symtype(par_list[i].type)) )
				    {
        	            yyerror(par_list[i].name);
                    }
				}
			}
		}
		if( procedure_flag == 1 )
        {
            if(!add_procedure(pro_name,par_num))
            {
                yyerror(pro_name);
            }    
            procedure_flag = 0;
			
			locate_table();
			
			for( int i = par_all_num - par_num; i < par_all_num; i++)
			{
			    //printf("  %s \n",par_list[i].name);
				par_list[i].proc_func_name = pro_name;
				if( par_list[i].is_var )
				{
				    if( !add_reference_parameter(pro_name,par_list[i].name,return_symtype(par_list[i].type)) )
				    {
        	            yyerror(par_list[i].name);
                    }
				}
				else
				{
				    if( !add_parameter(par_list[i].proc_func_name,par_list[i].name,return_symtype(par_list[i].type)) )
				    {
        	            yyerror(par_list[i].name);
                    }
				}
			}
		}

	}
	subprogram_body
    {
        /* subprogram → subprogram_head ; subprogram_body */
        /* 翻译方案 31 */ 
    }
    | error BDY_semicolon subprogram_body;
subprogram_head:
    SYM_procedure
    {
        par_num = 0;
    	procedure_flag = 1;
		
		head=(struct id_list*)malloc(sizeof(struct id_list));
        head->next=NULL;
        ppp=(struct id_list*)malloc(sizeof(struct id_list));
        ppp->next=NULL;
    } 
	id formal_parameter
    {   
		pro_name = $3;
		print("void");
        print(" ");
        print($3);
        print(" (");
        test_function=(struct id_list*)malloc(sizeof(struct id_list));
        test_function=head->next;
        while(test_function!=NULL)
        {
            par_num++;
			
			print(test_function->type);
            print (" ");
            if(test_function->var_flag==1)
            {
                print("&");
            }
            print(test_function->name);
            if(test_function->next!=NULL)
            {
                print(",");
            }
            test_function=test_function->next;
        }
        print(" )\n");
        /* subprogram_head → procedure id formal_parameter */
        /* 翻译方案 32 */ 
    }
    |
    SYM_function
    {
        par_num = 0;
        function_flag = 1;
		
		head=(struct id_list*)malloc(sizeof(struct id_list));
        head->next=NULL;
        ppp=(struct id_list*)malloc(sizeof(struct id_list));
        ppp->next=NULL;

    } 
	id formal_parameter BDY_colon simple_type
    {
		func_type = code_get_type($6);	
		print(code_get_type($6));
        print(" ");
        print($3);
        function_name=$3;
        print(" (");
        test_function=(struct id_list*)malloc(sizeof(struct id_list));
        test_function=head->next;
        while(test_function!=NULL)
        {
            par_num++;
			
		    print(test_function->type);
            print (" ");
            if(test_function->var_flag==1)
            {
                print("&");
            }
            print(test_function->name);
            if(test_function->next!=NULL)
            {
                print(",");
            }
            test_function=test_function->next;
        }
        print(" )\n");
        /* subprogram_head → function id formal_parameter : simple_type */ 
        /* 翻译方案 33 */
    }
    ;

formal_parameter:
    BDY_lparen parameter_list BDY_rparen
    {
        /* formal_parameter → ( parameter_list ) */
        /* 翻译方案 34 */ 
    }
    |
    {
        
        /* formal_parameter → ε */
        /* 翻译方案 35 */
    }
    | error BDY_rparen;
parameter_list:
    parameter_list BDY_semicolon parameter
    {
        /* parameter_list → parameter_list ; parameter */
        /* 翻译方案 36 */ 
    }
    |
    parameter
    {
        /* parameter_list → parameter */ 
        /* 翻译方案 37 */
    }
    | error BDY_semicolon parameter;
parameter:
    var_parameter
    {
        /* parameter → var_parameter */ 
        /* 翻译方案 38 */
    }
    |
    value_parameter
    {
        /* parameter → value_parameter */ 
        /* 翻译方案 39 */
    };
var_parameter:
    SYM_var{var_flag=1;} value_parameter
    {
        
        /* var_parameter → var value_parameter */ 
        /* 翻译方案 40 */
    }
value_parameter:
    function_idlist BDY_colon simple_type
    {
        function_type[function_id]=code_get_type($3);
        test=head->next;
        while(test!=NULL)
        {   if(strlen(test->type)==0)
            {
                test->type=function_type[function_id];
                test->var_flag=var_flag;
            }
			
			par_list[par_all_num].name = test->name;
            par_list[par_all_num].type = test->type;
			par_list[par_all_num].is_var = var_flag;
            par_all_num++;
			
            test=test->next;
        }
        function_id++;
        var_flag=0;
        /* value_parameter → function_idlist : simple_type */ 
        /* 翻译方案 41 */
    };
subprogram_body:
    const_declarations
    var_declarations
    compound_statement
    {
	    relocate_table();
        /* subprogram_body */ 
        /* 翻译方案 42 */
    };
compound_statement:
    SYM_begin 
	{
	    print("{\n");
		//locate_table();
	} 
	statement_list SYM_end
    {
        print("}\n");
		//relocate_table();
        /* compound_statement → begin statement_list end */
        /* 翻译方案 43 */ 
    };
program_compound_statement:
    SYM_begin{print("int main()\n{\n");} statement_list SYM_end
    {
        print("system(\"pause\");\nreturn 0;");
        /* compound_statement → begin statement_list end */
        /* 翻译方案 43 */ 
    };
statement_list:
    statement_list BDY_semicolon statement
    {
        /* statement_list → statement_list ; statement */
        /* 翻译方案 44 */ 
    }
    |
    statement
    {
        /* statement_list → statement */ 
        /* 翻译方案 45 */
    }
    | error BDY_semicolon statement;
statement:
    variable assignop
    {
        if(flag==1)
        {
            flag=0;
        }
        else{
            print("=");
        }
    } expression
	{
		//printf("!!%d",get_type(itemp));
		if(IS_DEFINED(itemp)!=0)
		{
		if(is_const(itemp) == 1)
		{
			yyerror("Constants cannot be assigned");
		}
		if(stack_c[position_c-2] != stack_c[position_c-1])		
			yyerror("The expression type is different from the variable type.");
		position_c = position_c - 2;	
		}
	}
    {
        print(";\n");
        /* statement → variable assignop expression */ 
        /* 翻译方案 46 */
    }
    |
    procedure_call
    {
        /* statement → procedure_call */ 
        /* 翻译方案 47 */
    }
    |
    compound_statement
    {
        /* statement → compound_statement */ 
        /* 翻译方案 48 */
    }
    |
    SYM_if{print("if(");} expression 
	{	
		if((stack_c[position_c-1] != BOOL)&&(stack_c[position_c-1]!=INT))									//if判断语句中的类型必须为BOOL型
		{
			yyerror("The expression type should be BOOL");
		}
		position_c --;
	}
	SYM_then{print(")\n");} statement{} else_part
    {
        /* statement → if expression then statement else_part */ 
        /* 翻译方案 49 */
    }
    |
    SYM_for{print("for(");} id
	{	print($3);print("=");
		if(IS_DEFINED($3)==0)
		{
			yyerror("This identifier is not defined");
		}
		else if(get_type($3)!=INT)
		{
			yyerror("The id should be integer");
		}
	} 
	assignop expression
	{	print(";");
		if(stack_c[position_c-1]!=INT)
		{
			yyerror("The expression should be integer");
		}
		position_c--;
	} 
	SYM_to {print($3);print("<=");}expression {print(";");print($3);print("++)\n");}
	{	if(stack_c[position_c-1]!=INT)
		{
			yyerror("The expression should be integer");
		}
		position_c--;
	
	}
	SYM_do statement
    {
        print("\n");
        /* statement → for id assignop expression to expression do statement */ 
        /* 翻译方案 50 */
    }
    |
    SYM_while 
    {
        print("while");
        print("(");
    }
    expression
	{
		print(")");
		if((stack_c[position_c-1] != BOOL)&&(stack_c[position_c-1]!=INT))
			yyerror("It is expected to be integer");
		position_c=position_c--;
	} 
	SYM_do statement
    {
        /* while 翻译方案 */
    }
    |
    {
        /* statement → ε */
        /* 翻译方案 51 */
    };
variable:
    id
    {   
        //printf("@%d\n",get_type($1));
		if(strcmp($1,function_name)==0)
        {
            
            print("return ");
            flag=1;
        }
        else
        {
            
            print($1);
        }
		if(IS_DEFINED($1)==0)
		{
				itemp = $1;
				position_c++;
				yyerror("This identifier is not defined");
				stack_c[position_c-1] = INT;
		}
	    else
	    {
			itemp = $1;
			position_c++;
			if(get_type($1)==ARRAY||get_type($1)==FUNCTION)
				stack_c[position_c-1] = symbol_stack[find_element($1)].sub_type;
			else
			{
					stack_c[position_c-1] = get_type($1);
			}
    	//	if( get_type($1) == ARRAY )
    	//	    array_flag = 1;				/*标志为数组*/	
			if(get_type($1) == ARRAY)
				{
					num_of_arr = get_parameter_number($1);															//用来获取当前数组的维数并存在num_arr中
				}
		}
		ttemp = $1;
    }
     id_varpart
    {
        /* variable → id id_varpart */ 
        /* 翻译方案 52 */
    };
id_varpart:
    BDY_lfang{print("[");into_pf(ttemp);} array_expression_list BDY_rfang
    {
     print("]");   
		if(dimension==num_of_arr)																				//dimen用来存储exp_list中的维数或者参数个数
		{
			for(num_of_arr = 1;num_of_arr<=dimension;num_of_arr++)
			{
				if(stack_c[position_c-1] != INT)
					yyerror("The factor in the array should be integer");
				position_c--;																				//数组后面的每个都应该是int型
			}
		}
		else 
		{
			yyerror("The dimension of the array is wrong");
			position_c = position_c-dimension;														
		}
		out_pf();
        /* id_varpart → [ expression_list ] */ 
        /* 翻译方案 53 */
    }
    |
    {
		if(get_type(ttemp)==ARRAY)
			yyerror("The dimension of the array is wrong");
        /* id_varpart → ε */
        /* 翻译方案 54 */
    };
procedure_call:
    id
    {
/*        if(strcmp($1,"read")==0)
            {
                print("read");
            }
            else
            {
                if(strcmp($1,"write")==0)
                {
                    print("out");
                }
                else
                {*/
					if(IS_DEFINED($1)==0)
					{
						yyerror("This identifier is not defined");
					}
					else
                    print($1);

        print("();\n");
        /* procedure_call → id */ 
        /* 翻译方案 55 */
    }
    |
    id
    {
         /*if(strcmp($1,"read")==0)
            {
                print("read");
            }
            else
            {
                if(strcmp($1,"write")==0)
                {
                    print("out");
                }
                else
                {*/
					if(IS_DEFINED($1)==0)
					{
						yyerror("This identifier is not defined");
					}
					else
						print($1);
        
    } BDY_lparen{print("(");into_pf(ttemp);} expression_list BDY_rparen
    {
		if(IS_DEFINED($1)==1)
		{numa = get_parameter_number($1);
		for(int temp_i= dimension;temp_i>0;temp_i--)
		{
			type_of_pf[numa-temp_i] = stack_c[position_c-temp_i];
		}
		if(check_parameter_types($1,dimension,type_of_pf)==FAILED)
		{
			yyerror("the wrong arguments to the function");
		}}
		position_c = position_c-dimension;
		out_pf();
        print(");\n");
        /* procedure_call → id ( expression_list ) */ 
        /* 翻译方案 56 */
    };
else_part:
    SYM_else{print("\nelse\n");} statement
    {
        /* else_part → else statement */ 
        /* 翻译方案 57 */
    }
    | 
    %prec LOWER_THAN_ELSE
    {
        /* else_part → ε */
        /* 翻译方案 58 */ 
    }
    ;
expression_list:
    expression_list BDY_comma{print(",");} expression
    {
		dimension++;
        /* expression_list → expression_list , expression */
        /* 翻译方案 59 */ 
    }
    |
    expression
    {
		dimension++;
        /* expression_list → expression */ 
        /* 翻译方案 60 */
    }
    | error BDY_comma expression;
expression:
    simple_expression relop
    {
        print($2);
        if(strcmp($2,"=")==0)
        {
            print("=");
        }
    } 
    simple_expression
    {
		if(stack_c[position_c-1]==STRING)
		{
			yyerror("STRING is not expected here");
		}
		else
		{
		if(stack_c[position_c-1]!=stack_c[position_c-2])																					//在分析栈中，栈顶的前两个元素类型必须一样才能比较
		{
			yyerror("The expression type should be the same on both sides.");
		}
		}
		position_c --;
		stack_c[position_c-1] = BOOL;
        /* expression → simple_expression relop simple_expression */ 
        /* 翻译方案 61 */
    }
    |
    simple_expression
    {
        /* expression → simple_expression */ 
        /* 翻译方案 62 */
    };
simple_expression:
    simple_expression addop{print($2);} term
    {
		if(strcmp($2,"+")==0||strcmp($2,"-")==0)														//加法和减法运算进行类型的获取及存储
		{
			if(((stack_c[position_c-2] == INT)&&(stack_c[position_c-1] == FLOAT))||((stack_c[position_c-2] == FLOAT)&&(stack_c[position_c-1] == FLOAT))||((stack_c[position_c-2] == FLOAT)&&(stack_c[position_c-1] == INT)))
			{	
				position_c = position_c -1;
				stack_c[position_c-1]=FLOAT;
			}
			else if((stack_c[position_c-2] == INT) && (stack_c[position_c-1] == INT)) 
			{	
				position_c = position_c -1;
				stack_c[position_c-1]=INT;
			}
			else	
				{	
					yyerror("The addop is wrong");
					position_c--;
				}
		}
		else																										//and运算的类型获取及存储
		{
			if((stack_c[position_c-2] == BOOL)&&(stack_c[position_c-1] == BOOL))
				{
					position_c = position_c -1;
					stack_c[position_c-1] = BOOL;
				}
			else
				{
					yyerror("The addop is wrong");
					position_c--;}
		}	
        /* simple_expression → simple_expression addop term */
        /* 翻译方案 63 */ 
    }
    |
    term
    {
        /* simple_expression → term */ 
        /* 翻译方案 64 */
    };
term:
    term mulop{print($2);} factor
    {
		if((strcmp($2,"*")==0)||(strcmp($2,"/")==0))													//乘法和除法的类型获取及存储
		{
			if((stack_c[position_c-1] == INT)&&(stack_c[position_c-2] == INT))
			{	
				position_c --;
				stack_c[position_c-1] = INT;
			}
			else if(((stack_c[position_c-1] == INT)&&(stack_c[position_c-2] == FLOAT))||((stack_c[position_c-1] == FLOAT)&&(stack_c[position_c-2] == FLOAT))||((stack_c[position_c-1] == FLOAT)&&(stack_c[position_c-2] == INT)))
			{
				position_c --;
				stack_c[position_c-1] = FLOAT;
			}
		else 
			yyerror("The mulop is wrong");
		}
	
		else if((strcmp($2,"div")==0)||(strcmp($2,"%")==0))												//整除和取余的类型获取及存储
		{
			if(((stack_c[position_c-1] == INT)&&(stack_c[position_c-2] == INT))||((stack_c[position_c-1] == INT)&&(stack_c[position_c-2] == FLOAT))||((stack_c[position_c-1] == FLOAT)&&(stack_c[position_c-2] == FLOAT))||((stack_c[position_c-1] == FLOAT)&&(stack_c[position_c-2] == INT)))
			{
				position_c --;
				stack_c[position_c-1] = INT;
			}
			else 
				yyerror("The mulop is wrong");
		}
		else																											//or的类型获取及存储
		{
			if((stack_c[position_c-1] == BOOL)&&(stack_c[position_c-2] == BOOL))
			{
				position_c--;
				stack_c[position_c-1] = BOOL;
			}
			else
			yyerror("The mulop is wrong");
		}
        /* term → term mulop factor */ 
        /* 翻译方案 65 */
    }
    |
    factor
    {
        /* term → factor */ 
        /* 翻译方案 66 */
    };
factor:
    num
    {  
        print($1);
		position_c++;
        if(return_symtype(get_num_type($1)) == INT)
			stack_c[position_c-1] = INT;
		if(return_symtype(get_num_type($1)) == FLOAT)
			stack_c[position_c-1] = FLOAT;
        /* factor → num */ 
        /* 翻译方案 67 */
    }
    |
    str
    {
        /* 字符串翻译方案 */
    }
    |
    variable
    {
        /* factor → variable */ 
        /* 翻译方案 68 */
    }
    |
    id{print($1);}
	{
		if(IS_DEFINED($1)==1)
		{
			if(get_type($1)!=FUNCTION)
				yyerror("It is expected to be FUNCTION");
			position_c ++;
			stack_c[position_c-1] = get_return_type($1);
		}
		else	
			yyerror("This identifier is not defined");
	}
	BDY_lparen{print("(");into_pf($1);} expression_list BDY_rparen
    {
		if(IS_DEFINED($1)==1)
		{
			numa = get_parameter_number($1);
			for(int aa = dimension;aa>0;aa--)
			{
				type_of_pf[numa-aa] = stack_c[position_c-aa];
			}
			if(check_parameter_types($1,dimension,type_of_pf)==FAILED)
				yyerror("the wrong arguments to the function");
		}
		position_c = position_c-dimension;
		out_pf();
        print(")");
        /* factor → id ( expression_list ) */ 
        /* 翻译方案 69 */
    }
    |
    BDY_lparen{print("(");} expression BDY_rparen{print(")");}
    {
        /* factor → ( expression_list ) */ 
        /* 翻译方案 70 */
    }
    |
    SYM_not factor
    {
        print("!");
        print($1);
        /* factor → not factor */ 
        /* 翻译方案 71 */
    }
    |
    uminus factor
    {
        print("-");
        print($1);
        /* factor → uminus factor */ 
        /* 翻译方案 72 */
    };
array_expression_list:
    array_expression_list{print("]");} BDY_comma{print("[");} array_expression
    {
        //print("]");
		dimension++;
        /* expression_list → expression_list , expression */
        /* 翻译方案 59 */ 
    }
    |
    array_expression
    {
		dimension++;
        /* expression_list → expression */ 
        /* 翻译方案 60 */
    };
array_expression:
    array_simple_expression
    {
        /* expression → simple_expression */ 
        /* 翻译方案 62 */
    };
array_simple_expression:
    array_simple_expression addop{print($2);} array_term
    {
		if(strcmp($2,"+")==0||strcmp($2,"-")==0)														//加法和减法运算进行类型的获取及存储
		{
			if((stack_c[position_c-2] == INT) && (stack_c[position_c-1] == INT)) 
			{	
				position_c = position_c -1;
				stack_c[position_c-1]=INT;
			}
			else	
				{	
					yyerror("It is expected to be a integer");
					position_c--;}
		}

		else
			{
				yyerror("It is expected to be a integer");
				position_c--;
			}
        /* simple_expression → simple_expression addop term */
        /* 翻译方案 63 */ 
    }
    |
    array_term
    {
        /* simple_expression → term */ 
        /* 翻译方案 64 */
    };
array_term:
    array_term mulop{print($2);} array_factor
    {
		if((strcmp($2,"*")==0)||(strcmp($2,"/")==0))													//乘法和除法的类型获取及存储
		{
			if((stack_c[position_c-1] == INT)&&(stack_c[position_c-2] == INT))
			{	
				position_c --;
				stack_c[position_c-1] = INT;
			}

			else 
			yyerror("It is expected to be a integer");
		}
	
		else if((strcmp($2,"OPR_div")==0)||(strcmp($2,"%")==0))												//整除和取余的类型获取及存储
		{
			if(((stack_c[position_c-1] == INT)&&(stack_c[position_c-2] == INT))||((stack_c[position_c-1] == INT)&&(stack_c[position_c-2] == FLOAT))||((stack_c[position_c-1] == FLOAT)&&(stack_c[position_c-2] == FLOAT))||((stack_c[position_c-1] == FLOAT)&&(stack_c[position_c-2] == INT)))
			{
				position_c --;
				stack_c[position_c-1] = INT;
			}
			else 
				yyerror("It is expected to be a integer");
		}
		else																											//or的类型获取及存储
		{
			yyerror("It is expected to be a integer");
		}
        /* term → term mulop factor */ 
        /* 翻译方案 65 */
    }
    |
    array_factor
    {
        /* term → factor */ 
        /* 翻译方案 66 */
    };
array_factor:
    num
    {  
        print($1);
		position_c++;
        if(return_symtype(get_num_type($1)) == INT)
			stack_c[position_c-1] = INT;
		if(return_symtype(get_num_type($1)) == FLOAT)
			stack_c[position_c-1] = FLOAT;
        
        /* factor → num */ 
        /* 翻译方案 67 */
    }
    |
    variable
    {
        
        /* factor → variable */ 
        /* 翻译方案 68 */
    }
    |
    id{print($1);}
	{
		if(IS_DEFINED($1)==1)
		{
			if(get_type($1)!=FUNCTION)
				yyerror("It is expected to be FUNCTION");
			position_c ++;
			stack_c[position_c-1] = get_return_type($1);
		}
		else	
			yyerror("This identifier is not defined");
	}
	BDY_lparen{print("(");into_pf($1);} expression_list BDY_rparen
    {
		if(IS_DEFINED($1)==1)
		{
			numa = get_parameter_number($1);
			for(int aa = dimension;aa>0;aa--)
			{
				type_of_pf[numa-aa] = stack_c[position_c-aa];
			}
			check_parameter_types($1,dimension,type_of_pf);
		}
		position_c = position_c-dimension;
		out_pf();
        print(")");   
        /* factor → id ( expression_list ) */ 
        /* 翻译方案 69 */
    }
    |
    BDY_lparen{print("(");} expression BDY_rparen{print(")");}
    {
        /* factor → ( expression_list ) */ 
        /* 翻译方案 70 */
    }
    |
    SYM_not array_factor
    {
        print("!");
        print($1); 
        /* factor → not factor */ 
        /* 翻译方案 71 */
    }
    |
    uminus array_factor
    {
        print("-");
        print($1);
        /* factor → uminus factor */ 
        /* 翻译方案 72 */
    };
str:
    string
    {
        if(strlen($1)==3)
        {           
			if(!const_flag)
			{
			    print($1);
				position_c++;
			    stack_c[position_c-1] = CHAR;
			}
			const_type = "char";
        }
        else
        {
			const_type = "string";
			if(!const_flag)
			{
			    position_c++;
				stack_c[position_c-1] = STRING;
			
				s=(char*)malloc(sizeof(char)*100);
				print("\"");
				int a=strlen($1)-2;
				strncpy(s,($1)+1,a);     
                s[a]='\0'; 
				print(s);
				print("\"");
				free(s);
			}
        }
        /* str -> string */
    }
    ;

/* 额外处理 */
assignop:
    OPR_become;
relop:
    OPR_eql | OPR_neq | OPR_lss | OPR_leq | OPR_gtr | OPR_geq;
addop:
    OPR_plus | OPR_minus | SYM_or;
mulop:
    OPR_times | OPR_slash | SYM_div | SYM_mod | SYM_and;
uminus:
    OPR_minus;
%%
l