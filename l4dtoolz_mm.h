#ifndef _INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_
#define _INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_

#include <ISmmPlugin.h>
#include "signature.h"

class l4dtoolz:public ISmmPlugin{
public:
	bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late);
	bool Unload(char *error, size_t maxlen);

	const char *GetAuthor(){ return "Ivailosp, lakwsh"; }
	const char *GetName(){ return "L4DToolZ"; }
	const char *GetDescription(){ return ""; }
	const char *GetURL(){ return "https://github.com/lakwsh/l4dtoolz"; }
	const char *GetLicense(){ return ""; }
	const char *GetVersion(){ return "1.0.2.3"; }
	const char *GetDate(){ return __DATE__; }
	const char *GetLogTag(){ return "L4DToolZ"; }

	static void *GetCookie(){ return (uint)cookie_ptr&0xF?0:cookie_ptr; }
	static void *GetSv(){ return sv_ptr; }

	static void OnChangeMaxplayers(IConVar *var, const char *pOldValue, float flOldValue);
	static void OnChangePacketcheck(IConVar *var, const char *pOldValue, float flOldValue);
private:
	static bool CheckPacket(uint, int, char *p);

	static void *info_players_ptr;
	static void *info_players_org;
	static void *lobby_match_ptr;
	static void *lobby_match_org;
	static void *cookie_ptr;
	static void *sv_ptr;
	static void *maxslots_ptr;
	static void *maxslots_org;
	static void *slots_check_ptr;
	static void *slots_check_org;
	static void *players_running_ptr;
	static void *players_running_org;
	static void *players_range_ptr;
	static void *players_range_org;
	static void *packet_ptr;
	static void *packet_org;
};
extern l4dtoolz g_l4dtoolz;
PLUGIN_GLOBALVARS();
#endif //_INCLUDE_METAMOD_SOURCE_STUB_PLUGIN_H_
