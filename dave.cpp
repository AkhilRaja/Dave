#include <allegro.h>
#include<math.h>


#define left 1
#define right 2
#define down 3
#define pi 3.14
using namespace std;



BITMAP *bmp;

BITMAP *bk[10];
BITMAP *buffer;
BITMAP *tempbk1[10];
BITMAP *score;
BITMAP *killing;
BITMAP *bullet;




int deciderr=0,deciderl=0; 
int me=0;
int ecit=1;
int got=0;
int level=0; 
int killed=1;
int lives=3;
int scopo=0;

int direct[4];
enum{LEFT,RIGHT,UP,DOWN};

void setcord();
struct points
{
     
     BITMAP *coin;
       int x;
       int y; 
      points()
      {
                  
                  coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL);     
                }

};



points points[11];
struct keying
{
       BITMAP *keyy;
       int x;
       int y;
       BITMAP *gotit;
      
      keying()
      {
              x=352;
              y=114;
              keyy=load_bitmap("c:\\tc\\fipic\\kingpoint",NULL);
      
     }
       };
       
keying keyy;       




void keyit()
{
  
     draw_sprite(bk[0],keyy.keyy,keyy.x,keyy.y);
     }

void pointes()
{
     
     for(int i=0;i<10;i++)
          {
                  switch(i)
                  {
                           case 0: points[i].x=37; points[i].y=268; points[i].coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL); break;
                           case 1: points[i].x=98; points[i].y=129; points[i].coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL); break;
                           case 2: points[i].x=163;points[i].y=205; points[i].coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL); break;
                           case 3: points[i].x=227;points[i].y=129; points[i].coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL); break;
                           case 4: points[i].x=418;points[i].y=205; points[i].coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL); break;
                           case 5: points[i].x=484;points[i].y=129; points[i].coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL); break;
                           case 6: points[i].x=547;points[i].y=202; points[i].coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL); break;    
                           case 7: points[i].x=125;points[i].y=281; points[i].coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL); break;
                           case 8: points[i].x=237;points[i].y=281; points[i].coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL); break;    
                           case 9: points[i].x=292;points[i].y=205; points[i].coin=load_bitmap("c:\\tc\\fpic\\points.bmp",NULL); break;    
                          
                           
                           }
     keyy.keyy=load_bitmap("c:\\tc\\fpic\\kingpoint.bmp",NULL); 
          }  

}

void doit()
{
         keyit();
          for(int i=0;i<10;i++)
          draw_sprite(bk[0],points[i].coin,points[i].x,points[i].y);
}

void gotit()
{
     keyy.gotit=load_bitmap("c:\\tc\\fpic\\gotkey.bmp",NULL);
     draw_sprite(bk[0],keyy.gotit,121,440);
     got=1;
     }

void life()
{
     if(killed)
     lives--;
     
}
     

class enemy1
{
      private:
           int x;
           int y;
           int ok;
 BITMAP *enemy;
 BITMAP *tempenem;
 
     public:
         enemy1()
         {
            //enemy=create_bitmap(640,480);
                  enemy=load_bitmap("c:\\Tc\\fpic\\enemy1.bmp",NULL);
                                   ok=1;
          }    
       void shoot()
       {
            int tempx=0,tempy=0;
            int black=0;
            black=getpixel(bk[0],0,0);
       
             
            for(tempx=x,tempy=y;tempy<y+37;tempy++)
             if(getpixel(bk[level],tempx,tempy)!=black)
                 exit(1);
                 
             for(tempx=x,tempy=y;tempx<x+59;tempx++)
             if(getpixel(bk[level],tempx,tempy)!=black)
                 exit(1);
                 
             for(tempx=x,tempy=y+37;tempx<x+59;tempx++)
             if(getpixel(bk[level],tempx,tempy)!=black)
                 exit(1);
              }
        void moveenemy()
              {
               static int i=0;
               double p;
               int t;
               enemy=load_bitmap("c:\\Tc\\fpic\\enemy1.bmp",NULL);
              
               p=i*(pi/180);
               x=sin(p)*37+600;
               y=cos(p)*37+190;
               i++;
        
               if(ok)
               draw_sprite(bmp,enemy,x,y);
              
        }
       
      
        
};
 enemy1 enem;               




class character
{
      public:
             character();
             
         
             
