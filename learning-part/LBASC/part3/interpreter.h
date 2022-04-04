/*
 *Copyright (c) 2022 All rights reserved
 *@description: the header file for the interpreter
 *@author: Zhixing Lu
 *@date: 2022-04-04
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef LEARNING_PART_LBASC_PART3_INTERPRETER_H_
#define LEARNING_PART_LBASC_PART3_INTERPRETER_H_

#include <iostream>
#include <string>

#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIV '/'
#define SPACE ' '
#define INTERGER 'I'

struct token{
    char type;
    int value;
};

// the function to get the next token from the statement based on the pointer
token* get_next_token(const std::string &statement, int* pointer);

int term(const std::string &statement, int *pointer);


int expr(const std::string &statement);

// skip the space in the statement
void skip_whitespace(const std::string &statement, int *pointer);

// calculate the result based on operator
void calculate(token *result,token &op,token &term);

void debug_tools(token *t);

#endif // LEARNING_PART_LBASC_PART3_INTERPRETER_H_
