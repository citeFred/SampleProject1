#pragma once
#include <string>
using namespace std;

// Player 클래스
class Player
{
private:
	// 기본 정보
	string name;
	string characterClass;
	bool isHardcore;
	
	// 기본 능력치
	int strength, dexterity, vitality, energy;
	
	// 파생 능력치
	int level;
	int hp, maxHp;
	int mp, maxMp;
	float attackDamage;
	float attackSpeed;
	double movingSpeed;
	
	// 저항 능력치
	int fireResist, coldResist, lightningResist, poisonResist;
	
	// 인벤토리
	int inventory[5];
	
public:
	// 생성자
	Player(const string& name, const string& characterClass, bool isHardcore);
	
	// Getters
	string GetName() const { return name; }
	string GetCharacterClass() const { return characterClass; }
	bool GetIsHardcore() const { return isHardcore; }
	int GetStrength() const { return strength; }
	int GetDexterity() const { return dexterity; }
	int GetVitality() const { return vitality; }
	int GetEnergy() const { return energy; }
	int GetLevel() const { return level; }
	int GetHp() const { return hp; }
	int GetMaxHp() const { return maxHp; }
	int GetMaxMp() const { return maxMp; }
	int GetMp() const { return mp; }
	int GetFireResist() const { return fireResist; }
	int GetColdResist() const { return coldResist; }
	int GetLightningResist() const { return lightningResist; }
	int GetPoisonResist() const { return poisonResist; }
	float GetAttackDamage() const { return attackDamage; }
	float GetAttackSpeed() const { return attackSpeed; }
	float GetMovingSpeed() const { return movingSpeed; }
	int* GetInventory() { return inventory; }
	
	// 기능(함수)
	bool isAlive() const { return hp > 0; }
	void TakeDamage(int damage);
	int Attack() const;
	int CriticalAttack() const;
	void LevelUp();
	void PreviewCritical() const;
	void PrintLevel() const;
};