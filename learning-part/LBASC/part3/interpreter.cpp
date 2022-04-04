/*
 *Copyright (c) 2022 All rights reserved
 *@description: realization of the interpreter
 *@author: Zhixing Lu
 *@date: 2022-04-04
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "interpreter.h"

void debug(token *t) {
    printf("type = %c\n", t->type);
    printf("value = %d\n", t->value);
}

void skip_whitespace(const std::string &statement, int *pointer) {
    int length = statement.size();
    while (*pointer < length&&statement[*pointer] == SPACE) (*pointer)++;
}

token* get_next_token(const std::string &statement, int *pointer) {
    skip_whitespace(statement, pointer);
    token *t = (token*)malloc(sizeof(token));
    switch (statement[*pointer]) {
        case PLUS:
            t->type = PLUS;
            t->value = (int)statement[*pointer];
            (*pointer)++;
            break;
        case MINUS:
            t->type = MINUS;
            t->value = (int)statement[*pointer];
            (*pointer)++;
            break;
        case MULT:
            t->type = MULT;
            t->value = (int)statement[*pointer];
            (*pointer)++;
            break;
        case DIV:
            t->type = DIV;
            t->value = (int)statement[*pointer];
            (*pointer)++;
            break;
        default:
            t->type = INTERGER;
            t->value = term(statement, pointer);
            break;
    }
    return t;
}

int term(const std::string&statement, int *pointer) {
    int value = 0;
    while (statement[*pointer] >= '0'&&statement[*pointer] <= '9') {
        value = value*10 + statement[*pointer]-'0';
        (*pointer)++;
    }
    return value;
}

void calculate(token *result, token &op, token &term) {
    switch (op.type) {
    case PLUS:
        result->value += term.value;
        break;
    case MINUS:
        result->value -= term.value;
        break;
    case MULT:
        result->value *= term.value;
        break;
    case DIV:
        result->value /= term.value;
        break;
    default:
        std::cout<<"unknown signal "<< op.type<<std::endl;
        break;
    }
}

int expr(const std::string &statement) {
    int pointer = 0;
    token* result = get_next_token(statement, &pointer);
    // debug(result);
    // printf("%d\n",pointer);
    while (statement[pointer] != '\0') {
        token* op = get_next_token(statement, &pointer);
        // printf("%c\n",op->value);
        // printf("%d\n",pointer);
        token* term = get_next_token(statement, &pointer);
        // printf("%d\n",pointer);
        // debug(term);
        calculate(result, *op, *term);
        skip_whitespace(statement,&pointer);
    }
    return result->value;
}

