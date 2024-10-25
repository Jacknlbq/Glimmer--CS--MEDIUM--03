# CS-MEDIUM-03 实验：Linux命令行实现

## 不同点
* 该程序必定会输出当前目录下的东西，也就是说我如果输入`./myls.out ../`程序还是会输出当前目录的文件信息。
* 输出格式不相同，该程序明显不能规范输出，文件名长一点就错位了
* 最重要的是该程序不支持选项，输出的结果是固定的。

## 问题
1. 上述程序的头文件你见过哪些，没见过哪些？
    >没见过`<dirent.h> ,<sys/stat.h>,<sys/types.h>`
    >其他的都见过
2. 程序的运行从哪个地方开始？
    >肯定是从main开始。
3. 哪些函数是自定义函数，哪些是库函数？这些库函数分别属于哪些库？
    >`print_file_info`,`list_directory`是自定义函数。    
    >库函数：`opendir` `readdir` `perror` `stat` `snprintf`等等。
    >DIR和dirent有关的在<dirent.h>
    和stat有关的在<sys/stat.h>
4.  argc，*argv[]作为主函数的运行参数，它们的含义是什么？是在哪里输入的？
    >argc代表输入参数个数，*argv[]用于存储参数。在命令行输入的。
5.  有哪些语法/语句段/函数是你不理解/不清楚的？如何借助资料与工具了解它们的含义？
    >逻辑运算符以及各类没见过的函数还有一堆奇奇怪怪的结构体。    
    类似对树的遍历，哪里不懂就朝哪里搜，搜了后可能还会得到不知道的知识，再继续对这些知识进行搜索......到底之后再回到上级继续学习......直到几乎理解所有概念。