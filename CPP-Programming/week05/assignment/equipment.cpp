#include <iostream>
#include <iomanip>
using namespace std;
const int WARRIOR_NUM = 5;
const int WEAPON_NUM = 3;

class Headquarter;
class Warrior
{
private:
	Headquarter * pHeadquarter;
	int kindNo;										
	int no;
	int weaponNum;									
	int weaponNo[2];								
	double morale;									
	int loyalty;									
public:
	static char * product_s[WARRIOR_NUM];
	static char * weapon_list[WEAPON_NUM];
	static int initialLifeValue[WARRIOR_NUM];
	Warrior(Headquarter * p, int no_, int kindNo_);
	void PrintResult(int nTime);
	void PrintInfo(void);
};

class Headquarter
{
private:
	int totalLifeValue;
	bool stopped;
	int totalWarriorNum;
	int Color_C;
	int curMakingSeqIdx;							
	int warriorNum[WARRIOR_NUM]; 
	Warrior * pWarriors[1000];
public:
	friend class Warrior;
	static int makingSeq[2][WARRIOR_NUM];			
	void Init(int color_, int lifevalue_);
	~Headquarter();
	int Produce(int nTime);
	char * GetColor();
	static char * color[2];
};

Warrior::Warrior(Headquarter * p, int no_, int kindNo_)
{
	no = no_;
	kindNo = kindNo_;
	pHeadquarter = p;

	if (kindNo != 3 && kindNo != 4)
	{
		if (kindNo == 1)
			weaponNum = 2;
		else
			weaponNum = 1;
	}
	else
		weaponNum = 0;
	for (int i = 0; i < weaponNum; i++)
		weaponNo[i] = (no + i) % 3;

	morale = (kindNo == 0) ? ((double)p->totalLifeValue / initialLifeValue[0]) : 0.00;
	loyalty = (kindNo == 3) ? (p->totalLifeValue) : 0;
}

void Warrior::PrintResult(int nTime)
{
	cout << setfill('0') << setw(3) << nTime << " ";
	cout << pHeadquarter->GetColor() << " " << product_s[kindNo] << " " << no;
	cout << " born with strength " << initialLifeValue[kindNo] << ",";
	cout << pHeadquarter->warriorNum[kindNo] << " " << product_s[kindNo];
	cout << " in " << pHeadquarter->GetColor() << " headquarter" << endl;
}

void Warrior::PrintInfo(void)
{
	if (kindNo == 0)
		cout << "It has a " << weapon_list[weaponNo[0]] << ",and it's morale is " << fixed << setprecision(2) << morale << endl;
	else if (kindNo == 1)
		cout << "It has a " << weapon_list[weaponNo[0]] << " and a " << weapon_list[weaponNo[1]] << endl;
	else if (kindNo == 2)
		cout << "It has a " << weapon_list[weaponNo[0]] << endl;
	else if (kindNo == 3)
		cout << "It's loyalty is " << loyalty << endl;
}

void Headquarter::Init(int color_, int lifevalue_)
{
	Color_C = color_;
	totalLifeValue = lifevalue_;
	totalWarriorNum = 0;
	stopped = false;
	curMakingSeqIdx = 0;
	for (int i = 0; i < WARRIOR_NUM; i++)
		warriorNum[i] = 0;
}

Headquarter::~Headquarter()
{
	for (int i = 0; i < totalWarriorNum; i++)
		delete pWarriors[i];
}

int Headquarter::Produce(int nTime)
{
	if (stopped)
		return 0;

	int searchingTimes = 0;
	while (Warrior::initialLifeValue[makingSeq[Color_C][curMakingSeqIdx]] > totalLifeValue && searchingTimes < WARRIOR_NUM)
	{
		curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
		searchingTimes++;
	}

	int kindNo = makingSeq[Color_C][curMakingSeqIdx];

	if (Warrior::initialLifeValue[kindNo] > totalLifeValue)
	{
		stopped = true;
		cout << setfill('0') << setw(3) << nTime << " ";
		cout << this->GetColor() << " headquarter stops making warriors" << endl;

		return 0;
	}
	//制作士兵：
	totalLifeValue -= Warrior::initialLifeValue[kindNo];
	curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
	pWarriors[totalWarriorNum] = new Warrior(this, totalWarriorNum + 1, kindNo);
	warriorNum[kindNo]++;
	pWarriors[totalWarriorNum]->PrintResult(nTime);
	pWarriors[totalWarriorNum]->PrintInfo();
	totalWarriorNum++;

	return 1;
}

char * Headquarter::GetColor(void)
{
	return color[Color_C];
}

char * Warrior::product_s[] = { (char *)"dragon", (char *)"ninja", (char *)"iceman", (char *)"lion", (char *)"wolf" };
char * Warrior::weapon_list[WEAPON_NUM] = { (char *)"sword", (char *)"bomb", (char *)"arrow" };
int Warrior::initialLifeValue[WARRIOR_NUM];
int Headquarter::makingSeq[2][WARRIOR_NUM] = { { 2, 3, 4, 1, 0 },{ 3, 0, 1, 2, 4 } }; 
char * Headquarter::color[] = { (char *)"red", (char *)"blue" };

int main()
{
	int K;
	int M;
	int casecount = 1;
	Headquarter RedHead, BlueHead;

	cin >> K;

	while (K--)
	{
		cout << "Case:" << casecount << endl;
		casecount++;

		cin >> M;
		for (int i = 0; i < WARRIOR_NUM; i++)
			cin >> Warrior::initialLifeValue[i];

		RedHead.Init(0, M);
		BlueHead.Init(1, M);
		int nTime = 0;

		while (true)
		{
			int red = RedHead.Produce(nTime);
			int blue = BlueHead.Produce(nTime);
			if (red == 0 && blue == 0)
				break;
			nTime++;
		}
	}

	return 0;
}