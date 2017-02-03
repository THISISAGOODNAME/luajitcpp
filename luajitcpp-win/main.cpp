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

//    luaopen_base(L);
//    luaopen_table(L);
//    luaopen_package(L);
//    luaopen_io(L);
//    luaopen_string(L);

    luaL_openlibs(L);

    string str;

    while (true)
    {
        cout << "请输入lua代码:" << endl;
        cout << "> ";
        getline(cin, str, '\n');
//        cin >> str;
        if (str == "quit()")
        {
            break;
        }
        else
        {
            if (luaL_loadstring(L, str.c_str()) || lua_pcall(L, 0, 0, 0))
            {
                const char * msg = lua_tostring(L, -1);
                cout << string(msg) << endl;
            }
        }
    }

    lua_close(L);
}