             void setimagesleft(char image1[],char image2[],char image3[]);
             void setimagesright(char image1[],char image2[],char image3[]);
             void setimagesup(char image1[],char image2[]);
             void setimagesdown(char image1[],char image2[]);
             
             int Getx();
             int Gety();
             
             void setx(int newvalue);
             void sety(int newvalue);
             void values(int tex, int tey);
            
             void moveonx(int newvalue,BITMAP *mainbitmap,int cha=1);
             void moveony(BITMAP *mainbitmap,int cha=1);         
             void gravity(BITMAP *mainbitmap);
                       
             
             void drawnewsprite(BITMAP *tempbitmap,BITMAP *spritetodraw);
             void validator();
             
  
             
       private:
               
               int direction;
               int x;
               int y;
               BITMAP *images[4][3];
                 
             
};

void character::validator()
{
  int i,xtem,ytem;
  unsigned int tempx,tempy;
    int blue=0;
    blue=getpixel(tempbk1[0],2,0);
    int yellow=0;
    yellow=getpixel(tempbk1[0],3,0);
    int brown=0;
    brown=getpixel(tempbk1[0],1,0);
    int black=0;
    black=getpixel(bk[0],0,0);
    int fire=0;
    fire=getpixel(tempbk1[2],0,0);
 //////////////////INITIALISING   
  for(i=0;i<4;i++)
        direct[i]=1;
 
 //////////////////////UP?/////////////////////////////////////////////////////////
 for(xtem=x,ytem=y-3;xtem<x+28;xtem++)
    ////////////////////movement//////////////////////////////////////
     { if(getpixel(bk[level],xtem,ytem)!=black)
           direct[UP]=0;
     ///////////////////////points/////////////////////
     if(getpixel(tempbk1[level],xtem,ytem)==blue)
          {
             for(i=0;i<10;i++)
                 {
                    tempx=xtem-points[i].x;
                    tempy=ytem-points[i].y;
                             
                    if((tempx>=0&&tempx<=26)&&(tempy>=0&&tempy<=24))
                    {  
                         points[i].coin=load_bitmap("c:\\tc\\fpic\\pointsb.bmp",NULL);
                                   }
                                    
                }                                                       
          }
     //////////////////////key///////////////////////////////
     if(getpixel(tempbk1[level],xtem,ytem)==yellow)
            {
                 keyy.keyy=load_bitmap("c:\\tc\\fpic\\kingpointb.bmp",NULL);
                 gotit();
                 }     
                 
        if(getpixel(tempbk1[level],xtem,ytem)==brown)
          ecit=0;         
                  
     ///////////////////////kill//////////////////////////////////
     if(getpixel(tempbk1[level],xtem,ytem)==fire)
     {
                 killed=0;
                 }   
                 
                                                 
     
     }     
  
  //////////////////LEFT//////////////////////////////////////////////////////
  for(xtem=x-3,ytem=y+1;ytem<y+40;ytem++)
      ////////////////////movement/////////////////////
      {
      if(getpixel(bk[level],xtem,ytem)!=black)
      direct[LEFT]=0;
       /////////////////points////////////////////////////////////                
         if(getpixel(tempbk1[level],xtem,ytem)==blue)
          {
             for(i=0;i<10;i++)
                 {
                    tempx=xtem-points[i].x;
                    tempy=ytem-points[i].y;
                             
                             if((tempx>=0&&tempx<=26)&&(tempy>=0&&tempy<=24))
                                    {  
                                       points[i].coin=load_bitmap("c:\\tc\\fpic\\pointsb.bmp",NULL);
                                    
                                       }
                                    
                 }                                                       
             }
             /////////////////key//////////////////////////////////
             if(getpixel(tempbk1[level],xtem,ytem)==yellow)
            {
                 keyy.keyy=load_bitmap("c:\\tc\\fpic\\kingpointb.bmp",NULL);
                 gotit();
                 } 
            if(getpixel(tempbk1[level],xtem,ytem)==brown)
                 if(got)
                 ecit=0;    
     ///////////////////////kill//////////////////////////////////
     if(getpixel(tempbk1[level],xtem,ytem)==fire)
     {
                 killed=0;
                 }     
              
              
      }       
  
  ////////////////////////DOWN///////////////
  for(xtem=x,ytem=y+1+40;xtem<x+28;xtem++)
     { 
     ///////////////////movement/////////////////////////////
     if(getpixel(bk[level],xtem,ytem)!=black)
           direct[DOWN]=0;
            ////////////////points////////////////
            if(getpixel(tempbk1[level],xtem,ytem)==blue)
          {
             for(i=0;i<10;i++)
                 {
                    tempx=xtem-points[i].x;
                    tempy=ytem-points[i].y;
                             
                             if((tempx>=0&&tempx<=26)&&(tempy>=0&&tempy<=24))
                                    {  
                                       points[i].coin=load_bitmap("c:\\tc\\fpic\\pointsb.bmp",NULL);
                                    
                                       }
                                    
                 }                                                       
             }
               //////////////////////////key//////////////////
               if(getpixel(tempbk1[level],xtem,ytem)==yellow)
            {
                 keyy.keyy=load_bitmap("c:\\tc\\fpic\\kingpointb.bmp",NULL);
                  gotit();
                 }  
                 if(getpixel(tempbk1[level],xtem,ytem)==brown)
                 if(got)
                 ecit=0; 
    
     ///////////////////////kill//////////////////////////////////
     if(getpixel(tempbk1[level],xtem,ytem)==fire)
     {
                 killed=0;
                 }
              
              
    
    
     }       
  /////////////////////////////RIGHT////////////////////////////////////////////////////////////////////////////
  for(xtem=x+28+3,ytem=y+1;ytem<y+39;ytem++)
      {
      ///////////////////////////////////movement////////////
      if(getpixel(bk[level],xtem,ytem)!=black)
           direct[RIGHT]=0;
         ////////////////////////points/////////////////////////  
            if(getpixel(tempbk1[level],xtem,ytem)==blue)
          {
             for(i=0;i<10;i++)
                 {
                    tempx=xtem-points[i].x;
                    tempy=ytem-points[i].y;
                             
                             if((tempx>=0&&tempx<=26)&&(tempy>=0&&tempy<=24))
                                    {  
                                       points[i].coin=load_bitmap("c:\\tc\\fpic\\pointsb.bmp",NULL);
                                    
                                       }
                                    
                 }                                                       
             }
        ///////////////////////key////////////////////////////////     
              if(getpixel(tempbk1[level],xtem,ytem)==yellow)
            {
                 points[10].coin=load_bitmap("c:\\tc\\fpic\\kingpointb.bmp",NULL);
                 gotit();
                }   
                if(getpixel(tempbk1[level],xtem,ytem)==brown)
                if(got)
                ecit=0;
      }   
               ///////////////////////kill//////////////////////////////////
     if(getpixel(tempbk1[level],xtem,ytem)==fire)
     {
                 killed=0;
                 } 
             
                  
  }
            
            
    
   
 /////////////////////////constructor.//////////////////////////////////////////           
   character::character()
             {

                                   direction=3;
                                   x=66;y=345;
                                   images[2][0]=NULL;                      
                                   
                                   }
                                   
                                   
                                   

                               
    ///////////setting imges.//////////////////         
             void character::setimagesleft(char image1[],char image2[],char image3[])
             {
                  images[0][0]=load_bitmap(image1,NULL);
                  images[0][1]=load_bitmap(image2,NULL);
                  images[0][2]=load_bitmap(image3,NULL);
                  }
                  
            void character::setimagesright(char image1[],char image2[],char image3[])
             {
                  images[1][0]=load_bitmap(image1,NULL);
                  images[1][1]=load_bitmap(image2,NULL);
                  images[1][2]=load_bitmap(image3,NULL);
    
                  }
                  
            void character::setimagesup(char image1[],char image2[])
             {
                  images[3][0]=load_bitmap(image1,NULL);
                  images[3][1]=load_bitmap(image2,NULL);
                  }
           void character::setimagesdown(char image1[],char image2[])
             {
                  images[4][0]=load_bitmap(image1,NULL);
                  images[4][2]=load_bitmap(image2,NULL);
                  }
        
             
                  
             int character::Getx()     
             {
                 return x;
                 }
                 
              int character::Gety()
              {
                  return y;
                  }
              
              void character::setx(int newvalue)
              {
                      x=newvalue;
                      }
              
              void character::sety(int newvalue)
              {
                   y=newvalue;
                   }
             
              void character::values(int tex,int tey)
             {
                   x=tex;
                   y=tey;
                   }
              
    void character::moveonx(int newdirection,BITMAP *mainbitmap,int cha)
              {
                   static int choice;  
                   direction=newdirection;
                   if(direction==left&&cha==1)
                   {
                                                                                                    
                                         
                                                      if(direct[LEFT])
                                                      x-=2;
                                                   
                                                
                                             if(!key[KEY_UP])
                                             {        if(choice/10==1||choice/10==3)
                                                      drawnewsprite(mainbitmap,images[0][0]);
                                                      if(choice/10==0)
                                                      drawnewsprite(mainbitmap,images[0][1]);
                                                      if(choice/10==2)
                                                      drawnewsprite(mainbitmap,images[0][2]);
                                                      
                                                 
                                                 
                                                 if(choice<40) 
                                                 choice++;
                                                 else 
                                                 choice=0;
                                             }         
                     }
                                                 
                                                 
                 else 
                 {
                     if(direction==left)
                          drawnewsprite(mainbitmap,images[0][0]);  
                      
                 }
                 if(direction==right&&cha==1)    
                 {
                                            
                                                    if(direct[RIGHT])
                                                          x+=2;
                                                    
                      
                                          if(!key[KEY_UP])
                       
                                          {            if(choice/10==1||choice/10==3)
                                                      drawnewsprite(mainbitmap,images[1][0]);
                                                      if(choice/10==0)
                                                      drawnewsprite(mainbitmap,images[1][1]);
                                                      if(choice/10==2)
                                                      drawnewsprite(mainbitmap,images[1][2]);
                                                      
                                                 
                                                
                                                 if(choice<40) 
                                                 choice++;
                                                 else 
                                                 choice=0;
                                                 }
                 }
                 else
                 {if(direction==right)
                 {
                     drawnewsprite(mainbitmap,images[1][0]);
                     }}
                                        
      }      
                                                 
                                                 
                                                 
      
             
             
          void character::moveony(BITMAP *mainbitmap,int cha)
                { 
                 
                       int dec=1;
                             if(cha==1)                    
                             {              
                             if(direct[UP])
                             y-=2;
                             
                             if(key[KEY_RIGHT]&&direct[RIGHT])  
                             {
                             x+=2;
                             drawnewsprite(mainbitmap,images[3][0]);      
                             }
                             else if(key[KEY_LEFT]&&direct[LEFT])
                              {
                                                 x-=2;
                                                 drawnewsprite(mainbitmap,images[3][1]);
                                                 }
                           else
                           drawnewsprite(mainbitmap,images[3][0]);
                            }
                             
                  }                                   






