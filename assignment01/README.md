# 第一次作业 - 前缀表达式转中缀表达式

> [makefile video](https://www.bilibili.com/video/BV1B4411F7EK)
> [作业要求](readme.txt)

这里梳理一下assignment1的实验思路,readme.txt中已经描述的十分清晰了. 我就简单讲一下吧

## 实验环境和基本使用

首先运行此代码需要linux环境,windows系统可以使用WSL.

- 先编译 `make -f unixmake.mak`得到一堆警告和一堆.o和最后的可执行文件

  其实windows也可以编译`mingw32-make -f unixmake.mak`,不过还是推荐linux

- 其中makefile(unixmake.mak)中已经完成了所有文件的编译和链接,所以有的文件没有引用其他头文件(如main.c)
- 清除操作 `make -f unixmake.make clean`,删除文件,用于尝试改错debug

## 程序执行过程

main.c中包含main函数,为gcc编译后c语言程序的默认入口. 所有执行(exe)文件都以main为入口

