#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#define LOVR_VERSION_MAJOR 0
#define LOVR_VERSION_MINOR 1
#define LOVR_VERSION_PATCH 0

void lovrInit(lua_State* L, int argc, char** argv);
void lovrDestroy(int exitCode);
void lovrRun(lua_State* L);
