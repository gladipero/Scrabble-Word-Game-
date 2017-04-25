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
		board[15][15];

void movecell(int x, int y)
{
	int c, flag=1,counter1=0,counter2=0;
	while(flag)
	{
		c = 0;
		setfillstyle(SOLID_FILL, BLACK);
		switch((c=getch()))
		{
			case KEY_UP:
				//cout<<"Up";
			if(counter1<7&&counter1 > -8)
				{floodfill(x, y, WHITE);
				y=y-24;
				counter1++;
			    }
				break;
			case KEY_DOWN:
				//cout<<"Down";
			    if(counter1<8&&counter1 > -7)

				 {floodfill(x, y, WHITE);
				  y=y+24;
				  counter1--;
				}
				  break;
			case KEY_LEFT:

				//cout<<"Left";
				if(counter2<8&&counter2>-7)
				{
				 floodfill(x, y, WHITE);
				 x=x-24;
				 counter2--;
				}
				break;
			case KEY_RIGHT:
				//cout<<"Right";
				if(counter2<7&&counter2>-8)
				{
				 floodfill(x, y, WHITE);
				 x=x+24;
				 counter2++;
				 }
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
			outtextxy((518+5 + j*25), y, &ch);
		}

	}
}

void boardgraph()
{
	int i, x=320, y=289;
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TC/BGI");

	setcolor(WHITE);
	//Horizontal lines
	line(143,99,499+4,99);
	line(143,123,499+4,123);
	line(143,147,499+4,147);
	line(143,171,499+4,171);
	line(143,195,499+4,195);
	line(143,219,499+4,219);
	line(143,243,499+4,243);
	line(143,267,499+4,267);
	line(143,291,499+4,291);
	line(143,315,499+4,315);
	line(143,339,499+4,339);
	line(143,363,503,363);
	line(143,387,503,387);
	line(143,411,503,411);
	line(143,435,503,435);
	line(143,459,503,459);



	//Vertical lines
	line(143,99,143,459);
	line(167,99,167,459);
	line(191,99,191,459);
	line(215,99,215,459);
	line(239,99,239,459);
	line(263,99,263,459);
	line(287,99,287,459);
	line(311,99,311,459);
	line(335,99,335,459);
	line(359,99,359,459);
	line(383,99,383,459);
	line(407,99,407,459);
	line(431,99,431,459);
	line(455,99,455,459);
	line(479,99,479,459);
	line(503,99,503,459);
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
	line(510+5,270,635+3,270);
	line(510+5,270,510+5,250);
	line(535+5,270,535+5,250);
	line(560+5,270,560+5,250);
	line(585+5,270,585+5,250);
	line(610+5,270,610+5,250);
	line(635+3,270,635+3,250);

	line(510+5,320,635+3,320);
	line(510+5,320,510+5,300);
	line(535+5,320,535+5,300);
	line(560+5,320,560+5,300);
	line(585+5,320,585+5,300);
	line(610+5,320,610+5,300);
	line(635+3,320,635+3,300);

	setfillstyle(SOLID_FILL, BLUE);
	floodfill(x,y,WHITE);
       //	outtextxy(338,365,"_");

	setcolor(RED);
	settextstyle(4,HORIZ_DIR,9.9);
	outtextxy(90, -15, "SCRABBLE");

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

