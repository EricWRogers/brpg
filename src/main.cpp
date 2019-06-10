#include <stdio.h>
#include <iostream>

#include "debug.hpp"
#include "console.hpp"

#include "lua5.3/lua.hpp"

lua_State* luaState;

const char * const CONFIG_FILE = "config.lua";

char stringBuilderBuffer[512];

void runScript(lua_State* state, const char* file)
{
    int result = luaL_loadfile(state, file);

    if (result == LUA_OK)
    {
        // use pcall to execute the script.
        result = lua_pcall(state, 0, LUA_MULTRET, 0);

        if (result != LUA_OK)
        {
            std::cout << state << std::endl;
        }
    }
    else
    {
        std::cout << state << std::endl;
    }
}

void call(lua_State* state, const char* functionName) {
    // pushes onto the stack the value of the global name of the lua function to be called.
    int type = lua_getglobal(state, functionName);

    if (type == LUA_TNIL)
    {
        snprintf(stringBuilderBuffer, sizeof(stringBuilderBuffer), "Attempted to call undefined Lua function: %s", functionName);
        std::cout << stringBuilderBuffer << std::endl;
    }
    else if (lua_pcall(state, 0, 0, 0) != 0)
    {
        std::cout << state << std::endl;
    }
}

int LuaLog(lua_State* state) {
    const char* text = lua_tostring(state, 1);
    Log(text);
    return 0;
}

void Start();
void Update();

int main( int argc, const char* argv[] )
{
	luaState = luaL_newstate();
    luaL_openlibs(luaState);

	lua_register(luaState, "Log", LuaLog);

	runScript(luaState, CONFIG_FILE);

	call(luaState, "Start");

	std::string possibleChoices[] = {"1", "2", "3"};
	//MessageForPlayer("Testing Qestion", possibleChoices);

	while(1) {
		call(luaState, "Update");
	}
}
