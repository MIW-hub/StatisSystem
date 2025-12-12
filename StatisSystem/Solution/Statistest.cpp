#include<iostream>
#include<cmath>

using namespace std;

class StatisSetting
{
public:
	string name;
	int level,hp, mp, power, defense;
	int HpPotion, MpPotion;
	bool PowerBuff;
	bool DefenseBuff;

	StatisSetting() {
		name = "";
		level = 1;
		hp = 0;
		mp = 0;
		power = 0;
		defense = 0;
		HpPotion = 5;
		MpPotion = 5;
		PowerBuff = false;
		DefenseBuff = false;
	}


	string CharName(string p1Name) {
		name = p1Name;
		return name;
	}

};
// 왜 반복이 안되지?!!?!
void setPotion(StatisSetting* player, int* p_HPPotion, int* p_MPPotion) {

	int Recovery = 20;	

	if (p_MPPotion == nullptr)
	{
		if (player->HpPotion > 0)
		{
			player->HpPotion --;
			player->hp += Recovery;
		}
		else 
		{
			cout << "HP 포션이 없습니다. 레벨업 후 사용 가능합니다." << endl;
		}
	}
	else if (p_HPPotion == nullptr) {
		if (player->MpPotion > 0)
		{
			player->MpPotion--;
			player->mp += Recovery;
		}
		else
		{
			cout << "MP 포션이 없습니다. 레벨업 후 사용 가능합니다." << endl;
		}
	}	 
}
void PowerUp(int& num) {
	num = num * 2;
}

void Powerdown(int& num) {
	num = num / 2;
}

void DefenseUp(int& num) {
	num = num * 2;
}

void DefenseDown(int& num) {
	num = num / 2;
}
void levelup(StatisSetting* player) {
	player->level++;
	player->HpPotion++;
	player->MpPotion++;
}

int main()
{	
	StatisSetting p1;
	int arrStatis[4] = {1,2,3,4};	
	string arrName[4] = { "hp","mp","power","defense" };
	int inputNum = 0;
	string InputName;
	int inputChoice = 6;
	int PotionNum = 5;
	int HpRecovery = 20;
	int MpRecovery = 20;
	int& str = p1.power;
	int& def = p1.defense;
	bool& PBuff = p1.PowerBuff;
	bool& DBuff = p1.DefenseBuff;

	cout << "이름이 작성해주세요." << endl;
	cin >> InputName;

	p1.CharName(InputName);
	cout << p1.CharName(InputName) << "님 환영합니다." << endl;

	// 스테이터스 정보 입력
	for(int i = 0; i < 4; i++)
	{
		if (arrStatis[i] == 1) 
		{
			do {
				cout << "HP를 입력해주세요." << endl;
				cin >> inputNum;
				if (inputNum < 50) { cout << "50이상의 숫자를 입력해주세요" << endl;}
			} while (inputNum < 50);
			p1.hp = inputNum;			
		}
		else if(arrStatis[i]== 2)
		{		
			do {
				cout << "MP를 입력해주세요." << endl;
				cin >> inputNum;
				if (inputNum < 50) { cout << "50이상의 숫자를 입력해주세요" << endl; }
			} while (inputNum < 50);
			p1.mp = inputNum;
		}
		else if (arrStatis[i] == 3) 
		{
			do {
				cout << "공격력을 입력해주세요." << endl;
				cin >> inputNum;
				if (inputNum < 0) { cout << "0이상의 숫자를 입력해주세요" << endl; }
			} while (inputNum < 0);
			p1.power = inputNum;
		}
		else if (arrStatis[i] == 4)
		{
			do {
				cout << "방어력을 입력해주세요." << endl;
				cin >> inputNum;
				if (inputNum < 0) { cout << "0이상의 숫자를 입력해주세요" << endl; }
			} while (inputNum < 0);
			p1.defense = inputNum;
		}
		else {
			cout << "스테이터스 정보가 활성화됬습니다." << endl;
			continue;
		}
	}

	cout << p1.name << "TRPG 세계로 오신 것을 환영합니다." << endl;
	
	do {
		cout << "선택지를 정해주세요" << endl;
		cout << "1. HP 포션" << endl << "2. MP 포션" << endl << "3. 공격력버프" << endl << "4. 방어력버프" << endl << "5. 현재상태" << endl << "6. 레벨업" << endl << "7. 종료" << endl;
		cin >> inputChoice;

		switch (inputChoice)
		{
		case 1:
			cout << "HP가 20 회복되었습니다." << endl;			
			setPotion(&p1,&HpRecovery,nullptr);
			break;
		case 2:
			cout << "MP가 20 회복되었습니다." << endl;
			setPotion(&p1, nullptr, &MpRecovery);
			break;
		case 3:			
			if (PBuff == false) {
				cout << "공격력이 2배로 올랐습니다." << endl;
				PBuff = true;
				PowerUp(str);
			}
			else {
				cout << "공격력이 원래대로 돌아왔습니다." << endl;
				PBuff = false;
				Powerdown(str);
			}
			break;
		case 4:		
			if (DBuff == false) {
				cout << "방어력이 2배로 올랐습니다." << endl;
				DBuff = true;
				DefenseUp(def);
			}
			else {
				cout << "방어력이 원래대로 돌아왔습니다." << endl;
				DBuff = false;
				DefenseDown(def);
			}
			break;
		case 5:
			cout << "상태창 !!." << endl;
			cout << "이름 :" << p1.name << endl << "HP :" << p1.hp << endl << "MP :" << p1.mp << endl << "공격력 :" << p1.power << endl << "방어력 :" << p1.defense << endl << "포션개수" << p1.HpPotion << "/" << p1.MpPotion << endl;
			break;
		case 6:
			cout << "레벨이 상승되었습니다. 포션이 1개씩 추가됩니다." << endl;
			levelup(&p1);
			break;
		case 0:
			cout << "게임을 종료합니다." << endl;
			break;
		default:
			cout << "선택지에 없는 선택을 해셨습니다. 다시 선택해주시기를 부탁드립니다." << endl;
			break;
		}
		cout << ""<<endl << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	} while (inputChoice != 0);
	
	





	return 0;
}