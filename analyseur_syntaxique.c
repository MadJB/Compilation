#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboles.h"
#include "util.h"
#include "analyseur_syntaxique.h"


int yylex(void);
extern char *yytext;
FILE *yyin;
int uniteCourante;

void E(void)
{	
	T();
	E2();
	
}

void E2(void) //E'
{	
	
	if ( uniteCourante == PLUS)
	{
		uniteCourante = yylex();
		E();
	}
	
	
	

}	
void T(void)
{	
	
	
	F();
	T2();
	
}

void T2(void) // T'
{	
	
	if ( uniteCourante == FOIS)
	{
		uniteCourante = yylex();
		T();
	}
}	
	
void F(void)
{	
	
	if ( uniteCourante == PARENTHESE_OUVRANTE)
	{
		uniteCourante = yylex();
		E();
	
		if  ( uniteCourante == PARENTHESE_FERMANTE)
		{
			uniteCourante = yylex();
		}
		else 
		{
			printf("Erreur de syntaxe: parenthese fermante attendue\n");
			exit(-1);
			
		}
	}
	
	else if ( uniteCourante == NOMBRE)
	{
		uniteCourante = yylex();
	}
	
	else 
	{
		printf("Erreur de syntaxe: nombre ou parenthese attendue\n");
		exit(-1);	
    }
}	
	
	

