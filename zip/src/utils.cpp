#include <dmsdk/lua/lauxlib.h>
#include <dmsdk/dlib/log.h>
#include "extension.h"
#include "utils.h"

namespace utils {
	void check_arg_count(lua_State *L, int count_exact) {
		int count = lua_gettop(L);
		if (count != count_exact) {
			luaL_error(L, "This function requires %d argument(s), got %d.", count_exact, count);
		}
	}

	void check_arg_count(lua_State *L, int count_from, int count_to) {
		int count = lua_gettop(L);
		if (count < count_from || count > count_to) {
			luaL_error(L, "This function requires from %d to %d arguments, got %d.", count_from, count_to, count);
		}
	}

	bool check_arg_type(lua_State *L, const char *function_name, const char *arg_name, int index, int type) {
		int actual_type = lua_type(L, index);
		if (actual_type == type) {
			return true;
		} else {
			const char *type_name = lua_typename(L, type);
			const char *actual_type_name = lua_typename(L, actual_type);
			dmLogError(EXTENSION_NAME_STRING ".%s(): the argument `%s` at index %d has to be a %s, got a %s instead.", function_name, arg_name, index, type_name, actual_type_name);
			return false;
		}
	}
}