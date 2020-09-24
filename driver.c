//
// Created by wbh on 2020/9/24.
//


#include <stdio.h>

// 这个mymain被8cc.c的main输出到一个文件里面，内容是一个用汇编代码写的函数mymain
extern int mymain(void);

int main(int argc, char **argv) {
    int val = mymain();
    printf("%d\n", val);
    return 0;
}