//clock 1.0

#ifndef __MYCLOCK
#define __MYCLOCK

#include "stdio.h"

class MYCLOCK
{
public:
	MYCLOCK()
	{
		iNum=0;
		iIsActive=0;
		iNumShow=0;
		iElapse=100;
		ishow=0;
	}
	~MYCLOCK()
	{
		Destroy();
	}

	void Begin(HWND hw,int elapse,int timetotal)
	{
		if(iIsActive)
			return;//�Ѿ������ˣ�ֱ�ӷ���

		hWnd=hw;
		iElapse=elapse;

		SetTimer(hWnd,1,iElapse,NULL);
		iNum=1000/iElapse;//һ���ӵ�ʱ����Ϣ����
		iNumShow=timetotal;
		iIsActive=1;
	}
	void Destroy()
	{
		if(iIsActive)
		{
			iIsActive=0;
			KillTimer(hWnd,1);
		}
	}

	//��Σ� ����
	void ReStart(int timetotal)
	{
		iNumShow=timetotal;	
		iNum=1000/iElapse;
		ishow=1;
	}

	//////////////////////////// ��ʾ����
	void SetDevice(HDC h)
	{
		hDC=h;
	}

	void Show(int x,int y)
	{
		char temp[20]={0};

		if(!ishow)
			return;

		sprintf(temp,"TIME: %d  ",iNumShow);
		TextOut(hDC,x, y, temp,strlen(temp));
	}

	//��������������
	int DecCount()
	{
		iNum--;
		if(iNum==0)
		{
			//����һ��
			iNum=1000/iElapse;
			iNumShow--;
			if(iNumShow<=0)
			{
				//������
				return 1;
			}
		}
		return 0;
	}

	int Dec()
	{
		iNum--;
		if(iNum<=0)
		{
			//����һ��
			iNum=1000/iElapse;
			iNumShow--;
			if(iNumShow<=0)
			{
				iNumShow=0;
				Destroy();
				return 1;
			}
		}
		return 0;
	}
	
	//
	void SetShow(int i)
	{
		ishow=i;
	}

public:
	HWND hWnd;
	HDC hDC;

	int iNum;
	int iNumShow;
	int iElapse;
	int iIsActive;

	int ishow;
};


#endif