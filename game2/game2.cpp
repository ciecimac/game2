// game2.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int nPower; //��������
	int nLifeValue; //��������ֵ
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
		//���������������˶����Ĵ���
		nLifeValue -= nPower;
	}
	void Attack(CCreature * pobj)
	{
		//���������ֹ��������Ĵ���
		pobj->Hurted(nPower);
		pobj->FightBack(this);
	}
	// void Hurted( int nPower);
	void FightBack(CCreature * pobj)
	{
		//�����������ַ��������Ĵ���
		pobj->Hurted(nPower / 2);
	}

};
class CDragon :public CCreature
{
public:
	//�����е����Ժͷ���
};
class CWolf :public CCreature
{
public:
	//�����е����Ժͷ���

};
class CGhost :public CCreature
{
public:
	//�������е����Ժͷ���

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

