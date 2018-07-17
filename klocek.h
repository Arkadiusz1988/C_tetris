# ifndef klocek_h
# define klocek_h


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include  <math.h>
#include <windows.h>




struct klocek {
       int polozenie_gora;
       int polozenie_lewo;     
       int ruch;
       int tab[4][4];
       };
      
void zeruj_klocek(struct klocek* kl);
void wyswietl_klocek(struct klocek* kl, struct tetris* t);
void kolizja_klocek(struct klocek* kl, struct tetris * tr);
int czy_kl_poza_granicami(struct klocek* kl, struct tetris *tr,int kier);
void skopiuj_klocek(struct klocek* kl, struct tetris * tr);
       
#endif
