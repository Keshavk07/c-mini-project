
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;


typedef struct tailpos
{
       int x;
       int y;
       struct tailpos *next;
       struct tailpos *prev;
} tail;


int d = 4;

class snake
{
public:
       int wallsX, wallsY;
       int walleX, walleY;
       int score;

       int foodx, foody;

       HANDLE console_handle;
       COORD cur_cord;



       tail *start, *current, *newtail;
       snake();
       void insert(int x, int y);
       void draw();
       void drawWall();
       void move();
       bool collision();
       void drawfood(int x = 0);
       void drawinit();
       void labelDead();
       void menu();
       void help();
};


void loop(snake &ob);


snake::snake()
{

       score = 0;

       start = NULL;
       current = NULL;
       newtail = NULL;
       console_handle = GetStdHandle(STD_OUTPUT_HANDLE);

       foodx = 12;
       foody = 14;

       wallsX = 2;
       wallsY = 2;
       walleX = 70;
       walleY = 20;

       cur_cord.X = 152;
       cur_cord.Y = 500;
       SetConsoleScreenBufferSize(console_handle, cur_cord);
}

void snake ::insert(int x, int y)
{

       if (start == NULL)
       {
              newtail = new tail;
              newtail->x = x;
              newtail->y = y;
              newtail->next = NULL;
              newtail->prev = NULL;
              start = newtail;
              current = newtail;
       }
       else
       {
              newtail = new tail;
              newtail->x = x;
              newtail->y = y;
              newtail->next = NULL;
              newtail->prev = current;
              current->next = newtail;
              current = newtail;
       }
}



void snake::move()
{
       tail *tmp, *cur;

       tmp = current;

       while (tmp->prev != NULL)
       {
              tmp->x = tmp->prev->x;
              tmp->y = tmp->prev->y;
              tmp = tmp->prev;
       }

       if (d == 1)
              start->y--;

       if (d == 2)
              start->y++;

       if (d == 3)
              start->x--;

       if (d == 4)
              start->x++;
}


void snake::draw()
{

       cur_cord.X = 2;
       cur_cord.Y = 0;

       SetConsoleCursorPosition(console_handle, cur_cord);
       cout << "SCORE : " << score;

       tail *tmp, *last;
       tmp = start;
       last = current;

       while (tmp != NULL)
       {
              cur_cord.X = tmp->x;
              cur_cord.Y = tmp->y;
              SetConsoleCursorPosition(console_handle, cur_cord);

              cout << (char)219;
              tmp = tmp->next;
       }

       cur_cord.X = last->x;
       cur_cord.Y = last->y;
       SetConsoleCursorPosition(console_handle, cur_cord);
       cout << ' ';

       cur_cord.X = foodx;
       cur_cord.Y = foody;
       SetConsoleCursorPosition(console_handle, cur_cord);
       cout << (char)15;
}

void snake::drawWall()
{

       cur_cord.X = wallsX;
       for (int y = wallsY; y <= walleY; y++)
       {
              cur_cord.Y = y;
              SetConsoleCursorPosition(console_handle, cur_cord);
              cout << '#';
       }

       cur_cord.Y = wallsY;
       for (int x = wallsX; x <= walleX; x++)
       {
              cur_cord.X = x;
              SetConsoleCursorPosition(console_handle, cur_cord);
              cout << '#';
       }

       cur_cord.X = walleX;
       for (int y = wallsY; y <= walleY; y++)
       {
              cur_cord.Y = y;
              SetConsoleCursorPosition(console_handle, cur_cord);
              cout << '#';
       }


       cur_cord.Y = walleY;
       for (int x = wallsX; x <= walleX; x++)
       {
              cur_cord.X = x;
              SetConsoleCursorPosition(console_handle, cur_cord);
              cout << '#';
       }
}

void snake::drawfood(int x)
{
       tail *tmp;
       tmp = start;
       if (x == 1)
       {
              foodx = rand() % 2 + 39;
              foody = rand() % 2 + 16;

              while (tmp->next != NULL)
              {
                     if (foodx == tmp->x && foody == tmp->y)
                     {
                            drawfood(1);
                            cout << "drawn";
                     }

                     tmp = tmp->next;
              }
       }
}

void snake::drawinit()
{
       drawWall();
}


bool snake::collision()
{
       tail *tmp;
       tmp = start->next;

       while (tmp->next != NULL)
       {
              if (start->x == tmp->x && start->y == tmp->y)
                     return true;

              tmp = tmp->next;
       }

       if (start->x == foodx && start->y == foody)
       {
              insert(foodx, foody);
              drawfood(1);
              score++;
       }


       for (int x = wallsX; x <= walleX; x++)
       {
              if (start->x == x && start->y == wallsY)
              {
                     return true;
              }
       }

       for (int y = wallsY; y <= walleY; y++)
       {
              if (start->x == wallsX && start->y == y)
              {
                     return true;
              }
       }

       for (int y = wallsY; y <= walleY; y++)
       {
              if (start->x == walleX && start->y == y)
              {
                     return true;
              }
       }

       for (int x = wallsX; x <= walleX; x++)
       {
              if (start->x == x && start->y == walleY)
              {
                     return true;
              }
       }

       return false;
}

void snake::labelDead()
{

       cur_cord.X = (walleX / 2);
       cur_cord.Y = (walleY / 2);

       SetConsoleCursorPosition(console_handle, cur_cord);

       cout << "YOU ARE DEAD\n";

       cur_cord.Y = (walleY / 2) + 1;
       SetConsoleCursorPosition(console_handle, cur_cord);
       cout << "YOUR HIGH SCORE IS " << score;
}



void snake::menu()
{
       char word;
       ifstream iFile("menu.txt");
       word = iFile.get();
       while (iFile)
       {

              cout << word;
              word = iFile.get();
       }
       iFile.close();

}

void snake::help()
{
       char word;
       ifstream iFile("help.txt");
       word = iFile.get();
       while (iFile)
       {

              cout << word;
              word = iFile.get();
       }
       iFile.close();

       getch();
}


int main()
{

       snake obc;
       obc.menu();
       switch (getch())
       {
       case 'z':
              system("CLS");
              loop(obc);
              break;
       case 'h':
              system("CLS");
              obc.help();
              system("CLS");
              main();
              break;
       case 'q':
              break;
       default:
              system("CLS");
              main();
       }

       return 0;
}


void loop(snake &ob)
{
       ob.insert(10, 6);
       ob.insert(10, 7);
       ob.insert(10, 8);
       ob.insert(10, 9);

       ob.drawinit();
       int dir = 1;
       while (1)
       {
              ob.draw();
              Sleep(200);


              if (ob.collision())
              {
                     ob.labelDead();
                     break;
              }

              if (kbhit())
              {
                     switch (getch())
                     {
                     case 'w':
                            d = 1;
                            break;
                     case 's':
                            d = 2;
                            break;
                     case 'a':
                            d = 3;
                            break;
                     case 'd':
                            d = 4;
                            break;
                     case 'm':
                            ob.insert(10, 7);
                            break;
                     }

              }

              ob.move();
       }
       int x;
       cin >> x;
}
