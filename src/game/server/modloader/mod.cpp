//
// Created by moonmagian on 5/2/16.
//

#include "mod.h"
CProjectile mod::makeProjectile(CGameWorld *pGameWorld, int Type, int Owner,CPlayer* sender,vec2 Pos, vec2 Dir, int Span, int Damage,
                                bool Explosive, float Force, int SoundImpact, int Weapon, IServer* server) {
    CProjectile *pProj = new CProjectile(pGameWorld, Type,
                                         Owner,
                                         Pos,
                                         Dir,
                                         Span,
                                         Damage, Explosive, Force, SoundImpact, Weapon);

    // pack the Projectile and send it to the client Directly
    CNetObj_Projectile p;
    pProj->FillInfo(&p);
    CMsgPacker Msg(NETMSGTYPE_SV_EXTRAPROJECTILE);
    Msg.AddInt(1);
    for(unsigned i = 0; i < sizeof(CNetObj_Projectile)/sizeof(int); i++)
        Msg.AddInt(((int *)&p)[i]);
    server->SendMsg(&Msg, 0, sender->GetCID());
}
void mod::game_chat_makeBroadcast(const char *content, IServer *server){
    CNetMsg_Sv_Broadcast s;
    char aBuf[256];
    str_format(aBuf, sizeof(aBuf), content);
    s.m_pMessage = aBuf;
    server->SendPackMsg(&s, 0, -1);
}