#! /bin/bash

# 测试是否能编译数字和字符串
function compile {
  echo "$1" | ./8cc > tmp.s
  if [ "$?" -ne 0 ] ; then
    echo "Failed to compile $1"
    exit
  fi
  gcc -o tmp.out driver.c tmp.s
  if [ $? -ne 0 ]; then
    echo "GCC failed"
    exit
  fi
}

# test函数
function test {
  # 函数形参
  expected="$1"
  expr="$2"

  # 把echo "$expr"作为参数传入8cc 并且输入到tmp.s中
  echo "$expr" | ./8cc > tmp.s
  # $? 指的是上一个命令的结果
  if [ ! $? ]; then
    echo "Failed to compile $expr"
    exit
  fi
  # 编译driver.c和tmp.s到tmp.out文件中
  gcc -o tmp.out driver.c tmp.s || exit
  result="`./tmp.out`"
  # 检查结果
  if [ "$result" != "$expected" ]; then
    echo "Test failed: $expected expected but got $result"
    exit
  fi
}

function testfail {
  expr="$1"
  echo "$expr" | 8cc > /dev/null 2>&1
  if [ $? -eq 0 ]; then
    echo "Should fail to compile, but succeed: &expr"
    exit
  fi
}

# 执行makefile文件
make -s 8cc

test 0 0
test abc '"abc"'

test 3, '1+2'
test 3, '1 + 2'
test 10, '1+2+3+4'

testfail '"abc"'
testfail '0abc'
testfail '1+'

echo "All tests passed"