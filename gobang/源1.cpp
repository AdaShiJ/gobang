#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <list>
#include <windows.h>

#define WIDTH 280
#define LLINE 15

using namespace std;

typedef  struct CCHESS
{
	int ttime;
	int nowxx;
	int nowyy;
	int numer;
} CCHESS;

typedef list<CCHESS> LIST;

/*typedef  struct CCHESS_NODE
{
	CCHESS note;
	struct CCHESS_NODE *next;
} CCHESS_ARRAY;*/
LIST CHESSLIST;

int EXTENT = WIDTH / (LLINE - 1), i = WIDTH / 3, j = WIDTH / 30;
int nowx, nowy, time, n;
//int nowx = i + EXTENT*(LLINE - 1) / 2, nowy = i + EXTENT * (LLINE - 1) / 2;
int CHESS_NUMBER = 0;//一共225个棋子
int CHESS[15][15];
int countw, countb;
CCHESS chessman;

void init_chessboard()
{
	int m = i + EXTENT, n = i + EXTENT;//i=100 j=10
	line(i, i, i, i + WIDTH);
	line(i, i + WIDTH, i + WIDTH, i + WIDTH);
	line(i + WIDTH, i + WIDTH, i + WIDTH, i);
	line(i + WIDTH, i, i, i);//内层边框
	line(i - j, i - j, i - j, i + WIDTH + j);
	line(i - j, i + WIDTH + j, i + WIDTH + j, i + WIDTH + j);
	line(i + WIDTH + j, i + WIDTH + j, i + WIDTH + j, i - j);
	line(i + WIDTH + j, i - j, i - j, i - j);//外层边框
	while (m < i + WIDTH)
	{
		line(m, i, m, i + WIDTH);
		m = m + EXTENT;
	}
	while (n < i + WIDTH)
	{
		line(i, n, i + WIDTH, n);
		n = n + EXTENT;
	}
}

