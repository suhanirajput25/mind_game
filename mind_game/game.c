#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
void load_graphics();
void show_graphics();
void print_magic();
void circ();
void answer();
int mx=0,my=0,key=0;

main()
{ load_graphics();
  show_graphics();          	//  }  Use any one---
//  nosound();			//  }        ---in one time
  print_magic();
  getch();
  circ();
  answer();
  fflush(stdin);  fflush(stdout);	flushall();
  getch();
  closegraph();
}

void load_graphics()
{ int gd=DETECT,gm;
  sound(100);
  clrscr();
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  mx=getmaxx();  my=getmaxy();
}

void show_graphics()
{ int i;
  setcolor(LIGHTRED);  settextstyle(10,0,2);
  moveto(mx/2-70,my/2-30);
  delay(10);
  outtext("L");  delay(500);  outtext("o");  delay(500);
  outtext("a");  delay(500);  outtext("d");  delay(500);
  outtext("i");  delay(500);  outtext("n");  delay(500);
  outtext("g");  delay(500);  outtext(".");  delay(500);
  outtext(".");  delay(500);  outtext(".");  delay(500);
  for(i=1;i<=5;i++)
  { delay(500); setcolor(BLACK);	outtextxy(mx/2-70,my/2-30,"Loading...");
	delay(500);setcolor(LIGHTRED);	outtextxy(mx/2-70,my/2-30,"Loading...");
  }
  delay(2000);
  for(i=0;i<=mx/2;++i)
  { sound(i*15);
    setcolor(random(15));    rectangle(i,i,mx-i,my-i);
    delay(8);
  }
  nosound();  cleardevice();
}

void print_magic()		//Printing table
{ int i,ch,j,c=1;
  int x,y;
  char str[40];
  randomize();
  settextstyle(2,0,6);	settextjustify(0,0);
  outtextxy(280,my/4-40,"STEPS");
  outtextxy(10,my/4,"* Choose any one number between 10 & 99 (means of two digits)");
  outtextxy(10,my/4+15,"* Add both digits of this choosen number,");
  outtextxy(10,my/4+30,"* Subtract this sum from the original two digit number,");
  outtextxy(10,my/4+45,"* Keep symbole in mind, associated with this resultant number,");
  outtextxy(10,my/4+60,"* Then press any key to continue,");
  outtextxy(10,my/4+90,"Note: � Computer will calculate symbole according to pressed key!");
  outtextxy(66,my/4+105,"� Symbole table has random symboles");
  textcolor(YELLOW+BLINK);

  setcolor(10);
  outtextxy(10,320,"Produced By :");

  outtextxy(10,340,": Shobhit sir");
  outtextxy(10,360,": suhani");

  cprintf("Suppose");
  sprintf(str,"%s","\0");
  for(i=50;(i>=0)&&(!kbhit());--i)
  { delay(1000);
    setcolor(BLACK);
    outtextxy(mx/2,3*my/4,str);
    setcolor(LIGHTRED);
    sprintf(str,"Press any key (%2d )...",i);
    outtextxy(mx/2,3*my/4,str);
  }
  if(kbhit())	getch();
  fflush(stdin);	fflush(stdout);   flushall();
  cleardevice();
  do
  { key=random(255);
  }while(iscntrl(key)||isspace(key)||isdigit(key));
  setfillstyle(1,YELLOW);  floodfill(mx/2,my/2,WHITE);
  setlinestyle(0,0,3);  setcolor(RED);
  rectangle(3,3,mx-3,my-3);  rectangle(5,5,mx-5,my-5);
  setlinestyle(0,0,1);  setcolor(MAGENTA);
  settextstyle(6,0,1);
  for(y=22,i=1;i<=20;y+=22,i++)
  {  for(x=0,j=0;j<=4;x+=100,j++)
     { do
       { ch=random(255);
       }while(iscntrl(ch)||isspace(ch)||isdigit(ch));
       if((c+(j*20))%9==0)      ch=key;
       sprintf(str,"%10d =%2c",c+(j*20),ch);       outtextxy(x,y,str);
     }++c;
  }
  sprintf(str,"%s","\0");
  for(i=31;(i>=0)&&(!kbhit());--i)
  { delay(1000);
    setcolor(YELLOW);    outtextxy(100,my-18,str);
    setcolor(LIGHTRED);
    sprintf(str,"If choosed then press any key (%2d )...",i);
    outtextxy(100,my-18,str);
  }
  for(i=1000;!kbhit();i=(i>200)?(i-30):200)
  {  delay(i);    printf("\a");
  }
}

void circ()
{ int i,j,a=3,r1=1,r2=mx/2;
  cleardevice();
  setfillstyle(8,LIGHTRED);  floodfill(mx/2,my/2,WHITE);
  settextstyle(1,0,2);	settextjustify(1,1);	setcolor(YELLOW);
  outtextxy(mx/2,my/2,"Please wait while calculating user's mind's status...");
  delay(2000);
  setlinestyle(1,0,3);
  for(i=0;i<=5;++i)
  { do
    { setcolor(random(15));
      circle(mx/2,my/2,r1);	circle(mx/2,my/2,r2);
      r1+=a; 			r2-=a;
    }while(((r1>=0)&&(r1<=mx/2))&&((r2>=0)&&(r2<=mx/2)));
    a=-a;
  }
  setlinestyle(1,0,1);  setcolor(BLACK);
  for(i=0;i<=mx/2+my/2;++i)
  { circle(mx/2,my/2,i);
    delay(3);
  }
}

void answer()
{ int i,j,c=0;
  char str[20];
  settextjustify(1,1);
  do
  { cleardevice();
    do
    { i=random(255);
    }while(iscntrl(i)||isspace(i)||isdigit(i));
    if(c>=10+random(10))
      i=key;
    sprintf(str,"%c",i);
    settextstyle(1,0,0);  settextjustify(1,1);
    for(j=0;j<=8;++j)
    { delay(10);
      setcolor(BLACK);     outtextxy(mx/2,my/2,str);
      settextstyle(1,0,j);
      setcolor(YELLOW);      outtextxy(mx/2,my/2,str);
    }
    settextstyle(1,0,8);
    if(key==i)	      //Prints right charcter  in diffrent colors
      for(j=15;j>=2;--j)
      { delay(300);
	setcolor(j);     outtextxy(mx/2,my/2,str);
      }
    delay(500);
    settextstyle(7,0,2);
    if(key==i)
    { setcolor(GREEN);
      outtextxy(mx/2,my/2+120,"� Right �");
    }
    else
    { setcolor(RED);
      outtextxy(mx/2,my/2+120,"� Sorry! Let me try again... �");
    }
    delay(500);
    ++c;
  }while(key!=i);
}