void character::drawnewsprite(BITMAP *tempbitmap,BITMAP *spritetodraw)
{
     draw_sprite(tempbitmap,spritetodraw,Getx(),Gety());
     }
     


void character::gravity(BITMAP *mainbitmap)
{
int red=0;
         red=getpixel(tempbk1[0],1,1); 
 
          blit(bk[level],bmp,0,0,0,0,640,480);
                                                y+=2;
                                                if(key[KEY_RIGHT]&&direct[RIGHT])
                                                 drawnewsprite(mainbitmap,images[4][0]);  
                                                        
                                                
                                                                                        
                                                else if(key[KEY_LEFT]&&direct[LEFT])
                                                  drawnewsprite(mainbitmap,images[4][2]);
                                                     
                                                                                             
                                               else
                                               drawnewsprite(mainbitmap,images[3][0]);




}
character mychar;


void kill()
{
     draw_sprite(bk[level],killing,mychar.Getx(),mychar.Gety());
     }
void shooting()
{
 
 static int tempx=0;
 static int tempy=0;
 static int decider=1;
 if(key[KEY_B]&&decider)
 {
               tempx=mychar.Getx()+28;
               tempy=mychar.Gety()+20;  
               }
            
        if(tempx<640&&tempx!=0)       
                {       
                     tempx+=3;
                    
                     draw_sprite(bmp,bullet,tempx,tempy);
                     decider=0;
                     if(tempx>=637)
                     decider=1;
                    }                                
        

  }


