/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "god.h"
#include <iostream>
#include <map>
int tick = 0;
bool decrease = false;
CGameControllerGod::CGameControllerGod(class CGameContext *pGameServer)
: IGameController(pGameServer)
{
	//m_GameFlags = GAMEFLAG_TEAMS;
	// Exchange this to a string that identifies your game mode.
	// DM, TDM and CTF are reserved for teeworlds original modes.
	m_pGameType = "KILL";
	//m_GameFlags = GAMEFLAG_TEAMS; // GAMEFLAG_TEAMS makes it a two-team gamemode
}

void CGameControllerGod::Tick()
{

	//GameServer()->m_apPlayers[0]->GetCharacter()->GiveNinja();
	// this is the main part of the gamemode, this function is run every tick
	IGameController::Tick();
	refresh();
	for(std::map<CPlayer*, int>::iterator c = life_map.begin(); c != life_map.end(); ++c){
		if(*((*c).first->GetCharacter()->getArmor()) != 0){
			((*c).first)->GetCharacter()->IncreaseArmor(-*(*c).first->GetCharacter()->getArmor());
		}
		if(tick == 100 && *(*c).first->GetCharacter()->getHealth() > 3){
			(*c).first->GetCharacter()->TakeDamage(vec2(0,0), 1, -1, WEAPON_GAME);
		}
	}
	if(tick == 100){
		tick = 0;
	}
	else{
		tick ++;
	}
//	std::cout<<tick<<std::endl;
}
void CGameControllerGod::OnCharacterSpawn(class CCharacter *pChr) {
	IGameController::OnCharacterSpawn(pChr);
}
void CGameControllerGod::Snap(int SnapId) {
	IGameController::Snap(SnapId);
	}
	//if(c->m_Armor != 10){
	//	std::cout<<"cool one"<<std::endl;
	//}
void CGameControllerGod::refresh(){

		CCharacter* e[Server()->MaxClients()];
		int times = GameServer()->m_World.FindEntities(vec2(0, 0), 1e100, (CEntity**)e, Server()->MaxClients(), CGameWorld::ENTTYPE_CHARACTER);
		if(times == life_map.size()) return;
		life_map.clear();
		for(int loop = 0 ; loop != times ; ++loop){
			int health = *(e[loop]->getHealth());
			std::pair<CPlayer*, int> p(e[loop]->GetPlayer(), health);
			life_map.insert(p);

	}}
int CGameControllerGod::OnCharacterDeath(class CCharacter *pVictim, struct CPlayer *pKiller, int Weapon){
	IGameController::OnCharacterDeath(pVictim, pKiller, Weapon);
	if (pVictim && Weapon != WEAPON_GAME && Weapon != WEAPON_WORLD) {
		pKiller->GetCharacter()->IncreaseHealth(10 - *pKiller->GetCharacter()->getHealth());
	}
}
