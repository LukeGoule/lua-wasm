@echo off

echo Installing emdk
cd emsdk
git pull
call .\emsdk.bat install latest
call .\emsdk.bat activate latest
cd ..

echo Building environment
call .\emsdk\emsdk_env.bat

echo Building source
call emcc -O3 -s WASM=1 -s EXPORTED_FUNCTIONS=_runstring,stringToUTF8,_free,_malloc -o web\build\lua.js lua_runstring.c lua_src/onelua.c

echo Starting server
call python3 -m http.server 8000 --directory ./web