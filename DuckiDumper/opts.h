#pragma once
#include "pch.h"
#include <string>
#include <vector>

struct PatternConfig {
    std::string Name;
    std::string BytePattern;
    bool bFollowJump = true;

};
struct Settings {
    static inline bool bNullPtrWarn = false;
};


static const std::vector<PatternConfig> PatternsToScan = {
    //Example: {"NameHere","PatternHere,false}, if set to "true" it will skip that

    {"NameHere", "PatternHere", false },
    {"NameHere", "PatternHere", true }
};
