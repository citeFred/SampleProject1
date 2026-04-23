#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include <iomanip>
	using namespace std;

	// Call By Value: 복사본 전달 -> 원본은 변경 불가
	void PreviewCritical(float attackDamage) {
		attackDamage *= 2; // Parameter 복사본만 2배, 원본 변수는 그대로?
		cout << "크리티컬 예상 데미지:" << attackDamage << "\n";
	}

	// Call By Reference: 예시) 참조자 절달 -> 실제 크리티컬 데미지 적용
	void ApplyCriticalDamage(int& goblinHp, float attackDamage) {
		int critDamage = attackDamage * 2; // 치명타는 2배 데미지 적용
		goblinHp -= critDamage; // 원본 goblinHp를 직접 감소
	}

	// Call By Address: 주소 전달 -> 원본 직접 수정 가능
	//void LevelUp(int* level) {
		//(*level)++; // 역참조로 level 원본 직접 증가
	//}

	// Call By Reference: 참조자 전달 -> * 없이 원본 직접 수정
	void LevelUpRef(int& level) {
		level++;
	}

	// const 참조자: 복사 비용 절약 + 원본 수정 차단
	void PrintLevel(const int& level) {
		cout << "현재 레벨: " << level << "\n";
		//level++; // 컴파일 오류발생, const라 원본의 수정이 불가함
	}
	
	// Monster 클래스 
	class Monster
	{
	private:
		int hp, maxHp;
		int attackDamage;
		
	public:
		Monster(int initHp, int atk) : hp(initHp), maxHp(initHp), attackDamage(atk)
		{
			cout << "[몬스터 등장!] HP :" << hp << " / ATK: " << attackDamage << "\n";
		}
		~Monster()
		{
			cout << "[몬스터 소멸!]\n"; // 소멸자 확인용 로그
		}
		int GetHp()	const { return hp; }
		int GetMaxHp() const { return maxHp; }
		bool isAlive() const { return hp > 0; }
		void TakeDamage(int damage) // 몬스터가 피해를 받음
		{
			hp -= damage;
			if (hp < 0) hp = 0; // 음수 방지
		}
		int Attack() const { return attackDamage; } // 몬스터가 플레이어를 공격
	};

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
		Player(const string& name, const string& characterClass, bool isHardcore) // 외부입력 값 세팅 초기화
			: name(name), characterClass(characterClass), isHardcore(isHardcore), // 단순 값 세팅 초기화
		strength(50), dexterity(50), vitality(50), energy(50),
		level(1),
		fireResist(0), coldResist(0), lightningResist(0), poisonResist(0)
		{
			maxHp = vitality * 2; // 계산이 필요한 값 세팅 초기화
			hp = maxHp;
			maxMp = (int)energy * 1.5f;
			mp = maxMp;
			attackDamage = strength * 0.2f;
			attackSpeed = dexterity / 10.0f;
			movingSpeed = dexterity / 30.0f;
			for (int i = 0; i < 5; ++i) inventory[i] = 0;
		}
		
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
		void TakeDamage(int damage)
		{
			hp -= damage;
			if (hp <= 0) hp = 0;
		}
		int Attack() const { return (int)attackDamage; }
		int CriticalAttack() const { return (int)(attackDamage * 2); }
		void LevelUp() { level++; }
		void PreviewCritical() const
		{
			float preview = attackDamage * 2;
			cout << "크리티컬 예상 데미지: " << preview << "\n";
		}
		
		void PrintLevel() const
		{
			cout << "현재 레벨: " << level << "\n";
		}
	};

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
		// 생성자 호출
		Monster goblin(30, 10);
		
		int action;
		string combatMessage = "[System] Battle Started!"; // 전투 메시지 저장용 변수

		cout << "==================================================\n";
		cout << "||" << left << setw(46) << "           A WILD GOBLIN APPEARED!" << "||\n";
		cout << "==================================================\n\n";

		system("pause"); // 조우 메시지 확인용 1회 대기
		system("cls");

		while (goblin.isAlive() && player.isAlive()) {
			int dGoblinHp = goblin.GetHp();
			int dPlayerHp = player.GetHp();

			int gBarCnt = (dGoblinHp * 20) / goblin.GetMaxHp();
			int pBarCnt = (dPlayerHp * 20) / player.GetMaxHp();

			string gBar = string(gBarCnt, '=') + string(20 - gBarCnt, '-');
			string pBar = string(pBarCnt, '=') + string(20 - pBarCnt, '-');

			// 체력 게이지와 이전 턴의 결과를 함께 출력
			cout << "==================================================\n";
			cout << "|| GOBLIN [" << gBar << "] " << left << setw(12) << dGoblinHp << "||\n";
			cout << "|| PLAYER [" << pBar << "] " << left << setw(12) << dPlayerHp << "||\n";
			cout << "==================================================\n";
			cout << combatMessage << "\n";
			cout << "--------------------------------------------------\n";
			cout << ">> 1. Attack\n>> 2. Bash Attack\n Select Action : ";
			cin >> action;

			// 행동 처리 및 결과 메시지 갱신
			if (action == 1) {
				goblin.TakeDamage(player.Attack()); // 객체 스스로가 데미지를 처리하고 있음
				combatMessage = "=> You attacked the Goblin! (Dmg: " + to_string(player.Attack()) + ")";

				if (goblin.isAlive()) {
					player.TakeDamage(goblin.Attack());
					combatMessage += "\n=> The Goblin attacked you! (Dmg: 30)";
				}
			}
			else if (action == 2) {
				goblin.TakeDamage(player.CriticalAttack()); // 2배 데미지 받음
				combatMessage = "=> Bash Hit! (Dmg: " + to_string(player.CriticalAttack()) + ")";

				if (goblin.isAlive()) {
					player.TakeDamage(goblin.Attack());
					combatMessage += "\n=> The Goblin attacked you! (Dmg: 30)";
				}
			}
			else {
				cin.clear();
				cin.ignore(100, '\n');
				player.TakeDamage(goblin.Attack());
				combatMessage = "=> Invalid action! You stumbled.\n=> The Goblin attacked you! (Dmg: 30)";
			}

			// 대기 없이 즉시 화면을 지우고 루프 처음으로 돌아가 변경된 체력바 출력
			system("cls");
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
			player.LevelUp();
			player.PrintLevel();
		}

		cout << "\n";
		system("pause"); // 프로그램 종료 전 결과창 유지
		return 0;
	}