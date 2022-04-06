

from spi import Lexer, Parser,PLUS,MINUS,MUL,DIV

class NodeVisitor(object):
    def visit(self, node):
        # type(node).__name__ = BinOp / Num
        method_name = 'visit_' + type(node).__name__
        #print(method_name)
        
        # equal to use : self.visit_BinOp(node) / self.visit_Num(node)
        visitor = getattr(self, method_name, self.generic_visit)
        return visitor(node)

    def generic_visit(self, node):
        raise Exception('No visit_{} method'.format(type(node).__name__))


class Interpreter_infix2suffix(NodeVisitor):
    def __init__(self, parser):
        self.parser = parser

    def visit_BinOp(self, node):
        return f'{self.visit(node.left)} {self.visit(node.right)} {node.op.value}'

    def visit_Num(self, node):
        return node.value

    def interpret(self):
        tree = self.parser.parse()
        return self.visit(tree)

class Interpreter_infix2prefix(NodeVisitor):
    def __init__(self, parser):
        self.parser = parser

    def visit_BinOp(self, node):
        return f'{node.op.value} {self.visit(node.left)} {self.visit(node.right)}'

    def visit_Num(self, node):
        return node.value

    def interpret(self):
        tree = self.parser.parse()
        return self.visit(tree)

def main():
    
    correctness = 0
    cnt = 0
    
    # if directly run this python file to test, please use this code
    # suffix_file = open('suffix_answer.txt', 'r')
    # prefix_file = open('prefix_answer.txt', 'r')
    
    suffix_file = open('LBASC/part7/suffix_answer.txt', 'r')
    prefix_file = open('LBASC/part7/prefix_answer.txt', 'r')

    suffix_answers = suffix_file.readlines()
    prefix_answers = prefix_file.readlines()
    
    while True:
        
        text = input("calc> ")
        print(text)
        if text == "END":break
        lexer = Lexer(text)
        parser = Parser(lexer)
        interpreter_infix2suffix = Interpreter_infix2suffix(parser)
        result_suffix = interpreter_infix2suffix.interpret()
        #print(result_suffix)
        lexer = Lexer(text)
        parser = Parser(lexer)
        interpreter_infix2prefix = Interpreter_infix2prefix(parser)
        result_prefix = interpreter_infix2prefix.interpret()
        #print(result_prefix)
        suffix_answers[cnt] = suffix_answers[cnt].strip('\n')
        prefix_answers[cnt] = prefix_answers[cnt].strip('\n')
        if result_suffix == suffix_answers[cnt]:
            print("Suffix: {}".format(result_suffix) + "   ("+chr(0x2714)+")")
            correctness += 1
        else :
            print('correct answer is : ', suffix_answers[cnt])
            print('your answer is : ', result_suffix)
        if result_prefix == prefix_answers[cnt]:
            print("Prefix: {}".format(result_prefix) + "   ("+chr(0x2714)+")")
            correctness += 1
        else :
            print('correct answer is : ', prefix_answers[cnt])
            print('your answer is : ', result_prefix)
        cnt += 1
    print(f"correctness : {correctness}/{cnt*2}")
    suffix_file.close()
    prefix_file.close()

if __name__ == "__main__":
    main()