#pragma once
#include <string>

#include "Character.h"
using namespace std;

// Character 클래스를 상속 받은 Player 클래스
class Player : public Character
{
private:
	// Player 고유 정보
	string name;
	string characterClass;
	bool isHardcore;
	
	// 경험치
	int exp, expToNextLevel;
	
	// 인벤토리
	int inventory[5];
	
public:
	// 생성자
	Player(const string& name, const string& characterClass, bool isHardcore);
	
	string GetName() const { return name; }
	string GetCharacterClass() const { return characterClass; }
	bool GetIsHardcore() const { return isHardcore; }
	int GetExp() const { return exp; }
	int GetExpToNextLevel() const { return expToNextLevel; }
	int* GetInventory() { return inventory; }
	
	// 기능(함수)
	int CriticalAttack() const;
	void LevelUp();
	void GainExp(int amount);
	void PreviewCritical() const;
	void PrintLevel() const;
};