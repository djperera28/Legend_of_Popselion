#ifndef POPSOPEDIA_H
#define POPSOPEDIA_H

#include <unordered_map>
#include <string>
#include "popsmon.h"

class Popsopedia {
    public:
        static void init();                                       // loads all Popsmon into the registry
        static Popsmon get(const std::string& name);
        static Popsmon randomWild();

    private:
        static std::unordered_map<std::string, Popsmon> registry; // name to Popsmon mapping
};

#endif