void setup()
{
       buffer=create_bitmap(640,480);
       mychar.setimagesleft("c:\\tc\\fpic\\l1.bmp","c:\\tc\\fpic\\l3.bmp","c:\\tc\\fpic\\l2.bmp");
       mychar.setimagesright("c:\\tc\\fpic\\r1.bmp","c:\\tc\\fpic\\r3.bmp","c:\\tc\\fpic\\r2.bmp");
       mychar.setimagesup("c:\\tc\\fpic\\u1.bmp","c:\\tc\\fpic\\u2.bmp");
       mychar.setimagesdown("c:\\tc\\fpic\\d1.bmp","c:\\tc\\fpic\\d2.bmp");
       bmp=create_bitmap(640,480);
       killing=create_bitmap(640,480);
       killing=load_bitmap("c:\\Tc\\fpic\\killed.bmp",NULL);
       bullet=create_bitmap(640,480);
       bullet=load_bitmap("c:\\Tc\\fpic\\mybullet.bmp",NULL);
    
      }
       
       
void background()
{
           bk[0]=load_bitmap("c:\\tc\\fpic\\1level1.bmp",NULL);
                 tempbk1[0]=load_bitmap("c:\\tc\\fpic\\tempbk1.bmp",NULL);              
           
           bk[1]=load_bitmap("c:\\tc\\fpic\\3.bmp",NULL); 
           
           bk[2]=load_bitmap("c:\\Tc\\fpic\\1level2.bmp",NULL);
           bk[3]=load_bitmap("c:\\Tc\\fpic\\2level2.bmp",NULL);
           bk[4]=load_bitmap("c:\\Tc\\fpic\\3level2.bmp",NULL);
                tempbk1[2]=load_bitmap("c:\\Tc\\fpic\\tempbk2.bmp",NULL);
                tempbk1[3]=load_bitmap("c:\\Tc\\fpic\\tempbk3.bmp",NULL);
                tempbk1[4]=load_bitmap("c:\\Tc\\fpic\\tempbk4.bmp",NULL);
  
           bk[5]=load_bitmap("c:\\tc\\fpic\\1level3.bmp",NULL);
           bk[6]=load_bitmap("c:\\tc\\fpic\\2level3.bmp",NULL);
                tempbk1[5]=load_bitmap("c:\\tc\\fpic\\tempbk5.bmp",NULL);
                tempbk1[6]=load_bitmap("c:\\tc\\fpic\\tempbk6.bmp",NULL);
                
                 
  
  }     
 void scoring()
 {
      score=load_bitmap("c:\\tc\\fpic\\score.bmp",NULL);
      draw_sprite(bk[0],score,25,2); 
 }
