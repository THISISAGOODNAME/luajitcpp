# luajitcpp
luajit and c++ integration

## 在linux/osx/msys上编译

&#160; &#160; &#160; &#160;在posix系统上，编译时需要使用如下命令

```bash
make PREFIX=/home/myself/lj2

```
制定生成的动态库路径，否则使用`/usr/local`。

> 在cmake中使用`include_directories()`指定无效

&#160; &#160; &#160; &#160;在x86_64的mac上，使用luajit需要给编译器参数加上

```bash
-pagezero_size 10000 -image_base 100000000
```

> 同时：建议在OSX/x64上运行的luajit程序都使用`rebase`命令重设动态库

## 在MSVC下编译

&#160; &#160; &#160; &#160;在luajit源码根目录下执行：

```bash
cd src
msvcbuild
```

得到的lua51.dll就是我们需要的动态库
