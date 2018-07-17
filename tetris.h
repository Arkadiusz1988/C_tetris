#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include  <math.h>
#include <windows.h> 
#include "klocek.h"



# ifndef tetris_h
# define tetris_h



struct tetris{
       struct klocek* tab_kl;
       int ile_klockow;
       int wysokosc;
       int szerokosc;
       int* pola;
       int punkty;
       
       };       
void wyswietl_tetris(struct tetris* t);
void utworz_klocek( int rodzaj,struct tetris* t);
void utworz_tetris(struct tetris* t, int wysokosc, int szerokosc);
void usun_pelny(struct tetris* t);
int czy_wiersz_pelny(struct tetris* t, int i);
 void usun_wiersz(struct tetris* t, int i);
 void krok(struct tetris* t);
 void wyswietl(struct tetris* t);
 void ramka(struct tetris* t);
 void gotoxy(int x, int y);
 void kolizja(struct tetris * tr);
void obroc_lewo(struct tetris* tr);
void obroc_prawo(struct tetris* tr);
void przesun_lewo(struct tetris* tr);
void przesun_prawo(struct tetris* tr);
void wyswietl_tab(struct tetris*tr);
void ruch(struct tetris*tr);


#endif
