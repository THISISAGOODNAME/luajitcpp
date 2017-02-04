--
-- Created by IntelliJ IDEA.
-- User: yangyanjun
-- Date: 2017/2/4
-- Time: 上午11:16
-- To change this template use File | Settings | File Templates.
-- version.lua
--

print("LUA_VERSION: \t".._VERSION)

require("jit")
print("LUAJIT_VERSION: \t"..jit.version)
print("LUAJIT_VERSION_NUM: \t"..jit.version_num)
print("OS: \t"..jit.os)
print("ARCH: \t"..jit.arch)


