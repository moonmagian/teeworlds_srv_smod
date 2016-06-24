//
// Created by moonmagian on 5/2/16.
//

#ifndef SRC_MOD_H
#define SRC_MOD_H
#include <game/server/gamecontroller.h>
#include <engine/shared/config.h>
#include <game/server/entities/character.h>
#include <game/server/player.h>
#include <game/server/gamemodes/smod.h>
#include "game/server/entities/projectile.h"
//#include <game/server/modloader/modEvents.h>
#include <string>
#include "mod_actions.h"
class mod {
public:
    std::string modName;
    int modVerson;
    static CGameContext* gameServer;
    static IServer* server;
    //basic overridable APIs
    virtual void onKeyStatusChanged(modKeyStatus mks, CCharacter* character){};
    virtual void onCharacterSpawn(CCharacter* c, IGameController* igc){};
    virtual modDamageTakenAction OnDamageTaken(vec2 Force, int Dmg, int From, int Weapon, CCharacter *cch){modDamageTakenAction mta;return mta;};
    virtual modPickupAction onPickup(int type, int subtype){modPickupAction mpa; return mpa;};
    virtual void OnCharacterDeath(class CCharacter *pVictim, struct CPlayer *pKiller, int Weapon, IGameController* igc){};
    virtual modFireAction onFire(int Weapon, CCharacter* cch){modFireAction mfa; return mfa;}
    virtual void tick(IGameController* igc){};
    virtual modVoteAction onVoteStart(char voteDescription[], char voteCommand[], int voteCreator, CGameContext* gameserver){modVoteAction mva; return mva;};
    //mod APIs, don't change them unless necessary.
    virtual CProjectile makeProjectile(CGameWorld *pGameWorld, int Type, int Owner, CPlayer* sender, vec2 Pos, vec2 Dir, int Span,
                               int Damage, bool Explosive, float Force, int SoundImpact, int Weapon, IServer* server);
    virtual void game_chat_makeBroadcast(const char *content, IServer *server);
    virtual void game_chat_makeBroadcast(const char *content, int cid, IServer *server);
//    virtual void game_chat_makeChat(CNetMsg_Sv_Chat* message, IServer *server);
};



#endif //SRC_MOD_H
