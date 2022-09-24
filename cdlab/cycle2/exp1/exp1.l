 //Implementation of Lexical Analyzer using Lex tool
 
%{
int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*

%%

#.* {printf("\n%s is a preprocessor directive",yytext);}
int |
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else |
goto {printf("\n%s is a KEYWORD",yytext);}
"/*" {COMMENT=1;}{printf("\n%s is a COMMENT",yytext);}
{identifier}\( {if(!COMMENT)printf("\nFUNCTION\n%s",yytext);}
\{  {if(!COMMENT)printf("\nBLOCK BEGINS");}
\}  {if(!COMMENT)printf("\nBLOCK ENDS");}
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("\n%s is an IDENTIFIER",yytext);}
\".*\" {if(!COMMENT)printf("\n%s is a STRING",yytext);}
[0-9]+ {if(!COMMENT) printf("\n%s is a NUMBER",yytext);}
\)(\:)? {if(!COMMENT)printf("\n");ECHO;printf("\n");}
\( ECHO;
= {if(!COMMENT)printf("\n%s is an ASSIGNMENT OPERATOR",yytext);}
\<= |
\>= |
\< |
== |
\> {if(!COMMENT) printf("\n%s is a RELATIONAL OPERATOR",yytext);}

%%

int main(int argc, char **argv) {
	char filename[50];
	
	printf("Enter filename: ");
	scanf("%s", filename);
	
	FILE *file;
	file = fopen(filename,"r");
	
	if(!file) {
		printf("Could not open the file\n");
		exit(0);
	}
	
	yyin = file;
	yylex();
	printf("\n");
	return(0);
}

int yywrap() {
	return(1);
}