void moveplayer()
{
   static int upper=0,charec,gravity=1;
   int red=0;
         red=getpixel(tempbk1[0],1,1); 
   
     mychar.validator();
if(killed==0)
kill();
           
if(killed)
 {
     
     if(key[KEY_RIGHT]&&!(upper))
      {
                       mychar.moveonx(right,bmp);
                       charec=RIGHT;
      }
     else  if(key[KEY_LEFT]&&!(upper))
     {
                      mychar.moveonx(left,bmp);
                      charec=LEFT;
     }                  
     if(direct[DOWN]&&upper==0 )
         {
         mychar.gravity(bmp);
         gravity=0;
        
         }
     if(!direct[DOWN])
      {
                       gravity=1;
                       }
                                
     if(key[KEY_UP])
     {      
        
        if(gravity&&upper==0)
        {
          if(mychar.Gety()<150)
          upper=20;
          else upper=40;
          charec=UP;
        }
     }
     
      if(upper)
     {
                     mychar.moveony(bmp); 
                     upper--;
     }
   else  if(!(key[KEY_LEFT]||key[KEY_RIGHT]||key[KEY_UP]||direct[DOWN]))
     {
           if(charec==LEFT)
               mychar.moveonx(left,bmp,0);       
           if(charec==RIGHT)
               mychar.moveonx(right,bmp,0);
           if(charec==UP)
               mychar.moveonx(right,bmp,0);
     }
     if(level>5) 
     shooting();
     
 } 
 

}


