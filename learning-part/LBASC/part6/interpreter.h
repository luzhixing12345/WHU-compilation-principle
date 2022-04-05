/*
 *Copyright (c) 2022 All rights reserved
 *@description: header file of interpreter.cpp
 *@author: Zhixing Lu
 *@date: 2022-04-06
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#ifndef LEARNING_PART_LBASC_PART6_INTERPRETER_H_
#define LEARNING_PART_LBASC_PART6_INTERPRETER_H_

#include <iostream>
#include <string>
#include "lexer.h"

class interpreter {

/* 
    上下文无关文法:

    expr : term ((PLUS | MINUS) term)*
    term : factor ((MULT | DIV) factor)*
    factor : (PLUS | MINUS) factor | INTEGER | LEFT_PARENTHESIS expr RIGHT_PARENTHESIS
 
*/
public:
    explicit interpreter(lexer *lexer);
    int expr();
    int term();
    int factor();
    void advance();
private:
    lexer lexer_;
    std::string statement_;
    token *current_token_;
};





#endif // LEARNING_PART_LBASC_PART6_INTERPRETER_H_
