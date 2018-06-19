// game2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class CWolf;
class CGhost;
class CCreature;
class CCreature
{
protected:
	int nPower; //代表攻击力
	int nLifeValue; //代表生命值
public:
	void display()
	{
		cout << "nPower=" << nPower << "  nLifeValue=" << nLifeValue << endl;
	}
	void setvalue(int p, int l)
	{
		nPower = p;
		nLifeValue = l;
	}
	void Hurted(int nPower)
	{
		//．．．．表现受伤动作的代码
		nLifeValue -= nPower;
	}
	void Attack(CCreature * pobj)
	{
		//．．．表现攻击动作的代码
		pobj->Hurted(nPower);
		pobj->FightBack(this);
	}
	// void Hurted( int nPower);
	void FightBack(CCreature * pobj)
	{
		//．．．．表现反击动作的代码
		pobj->Hurted(nPower / 2);
	}

};
class CDragon :public CCreature
{
public:
	//龙特有的属性和方法
};
class CWolf :public CCreature
{
public:
	//狼特有的属性和方法

};
class CGhost :public CCreature
{
public:
	//幽灵特有的属性和方法

};
int main()
{
	CDragon oDragon;
	oDragon.setvalue(20, 100);
	CWolf oWolf;
	oWolf.setvalue(4, 100);
	CGhost oGhost;
	oGhost.setvalue(10, 100);
	oDragon.display();
	oWolf.display();
	oGhost.display();
	oDragon.Attack(&oWolf);
	oDragon.Attack(&oWolf);
	oGhost.Attack(&oDragon);
	oDragon.display();
	oWolf.display();
	oGhost.display();
	return 0;
}