void judge(int t)
{
	int chessx, chessy,e,f,jflag=1;
	chessx = (nowx - i) / EXTENT + 1;
	chessy = (nowy - i) / EXTENT + 1;
	/*if ((CHESS[chessx][chessy]%2 == CHESS[chessx][chessy + 1]%2 && CHESS[chessx][chessy + 1] !=0)||( CHESS[chessx][chessy]%2 == CHESS[chessx ][chessy- 1]%2&& CHESS[chessx][chessy - 1] % 2!=0))
	{
		for (e = chessy; e <= chessy + 5,jflag=0; e++)
		{
			if (CHESS[chessx][e]%2 == CHESS[chessx][chessy]%2 && CHESS[chessx][e] != 0) count++;
			else jflag=1;
		}
		for (e = chessy; e >= chessy - 5, jflag = 0; e--)
		{
			if (CHESS[chessx][e]%2 == CHESS[chessx][chessy]%2 && CHESS[chessx][e]!= 0) count++;
			else jflag=1;
		}
		if(count==5)
			if(t%2==0)
				MessageBox(NULL, TEXT(" The white side wins"), TEXT("WGame Over!"), MB_OK);
			else MessageBox(NULL, TEXT(" The black side wins"), TEXT("WGame Over!"), MB_OK);
	}*/
	countw = 1;
	if (CHESS[chessx][chessy] % 2 == 0)
	{
		e = chessy;
		while(jflag)
		{
			if (CHESS[chessx][e+1] % 2 == 0 && CHESS[chessx][e+1] != 0)
			{
				countw++;
				e++;
			}
			else jflag = 0;
		}
		jflag = 1;
		e = chessy;
		while(jflag)
		{
			if (CHESS[chessx][e-1] % 2 == 0 && CHESS[chessx][e-1] != 0)
			{
				countw++;
				e--;
			}
			else jflag = 0;
		}
		if (countw == 5)
			MessageBox(NULL, TEXT(" The white side wins！"), TEXT("Game Over!"), MB_OK);
		else countw = 1;
	}
	jflag = 1;
	countb = 1;
	if (CHESS[chessx][chessy] % 2 != 0)
	{
		e = chessy;
		while (jflag)
		{
			if (CHESS[chessx][e + 1] % 2 != 0 )
			{
				countb++;
				e++;
			}
			else jflag = 0;
		}
		jflag = 1;
		e = chessy;
		while (jflag)
		{
			if (CHESS[chessx][e - 1] % 2 != 0)
			{
				countb++;
				e--;
			}
			else jflag = 0;
		}
		if (countb == 5)
			MessageBox(NULL, TEXT(" The black side wins!"), TEXT("Game Over!"), MB_OK);
		else countb = 1;
	}//纵向判断

	jflag = 1;
	countw = 1;
	if (CHESS[chessx][chessy] % 2 == 0)
	{
		e = chessx;
		while (jflag)
		{
			if (CHESS[e + 1][chessy] % 2 == 0 && CHESS[e + 1][chessy] != 0)
			{
				countw++;
				e++;
			}
			else jflag = 0;
		}
		jflag = 1;
		e = chessx;
		while (jflag)
		{
			if (CHESS[e - 1][chessy] % 2 == 0 && CHESS[e - 1][chessy] != 0)
			{
				countw++;
				e--;
			}
			else jflag = 0;
		}
		if (countw == 5)
			MessageBox(NULL, TEXT(" The white side wins！"), TEXT("Game Over!"), MB_OK);
		else countw = 1;
	}
	jflag = 1;
	countb = 1;
	if (CHESS[chessx][chessy] % 2 != 0)
	{
		e = chessx;
		while (jflag)
		{
			if (CHESS[e + 1][chessy] % 2 != 0)
			{
				countb++;
				e++;
			}
			else jflag = 0;
		}
		jflag = 1;
		e = chessx;
		while (jflag)
		{
			if (CHESS[e - 1][chessy] % 2 != 0)
			{
				countb++;
				e--;
			}
			else jflag = 0;
		}
		if (countb == 5)
			MessageBox(NULL, TEXT(" The black side wins!"), TEXT("Game Over!"), MB_OK);
		else countb = 1;
	}//横向判断

	jflag = 1;
	countw = 1;
	if (CHESS[chessx][chessy] % 2 == 0)
	{
		e = chessx;
		f = chessy;
		while (jflag)
		{
			if (CHESS[e + 1][f+1] % 2 == 0 && CHESS[e + 1][f+1] != 0)
			{
				countw++;
				e++;
				f++;
			}
			else jflag = 0;
		}
		jflag = 1;
		e = chessx;
		f = chessy;
		while (jflag)
		{
			if (CHESS[e - 1][f-1] % 2 == 0 && CHESS[e - 1][f-1] != 0)
			{
				countw++;
				e--;
				f--;
			}
			else jflag = 0;
		}
		if (countw == 5)
			MessageBox(NULL, TEXT(" The white side wins！"), TEXT("Game Over!"), MB_OK);
		else countw = 1;
	}
	jflag = 1;
	countb = 1;
	if (CHESS[chessx][chessy] % 2 != 0)
	{
		e = chessx;
		f = chessy;
		while (jflag)
		{
			if (CHESS[e + 1][f+1] % 2 != 0)
			{
				countb++;
				e++;
				f++;
			}
			else jflag = 0;
		}
		jflag = 1;
		e = chessx;
		f = chessy;
		while (jflag)
		{
			if (CHESS[e - 1][f-1] % 2 != 0)
			{
				countb++;
				e--;
				f--;
			}
			else jflag = 0;
		}
		if (countb == 5)
			MessageBox(NULL, TEXT(" The black side wins!"), TEXT("Game Over!"), MB_OK);
		else countb = 1;
	}//左斜

	jflag = 1;
	countw = 1;
	if (CHESS[chessx][chessy] % 2 == 0)
	{
		e = chessx;
		f = chessy;
		while (jflag)
		{
			if (CHESS[e + 1][f - 1] % 2 == 0 && CHESS[e + 1][f - 1] != 0)
			{
				countw++;
				e++;
				f--;
			}
			else jflag = 0;
		}
		jflag = 1;
		e = chessx;
		f = chessy;
		while (jflag)
		{
			if (CHESS[e - 1][f + 1] % 2 == 0 && CHESS[e - 1][f - 1] != 0)
			{
				countw++;
				e--;
				f++;
			}
			else jflag = 0;
		}
		if (countw == 5)
			MessageBox(NULL, TEXT(" The white side wins！"), TEXT("Game Over!"), MB_OK);
		else countw = 1;
	}
	jflag = 1;
	countb = 1;
	if (CHESS[chessx][chessy] % 2 != 0)
	{
		e = chessx;
		f = chessy;
		while (jflag)
		{
			if (CHESS[e + 1][f - 1] % 2 != 0)
			{
				countb++;
				e++;
				f--;
			}
			else jflag = 0;
		}
		jflag = 1;
		e = chessx;
		f = chessy;
		while (jflag)
		{
			if (CHESS[e - 1][f + 1] % 2 != 0)
			{
				countb++;
				e--;
				f++;
			}
			else jflag = 0;
		}
		if (countb == 5)
			MessageBox(NULL, TEXT(" The black side wins!"), TEXT("Game Over!"), MB_OK);
		else countb = 1;
	}//右斜
}

