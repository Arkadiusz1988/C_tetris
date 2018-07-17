#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include  <math.h>
#include <windows.h> 
#include "tetris.h"
#include "klocek.h"      

       


     
 
void zeruj_klocek(struct klocek* kl){
     int i,j;
     for(i=0; i<4; i++)
              for(j=0; j<4; j++)
                  kl->tab[i][j]=0;
     }
 
     
void utworz_klocek( int rodzaj,struct tetris* t){
     int i,j,poz,x,y;
     struct klocek* kl;
          kl = (struct klocek*)malloc(sizeof(struct klocek));
     zeruj_klocek(kl);
     kl->ruch=1;
     t->ile_klockow++;
     t->tab_kl=(struct klocek*)realloc(t->tab_kl,t->ile_klockow*sizeof(struct klocek));
     
     if(rodzaj==0){
          kl->tab[1][0]=1;
          kl->tab[1][1]=1;
          kl->tab[1][2]=1;
          kl->tab[1][3]=1;
           }
     if(rodzaj==1){
          kl->tab[2][0]=1;
          kl->tab[1][0]=1;
          kl->tab[1][1]=1;
          kl->tab[1][2]=1;
           }
     if(rodzaj==2){
          kl->tab[1][0]=1;
          kl->tab[1][1]=1;
          kl->tab[1][2]=1;
          kl->tab[2][2]=1;
           }
     if(rodzaj==3){
          kl->tab[0][0]=1;
          kl->tab[0][1]=1;
          kl->tab[1][0]=1;
          kl->tab[1][1]=1;
           }
     if(rodzaj==4){
          kl->tab[1][0]=1;
          kl->tab[1][1]=1;
          kl->tab[1][2]=1;
          kl->tab[2][1]=1;
           }
     if(rodzaj==5){
          kl->tab[2][0]=1;
          kl->tab[2][1]=1;
          kl->tab[1][1]=1;
          kl->tab[1][2]=1;
           }
     if(rodzaj==6){
          kl->tab[1][0]=1;
          kl->tab[1][1]=1;
          kl->tab[2][1]=1;
          kl->tab[2][2]=1;
           }
           
     kl->polozenie_gora=4;
     kl->polozenie_lewo=(t->szerokosc-4)/2;   
 
          for(i=0;i<4;i++){
               for(j=0;j<4;j++){
                                if(kl->tab[i][j]==1){
                                    x=kl->polozenie_lewo+i;
                                    y=kl->polozenie_gora+j;
                                    poz=(y)*t->szerokosc + (x-1);
                                    if((t->pola[poz]==1)) {
                                                          printf("koniec"); 
                                                          return;
                                                          }
                                    }
                     }
               }
     t->tab_kl[t->ile_klockow-1]=(*kl);              
     
 }
 
 void utworz_tetris(struct tetris* t, int wysokosc, int szerokosc){
      t->wysokosc=wysokosc;
      t->szerokosc=szerokosc;
      t->pola=(int*)malloc(szerokosc*wysokosc*sizeof(int));
      t->ile_klockow=0;
      t->tab_kl=NULL;
      t->punkty=0;
      }
      
 void usun_pelny(struct tetris* t){
      int i;
      for(i=0; i<t->wysokosc; i++){
               if(czy_wiersz_pelny(t,i)==1)
                   usun_wiersz(t,i);
      }
   
 }
 
int czy_wiersz_pelny(struct tetris* tr, int j){
      int i;
      for(i=1;i<tr->szerokosc-1;i++)
                                  if(tr->pola[j*tr->szerokosc +i]!=1) return 0;
      
      return 1;
      }
 void usun_wiersz(struct tetris* tr, int i){
      int j=0,k=0,x,y;
      tr->punkty+=100;
      for(j=i;j>4;j--)
          for(k=1;k<tr->szerokosc-1;k++){
                                         y=j;
                                         x=k;
                                        tr->pola[y*tr->szerokosc +x] = tr->pola[(y-1)*tr->szerokosc +x];
                                        }
      }      
     
 void krok(struct tetris* t){
      int i;
     
      for(i=0;i<t->ile_klockow;i++)
         if(t->tab_kl[i].ruch==1) t->tab_kl[i].polozenie_gora++;
      
      }
      

  void wyswietl_tetris(struct tetris* t){
     int i;
     system("cls");
     
     ramka(t);
     wyswietl_tab(t);
     gotoxy(2,2);
     printf("PKT:%d",t->punkty);
     
     for(i=2;i<t->szerokosc;i++){
                                   gotoxy(i,7);
                                   printf("_");
                                   }
      
     for(i=0;i<t->ile_klockow;i++){
         if(t->tab_kl[i].ruch==1) wyswietl_klocek(&t->tab_kl[i],t);
      
      }


     }
     
     void wyswietl_klocek(struct klocek* kl, struct tetris* t){
         int i,j,pom,x,y;
         for(i=0;i<4;i++){
               for(j=0;j<4;j++){
                                if(kl->tab[i][j]==1){
                                    x=kl->polozenie_lewo+i;
                                    y=kl->polozenie_gora+j;
                                    gotoxy(x,y);
                                    printf("X");
                                }
                     
                     }
               
               } 
          
          }
     
     
  void ramka(struct tetris* t){
     int i;
     for(i=1;i<=t->szerokosc;i++){
        gotoxy(i,1);
        printf("*");                              
                                   }
      for(i=1;i<=t->szerokosc;i++){
        gotoxy(i,3);
        printf("*");                              
                                   }
                                  
     for(i=1;i<=t->szerokosc;i++){
        gotoxy(i,t->wysokosc);
        printf("*");                              
                                   }                                       
       for(i=1;i<=t->wysokosc;i++){
        gotoxy(1,i);
        printf("*");                              
                                  }
     for(i=1;i<=t->wysokosc;i++){
        gotoxy(t->szerokosc,i);
        printf("*");                              
                                   }   
                                                                       
     }
     void kolizja(struct tetris * t){
          int i;
      
          for(i=0;i<t->ile_klockow;i++){
                 if(t->tab_kl[i].ruch==1) {
                                          kolizja_klocek(&t->tab_kl[i],t);
                                          }
                 }
          
      }
     void kolizja_klocek(struct klocek* kl, struct tetris * tr){
          int i,j,poz,x,y;
         for(i=0;i<4;i++){
               for(j=0;j<4;j++){
                                if(kl->tab[i][j]==1){
                                    x=kl->polozenie_lewo+i;
                                    y=kl->polozenie_gora+j;
                                    poz=(y)*tr->szerokosc + (x-1);
                                    if((y==tr->wysokosc-1)||(tr->pola[poz]==1)) {
                                                          kl->ruch=0;
                                                          skopiuj_klocek(kl,tr);
                                                          utworz_klocek(rand()%6,tr); 
                                                          return;
                                                          }
                                                       
                                }
                     
                     }
               
               } 
          
     }

