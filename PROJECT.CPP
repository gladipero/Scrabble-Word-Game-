#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <fstream.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define SPACE 32
#define ENTER 13

int team=1, tempctr1=0, tempctr2=0;

struct temp
{
	char alpha;
	int x;
	int y;
}
temp1[10], temp2[10];

char 	player1[10],
		player2[10],
		alpha,
		board[15][15];

int indictionary(char *str)
{
	int flag=0;
	ofstream f;
	ifstream g;
	f.open("temp.txt", ios::trunc);
	f<<str;
	f.close();
	getch();
	g.open("temp.txt");
	g>>flag;
	g.close();
	return(flag);
}

int verifystr(int i, int j)
{
	int k=0;
	char str[15]="";
	char c;
	cout<<"Direction: ";
	switch((c=getch()))
	{

		case 'v':
			while( board[i-1][j] && i>0)
				i--;

			while(board[i][j] && i<15)
			{

				str[k]=board[i][j];
				k++;
				i++;
			}
			break;

		case 'h':

			while( board[i][j-1] && j>0)
				j--;

			while(board[i][j] && j<15)
			{
				str[k]=board[i][j];
				k++;
				j++;
			}
			break;

		default:
			break;

	}

	return(indictionary(str));

}

int verifyalpha()
{
	int i;

	if(team==1)
	{
		for(i=0; i<10; i++)
			if(int(player1[i])+32 == int(alpha))
			{
				player1[i]=NULL;
				temp1[tempctr1++].alpha=alpha;
				return 1;
			}
	}

	else
	{
		for(i=0; i<10; i++)
			if(int(player2[i])+32 == int(alpha))
			{
				player2[i]=NULL;
				temp2[tempctr2++].alpha=alpha;
				return 1;
			}
	}
	return 0;
}

void movecell(int x, int y)
{
	int c, flag=1, ctr1=7, ctr2=7;
	while(flag==1)
	{
		c = 0;
		setfillstyle(SOLID_FILL, BLACK);

		switch((c=getch()))
		{

			case UP:
				//cout<<"Up";
				if(ctr1 < 16 && ctr1 > 0)
				{
					floodfill(x, y, WHITE);
					alpha=board[ctr1][ctr2];
					outtextxy(x-3, y-30, &alpha);
					y=y-24;
					ctr1--;
				}
				break;

			case DOWN:
				//cout<<"Down";
				if(ctr1 < 14 && ctr1 > -1)
				{
					floodfill(x, y, WHITE);
					alpha=board[ctr1][ctr2];
					outtextxy(x-3, y-30, &alpha);
					y=y+24;
					ctr1++;
				}
				break;

			case LEFT:
				//cout<<"Left";
				if(ctr2 < 15 && ctr2 > 0)
				{
					floodfill(x, y, WHITE);
					alpha=board[ctr1][ctr2];
					outtextxy(x-3, y-30, &alpha);
					x=x-24;
					ctr2--;
				}
				break;

			case RIGHT:
				//cout<<"Right";
				if(ctr2 < 14 && ctr2 > -1)
				{
					floodfill(x, y, WHITE);
					alpha=board[ctr1][ctr2];
					outtextxy(x-3, y-30, &alpha);
					x=x+24;
					ctr2++;
				}
				break;

			case SPACE:
				//cout<<"SPACE";
				if(board[ctr1][ctr2])
				{
					cout<<board[ctr1][ctr2];
					flag=1;
					break;
				}
				setfillstyle(SOLID_FILL, RED);
				flag=2;
				break;

			case ENTER:
				//cout<<"ENTER";
				if(verifystr(ctr1, ctr2))
				{
					cout<<"Word exists";
					team= (team==1) ? 2:1;
				}
				else
					cout<<"No word";
				break;

			case ESC:
				//cout<<"ESCAPE";
				flag=0;
				break;
		}

		if(flag==1)
			setfillstyle(INTERLEAVE_FILL, RED);

		floodfill(x, y, WHITE);


		if(flag==2)
		{
			alpha=getch();
			settextstyle(6, HORIZ_DIR, 3);
			outtextxy(x-3, y-30, &alpha);
			flag=1;
			if(verifyalpha())
				board[ctr1][ctr2]=alpha;
			else
				cout<<"N/A in team"<<team;
		}
	}
}

void fillplayer1()
{
	int i, j, k;
	srand(time(NULL));
	char ch;
	int y;
	for(i=0, k=0; i<2; i++)
	{
		if(i==0)
			y=245;
		else
			y=295;

		for(j=0; j<5; j++, k++)
		{
			if(player1[k]==NULL)
			{
				ch=65+random(26);
				player1[k]=ch;
			}
			ch=player1[k];
			outtextxy((9 + j*25), y, &ch);
		}
	}
}

