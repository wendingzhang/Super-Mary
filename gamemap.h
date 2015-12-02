#ifndef __GAMEMAP
#define __GAMEMAP

#include "bitmaptool.h"

struct MapObject
{
	int x;
	int y;
	int w;
	int h;
	int id;
	int iframe;
	int show;	//�Ƿ���ʾ
};

struct ROLE
{
	int x;
	int y;
	int w;
	int h;
	int id;
	int iframe;
	int xleft;
	int xright;
	int movex;

	int show;	//�Ƿ���ʾ
};

class GAMEMAP
{
public:
	int LoadMap();
	
	void Init();
	void InitMatch();
	//���,��������ͼ
	void Show(MYBITMAPOBJ & bmobj);
	//���,������������ͼ
	void ShowBkObj(MYANIOBJ & bmobj);
	//���,������������ͼ
	void ShowAniObj(MYANIOBJ & bmobj);

	void ShowInfo(HDC h);
	void ShowOther(HDC h);

	//���̴���
	int KeyProc(int iKey);
	void KeyUpProc(int iKey);

	void MoveView();
	void SetViewState(int i);
	void SetGameState(int i);
	//hittest
	int RoleCanMove(int xoff, int yoff);
	int CheckRole();
	int CheckAni(int itimeclip);//��Σ�ʱ��Ƭ
	void ClearEnemy(int i);
	void ClearCoin(int i);
	//�߼����
	int IsWin();
	void Fail();
	void Fail_Wait();
	
	GAMEMAP();
	~GAMEMAP();
	
	//data
	int iMatch;
	int iLife;
	int iGameState;
	int iMoney;

	struct MapObject MapArray[MAX_MAP_OBJECT];
	int iMapObjNum;

	struct MapObject MapBkArray[MAX_MAP_OBJECT];
	int iMapBkObjNum;

	struct ROLE MapEnemyArray[MAX_MAP_OBJECT];
	int iMapEnemyNum;

	struct MapObject MapCoinArray[MAX_MAP_OBJECT];
	int iCoinNum;

	//view
	int viewx;
	int viewy;
	int iViewState;

	//frame control
	int ienemyframe;

	int ibkobjframe;

	int iCoinFrame;

	//FIRE
	struct ROLE FireArray[MAX_MAP_OBJECT];
	int iFireNum;
	int iTimeFire;//�����ӵ���ʱ����
	int iBeginFire;
	int ifireframe;

	//bomb
	struct MapObject BombArray[MAX_MAP_OBJECT];
	int iBombNum;

};

#endif