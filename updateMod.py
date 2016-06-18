import os
def modCheck(direction):
    if(os.path.exists("./src/game/server/gameMods/" + direction + "/mod.meta") and os.path.exists("./src/game/server/gameMods/" + direction + "/mod.cpp") and os.path.exists("./src/game/server/gameMods/" + direction + "/mod.h")):
        return True
    else:
        return False
def modMeta(direction):
    f = open('./src/game/server/gameMods/' + direction + '/mod.meta', 'r')
    name = 'undef'
    link = 'undef'
    author = 'undef'
    ver = 'undef'
    for ln in f.readlines():
        ln = ln.replace('\n', '')
        lns = ln.split(' ')
        if len(lns) != 2:
            continue
        if(lns[0] == 'mod_name'):
            name = lns[1]
        if(lns[0] == 'mod_author'):
            author = lns[1]
        if(lns[0] == 'mod_version'):
            ver = lns[1] 
        if(lns[0] == 'mod_upgrade' and lns[1] != '0'):
            link = lns[1]
    return (name, ver, author, link)
modList = []
for parents, directions, filenames in os.walk("./src/game/server/gameMods"):
    if(parents != "./src/game/server/gameMods"):
        continue
    for direction in directions:
        print("Checking for folder... ", direction)
        if modCheck(direction):
            modList.append((direction, modMeta(direction)))
            print('Mod name:' + modList[-1][1][0])
            print('Mod version:' + modList[-1][1][1])
            print('Mod author:' + modList[-1][1][2])
            print('Mod upgrade link:' + modList[-1][1][3])
            print("Mod confirmed. Added to modlist.")
            print('-----')
#TODO:NETWORK UPGRADE.
f = open("./src/game/server/gamemodes/smod.cpp", 'r')
nf = []
status = 0
for line in f.readlines():
    if line.startswith('//@MODLOADER_END'):
        status = 0
    if(status == 0):
        nf.append(line)
    if line.startswith('//@MODLOADER_INCLUDE'):
        status = 1
        for m in modList:
            nf.append('''#include "game/server/gameMods/''' + m[0] + '''/mod.h"\n''')
            nf.append(m[1][0] + ' m_' + m[1][0] + ';\n')
    if line.startswith('//@MODLOADER_ADD'):
        status = 1
        for m in modList:
            nf.append('''(*modLoaderGetter::modloader_main) += &m_''' + m[1][0] + ';\n')
f.close()
f = open("./src/game/server/gamemodes/smod.cpp", "w")
f.writelines(nf)
f.close()
print('Mod update complete')
while True:
    a = input('Do you want to launch your server now? [y/N]')
    if(a == 'y' or a == 'Y'):
        #launch server
        import launchSrv
        break
    if(a == 'n' or a == 'N' or a == ''):
        break 
    else:
        continue