void fillplayer2()
{
	int i,j,k;
	char ch;
	k=0;
	for(i=0, k=0; i<2; i++)
	{
		int y;
		if(i==0)
			y=245;
		else
			y=295;

		for(j=0; j<5; j++, k++)
		{
			if(player2[k]==NULL)
			{
				ch=65+random(26);
				player2[k]=ch;
			}
			ch=player2[k];
			outtextxy((523 + j*25), y, &ch);
		}
	}
}

void boardgraph()
{
	int i, x=320, y=289, x1, y1, x2, y2;
	clrscr();

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TC/BGI");
	setcolor(WHITE);

	//Horizontal lines
	for(i=0, x1=143, x2=503, y1=99, y2=99;
		i<16;
		i++, y1+=24, y2+=24)

		line(x1, y1, x2, y2);

  /*line(143, 99 , 503, 99);
	line(143, 123, 503, 123);
	line(143, 147, 503, 147);
	line(143, 171, 503, 171);
	line(143, 195, 503, 195);
	line(143, 219, 503, 219);
	line(143, 243, 503, 243);
	line(143, 267, 503, 267);
	line(143, 291, 503, 291);
	line(143, 315, 503, 315);
	line(143, 339, 503, 339);
	line(143, 363, 503, 363);
	line(143, 387, 503, 387);
	line(143, 411, 503, 411);
	line(143, 435, 503, 435);
	line(143, 459, 503, 459);
  */

	//Vertical lines
	for(i=0, x1=143, x2=143, y1=99, y2=459;
		i<16;
		i++, x1+=24, x2+=24)

		line(x1, y1, x2, y2);

  /*line(143, 99, 143, 459);
	line(167, 99, 167, 459);
	line(191, 99, 191, 459);
	line(215, 99, 215, 459);
	line(239, 99, 239, 459);
	line(263, 99, 263, 459);
	line(287, 99, 287, 459);
	line(311, 99, 311, 459);
	line(335, 99, 335, 459);
	line(359, 99, 359, 459);
	line(383, 99, 383, 459);
	line(407, 99, 407, 459);
	line(431, 99, 431, 459);
	line(455, 99, 455, 459);
	line(479, 99, 479, 459);
	line(503, 99, 503, 459);
  */

	//Player1 left panel
	line(0   , 270, 127 , 270);
	line(0   , 270, 0   , 250);
	line(25.5, 270, 25.5, 250);
	line(51  , 270, 51  , 250);
	line(76.5, 270, 76.5, 250);
	line(102 , 270, 102 , 250);
	line(127 , 270, 127 , 250);

	line(0   , 320, 127 , 320);
	line(0   , 320, 0   , 300);
	line(25.5, 320, 25.5, 300);
	line(51  , 320, 51  , 300);
	line(76.5, 320, 76.5, 300);
	line(102 , 320, 102 , 300);
	line(127 , 320, 127 , 300);

	//Player 2 right panel
	line(515, 270, 638, 270);
	line(515, 270, 515, 250);
	line(540, 270, 540, 250);
	line(565, 270, 565, 250);
	line(590, 270, 590, 250);
	line(615, 270, 615, 250);
	line(638, 270, 638, 250);

	line(515, 320, 638, 320);
	line(515, 320, 515, 300);
	line(540, 320, 540, 300);
	line(565, 320, 565, 300);
	line(590, 320, 590, 300);
	line(615, 320, 615, 300);
	line(638, 320, 638, 300);

	setfillstyle(INTERLEAVE_FILL, RED);
	floodfill(x,y,WHITE);

	setcolor(RED);
	settextstyle(4,HORIZ_DIR,9.9);
	outtextxy(63, -15, "SCRABBLE");

	settextstyle(2, HORIZ_DIR, 8);
	setcolor(GREEN);
	fillplayer1();
	setcolor(CYAN);
	fillplayer2();

	setcolor(YELLOW);
	movecell(x, y);
}

int main()
{
	clrscr();
	int i, j, n;

	cout<<"Scrabble Word Game:\n"
		<<"Press 1 For New game\n"
		<<"Press 2 to exit\n";

	int switchs,k;
	cin>>switchs;

	switch(switchs)
	{
		case 1:

			for(k=0; k<10; k++)
			{
				player1[k]=NULL;
				player2[k]=NULL;
			}

			for(i=0; i<15; i++)
				for(j=0; j<15; j++)
					board[i][j]=NULL;
			//board[7][8]='a';

			boardgraph();
			break;

		case 2:
			return (0);
	}
	getch();
	closegraph();
	return(0);
}