int main() 
{

allegro_init();

    	install_keyboard();
	    install_mouse();
        set_color_depth(16);


set_gfx_mode(GFX_AUTODETECT, 640,480 , 0, 0);

setup();
background();
pointes();
scoring();

BITMAP *bbbmm;
                   bbbmm=create_bitmap(640,480);
                  
                  BITMAP *mage1;
                  mage1=load_bitmap("c:\\tc\\fpic\\r1.bmp",NULL);
                  BITMAP *mage2;
                  mage2=load_bitmap("c:\\tc\\fpic\\r2.bmp",NULL);
                  BITMAP *mage3;
                  mage3=load_bitmap("c:\\tc\\fpic\\r3.bmp",NULL);
                  int x=37; 

//ecit;(key[KEY_ESC])||
/*
	while(ecit)

 {
    blit(bk[0],bmp,0,0,0,0,640,480);
   	doit();
       moveplayer();
    vsync();
    blit(bmp,screen,0,0,0,0,640,480);    
    
    }





////////////////////////////end of level 1//////////////////////////////
 while(x<=630)
    
    {
                
                blit(bbbmm,screen,0,0,0,0,640,480);            
               
              vsync();
                  blit(bk[1],bbbmm,0,0,0,0,640,480);                                             
                  static int choice;
          
                
                   x+=1;
                                                      if(choice/10==1||choice/10==3)
                                                      draw_sprite(bbbmm,mage1,x,191);
                                                      if(choice/10==0)
                                                      draw_sprite(bbbmm,mage2,x,191);
                                                      if(choice/10==2)
                                                      draw_sprite(bbbmm,mage3,x,191);
                   if(choice<40) 
                                                 choice++;
                                                 else 
                                                 choice=0;
                                                
                                                 
                
                     mychar.setx(66);
                     mychar.sety(330);                                  

 
}
 ////////////////////////////level 2////////////////////////////////////////
  
 
level=2;
 killed=1;
 while( mychar.Getx()<=600)//&&mychar.Gety()>=228)
    
  {  
 
    blit(bk[level],bmp,0,0,0,0,640,480);
   	
       moveplayer();
       vsync();
       blit(bmp,screen,0,0,0,0,640,480);    
       }
  
  
  
level=3;
killed=1;
mychar.setx(45);
mychar.sety(170);
while(mychar.Getx()<600)
   {
   
       blit(bk[level],bmp,0,0,0,0,640,480);
       moveplayer();
       vsync();
       blit(bmp,screen,0,0,0,0,640,480);    
                     
                     }
  
  

  
  level=4;
  killed=1;
  mychar.setx(11);
  mychar.sety(252);
  got=1;
  ecit=1;
   while(ecit)
   {
   
       blit(bk[level],bmp,0,0,0,0,640,480);
       moveplayer();
       vsync();
       blit(bmp,screen,0,0,0,0,640,480);    
                     
                     } 
    


       
 x=37;    
    while(x<=630)
    
    {
                
                blit(bbbmm,screen,0,0,0,0,640,480);            
               
                  vsync();
                  blit(bk[1],bbbmm,0,0,0,0,640,480);                                             
                  static int choice;
          
                
                   x+=1;
                                                      if(choice/10==1||choice/10==3)
                                                      draw_sprite(bbbmm,mage1,x,191);
                                                      if(choice/10==0)
                                                      draw_sprite(bbbmm,mage2,x,191);
                                                      if(choice/10==2)
                                                      draw_sprite(bbbmm,mage3,x,191);
                   if(choice<40) 
                                                 choice++;
                                                 else 
                                                 choice=0;
                                                
                                                 
                
                     mychar.setx(66);
                     mychar.sety(330);                                  

 
}
    
    
    
    
 level=5;  
 killed=1;
 mychar.setx(65);
 mychar.sety(230); 
  
    while(mychar.Getx()<600)
    {
              blit(bk[level],bmp,0,0,0,0,640,480);
              moveplayer();
              vsync();
       
       blit(bmp,screen,0,0,0,0,640,480);           
    
     }
   */
   level=6;
   killed=1;
   mychar.setx(25);
   mychar.sety(220);
   
 //  mychar.Getx()<600
   
   while(!key[KEY_ESC])
    {
              blit(bk[level],bmp,0,0,0,0,640,480);
              moveplayer();
              vsync();
              enem.moveenemy();
              blit(bmp,screen,0,0,0,0,640,480);     
                    
    
     }
   
   
   
   
   
   
   
   
   
   
   
   
    return 0;
}
END_OF_MAIN()














