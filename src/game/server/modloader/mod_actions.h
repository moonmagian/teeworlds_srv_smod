//
// Created by moonmagian on 5/7/16.
//

#ifndef SRC_MOD_DAMAGE_TAKEN_ACTION_H
#define SRC_MOD_DAMAGE_TAKEN_ACTION_H
#define FORCEVOTE_YES 1
#define FORCEVOTE_NO 2
struct modDamageTakenAction{
public:
    modDamageTakenAction(){
        do_force = true;
        do_sound = true;
        do_emotion = true;
        do_damage = true;
    }
    bool do_damage;
    bool do_sound;
    bool do_emotion;
    bool do_force;
};
struct modKeyStatus{
bool m_Fire;
    bool m_Direction;
    bool m_TargetX;
    bool m_TargetY;
    bool m_Jump;
    bool m_Hook;
    bool m_PlayerFlags;
    bool m_WantedWeapon;
    bool m_NextWeapon;
    bool m_PrevWeapon;
};
struct modPickupAction{
    bool breakPickup;
    bool doSound;
    modPickupAction(){
        breakPickup = false;
        doSound = true;
    }
};
struct modFireAction{
    bool doAmmoDecrease;
    int AmmoDecreaseValue; //If ammo doesnt reach the AmmoDecreaseValue, the shooting will be canceled.
    //For a better control ( such as half the damage when Ammo is not enough, control the WeaponStatus directly and be careful.
    bool breakShoot;
    modFireAction(){
        doAmmoDecrease = true;
        breakShoot = false;
        AmmoDecreaseValue = 1;
    }
};
struct modVoteAction{
    bool breakVote;
    bool forceVote;
    int forceVoteType;
    modVoteAction(){
        breakVote = false;
        forceVote = false;
        forceVoteType = FORCEVOTE_NO;
    }
};
#endif //SRC_MOD_DAMAGE_TAKEN_ACTION_H
