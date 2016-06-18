//
// Created by moonmagian on 5/4/16.
//

#ifndef SRC_TESTMOD_H
#define SRC_TESTMOD_H

#include <game/server/modloader/mod.h>

class testMod: public mod {
public:
    virtual void onCharacterSpawn(CCharacter *c, IGameController *ic);
    virtual modDamageTakenAction OnDamageTaken(vec2 Force, int Dmg, int From, int Weapon, CCharacter *cch);
    virtual void onKeyStatusChanged(modKeyStatus mks, CCharacter* character);
    virtual modPickupAction onPickup(int type, int subtype);
    virtual modFireAction onFire(int weapon, CCharacter* c);
    virtual void tick(IGameController* ic);
    virtual modVoteAction onVoteStart(char voteDescription[], char voteCommand[], int voteCreator, CGameContext* gameserver);
    testMod();
};


#endif //SRC_TESTMOD_H
