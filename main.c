#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include  <math.h>
#include <windows.h> 
#include "tetris.h"
#include "klocek.h"      

int main(){
     struct tetris* tr;
     tr=(struct tetris*) malloc(sizeof(struct tetris));
     
     utworz_tetris(tr,30,20);
     
     int gra;
     gra=0;
     char pom, key;
          utworz_klocek(4,tr);  
     
     do{
          if(kbhit()){         
                                key=getch(); 
                                }
          else{
              key='q';
               }
switch(key){
                      case 'w': obroc_prawo(tr);
                      break;
                      case 's': obroc_lewo(tr);
                      break;
                      case 'a': przesun_lewo(tr);
                      break;
                      case 'd': przesun_prawo(tr);
                      break;
                      
                      }
          sleep(500);
          krok(tr);

          wyswietl_tetris(tr);

          kolizja(tr);
          usun_pelny(tr);
          

          }while(gra==0);
          
         

     }
