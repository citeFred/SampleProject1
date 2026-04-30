#pragma once
#include "Monster.h"
#include "Player.h"
#include "Ringbuffer.h"

class Battle
{
private:
    Player& player;
    Monster& monster;
    shared_ptr<Mercenary> mercenary; // 없는 경우 nullptr
    // string combatMessage;
    Ringbuffer<string> battleLog; // 링버퍼를 통해 최근 5개 전투 메시지를 저장
    
public:
    Battle(Player& player, Monster& monster, shared_ptr<Mercenary> mercenary = nullptr);
    bool Run();
};
