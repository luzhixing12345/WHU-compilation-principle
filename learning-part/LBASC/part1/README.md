# part-1

## code job

- [x] 修改代码以允许输入中使用多位整数，例如"12+3"
- [x] 添加一个跳过空格字符的方法，以便计算器可以处理带有空格字符（如"12 + 3"）的输入
- [x] 修改代码，而不是"+"句柄"-"来评估减法，如"7-5"

correctness:

```python
python test.py part1
```

![20220406020709](https://raw.githubusercontent.com/learner-lu/picbed/master/20220406020709.png)

## Q&A

- What is an interpreter?

  ```shell
  直接执行用编程语言编写的指令的程序,不转换为机器代码
  ```

- What is a compiler?
  
  ```a
  编译器是一个程序,就可以阅读某一种语言(源代码)编写的程序,并把该程序翻译为一个等价的用另一种语言(目标语言)编写的程序
  ```

- What’s the difference between an interpreter and a compiler?
  
  ```a
  编译器是一种程序，它可以读取一种语言（源语言）的程序，并将其翻译成另一种语言（目标语言）的等效程序，
  并报告在翻译过程中检测到的源程序中的任何错误。

  解释器直接对用户提供的输入执行源程序中指定的操作。
  ```

- What is a token?

  ```a
  token是键值对. <type,value>
  ```

- What is the name of the process that breaks input apart into tokens?

  ```a
  词法分析(lexical analysis)
  ```

- What is the part of the interpreter that does lexical analysis called?
  
  ```a
  the first step your interpreter needs to do is read the input of characters and convert it into a stream of tokens.
  解释器将输入字符转换为一个个token,该部分叫词法分析器(lexcial analyser->lexer)
  ```

- What are the other common names for that part of an interpreter or a compiler?

  ```a
  扫描仪(scanner) 分词器(tokenizer)
  ```
