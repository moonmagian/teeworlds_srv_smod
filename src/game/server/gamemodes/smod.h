/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_GAMEMODES_MOD_H
#define GAME_SERVER_GAMEMODES_MOD_H
#include <game/server/gamecontroller.h>
#include <engine/shared/config.h>
#include <game/server/entities/character.h>
#include <game/server/player.h>
#include <map>

// you can subclass GAMECONTROLLER_CTF, GAMECONTROLLER_TDM etc if you want
// todo a modification with their base as well.
class CGameControllerSMod : public IGameController
{
public:
    CGameControllerSMod(class CGameContext *pGameServer);
    virtual void Tick();
    virtual void OnCharacterSpawn(class CCharacter *pChr);
    virtual int OnCharacterDeath(class CCharacter *pVictim, struct CPlayer *pKiller, int Weapon);
    virtual void Snap(int SnapId);
    //moon APIs
    // add more virtual functions here if you wish
};
#endif
