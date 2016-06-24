//
// Created by moonmagian on 5/4/16.
//

#include "mod.h"
#include <iostream>
testMod::testMod():mod() {
this->modName = "moonMod";
}
void testMod::onCharacterSpawn(CCharacter *c, IGameController *ic) {
    std::cout << "Some one has spawned" << std::endl;
}
modDamageTakenAction testMod::OnDamageTaken(vec2 Force, int Dmg, int From, int Weapon, CCharacter *cch) {
    std::cout << "Damage taken. From: " << From << " to " << cch->GetPlayer()->GetCID() << std::endl;
    modDamageTakenAction mta;
    gameServer->m_apPlayers[0]->GetCharacter()->getWeaponStatus(WEAPON_GRENADE)->m_Ammo = 2;
    if(From == cch->GetPlayer()->GetCID() && Weapon == WEAPON_GRENADE){
        mta.do_damage = false;
        mta.do_force = true;
        mta.do_emotion = true;
        mta.do_sound = true;
    }
    return mta;
}
void testMod::onKeyStatusChanged(modKeyStatus mks, CCharacter* character) {
    if(mks.m_Fire){
        std::cout << "Fire is pressed by " << character->Server()->ClientName(character->GetPlayer()->GetCID()) << std::endl;
        if(*(character->getActiveWeapon()) == WEAPON_RIFLE || *(character->getActiveWeapon()) == WEAPON_GRENADE || *(character->getActiveWeapon()) == WEAPON_GRENADE){
            if(character->getWeaponStatus(*(character->getActiveWeapon()))->m_Ammo == 0){
                character->IncreaseArmor(-2);
                character->getWeaponStatus(*(character->getActiveWeapon()))->m_Ammo = 10;
            }
        }

    }
}
modPickupAction testMod::onPickup(int type, int subtype) {
    modPickupAction mpa;
    if(type == POWERUP_ARMOR){
        mpa.breakPickup = true;
    }
    return mpa;
}
modFireAction testMod::onFire(int weapon, CCharacter *c) {
    modFireAction mfa;
    mfa.doAmmoDecrease = false;
    CNetMsg_Sv_Motd m;
//    char aBuf[256];
//    std::string content = "aa";
//    str_format(aBuf, sizeof(aBuf), content.c_str());
//    m.m_pMessage = aBuf;
//    game_chat_make(&m, c->Server());
    game_chat_makeBroadcast(c->GameServer()->m_aVoteDescription, c->Server());
    return mfa;
}
void testMod::tick(IGameController *ic) {
}
modVoteAction testMod::onVoteStart(char *voteDescription, char *voteCommand, int voteCreator, CGameContext* gameserver) {
    modVoteAction mva;
    if(gameserver->m_apPlayers[voteCreator]->GetCharacter()->IsGrounded()){
        mva.breakVote = true;
    }
    return mva;
}
