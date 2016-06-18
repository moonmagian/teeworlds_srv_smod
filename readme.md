#Teeworlds\_srv\_smod
##What's this
Teeworlds\_srv\_smod is a simple modloader for teeworlds server. With smod you can easily load many mods. You can make things like hammerFng, login system and so on. Also, Smod provides some APIs which will make mod development easy and fast.
##Installation

smod needs lua, Python, a c++ compiler and [bam](https://github.com/matricks/bam "bam") to run.You need to compile bam and put it into bam/, make sure that you don't get error when running
`
./bam/bam
`
After this you can use smod.
##Usage
###For users
Mods are located in src/game/server/gameMods.
When you delete mods or add mods, you need to run `python updateMod.py`. You can use `python launchSrv.py` to launch server. If you didn't change any mods, launching the binary file of teeworlds server also works.
###For developers
smod is easy to use. There has been a sample mod called testMod in the mod folder.To develop a mod, You need a folder which contains at least mod.cpp, mod.h and mod.meta.Here is a sample for mod.meta.
```
//mod.meta
mod_name [name of your mod]
//the mod name must be the same as the class name of the mod.
mod_author [author]
mod_version [version]
mod_upgrade [WIP feature, use 0 for now]
```
and mod.h looks like this.
```cpp
//mod.h
#ifndef SRC_TESTMOD_H
#define SRC_TESTMOD_H

#include <game/server/modloader/mod.h>
//You have to include this to use APIs.
//the class inherites mod class. Name of the class must be the same as your mod_name
class testMod: public mod {
public:
//Use this way to add your methods.
    virtual void onCharacterSpawn(CCharacter *c, IGameController *ic);
    virtual modDamageTakenAction OnDamageTaken(vec2 Force, int Dmg, int From, int Weapon, CCharacter *cch);
    virtual void onKeyStatusChanged(modKeyStatus mks, CCharacter* character);
    virtual modPickupAction onPickup(int type, int subtype);
    virtual modFireAction onFire(int weapon, CCharacter* c);
    virtual void tick(IGameController* ic);
    virtual modVoteAction onVoteStart(char voteDescription[], char voteCommand[], int voteCreator, CGameContext* gameserver);
};


#endif //SRC_TESTMOD_H
```

