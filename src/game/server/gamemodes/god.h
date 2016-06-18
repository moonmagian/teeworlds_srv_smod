/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_GAMEMODES_GOD_H
#define GAME_SERVER_GAMEMODES_GOD_H
#include <game/server/gamecontroller.h>
#include <engine/shared/config.h>
#include <game/server/entities/character.h>
#include <game/server/player.h>
#include <map>

// you can subclass GAMECONTROLLER_CTF, GAMECONTROLLER_TDM etc if you want
// todo a modification with their base as well.
class CGameControllerGod : public IGameController
{
public:
	int player_count_l;
	std::map<CPlayer*, int> life_map;
	CGameControllerGod(class CGameContext *pGameServer);
	virtual void Tick();
	int OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon);
	virtual void OnCharacterSpawn(class CCharacter *pChr);
	virtual void Snap(int SnapId);
	virtual void refresh();
	// add more virtual functions here if you wish
};
#endif
