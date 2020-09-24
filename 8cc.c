//
// Created by wbh on 2020/9/24.
//


#include <stdio.h>
#include <stdlib.h>

// 生成一个用汇编代码编写的函数mymain
int main(int argc, char **argv) {
    int val;
    if (scanf("%d", &val) == EOF) {
        perror("scanf");
        exit(1);
    }
    printf("\t.text\n\t"
           ".global mymain\n"
           "mymain:\n\t"
           "mov $%d, %%eax\n\t"
           "ret\n", val);
    return 0;
}