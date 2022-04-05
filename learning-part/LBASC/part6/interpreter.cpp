/*
 *Copyright (c) 2022 All rights reserved
 *@description: interpreter should be used for interpreting the statement with tokens
 *@author: Zhixing Lu
 *@date: 2022-04-06
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/


#include "interpreter.h"
#include "lexer.h"

interpreter::interpreter(const std::string &statement, lexer *lexer) : lexer_(*lexer), statement_(statement) {}

int interpreter::expr() {
    int result = term();
    while (lexer_.get_next_token() != nullptr) {
        token *t = lexer_.get_next_token();
        if (t->type == PLUS) {
            result += term();
        } else if (t->type == MINUS) {
            result -= term();
        }
    }
    return result;
}

int interpreter::term() {
    int result = factor();
    while (lexer_.get_next_token() != nullptr) {
        token *t = lexer_.get_next_token();
        if (t->type == MULT) {
            result *= factor();
        } else if (t->type == DIV) {
            result /= factor();
        }
    }
    return result;
}

int interpreter::factor() {
    token *t = lexer_.get_next_token();
    if (t->type == PLUS) {
        return factor();
    } else if (t->type == MINUS) {
        return -factor();
    } else if (t->type == INTEGER) {
        return t->value;
    } else if (t->type == LEFT_PARENTHESIS) {
        int result = expr();
        t = lexer_.get_next_token();
        if (t->type != RIGHT_PARENTHESIS) {
            throw "invalid syntax";
        }
        return result;
    }
    throw "invalid syntax";
}

