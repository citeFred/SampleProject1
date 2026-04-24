#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include <iomanip>

#include "Battle.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

int main()
{
	string userName;
	string charactorClass;
	int classChoiceInput;
	char hardcoreInput;
	bool isHardcore = true;

	// 1. 캐릭터 생성 UI
	cout << "==========================================================================\n";
	cout << "      :::::::::  :::::::::::     :::     :::::::::  :::        :::::::: \n";
	cout << "     :+:    :+:     :+:         :+:     :+:    :+: :+:       :+:    :+: \n";
	cout << "    +:+    +:+     +:+        +:+ +:+   +:+    +:+ +:+       +:+    +:+  \n";
	cout << "   +#+    +:+     +#+       +#+  +:+  +#++:++#+  +#+       +#+    +:+   \n";
	cout << "  +#+    +#+     +#+      +#+#+#+#+# +#+    +#+ +#+       +#+    +#+    \n";
	cout << " #+#    #+#     #+#     #+#      #+# #+#    #+# #+#       #+#    #+#     \n";
	cout << "#########  ########### ###      ### #########  ##########  ########      \n";
	cout << "                                             ::::::::                   \n";
	cout << "                                           :+:    :+:                   \n";
	cout << "        M  U  D                                 +:+                     \n";
	cout << "                                            +#++:                       \n";
	cout << "       E D I T I O N                      +#+                           \n";
	cout << "                                        #+#                             \n";
	cout << "                                      ##########                        \n";
	cout << "==========================================================================\n";
	cout << ">> Input your name : ";
	cin >> userName;

	system("cls"); // 화면 지우기

	// 직업 선택 UI
	cout << "==================================================\n";
	cout << "||" << left << setw(46) << "               SELECT YOUR CLASS" << "||\n";
	cout << "--------------------------------------------------\n";
	cout << "|| 1. Amazon       2. Assassin     3. Barbarian ||\n";
	cout << "|| 4. Druid        5. Necromancer  6. Paladin   ||\n";
	cout << "|| 7. Sorceress    8. Warlock                   ||\n";
	cout << "==================================================\n";
	cout << ">> Input Class Number : ";
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
		cout << "[System] Invalid choice. Defaulting to Unknown.\n";
		break;
	}

	system("cls"); // 화면 지우기

	// Hardcore 모드 선택
	cout << ">> Enable Hardcore Mode? (1) Yes / (0) No : ";
	cin >> hardcoreInput;

	if (hardcoreInput == '1') {
		isHardcore = true;
		cout << "[System] Hardcore mode enabled. Death is permanent.\n";
	}
	else if (hardcoreInput == '0') {
		isHardcore = false;
		cout << "[System] Standard mode enabled.\n";
	}
	else {
		isHardcore = false;
		cout << "[System] Invalid input. Defaulting to Standard mode.\n";
	}

	cout << "\n";
	system("pause"); // 안내 메시지 확인을 위한 대기
	system("cls");   // 화면 지우기

	// Player 객체 생성 - 입력받은 값들로 초기화, 스탯은 내부에서 자동 계산됨
	Player player(userName, charactorClass, hardcoreInput);
	
	// 2. 캐릭터 상태창 UI
	string hcText = isHardcore ? "ON" : "OFF";

	cout << "==================================================\n";
	cout << "||" << left << setw(46) << "               CHARACTER STATUS" << "||\n";
	cout << "==================================================\n";
	cout << "|| " << left << setw(13) << "NAME" << " || " << left << setw(27) << player.GetName() << " ||\n";
	cout << "|| " << left << setw(13) << "CLASS" << " || " << left << setw(27) << player.GetCharacterClass() << " ||\n";
	cout << "|| " << left << setw(13) << "LEVEL" << " || " << left << setw(27) << player.GetLevel() << " ||\n";
	cout << "==================================================\n";
	cout << "|| " << left << setw(13) << "HP" << " || " << left << setw(27) << player.GetMaxHp() << " ||\n";
	cout << "|| " << left << setw(13) << "MP" << " || " << left << setw(27) << player.GetMaxMp() << " ||\n";
	cout << "|| " << left << setw(13) << "DAMAGE" << " || " << left << setw(27) << player.GetAttackDamage() << " ||\n";
	cout << "|| " << left << setw(13) << "ATTACK SPD" << " || " << left << setw(27) << player.GetAttackSpeed() << " ||\n";
	cout << "|| " << left << setw(13) << "MOVING SPD" << " || " << left << setw(27) << player.GetMovingSpeed() << " ||\n";
	cout << "--------------------------------------------------\n";
	cout << "|| " << left << setw(13) << "STRENGTH" << " || " << left << setw(27) << player.GetStrength() << " ||\n";
	cout << "|| " << left << setw(13) << "DEXTERITY" << " || " << left << setw(27) << player.GetDexterity() << " ||\n";
	cout << "|| " << left << setw(13) << "VITALITY" << " || " << left << setw(27) << player.GetVitality() << " ||\n";
	cout << "|| " << left << setw(13) << "ENERGY" << " || " << left << setw(27) << player.GetEnergy() << " ||\n";
	cout << "==================================================\n";
	cout << "|| " << left << setw(13) << "HARDCORE" << " || " << left << setw(27) << player.GetIsHardcore() << " ||\n";
	cout << "|| " << left << setw(13) << "FIRE RES" << " || " << left << setw(27) << player.GetFireResist() << " ||\n";
	cout << "|| " << left << setw(13) << "LIGHT RES" << " || " << left << setw(27) << player.GetLightningResist() << " ||\n";
	cout << "|| " << left << setw(13) << "COLD RES" << " || " << left << setw(27) << player.GetColdResist() << " ||\n";
	cout << "|| " << left << setw(13) << "POISON RES" << " || " << left << setw(27) << player.GetPoisonResist() << " ||\n";
	cout << "==================================================\n\n";

	system("pause"); // 상태창 확인 대기
	system("cls");   // 화면 지우기

	// 3. 전투 시스템 UI
	int pendingExp = 0;
	{
		// 생성자 호출
		Monster goblin(50, 0, 15, 0, 50);
		
		cout << "==================================================\n";
		cout << "||" << left << setw(46) << "           A WILD GOBLIN APPEARED!" << "||\n";
		cout << "==================================================\n\n";

		system("pause"); // 조우 메시지 확인용 1회 대기
		system("cls");

		// 전투기능 클래스 구현 이후 전투 생성과 실행
		Battle battle(player, goblin);
		battle.Run();
		
		pendingExp = goblin.GetExpReward(); // 몬스터 객체 소멸 전 경험치 보상 저장
	}
		
	// 전투 종료 후 결과 판정
	if (!player.isAlive()) {
		cout << "==================================================\n";
		cout << "||" << left << setw(46) << "                 YOU DIED..." << "||\n";
		cout << "==================================================\n";
	}
	else {
		cout << "==================================================\n";
		cout << "||" << left << setw(46) << "          YOU DEFEATED THE GOBLIN!" << "||\n";
		cout << "==================================================\n";

		srand((unsigned int)time(NULL));

		cout << "\n[System] Looting Items...\n";

		int* invPtr = player.GetInventory();			// invPtr -> gameInventory 시작주소 [0]

		// 포인터로 인벤토리에 랜덤 숫자 저장
		for (int i = 1; i <= 3; i++) {
			*invPtr = rand() % 4 + 1;			// 역참조로 현재 칸에 아이템 코드를 저장하고자 함
			invPtr++;
		}

		// 포인터 순회로 인벤토리 출력(5칸)
		invPtr = player.GetInventory();		// invPtr 처음으로 리셋
		int slot = 0;

		cout << "==================================================\n";
		cout << "||" << left << setw(46) << "          INVENTORY" << "||\n";
		cout << "==================================================\n";
		while (invPtr < player.GetInventory() + 5) {
			string itemName;
			if (*invPtr == 1) itemName = "Gold";
			else if (*invPtr == 2) itemName = "Healing Potion";
			else if (*invPtr == 3) itemName = "Weapon";
			else if (*invPtr == 4) itemName = "Armor";
			else itemName = "None";
			cout << " > Slot " << slot << " < [" << itemName<<"]\n";
			invPtr++;
			slot++;
		}

		// 레벨업
		player.GainExp(pendingExp);
		player.PrintLevel();
	}

	cout << "\n";
	system("pause"); // 프로그램 종료 전 결과창 유지
	return 0;
}