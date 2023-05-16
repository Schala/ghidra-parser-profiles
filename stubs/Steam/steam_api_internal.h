#include "steam_api_common.h"

HSteamUser SteamAPI_GetHSteamUser();
void* SteamInternal_ContextInit(void *pContextInitData);
void* SteamInternal_FindOrCreateUserInterface(HSteamUser hSteamUser, const char *pszVersion);