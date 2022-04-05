# Token types
#
# EOF (end-of-file) token is used to indicate that
# there is no more input left for lexical analysis



INTEGER, EOF = 'INTEGER','EOF'

PLUS = 'PLUS'
MINUS = 'MINUS'
MULT = 'MULT'
DIV = 'DIV'


class Token(object):
    def __init__(self, type, value):
        # token type: INTEGER, PLUS, or EOF
        self.type = type
        # token value: 0, 1, 2. 3, 4, 5, 6, 7, 8, 9, '+', or None
        self.value = value

    def __str__(self):
        """String representation of the class instance.

        Examples:
            Token(INTEGER, 3)
            Token(PLUS '+')
        """
        return 'Token({type}, {value})'.format(
            type=self.type,
            value=repr(self.value)
        )

    def __repr__(self):
        return self.__str__()


class Interpreter(object):
    def __init__(self, text):
        # client string input, e.g. "3+5"
        self.text = text
        # self.pos is an index into self.text
        self.pos = 0
        # current token instance
        self.current_token = None

    def error(self):
        raise Exception('Error parsing input')

    def get_next_token(self):
        """Lexical analyzer (also known as scanner or tokenizer)

        This method is responsible for breaking a sentence
        apart into tokens. One token at a time.
        """
        text = self.text

        # is self.pos index past the end of the self.text ?
        # if so, then return EOF token because there is no more
        # input left to convert into tokens


        while self.pos<len(text) and text[self.pos]==' ':
            self.pos+=1
        if self.pos > len(text) - 1:
            return Token(EOF, None)
        # get a character at the position self.pos and decide
        # what token to create based on the single character
        current_char = text[self.pos]

        
        if current_char=='+':
            token = Token(PLUS,'+')
            self.pos+=1
            return token
        elif current_char=='-':
            token = Token(MINUS,'-')
            self.pos+=1
            return token
        elif current_char=='*':
            token = Token(MULT,'*')
            self.pos+=1
            return token
        elif current_char=='/':
            token = Token(DIV,'/')
            self.pos+=1
            return token
        elif current_char.isdigit():
            end_pos = self.pos
            while end_pos<len(text) and text[end_pos].isdigit():
                end_pos+=1
            number = text[self.pos:end_pos]
            self.pos=end_pos
            token = Token(INTEGER,int(number))
            return token

        self.error()

    def eat(self, token_type):
        # compare the current token type with the passed token
        # type and if they match then "eat" the current token
        # and assign the next token to the self.current_token,
        # otherwise raise an exception.
        if self.current_token.type == token_type:
            self.current_token = self.get_next_token()
        else:
            self.error()

    def expr(self):
        """expr -> INTEGER PLUS/MINUS INTEGER"""
        # set current token to the first token taken from the input
        self.current_token = self.get_next_token()

        # we expect the current token to be a single-digit integer
        left = self.current_token
        self.eat(INTEGER)

        while self.current_token.type!=EOF:
            op = self.current_token
            self.eat(op.type)
            
            right = self.current_token
            self.eat(INTEGER)


            if op.type==PLUS:
                left.value = left.value + right.value
            
            elif op.type==MINUS:
                left.value = left.value - right.value
            
            elif op.type==MULT:
                left.value = left.value*right.value
            elif op.type==DIV:
                left.value = left.value//right.value
        return left.value
                

def main():
    cnt = 1
    correctness = 0
    while True:
        text = input('calc> ')
        print(text)
        if text=='END':
            break
        if not text:
            continue
        interpreter = Interpreter(text)
        result = interpreter.expr()
        print("output =",result,end='')
        if result == cnt:
            print(f' ({chr(0x2713)})')
            correctness+=1
        cnt+=1
    print(f'\n{correctness}/{cnt-1}')


if __name__ == '__main__':
    main()