#include <stdio.h>
#include <string.h>
#include "emscripten.h"

#include "lua_src/lua.h"
#include "lua_src/lualib.h"
#include "lua_src/lauxlib.h"

EMSCRIPTEN_KEEPALIVE
void runstring(const char *js_string) {
    lua_State* L = luaL_newstate();
    
    luaL_openlibs(L);
    
    // Load the Lua code as a string
    if (luaL_loadstring(L, js_string) == LUA_OK) {
        // Execute the loaded code
        if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
            // Handle error if the code fails to execute
            const char *error = lua_tostring(L, -1);
            printf("Error running Lua code: %s\n", error);
            lua_pop(L, 1);  // Remove error message from the stack
        }
    } else {
        // Handle error if the code fails to load
        const char *error = lua_tostring(L, -1);
        printf("Error loading Lua code: %s\n", error);
        lua_pop(L, 1);  // Remove error message from the stack
    }

    lua_close(L);  // Close the Lua state
}