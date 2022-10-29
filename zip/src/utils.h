#ifndef utils_h
#define utils_h

#include <dmsdk/lua/lua.h>

namespace utils {
	void check_arg_count(lua_State *L, int count_exact);
	void check_arg_count(lua_State *L, int count_from, int count_to);
	bool check_arg_type(lua_State *L, const char *function_name, const char *arg_name, int index, int type);
}

#endif