void obroc_lewo(struct tetris* tr){
     int pom[4][4];
     int i,j,k;
     for(k=0;k<tr->ile_klockow;k++){
           if(tr->tab_kl[k].ruch==1){
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                                    pom[i][j]=tr->tab_kl[k].tab[i][j];
     
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                                    tr->tab_kl[k].tab[i][3-j]=pom[j][i];
           }
           if( czy_kl_poza_granicami(&tr->tab_kl[k],tr,0) ==0 ){
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                                    pom[i][j]=tr->tab_kl[k].tab[i][j];
     
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                                    tr->tab_kl[k].tab[3-j][i]=pom[i][j]; 
               }
     } 
     
     
     
     }
void obroc_prawo(struct tetris* tr){
     int pom[4][4];
     int i,j,k;
     for(k=0;k<tr->ile_klockow;k++){
           if(tr->tab_kl[k].ruch==1){
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                                    pom[i][j]=tr->tab_kl[k].tab[i][j];
     
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                                    tr->tab_kl[k].tab[3-j][i]=pom[i][j];
           }
           
           if( czy_kl_poza_granicami(&tr->tab_kl[k],tr,0) ==0 ){
               
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                                    pom[i][j]=tr->tab_kl[k].tab[i][j];
     
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                                    tr->tab_kl[k].tab[i][3-j]=pom[j][i];
               
               }
     
     } 
     
     }
void przesun_lewo(struct tetris* tr){
     int i = 0;
     for(i=0;i<tr->ile_klockow;i++){
           if(tr->tab_kl[i].ruch==1)
                                    if( czy_kl_poza_granicami(&tr->tab_kl[i],tr,-1) ==1 ) tr->tab_kl[i].polozenie_lewo--;
           } 
     }
void przesun_prawo(struct tetris* tr){
     int i = 0;
     for(i=0;i<tr->ile_klockow;i++){
           if(tr->tab_kl[i].ruch==1)
                                    if( czy_kl_poza_granicami(&tr->tab_kl[i],tr,1) ==1 ) tr->tab_kl[i].polozenie_lewo++;
           }
     }


int czy_kl_poza_granicami(struct klocek* kl,struct tetris *tr,int kier){
         int i,j,poz,x,y;
         for(i=0;i<4;i++){
               for(j=0;j<4;j++){
                                if(kl->tab[i][j]==1){
                                    x=kl->polozenie_lewo+i;
                                    y=kl->polozenie_gora+j;
                                    poz=(y-1)*tr->szerokosc + (x-1+kier);
                                    if((x==tr->szerokosc-1) && (kier==1)) {
                                                          return 0;
                                                          }
                                    if((x==2) && (kier==-1)) {
                                                          return 0;
                                                          }
                                    if(((x==2) || (x==tr->szerokosc-1)) && (kier==0) ) return 0;
                                    if(tr->pola[poz]==1) return 0;
                                                       
                                }
                     
                     }
               
               } 
     return 1;
    
}

void skopiuj_klocek(struct klocek* kl, struct tetris * tr){
     int i,j,poz,x,y;
         for(i=0;i<4;i++){
               for(j=0;j<4;j++){
                                if(kl->tab[i][j]==1){
                                                     x=kl->polozenie_lewo+i;
                                                     y=kl->polozenie_gora+j;
                                                     poz=(y-1)*tr->szerokosc + (x-1);   
                                                     tr->pola[poz]=1;
                                }
                     
                     }
               
               }
     
     
     }




void wyswietl_tab(struct tetris*tr){
     int i=0;
     for(i=0;i<tr->szerokosc*tr->wysokosc;i++)
         if(tr->pola[i]==1){
                       gotoxy(i%tr->szerokosc+1,i/tr->szerokosc+1);
                       printf("X");     
                            }
     }

void gotoxy(int x, int y)
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1 ;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
