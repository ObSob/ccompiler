# /bin/bash

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

# 执行makefile文件
make -s 8cc

test 0 0
test 42 42

rm -f tmp.out tmp.s
echo "All tests passed"