void move(int nx, int ny, int t)
{
	char in;
	int moveflag = 0, flag = 1;
	int a, b, chessx, chessy;
	setlinecolor(BLACK);
	setfillcolor(BLACK);
	in = getch();
	fillcircle(nowx, nowy, EXTENT / 3);
	setlinecolor(WHITE);
	if (nowx == i&&nowy != i&&nowx != i + WIDTH&&nowy != i + WIDTH)
	{
		line(nowx, nowy - EXTENT / 3, nowx, nowy + EXTENT / 3);
	    line(nowx , nowy, nowx + EXTENT / 3, nowy);
	}
	if (nowx != i&&nowy== i&&nowx != i + WIDTH&&nowy != i + WIDTH)
	{
		line(nowx, nowy , nowx, nowy + EXTENT / 3);
	    line(nowx - EXTENT / 3, nowy, nowx + EXTENT / 3, nowy);
	}
	if (nowx != i&&nowy != i&&nowx != i + WIDTH&&nowy == i + WIDTH)
	{
		line(nowx, nowy - EXTENT / 3, nowx, nowy);
		line(nowx - EXTENT / 3, nowy, nowx + EXTENT / 3, nowy);
	}
	if (nowx != i&&nowy != i&&nowx == i + WIDTH&&nowy != i + WIDTH)
	{
		line(nowx, nowy - EXTENT / 3, nowx, nowy + EXTENT / 3);
		line(nowx - EXTENT / 3, nowy, nowx, nowy);
	}
	if (nowx == i&&nowy == i)
	{
		line(nowx, nowy , nowx, nowy + EXTENT / 3);
		line(nowx, nowy, nowx + EXTENT / 3, nowy);
	}
	if (nowx == i + WIDTH&&nowy == i + WIDTH)
	{
		line(nowx, nowy - EXTENT / 3, nowx, nowy );
		line(nowx - EXTENT / 3, nowy, nowx , nowy);
	}
	if (nowx == i&&nowy == i + WIDTH)
	{
		line(nowx, nowy - EXTENT / 3, nowx, nowy );
		line(nowx, nowy, nowx + EXTENT / 3, nowy);
	}
	if (nowy == i&&nowx == i + WIDTH)
	{
		line(nowx, nowy , nowx, nowy + EXTENT / 3);
		line(nowx - EXTENT / 3, nowy, nowx , nowy);
	}
	if (nowx != i&&nowy != i&&nowx  != i+ WIDTH&&nowy  != i+ WIDTH)
	{
		line(nowx, nowy - EXTENT / 3, nowx, nowy + EXTENT / 3);
		line(nowx - EXTENT / 3, nowy, nowx + EXTENT / 3, nowy);
	}
	/*for (j = CHESSLIST.begin.number(); j != CHESSLIST.end.number(); ++j)
	{
		if (CHESSLIST.back.nowxx == nx&&CHESSLIST.back.nowyy==ny)
		{
			if(CHESSLIST.back.number%2==0)
			setfillcolor(WHITE);
			fillcircle(CHESSLIST.back.nowxx, CHESSLIST.back.nowyy, EXTENT / 3);
		}
	}*/
	for (a = 0; a < 16; a++)
	{
		for (b = 0; b < 16; b++)
		{
			if (CHESS[a][b] != 0 && time != 0 && a == (nowx - i) / EXTENT + 1 && b == (nowy - i) / EXTENT + 1)
				if (CHESS[a][b] % 2 == 0)
				{
					setfillcolor(WHITE);
					fillcircle(nowx, nowy, EXTENT / 3);
				}
				else
				{
					setfillcolor(BLACK);
					fillcircle(nowx, nowy, EXTENT / 3);
				}
		}
	}
	if (time % 2 == 0)setfillcolor(WHITE);
	switch (in)
	{
	case 'w':
		if (nowy <= i)
		{
			//printf("ERROR!");
			moveflag = 1;
			break;
		}
		else
		{
			nowy = nowy - EXTENT;
			fillcircle(nowx, nowy, EXTENT / 3);
			CHESS_NUMBER++;
		}
		break;

	case 's':
		if (nowy >= i + WIDTH)
		{
			//printf("ERROR!");
			moveflag = 1;
			break;
		}
		else
		{
			nowy = nowy + EXTENT;
			fillcircle(nowx, nowy, EXTENT / 3);
			CHESS_NUMBER++;
		}
		break;

	case 'a':
		if (nowx <= i)
		{
			//printf("ERROR!");
			moveflag = 1;
			break;
		}
		else
		{
			nowx = nowx - EXTENT;
			fillcircle(nowx, nowy, EXTENT / 3);
			CHESS_NUMBER++;
		}
		break;

	case 'd':
		if (nowx >= i + WIDTH)
		{
			//printf("ERROR!");
			moveflag = 1;
			break;
		}
		else
		{
			nowx = nowx + EXTENT;
			fillcircle(nowx, nowy, EXTENT / 3);
			CHESS_NUMBER++;
		}
		break;

	case 'o':
		for (a = 0; a < 16; a++)
		{
			for (b = 0; b < 16; b++)
			{
				if (CHESS[a][b] != 0 && time != 0 && a == (nowx - i) / EXTENT + 1 && b == (nowy - i) / EXTENT + 1)
				{
					flag = 0;
				}

			}
		}
		while (flag)
		{
			fillcircle(nowx, nowy, EXTENT / 3);
			/*chessman.nowxx = nowx;
			chessman.nowyy = nowy;
			chessman.ttime = time;
			chessman.numer = n;*/
			chessx = (nowx - i) / EXTENT + 1;
			chessy = (nowy - i) / EXTENT + 1;
			CHESS[chessx][chessy] = time;
			judge(time);
			++time;
			++n;
			nowx = i + EXTENT*(LLINE - 1) / 2;
			nowy = i + EXTENT * (LLINE - 1) / 2;
			//CHESSLIST.push_back(chessman);
			if (time % 2 == 0)
				setfillcolor(WHITE);
			else
				setfillcolor(BLACK);
			setlinecolor(WHITE);
			fillcircle(i + EXTENT*(LLINE - 1) / 2, i + EXTENT * (LLINE - 1) / 2, EXTENT / 3);
			flag = 0;
		}
	}
}


void play()
{
	/*if (time % 2 == 0) setfillcolor(BLACK);
	else setfillcolor(WHITE);*/
	int a, b;
	if (time == 0)
	{
		nowx = i + EXTENT*(LLINE - 1) / 2, nowy = i + EXTENT * (LLINE - 1) / 2;
		time = 1;
		n = 1;
	}
	if (time % 2 == 0)
		setfillcolor(WHITE);
	else
		setfillcolor(BLACK);
	setlinecolor(WHITE);
	fillcircle(i + EXTENT*(LLINE - 1) / 2, i + EXTENT * (LLINE - 1) / 2, EXTENT / 3);
	for (a = 0; a < 16; a++)
	{
		for (b = 0; b < 16; b++)
		{
			CHESS[a][b] = 0;
		}
	}
	while (CHESS_NUMBER <= 225)
	{
		move(nowx, nowy, time);
	}
}

int main()
{
	initgraph(500, 500);   // 创建绘图窗口，大小为 像素
	MessageBox(NULL, TEXT(" w=up, s=down, a=left,d=right,o=ok"), TEXT("Game Start!"), MB_OK);
	init_chessboard();
	play();
	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
}
