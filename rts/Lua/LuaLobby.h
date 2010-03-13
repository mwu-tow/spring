/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef LUALOBBY_H
#define LUALOBBY_H

#include "lib/liblobby/Connection.h"
#include "Lunar.h"

class LuaLobby : public Connection
{
public:
	LuaLobby(lua_State *L);
	~LuaLobby();

	// callables and callbacks (virtual)
	int Poll(lua_State *L);
	
	int Connect(lua_State *L);
	virtual void DoneConnecting(bool success, const std::string& err);

	int Register(lua_State *L);
	virtual void RegisterDenied(const std::string& reason);
	virtual void RegisterAccept();

	int Login(lua_State *L);
	virtual void Denied(const std::string& reason);
	virtual void LoginEnd();
	virtual void Aggreement(const std::string text);
	int ConfirmAggreement(lua_State *L);

	virtual void Motd(const std::string text);

	int JoinChannel(lua_State *L);
	virtual void Joined(const std::string& channame);
	virtual void JoinFailed(const std::string& channame, const std::string& reason);
	int LeaveChannel(lua_State *L);
	
	int Say(lua_State *L);
	int SayEx(lua_State *L);
	int SayPrivate(lua_State *L);
	virtual void Said(const std::string& channel, const std::string& user, const std::string& text);
	virtual void SaidEx(const std::string& channel, const std::string& user, const std::string& text);
	virtual void SaidPrivate(const std::string& user, const std::string& text);

	virtual void Disconnected();
	virtual void NetworkError(const std::string& msg);

	// inside stuff
	static bool RegisterUserdata(lua_State *L);

	static const char className[];
	static Lunar<LuaLobby>::RegType methods[];
	
private:
	lua_State *L;
};


#endif