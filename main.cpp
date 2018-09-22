#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;
int score=0;
int motiondetector=0;
void random2or4(int[][4]);
void preboard(int[][4]);
void right(int[][4]);
void left(int[][4]);
void down(int[][4]);
void up(int[][4]);
void output(int [][4]);
void loose(int[][4]);

int main()
{
    start:
    srand(time(NULL));
    int x,y;
    int aray[4][4];
    int result;
    //Making every index 0
    for(x=0;x<4;x++)
    {
        for(y=0;y<4;y++)
        {
            aray[x][y]=0;
        }
    }
   preboard(aray);
   output(aray);
   loose(aray);
    return 0;
}

//Function generating 2 or 4 on random index :)
void random2or4(int aray[][4])

{
    int a=rand()%2,x=rand()%4,y=rand()%4;
    if(a==0)
        a=2;
    if(a==1)
        a=4;

    while(aray[x][y]>=0)
    {
        if(aray[x][y]==0)
        {
            aray[x][y]=a;
            break;
        }
        x=rand()%4;
        y=rand()%4;
    }
}
//Generating 2 & 4 on 2 unique indexes
void preboard(int aray[][4])
{
    int x=rand()%4, y=rand()%4,l=0, element=rand()%2;
     while(aray[x][y]>=0)
    {
        if(aray[x][y]==0)
        {
            if(element==0)
            element=2;
            if(element==1)
            element=4;
            aray[x][y]=element;
            l=l+1;
        }
        if(l==2)
            {break;}
        x=rand()%4;
        y=rand()%4;
        element=rand()%2;
    }
}
// Moving Right
void right(int aray[][4])
{
    motiondetector=0;
    int x,y,z;
    for(x=0;x<4;x++)
    {
        for(y=0;y<3;y++)
        {
            if(aray[x][y]!=0)
            {
                for(z=y+1;z<4;z++)
                {
                    if(aray[x][z]!=0 && aray[x][y]!=aray[x][z])
                        break;
                    if(aray[x][y]==aray[x][z])
                    {
                        motiondetector=10;
                        aray[x][z]=aray[x][y]+aray[x][z];
                        score=score+aray[x][z];
                        aray[x][y]=0;
                        y=z+1;
                        break;
                    }
                }
            }
        }
    }

    for(x=0;x<4;x++)
    {
        for(y=3;y>=1;y--)
        {
            if(aray[x][y]==0)
            {
                for(z=y-1;z>=0;z--)
                {
                    if(aray[x][z]!=0)
                    {
                        motiondetector=10;
                       aray[x][y]=aray[x][z];
                       aray[x][z]=0;
                       break;
                    }
                }
            }
        }
    }
    if(motiondetector==10)
    {
        random2or4(aray);
        output(aray);
        loose(aray);
    }
    if(motiondetector==0)
    {
        output(aray);
        loose(aray);
    }
}
// Moving Left
void left(int aray[][4])
{
    motiondetector=0;
    int x,y,z;
for(x=0;x<4;x++)
    {
        for(y=3;y>0;y--)
        {
            if(aray[x][y]!=0)
                for(z=y-1;z>=0;z--)
            {
                if(aray[x][z]!=0 && aray[x][y]!=aray[x][z])
                    break;
                if(aray[x][y]==aray[x][z])
                {
                    motiondetector=10;
                    aray[x][z]=aray[x][y]+aray[x][z];
                    score=score+aray[x][z];
                    aray[x][y]=0;
                    y=z-1;
                    break;
                }
            }
        }
    }

    for(x=0;x<=3;x++)
    {
        for(y=0;y<3;y++)
        {
            if(aray[x][y]==0)
            {
                for(z=y+1;z<=3;z++)
                {
                    if(aray[x][z]!=0)
                    {
                        motiondetector=10;
                        aray[x][y]=aray[x][z];
                        aray[x][z]=0;
                        break;
                    }
                }
            }
        }
    }
    if(motiondetector==10)
    {
        random2or4(aray);
        output(aray);
        loose(aray);
    }
    if(motiondetector==0)
    {
        output(aray);
        loose(aray);
    }
}
//Moving Down
void down(int aray[][4])
{
    motiondetector=0;
    int x,y,z;
    for(x=0;x<4;x++)
    {
        for(y=3;y>0;y--)
        {
            if(aray[y][x]!=0)
            {
                for(z=y-1;z>=0;z--)
                {
                    if(aray[z][x]!=0 && aray[y][x]!=aray[z][x])
                        break;
                    if(aray[y][x]==aray[z][x])
                    {
                        motiondetector=10;
                        aray[y][x]=aray[y][x]+aray[z][x];
                        score=score+aray[y][x];
                        aray[z][x]=0;
                        y=z-1;
                        break;
                    }
                }
            }
        }
    }

    for(x=0;x<=3;x++)
    {
        for(y=3;y>0;y--)
        {
            if(aray[y][x]==0)
            {
                for(z=y-1;z>=0;z--)
                {
                    if(aray[z][x]!=0)
                    {
                       motiondetector=10;
                       aray[y][x]=aray[z][x];
                       aray[z][x]=0;
                       break;
                    }
                }
            }
        }
    }
    if(motiondetector==10)
    {
        random2or4(aray);
        output(aray);
        loose(aray);
    }
    if(motiondetector==0)
    {
        output(aray);
        loose(aray);
    }
}
//Up moving function
void up(int aray[][4])
{
    motiondetector=0;
    int x,y,z;
    for(y=0; y<4; y++)
    {
        for(x=3; x>0; x--)
        {
            if(aray[x][y]!=0)
            {
                for(z=x-1; z>=0; z--)
                {
                    if(aray[z][y]!=0 && aray[x][y]!=aray[z][y])
                        break;
                    if(aray[x][y]==aray[z][y])
                    {
                        motiondetector=10;
                        aray[z][y]=aray[x][y]+aray[z][y];
                        score=score+aray[z][y];
                        aray[x][y]=0;
                        x=z-1;
                        break;
                    }
                }
            }
        }
    }

    for(x=0; x<=3; x++)
    {
        for(y=0; y<3; y++)
        {
            if(aray[y][x]==0)
            {
                for(z=y+1; z<=3; z++)
                {
                    if(aray[z][x]!=0)
                    {
                        motiondetector=10;
                        aray[y][x]=aray[z][x];
                        aray[z][x]=0;
                        break;
                    }
                }
            }
        }
    }
    if(motiondetector==10)
    {
        random2or4(aray);
        output(aray);
        loose(aray);
    }
    if(motiondetector==0)
    {
        output(aray);
        loose(aray);
    }
}
//This function will give give output to user every time
void output(int aray[][4])
{
    system("cls");
    int x,y;
    for(x=0;x<4;x++)
    {
        cout<<"\n |  ";
        for(y=0;y<4;y++)
        {
            cout<<aray[x][y]<<"  |  ";
        }

        cout<<endl;
        for(y=0;y<=4;y++)
        {

            cout<<"----";
        }
        cout<<"------"<<endl;
    }
    cout<<"\n Score = "<<score<<endl;
}
//Win and loose function
void loose(int aray[][4])
{
    int x,y,r=10,d;
    for(x=0;x<=3;x++)
    {
        for(y=0;y<=3;y++)
        {
            if(aray[x][y]==2048)
           {
               cout<< "You won";
               r=1;
           }

            if(aray[x][y]==0)
                goto move;
        }
    }
    for (x=0;x<=3;x++)
    {
        for(y=0;y<3;y++)
        {
            if(aray[x][y]==aray[x][y+1])
                goto move;
        }
    }
    for(x=0;x<=3;x++)
    {
        for(y=3;y>0;y--)
            if(aray[x][y]==aray[x][y-1])
            goto move;
    }
    for(x=0;x<=3;x++)
    {
        for(y=0;y<3;y++)
            if(aray[y][x]==aray[y+1][x])
            goto move;
    }
    for(x=0;x<=0;x++)
    {
        for(y=3;y>0;y--)
            if(aray[y][x]==aray[y-1][x])
            goto move;
    };
    r=0;
    cout<<"\n You lose \n";
    move:
        //User wants to restart or not
   if(r==0 || r==1)
   {cout<<"\n Do you want to play again? Y for Yes \n";
   d=getch();
   if(d=='Y' || d=='y')
  {
      for(x=0;x<4;x++)
    {
        for(y=0;y<4;y++)
        {
            aray[x][y]=0;
        }
    }
   preboard(aray);
   output(aray);
   loose(aray);
  }}w
  if(r==10)
  {
    char m;
    cout<<"Press 'W' for Up \n Press 'A' for Left \n Press 'D' for Right \n Press 'S' for Down \n";
    m=getch();
    switch(m)
    {
    case 'W':
    case 'w':
        up(aray);
        break;

    case 'A':
    case 'a':
        left(aray);
        break;

    case 'D':
    case 'd':
        right(aray);
        break;

    case 'S':
    case 's':
        down(aray);
    default:
        cout<<"\n You were supposed to press A,S,D,W \n";
        loose(aray);
    }
  }
}
