# part7

这里作者描述的有点笼统,首先到[Graphviz](http://graphviz.org/download/)官网下载,我使用的是[win10-64位](https://github.com/luzhixing12345/compilation-principle/releases/download/v0.0.2/windows_10_cmake_Release_graphviz-install-3.0.0-win64.exe),安装加入环境变量

作者构建了`genptdot.py 和 spi.py`,下载这两部分后分别执行,windows好像不支持&&同时执行

```python
python genptdot.py "14 + 2 * 3 - 6 / 2" > parsetree.dot
dot -Tpng -o parsetree.png parsetree.dot
```

即可生成`parsetree.png`解析树

关于AST树的构建,我一开始也没太理解,我以`1+2+3+4+5`为例根据`spi.py`的代码来分析一下构建的思路

![20220406194533](https://raw.githubusercontent.com/learner-lu/picbed/master/20220406194533.png)

![20220406194514](https://raw.githubusercontent.com/learner-lu/picbed/master/20220406194514.png)

代码中的lexer没有变化,依然负责语法分析,根据text逐个解析token

parser每次返回的并不是值(.value),而是一个`BinOp`类封装的节点node

输入`1+2+3+4+5`,首先 node = self.term() , node的值就是1. 然后token是+, right = self.term(),right的值是2,所以封装的 `node = BinOp(left=node, op=token, right=self.term())`就是封装了一个{1+2}.然后这里是一个循环,下次取token是+,right = self.term()值是3,node变为{node+3}={{1+2}+3},也就是再往上一层,最后直到完成所有解析,最后的node为`{{{{1+2}+3}+4}+5}`

返回的node作为parser.parser()被interpreter调用,先由visit_BinOp对于二元操作符解析,然后分解到叶结点使用visit_Num得到.value,完成运算.

与之前相比(part5),主要的区别是将运算符的计算作为另一个部分单独提取了出来,由两部分化为三部分,这种思想与我在part3中的interpreter.cpp中的calculate函数类似
