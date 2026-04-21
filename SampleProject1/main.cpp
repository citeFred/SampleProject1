#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include <iomanip>
	using namespace std;

	int main()
	{
		char userName[50];
		string charactorClass;
		int classChoiceInput;
		char hardcoreInput;

		// 스탯 시스템
		int strength = 50;
		int dexterity = 50;
		int vitality = 50;
		int energy = 50;

		int level = 1;
		int hp = vitality * 2;
		int mp = energy * 1.5;
		float attackDamage = strength * 0.2f;
		float attackSpeed = dexterity / 10.0f;
		double movingSpeed = dexterity / 30.0;
		int fireResist = 0;
		int lightningResist = 0;
		int coldResist = 0;
		int poisonResist = 0;

		bool isHardcore = true;

		// "&" 주소 연산자
		cout << "hp변수의 값:  : " << hp << "\n";
		cout << "hp변수의 주소값: " << &hp << "\n"; // 변수의 주소값 출력 & 앰퍼샌드 연산자 사용
		system("pause"); // 변수 값과 주소값 확인을 위한 대기

		// "*" 역참조 연산자
		int* ptr = &hp;
		cout << "ptr == &hp: " << ptr << "\n"; 
		cout << "*ptr 값 : " << *ptr << "\n"; // 포인터를 역참조하여 hp값 읽기

		*ptr = 200; // 포인터를 역참조하여 hp값 쓰기및수정
		cout << "hp변수의 새로운 값: " << hp << "\n"; // hp값이 변경된 것을 확인

		//int* ptr2 = nullptr;
		//cout << "*ptr2 값 : " << *ptr2 << "\n";

		system("pause"); // 포인터 주소값 확인을 위한 대기

		cout << "sizeof(int) : " << sizeof(int) << "bytes \n";
		cout << "sizeof(int*) : " << sizeof(int*) << "bytes \n";
		cout << "sizeof(double*) : " << sizeof(double*) << "bytes \n";
		cout << "sizeof(char*) : " << sizeof(char*) << "bytes \n";


		system("pause"); // 포인터 주소값 확인을 위한 대기
		
		// 포인터 연산 (+1 = 자료형 메모리 크기만큼 이동)

		cout << "ptr : " << ptr << "\n";
		cout << "ptr+1 : " << ptr + 1  << "\n";
		cout << "ptr+2 : " << ptr + 2  << "\n";


		system("pause"); // 포인터 주소값 확인을 위한 대기


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

		// 2. 캐릭터 상태창 UI
		string hcText = isHardcore ? "ON" : "OFF";

		cout << "==================================================\n";
		cout << "||" << left << setw(46) << "               CHARACTER STATUS" << "||\n";
		cout << "==================================================\n";
		cout << "|| " << left << setw(13) << "NAME" << " || " << left << setw(27) << userName << " ||\n";
		cout << "|| " << left << setw(13) << "CLASS" << " || " << left << setw(27) << charactorClass << " ||\n";
		cout << "|| " << left << setw(13) << "LEVEL" << " || " << left << setw(27) << level << " ||\n";
		cout << "==================================================\n";
		cout << "|| " << left << setw(13) << "HP" << " || " << left << setw(27) << hp << " ||\n";
		cout << "|| " << left << setw(13) << "MP" << " || " << left << setw(27) << mp << " ||\n";
		cout << "|| " << left << setw(13) << "DAMAGE" << " || " << left << setw(27) << attackDamage << " ||\n";
		cout << "|| " << left << setw(13) << "ATTACK SPD" << " || " << left << setw(27) << attackSpeed << " ||\n";
		cout << "|| " << left << setw(13) << "MOVING SPD" << " || " << left << setw(27) << movingSpeed << " ||\n";
		cout << "--------------------------------------------------\n";
		cout << "|| " << left << setw(13) << "STRENGTH" << " || " << left << setw(27) << strength << " ||\n";
		cout << "|| " << left << setw(13) << "DEXTERITY" << " || " << left << setw(27) << dexterity << " ||\n";
		cout << "|| " << left << setw(13) << "VITALITY" << " || " << left << setw(27) << vitality << " ||\n";
		cout << "|| " << left << setw(13) << "ENERGY" << " || " << left << setw(27) << energy << " ||\n";
		cout << "==================================================\n";
		cout << "|| " << left << setw(13) << "HARDCORE" << " || " << left << setw(27) << hcText << " ||\n";
		cout << "|| " << left << setw(13) << "FIRE RES" << " || " << left << setw(27) << fireResist << " ||\n";
		cout << "|| " << left << setw(13) << "LIGHT RES" << " || " << left << setw(27) << lightningResist << " ||\n";
		cout << "|| " << left << setw(13) << "COLD RES" << " || " << left << setw(27) << coldResist << " ||\n";
		cout << "|| " << left << setw(13) << "POISON RES" << " || " << left << setw(27) << poisonResist << " ||\n";
		cout << "==================================================\n\n";

		system("pause"); // 상태창 확인 대기
		system("cls");   // 화면 지우기

		// 3. 전투 시스템 UI
		int maxGoblinHp = 30;
		int goblinHp = maxGoblinHp;
		int maxPlayerHp = hp;
		int action;
		string combatMessage = "[System] Battle Started!"; // 전투 메시지 저장용 변수

		cout << "==================================================\n";
		cout << "||" << left << setw(46) << "           A WILD GOBLIN APPEARED!" << "||\n";
		cout << "==================================================\n\n";

		system("pause"); // 조우 메시지 확인용 1회 대기
		system("cls");

		while (goblinHp > 0 && hp > 0) {
			int dGoblinHp = (goblinHp < 0) ? 0 : goblinHp;
			int dPlayerHp = (hp < 0) ? 0 : hp;

			int gBarCnt = (dGoblinHp * 20) / maxGoblinHp;
			int pBarCnt = (dPlayerHp * 20) / maxPlayerHp;

			string gBar = string(gBarCnt, '=') + string(20 - gBarCnt, '-');
			string pBar = string(pBarCnt, '=') + string(20 - pBarCnt, '-');

			// 체력 게이지와 이전 턴의 결과를 함께 출력
			cout << "==================================================\n";
			cout << "|| GOBLIN [" << gBar << "] " << left << setw(12) << dGoblinHp << "||\n";
			cout << "|| PLAYER [" << pBar << "] " << left << setw(12) << dPlayerHp << "||\n";
			cout << "==================================================\n";
			cout << combatMessage << "\n";
			cout << "--------------------------------------------------\n";
			cout << ">> 1. Attack\n>> Select Action : ";
			cin >> action;

			// 행동 처리 및 결과 메시지 갱신
			if (action == 1) {
				goblinHp -= attackDamage;
				combatMessage = "=> You attacked the Goblin! (Dmg: " + to_string((int)attackDamage) + ")";

				if (goblinHp > 0) {
					hp -= 30;
					combatMessage += "\n=> The Goblin attacked you! (Dmg: 30)";
				}
			}
			else {
				cin.clear();
				cin.ignore(100, '\n');
				hp -= 30;
				combatMessage = "=> Invalid action! You stumbled.\n=> The Goblin attacked you! (Dmg: 30)";
			}

			// 대기 없이 즉시 화면을 지우고 루프 처음으로 돌아가 변경된 체력바 출력
			system("cls");
		}
		// 전투 종료 후 결과 판정
		if (hp <= 0) {
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

			for (int i = 1; i <= 3; i++) {
				int lootRoll = rand() % 4;
				string itemName;

				if (lootRoll == 0) itemName = "Gold";
				else if (lootRoll == 1) itemName = "Healing Potion";
				else if (lootRoll == 2) itemName = "Weapon";
				else itemName = "Armor";

				cout << " > " << i << ". Get [" << itemName << "]\n";
			}
			cout << "--------------------------------------------------\n";
		}

		cout << "\n";
		system("pause"); // 프로그램 종료 전 결과창 유지
		return 0;
	}