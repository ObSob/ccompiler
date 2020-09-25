# **Markdown语法**

## 标题
“#”的个数表示标题级数

## 段落
空一行表示另一段

## 换行
在末尾空两格表示另一行


## 强调语法
### 粗体
用***包起来表示粗体
### 斜体
用*包起来表示斜体
### 粗斜体
用***包起来表示粗斜体

## 块引用
> 在一行前面加上>
### 多行引用
> 在行间空出一行>
>
> 否则会合并到一起
### 多级引用
> 一级
>
>> 二级
### 引用中可以插入其他元素
> 引用
>
> - Revenue was off the chart.
> - Profits were higher than ever.
>
> *Everything* is ***going*** according to **plan**.

## 列表
### 无序列表
-   "-(\t)"  其实-*+都i可以
-   表示无序列表
### 有序列表
 1. “1.(\t)”
 1. 表示有序列表
 
 ### 代码段

 ``
用键盘1左边的符号括起来 
或者是两个那个符号
 ``
 
    
    TAB(\t)
    也可以实现代码段

```c++
// 使用三个那个符号可以指定代码段的语言
namespace std;
int main(void){
    return 0;
}
```

## 水平线
用`***`, `---`, `___`
***
---
___

## 链接
google:[google](www.google.com"谷歌"")  
用`[`链接名`]``(`网站地址` “”)`  
括号里面可以插入标题  
### url
<https://google.com> ``<https://google.com>``
### email
<fake@example.com>  ``<fake@example.com>``（idea插件不支持）

## 插入图片
``
![info](url "title")
``  
![ycy](https://tse1-mm.cn.bing.net/th?id=OIP.4DwwDTw1xMGyo63lM9niBgHaMx&w=120&h=160&c=8&rs=1&qlt=90&dpr=1.25&pid=3.1&rm=2 "this is ycy")

## 转义字符
```
Character Name
\ 	backslash
` 	backtick (see also escaping backticks in code)
* 	asterisk
_ 	underscore
{ } 	curly braces
[ ] 	brackets
( ) 	parentheses
# 	pound sign
+ 	plus sign
- 	minus sign (hyphen)
. 	dot
! 	exclamation mark
| 	pipe (see also escaping pipe in tables)
```

