//
// Created by yangyanjun on 2017/2/4.
//


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "lua.hpp"

void TestLua();

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    std::cout << "世界, 你好!" << std::endl;
    TestLua();
    return 0;
}

void TestLua()
{
    lua_State *L = luaL_newstate();
    if (L == NULL)
    {
        cout << "lua初始化失败" << endl;
        return;
    }
    luaL_openlibs(L);

    string str;

    while (true)
    {
        cout << "请输入 lua 代码路径，输入 quit() 退出 lua 解释器" << endl;
        cout << "> ";
        getline(cin, str, '\n');
        if (str == "quit()") break;

        if (luaL_loadfile(L, str.c_str()) || lua_pcall(L, 0, 0, 0))
        {
            const char * msg = lua_tostring(L, -1);
            cout << string(msg) << endl;
        }
    }

    lua_close(L);
}
