#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27
#define ENTER 13

int m, n;

char 	player1[10],
		player2[10],
		board[10][10];

void movecell(int x, int y)
{
	int c, flag=1;
	while(flag)
	{
		c = 0;
		setfillstyle(SOLID_FILL, BLACK);
		switch((c=getch()))
		{
			case KEY_UP:
				//cout<<"Up";
				floodfill(x, y, WHITE);
				y=y-35;
				break;
			case KEY_DOWN:
				//cout<<"Down";
				floodfill(x, y, WHITE);
				y=y+35;
				break;
			case KEY_LEFT:
				//cout<<"Left";
				floodfill(x, y, WHITE);
				x=x-36;
				break;
			case KEY_RIGHT:
				//cout<<"Right";
				floodfill(x, y, WHITE);
				x=x+36;
				break;
			case ENTER:
				setfillstyle(SOLID_FILL, GREEN);
				//cout<<"ENTER";
				flag=0;
				break;
			case ESC:
				flag=0;
				break;
		}
		if(flag)
			setfillstyle(SOLID_FILL, BLUE);
		floodfill(x, y, WHITE);

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
			outtextxy((518 + j*25), y, &ch);
		}

	}
}

void boardgraph()
{
	int i, x=305, y=257;
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TC/BGI");

	setcolor(WHITE);
	//Horizontal lines
	line(143,100,499,100);
	line(143,135,499,135);
	line(143,170,499,170);
	line(143,205,499,205);
	line(143,240,499,240);
	line(143,275,499,275);
	line(143,310,499,310);
	line(143,345,499,345);
	line(143,380,499,380);
	line(143,415,499,415);
	line(143,450,499,450);

	//Vertical lines
	line(144,99,144,451);
	line(180,99,180,451);
	line(216,99,216,451);
	line(252,99,252,451);
	line(288,99,288,451);
	line(324,99,324,451);
	line(360,99,360,451);
	line(396,99,396,451);
	line(432,99,432,451);
	line(464,99,464,451);
	line(498,99,498,451);

	//Player1 left panel
	line(0,270,127,270);
	line(0,270,0,250);
	line(25.5,270,25.5,250);
	line(51,270,51,250);
	line(76.5,270,76.5,250);
	line(102,270,102,250);
	line(127,270,127,250);

	line(0,320,127,320);
	line(0,320,0,300);
	line(25.5,320,25.5,300);
	line(51,320,51,300);
	line(76.5,320,76.5,300);
	line(102,320,102,300);
	line(127,320,127,300);

	//Player 2 right panel
	line(510,270,635,270);
	line(510,270,510,250);
	line(535,270,535,250);
	line(560,270,560,250);
	line(585,270,585,250);
	line(610,270,610,250);
	line(635,270,635,250);

	line(510,320,635,320);
	line(510,320,510,300);
	line(535,320,535,300);
	line(560,320,560,300);
	line(585,320,585,300);
	line(610,320,610,300);
	line(635,320,635,300);

	setfillstyle(SOLID_FILL, BLUE);
	floodfill(x,y,WHITE);
	outtextxy(338,365,"_");

	setcolor(RED);
	settextstyle(4,HORIZ_DIR,9.9);
	outtextxy(60, -15, "SCRABBLE");

	settextstyle(2, HORIZ_DIR, 8);
	setcolor(GREEN);
	fillplayer1();
	setcolor(YELLOW);
	fillplayer2();

	movecell(x, y);
}

int main()
{
	clrscr();
	int n;

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
			boardgraph();
			break;

		case 2:
			return (0);
	}
	getch();
	closegraph();
	return(0);
}

