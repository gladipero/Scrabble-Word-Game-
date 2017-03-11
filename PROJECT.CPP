#include<iostream.h>
#include<conio.h>
#include<graphics.h>
int main()
{
    cout<<"asd";
    int board[10][10]; //Board 2D array
    int gd = DETECT, gm;

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
   line(-500,300,127,300);

   getch();
   closegraph();
   return 0;

}
