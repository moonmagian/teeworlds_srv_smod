//
// Created by moonmagian on 4/20/16.
//

#ifndef SRC_MODLOADER_H
#define SRC_MODLOADER_H

#include <set>
#include "mod.h"
class modLoader {
public:

    modLoader operator+=(mod* m){
        modList.insert(m);
        //modLoader::modList.push_back(m);
        return *this;
    }
//    modLoader operator-=(mod* m){
//        for(unsigned int i = 0; i != modList.size(); i++){
//            if(modList.at(i) == m){
//                modList.erase(modList.begin() + i);
//                return *this;
//            }
//        }
//        return *this;
//    }
    std::set<mod*> modList;
    //std::vector<mod*> modList;
};



#endif //SRC_MODLOADER_H
