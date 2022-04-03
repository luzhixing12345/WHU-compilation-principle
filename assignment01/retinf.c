/* retinf.c   	AXL分析器 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lex.h"

char err_id[] = "error";
char * midexp;
extern char * yytext;

struct YYLVAL {
  char * val;  /* 记录表达式中间临时变量 */
  char * expr; /* 记录表达式后缀式 */
  int last_op;  /* last operation of expression 
		   for elimination of redundant parentheses */
};

typedef struct YYLVAL Yylval;

Yylval * expression ( void );

char *newname( void ); /* 在name.c中定义 */

extern void freename( char *name );

void statements ( void )
{
  /*  statements -> expression SEMI  |  expression SEMI statements  */
  Yylval *temp;
  printf("Please input an affix expression and ending with \";\"\n");
  while( !match(EOI) ) {
    temp = expression();
	if(temp->expr != "error"){
    	printf("the infix expression is %s\n", temp -> expr);
    	freename(temp -> val);
    	free(temp -> expr);
    	free(temp);
	}
    if( match( SEMI ) ){
      printf("Please input an affix expression and ending with \";\"\n");
      advance();
    }
    else
      fprintf( stderr, "%d: Inserting missing semicolon\n", yylineno );
	  //statements();
  	}
}

Yylval *expression()
{ 
  /*
    expression -> PLUS expression expression
               |  MINUS expression expression
               |  TIMES expression expression
               |  DIVISION expression expression
	       	   |  NUM_OR_ID
  */
  Yylval  *temp = (Yylval*)malloc(sizeof(Yylval));
  
  Yylval *tempmid1,*tempmid2;
  //printf("0");
  while( match( PLUS )|| match(MINUS)||match(TIMES)||match(DIVISION)) {
    char op = *yytext;
	//printf("1");
	switch (op)
	{
	case '+':
		temp->last_op = PLUS;
		break;
	case '-':
		temp->last_op = MINUS;
		break;
	case '*':
		temp->last_op = TIMES;
		break;
	case '/':
		temp->last_op = DIVISION;
		break;
	default:
		fprintf( stderr, "unknown signal %c",op);
	}
    advance();
	//printf("?");
	tempmid1 = expression();
	//printf("123");
	tempmid2 = expression();
	//printf("345");
	int checkFirst = tempmid1->last_op == PLUS || tempmid1->last_op == MINUS;
	int checkSecond = tempmid2->last_op == PLUS || tempmid2->last_op == MINUS;
	if(temp->last_op == TIMES || temp->last_op == DIVISION){
		if (checkFirst && checkSecond){
			temp->expr = (char*)malloc(strlen(tempmid1->expr)+strlen(tempmid2->expr)+8);
			sprintf(temp->expr,"(%s) %c (%s)",tempmid1->expr,op,tempmid2->expr);
		}
		else if(checkFirst){
			temp->expr = (char*)malloc(strlen(tempmid1->expr)+strlen(tempmid2->expr)+6);
			sprintf(temp->expr,"(%s) %c %s",tempmid1->expr,op,tempmid2->expr);
		}
		else if(checkSecond){
			temp->expr = (char*)malloc(strlen(tempmid1->expr)+strlen(tempmid2->expr)+6);
			sprintf(temp->expr,"%s %c (%s)",tempmid1->expr,op,tempmid2->expr);
		}
		else{
			temp->expr = (char*)malloc(strlen(tempmid1->expr)+strlen(tempmid2->expr)+4);
			sprintf(temp->expr,"%s %c %s",tempmid1->expr,op,tempmid2->expr);
		}
	}
	else{
		temp->expr = (char*)malloc(strlen(tempmid1->expr)+strlen(tempmid2->expr)+4);
		sprintf(temp->expr,"%s %c %s",tempmid1->expr,op,tempmid2->expr);
	}


	printf("    %s %c= %s\n", tempmid1->val, op, tempmid2->val);
	freename(tempmid1->val);
	temp->val = tempmid1->val;
	return temp;
  }    

  	//printf("2");
	if(match(NUM_OR_ID)){
		printf("    %s = %0.*s\n", temp->val = newname(), yyleng, yytext);
		temp->expr = (char*)malloc(yyleng);
		strncpy(temp->expr,yytext,yyleng);
		advance();
		temp->last_op = TIMES;
		return temp;
	}
    else if (match(SEMI)){
		temp->expr = (char*)malloc(yyleng);
		temp->expr = "error";
		return temp;
	} 
	
	fprintf(stderr,"input is wrong.\n");
	advance();
	return ;
}
