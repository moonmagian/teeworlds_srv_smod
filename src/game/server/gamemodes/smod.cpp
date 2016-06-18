/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "smod.h"
#include "../modloader/modLoaderGetter.h"
#include <iostream>
#include <map>
//Don't delete next line
//@MODLOADER_INCLUDE
#include "game/server/gameMods/testMod/mod.h"
testMod m_testMod;
//@MODLOADER_END
CGameControllerSMod::CGameControllerSMod(class CGameContext *pGameServer)
        : IGameController(pGameServer)
{
    
    m_GameFlags = GAMEFLAG_TEAMS;
    m_pGameType = "SMOD";
//@MODLOADER_ADD
(*modLoaderGetter::modloader_main) += &m_testMod;
//@MODLOADER_END
    //m_GameFlags = GAMEFLAG_TEAMS;
}

void CGameControllerSMod::Tick()
{
    IGameController::Tick();
    for(std::set<mod *>::iterator i = modLoaderGetter::modloader_main->modList.begin(); i != modLoaderGetter::modloader_main->modList.end(); i++){
        (*i)->tick(this);
    }
    }

void CGameControllerSMod::OnCharacterSpawn(class CCharacter *pChr) {
    IGameController::OnCharacterSpawn(pChr);
    for(std::set<mod *>::iterator i = modLoaderGetter::modloader_main->modList.begin(); i != modLoaderGetter::modloader_main->modList.end(); i++){
        (*i)->onCharacterSpawn(pChr, this);
    }
}
void CGameControllerSMod::Snap(int SnapId) {
    IGameController::Snap(SnapId);
}
int CGameControllerSMod::OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon) {
    IGameController::OnCharacterDeath(pVictim, pKiller, Weapon);
    for(std::set<mod *>::iterator i = modLoaderGetter::modloader_main->modList.begin(); i != modLoaderGetter::modloader_main->modList.end(); i++){
        (*i)->OnCharacterDeath(pVictim, pKiller, Weapon, this);
    }

    return 0;
}
////moon mod part
//int CGameControllerSMod::getPlayerNumber(double range = 1e10000) {
//    //the value of range is normally not necessary
//    CCharacter* e[Server()->MaxClients()];
//    return GameServer()->m_World.FindEntities(vec2(0, 0), 1e100, (CEntity**)e, Server()->MaxClients(), CGameWorld::ENTTYPE_CHARACTER);
//}
