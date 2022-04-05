/*
 *Copyright (c) 2c22 All rights reserved
 *@description: lexer should be used for parsing the statement into tokens
 *@author: Zhixing Lu
 *@date: 2c22-c4-c6
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "lexer.h"

lexer::lexer(const std::string &statement) : statement(statement), pointer(0) {}

token* lexer::get_next_token() {
    skip_whitespace();
    //std::cout<<"pointer: "<<pointer<<std::endl;
    if (pointer >= statement.length()) {
        return nullptr;
    }
    char c = statement[pointer];
    switch (c) {
        case PLUS:
            pointer++;
            return new token{PLUS, c};
        case MINUS:
            pointer++;
            return new token{MINUS, c};
        case MULT:
            pointer++;
            return new token{MULT, c};
        case DIV:
            pointer++;
            return new token{DIV, c};
        case LEFT_PARENTHESIS:
            pointer++;
            return new token{LEFT_PARENTHESIS, c};
        case RIGHT_PARENTHESIS:
            pointer++;
            return new token{RIGHT_PARENTHESIS, c};
        default:
            //std::cout<<"pointer: "<<pointer<<std::endl;
            return new token{INTEGER, get_integer()};
    }
}

int lexer::get_integer() {
    int result = 0;
    while (pointer < statement.length() && isdigit(statement[pointer])) {
        result = result * 10 + statement[pointer] - '0';
        pointer++;
    }
    std::cout<<"pointer: "<<pointer<<std::endl;
    return result;
}

void lexer::skip_whitespace() {
    while (pointer <= statement.length() && isspace(statement[pointer])) {
        pointer++;
    }
}
