#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdarg.h>

// string 最大长度
#define BUFLEN 256

// 输出err函数，类似于printf使用
void error(char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

// 跳过空格
void skip_space(void){
    int c;
    while((c = getc(stdin)) != EOF) {
        if((isspace(c)))
            continue;
        ungetc(c, stdin);
        return ;
    }
}

// 编译数字
int read_number(int n){
    int c;
    // 获取输入
    while(c = getc((stdin)) != EOF){
        // 不是数字
        if(!isdigit(c)){
            ungetc(c, stdin);
            return n;
        }
        // 转换为十进制数字
        n = n * 10 + (c - '0');
    }
}

void compile_expr2(void) {
    for(;;) {
        skip_space();
        int c = getc(stdin);
        if (c == EOF) {
            printf("ret\n");
            exit(0);
        }
        char *op;
        if (c == '+') op = "add";
        else if (c == '-') op = "sub";
        else error("Operator expected, but got '%c'", c);
        skip_space();
        c = getc(stdin);
        if (!isdigit(c))
            error("Number expected, but got '%c'", c);
        printf("%s $%d, %%rax\n\t", op, read_number(c - '0'));
    }
}

void compile_expr(int n) {
    n = read_number(n);
    printf(".text\n\t"
           ".global intfn\n"
           "intfn:\n\t"
           "mov $%d, %%rax\n\t", n);
    compile_expr2();
}

// 编译字符串
void compile_string(void) {
    char buf[BUFLEN];
    int i = 0;
    while(1){
        int c = getc(stdin);
        // 字符串未正常结束
        if(c == EOF){
            error("Unterminated string");
        }
        // 遇到 " 表示字符串终止
        if(c == '"') break;
        // 遇到 \ 读取下一个字符
        if(c == '\\'){
            c = getc(stdin);
            // \ 未正常结束
            if(c == EOF){
                error("Unterminated \\");
            }
        }
        // 存入buf
        buf[i++] = c;
        // string超出最大长度
        if(i == BUFLEN - 1){
            error("String is too long");
        }
    }
    // 字符末尾补'\0'表示结束
    buf[i] = '\0';
    printf( "\t.data\n"
                    ".mydata:\n\t"
                    ".string \"%s\"\n\t"
                    ".global stringfn\n"
                    "stringfn:\n\t"
                    "lea .mydata(%%rip), %%rax\n\t"
                    "ret\n", buf);
    exit(0);
}

void compile(void) {
    int c = getc(stdin);
    if(!isdigit(c))
        compile_expr(c - '0');
    else if(c == '"')
        compile_string();
    else
        error("Don't know how to handle '%c'", c);
}

int main(int argc, char **argv) {
    compile();
    return 0;
}