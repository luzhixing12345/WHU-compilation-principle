# part7

这里作者描述的有点笼统,首先到[Graphviz](http://graphviz.org/download/)官网下载,我使用的是[win10-64位](https://github.com/luzhixing12345/compilation-principle/releases/download/v0.0.2/windows_10_cmake_Release_graphviz-install-3.0.0-win64.exe),安装加入环境变量

作者构建了`genptdot.py 和 spi.py`,下载这两部分后分别执行,windows好像不支持&&同时执行

```python
python genptdot.py "14 + 2 * 3 - 6 / 2" > parsetree.dot
dot -Tpng -o parsetree.png parsetree.dot
```

即可生成`parsetree.png`解析树

关于AST树的构建,我一开始也没太理解,我以`1+2+3+4+5`为例根据`spi.py`的代码来分析一下构建的思路

![20220407022119](https://raw.githubusercontent.com/learner-lu/picbed/master/20220407022119.png)

代码中的lexer没有变化,依然负责语法分析,根据text逐个解析token

parser每次返回的并不是值(.value),而是一个`BinOp`类封装的节点node

![20220407022143](https://raw.githubusercontent.com/learner-lu/picbed/master/20220407022143.png)

输入`1+2+3+4+5`,首先 node = self.term() , node的值就是1. 然后token是+, right = self.term(),right的值是2,所以封装的 `node = BinOp(left=node, op=token, right=self.term())`就是封装了一个{1+2}.然后这里是一个循环,下次取token是+,right = self.term()值是3,node变为{node+3}={{1+2}+3},也就是再往上一层,最后直到完成所有解析,最后的node为`{{{{1+2}+3}+4}+5}`

返回的node作为parser.parser()被interpreter调用,先由visit_BinOp对于二元操作符解析,然后分解到叶结点使用visit_Num得到.value,完成运算.

与之前相比(part5),主要的区别是将运算符的计算作为另一个部分单独提取了出来,由两部分化为三部分,这种思想与我在part3中的interpreter.cpp中的calculate函数类似

## code job

- [x] 编写一个转换器（提示：节点访问者），该转换器将算术表达式作为输入，并以后缀符号（也称为反向波兰语表示法 （RPN））打印出来。例如，如果转换器的输入是表达式 （5 + 3） \* 12 / 3，则输出应为 5 3 + 12 \* 3 /。请参阅此处的答案，但请先尝试自己解决。
- [x] 编写一个转换器（节点访问者），该转换器将算术表达式作为输入，并以LISP样式表示法打印出来，即2 + 3将变为（+ 2 3）和（2 + 3 \* 5）将变为（+ 2（\* 3 5））。您可以在此处找到答案，但在查看提供的解决方案之前，请先尝试解决它。

修改节点visit的时候返回值为字符串而不是计算,字符串的顺序根据前缀中缀后缀调整即可

correctness:

```python
python test.py part7
```

![20220407022000](https://raw.githubusercontent.com/learner-lu/picbed/master/20220407022000.png)
