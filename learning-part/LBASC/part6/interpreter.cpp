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

interpreter::interpreter(lexer *lexer) : lexer_(*lexer) {
    current_token_ = lexer_.get_next_token();
}

int interpreter::expr() {
    int result = term();
    std::cout<<"result: "<<result<<std::endl;
    while (current_token_->type == PLUS || current_token_->type == MINUS) {
        if (current_token_->type == PLUS) {
            advance();
            std::cout<<"current_token_->type: "<<current_token_->type<<std::endl;
            result += term();
        } else if (current_token_->type == MINUS) {
            advance();
            result -= term();
        }
    }
    return result;
}

int interpreter::term() {
    int result = factor();
    //std::cout<<"result: "<<result<<std::endl;
    while (current_token_->type == MULT || current_token_->type == DIV) {
        if (current_token_->type == MULT) {
            advance();
            result *= factor();
        } else if (current_token_->type == DIV) {
            advance();
            result /= factor();
        }
    }
    return result;
}

int interpreter::factor() {
    token *t = current_token_;
    //std::cout<<"t->type: "<<t->type<<std::endl;
    if (t->type == PLUS) {
        advance();
        return factor();
    } else if (t->type == MINUS) {
        advance();
        return -factor();
    } else if (t->type == INTEGER) {
        int result = t->value;
        //advance();
        return result;
    } else if (t->type == LEFT_PARENTHESIS) {
        advance();
        int result = expr();
        if (current_token_->type != RIGHT_PARENTHESIS) {
            throw "invalid syntax";
        }
        advance();
        return result;
    }
    throw "invalid syntax";
}

void interpreter::advance() {
    current_token_ = lexer_.get_next_token();
}
