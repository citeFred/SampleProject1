#include <iostream>
#include <string>
using namespace std;

int main()
{
	char userName[50];
	string charactorClass;
	char hardcoreInput;
	int classChoiceInput;

	// 스탯 시스템
	int strength = 50;
	int dexterity = 50;
	int vitality = 50;
	int energy = 50;

	// 1. 다양한 자료형의 변수 선언 및 초기값 할당
	int level = 1;
	int hp = 100;
	int mp = 100;
	float attackDamage = strength * 0.2f;
	float attackSpeed = dexterity / 10.0f;
	double movingSpeed = dexterity / 30.0f;

	// 저항 시스템
	int fireResist = 0;
	int lightningResist = 0;
	int coldResist = 0;
	int poisonResist = 0;

	// 하드코어 모두 여부 변수
	bool isHardcore = true;

	cout << "[ Character Creation ]\n";
	cout << "Input your Name : ";
	cin >> userName;
	cout << "Select your Class : \n";
	cout << "1. Amazon\n2. Assassin\n3. Barbarian\n4. Druid\n";
	cout << "5. Necromancer\n6. Paladin\n7. Sorceress\n8. Warlock\n";
	cout << "Input Class Number : ";
	cin >> classChoiceInput;
	
	switch (classChoiceInput) {
	case 1: charactorClass = "Amazon"; break;
	case 2: charactorClass = "Assassin"; break;
	case 3: charactorClass = "Barbarian"; break;
	case 4: charactorClass = "Druid"; break;
	case 5: charactorClass = "Necromancer"; break;
	case 6: charactorClass = "Paladin"; break;
	case 7: charactorClass = "Sorceress"; break;
	case 8: charactorClass = "Warlock"; break;
	default:
		charactorClass = "Unknown";
		cout << "[System] Invalid class selection. Defaulting to 'Unknown'.\n";
		break;
	}
	
	cout << "Enable Hardcore Mode? (1)Yes / (2)No : ";
	cin >> hardcoreInput;

	// 하드코어 모드 여부 설정(if, else if, else 조건문 사용)
	if (hardcoreInput == '1')
	{
		isHardcore = true;
		cout << "[System] Hardcore Mode enabled. Be careful, death is permanent!\n";
	}
	else if (hardcoreInput == '2')
	{
		isHardcore = false;
		cout << "[System] Standard Mode enabled.\n";
	}
	else
	{
		cout << "[System] Invalid input. Defaulting to Hardcore Mode enabled.\n";
		isHardcore = false;
	}

	cout << "\n ::::::::::: Welcome to the Sanctuary :::::::::::\n";
	cout << "User Name : " << userName << "\n";
	
	// 2. 변수에 저장된 데이터 출력 
	cout << "---------------- Character Status----------------\n";
	cout << "Class : " << charactorClass << "\n";
	cout << "Level : " << level << "\n";
	cout << "HP : " << hp << "\n";
	cout << "MP : " << mp << "\n";
	cout << "Attack Damage : " << attackDamage << "\n";
	cout << "Attack Speed : " << attackSpeed << "\n";
	cout << "Moving Speed : " << movingSpeed << "\n";
	cout << "Strength : " << strength << "\n";
	cout << "Dexterity : " << dexterity << "\n";
	cout << "Vitality : " << vitality << "\n";
	cout << "Energy : " << energy << "\n";
	cout << "Hardcore Mode : " << isHardcore << "(1: true, 0: false)\n";
	cout << "Fire Resistance: " << fireResist << "\n";
	cout << "Lightning Resistance: " << lightningResist << "\n";
	cout << "Cold Resistance: " << coldResist << "\n";
	cout << "Poison Resistance: " << poisonResist << "\n";

	cout << "------------------------------------------------\n";
		
	int goblinHp = 30;
	int action;
	
	cout << "\nA wild Goblin appears!\n";
	while (goblinHp > 0 && hp > 0) {
		cout << "\n[ Goblin HP: " << goblinHp << " | My HP: " << hp << " ]\n";
		cout << "\n1. Attack :";
		cin >> action;

		if (action == 1) {
			// 1. 플레이어 공격
			goblinHp -= attackDamage;
			cout << "=> You Attacked the wild Goblin! (-" << attackDamage << ")\n";

			// 2. 고블린이 살아있다면 반격
			if (goblinHp > 0) {
				hp -= 30;
				cout << "=> The wild Goblin attacked you! (-30)\n";
			}
		}
		else {
			cout << "=> Invalid action. Please choose a valid action.\n";
			hp -= 30;
			cout << "=> The wild Goblin attacked you! (-30)\n";
		}
	}

	cout << "\n";
	if (hp <= 0) {
		cout << "[System] You have been defeated by the wild Goblin...\n";
	}
	else {
		cout << "[System] Congratulations! You defeated the wild Goblin!\n";
	}

	return 0;
}