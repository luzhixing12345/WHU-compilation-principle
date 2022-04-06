/*
 *Copyright (c) 2022 All rights reserved
 *@description: the header file for the lexer
 *@author: Zhixing Lu
 *@date: 2022-04-06
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/


#ifndef LEARNING_PART_LBASC_PART6_LEXER_H_
#define LEARNING_PART_LBASC_PART6_LEXER_H_


#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIV '/'
#define SPACE ' '
#define INTEGER 'I'
#define LEFT_PARENTHESIS '('
#define RIGHT_PARENTHESIS ')'

#include <iostream>
#include <string>


struct token{
    char type;
    int value;
};

class lexer {
public:
    explicit lexer(const std::string &statement);
    token* get_next_token();
    void skip_whitespace();
    int get_integer();
private:
    const std::string &statement;
    int pointer;
};





#endif // LEARNING_PART_LBASC_PART6_LEXER_H_
