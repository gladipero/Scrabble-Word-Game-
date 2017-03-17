#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void fillplayers()
 {
   int i,j;
   for(i=0;i<2;i++)
    {
      int y;
      if(i==0)
	y=260;
	else
	y=310;
     for(j=0;j<5;j++)
      {
	outtextxy((13+j*26),y,"A");
      }
     }
 }

void boardgraph()
{
   int board[10][10];
   clrscr();
   int gd = DETECT, gm;
   int i;
   initgraph(&gd, &gm, "C:/TC/BGI");
   //Horizontal lines
   line(144,100,498,100);
   line(144,135,498,135);
   line(144,170,498,170);
   line(144,205,498,205);
   line(144,240,498,240);
   line(144,275,498,275);
   line(144,310,498,310);
   line(144,345,498,345);
   line(144,380,498,380);
   line(144,415,498,415);
   line(144,450,498,450);
   //Vertical lines
   line(144,100,144,450);
   line(180,100,180,450);
   line(216,100,216,450);
   line(252,100,252,450);
   line(288,100,288,450);
   line(324,100,324,450);
   line(360,100,360,450);
   line(396,100,396,450);
   line(432,100,432,450);
   line(464,100,464,450);
   line(498,100,498,450);
   //Letters panel for player1 left side
   //First five letters
   line(0,270,127,270);
   line(0,270,0,250);
   line(25.5,270,25.5,250);
   line(51,270,51,250);
   line(76.5,270,76.5,250);
   line(102,270,102,250);
   line(127,270,127,250);
   //second five letters
   line(0,320,127,320);
   line(0,320,0,300);
   line(25.5,320,25.5,300);
   line(51,320,51,300);
   line(76.5,320,76.5,300);
   line(102,320,102,300);
   line(127,320,127,300);

   //Player 2 right side
   line(510,270,635,270);
   line(510,270,510,250);
   line(535,270,535,250);
   line(560,270,560,250);
   line(585,270,585,250);
   line(610,270,610,250);
   line(635,270,635,250);
   //Remaining five letters
   line(510,320,635,320);
   line(510,320,510,300);
   line(535,320,535,300);
   line(560,320,560,300);
   line(585,320,585,300);
   line(610,320,610,300);
   line(635,320,635,300);
   fillplayers();
   getch();
   closegraph();
  // return 0;

}

int main()
{   clrscr();
    int n;
    cout<<"Scrabble Word Game:\n"<<"Press 1 For New game\n" << "Press 2 to exit\n";
    int switchs;
    cin>>switchs;
    switch(switchs)
    case 1:
    {
     {boardgraph();
     break;}
    case 2:
    return 0;
    }

 }

