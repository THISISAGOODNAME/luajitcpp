# luajitcpp
luajit and c++ integration

By default, modules are only searched under the prefix /usr/local. You can add an extra prefix to the search paths by appending the PREFIX option, e.g.:
```
make PREFIX=/home/myself/lj2
```
Note for OSX: if the MACOSX_DEPLOYMENT_TARGET environment variable is not set, then it's forced to 10.4.

If you're building a 64 bit application on OSX which links directly or indirectly against LuaJIT, you need to link your main executable with these flags:
```
-pagezero_size 10000 -image_base 100000000
```
Also, it's recommended to rebase all (self-compiled) shared libraries which are loaded at runtime on OSX/x64 (e.g. C extension modules for Lua). See: man rebase