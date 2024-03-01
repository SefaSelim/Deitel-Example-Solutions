#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52


void shuffle (unsigned int wDeck[][FACES]);
void deal (unsigned int wDeck[][FACES],const char *wFace[],
const char *wSuit[]);



           int main(void){

           unsigned int deck [SUITS][FACES] = {0};

           srand(time(NULL));




           const char *suit[SUITS]=
           {"Hearts","Diamonds","Clubs","Spades"};

           const char *face[FACES] = {
           "Ace","Deuce","Three","Four","Five","Six",
           "Seven","Eight","Nine","Ten","Jack","Queen","King"
           };

   // deal(deck,face,suit);



    shuffle(deck);


deal (deck,face,suit);


           }

           void shuffle(unsigned int wDeck[][FACES]){

               int irand,jrand,temp,n=0;

                  for (int i = 0 ; i<FACES;i++)
           {
               for (int j = 0; j<SUITS;j++)
               {
                    wDeck[i][j]=++n;
               } }


           for (int i = 0 ; i<FACES;i++)
           {
               for (int j = 0; j<SUITS;j++)
               {
                   irand = rand()%FACES;
                   jrand = rand()%SUITS;

                   temp = wDeck[i][j];
                    wDeck[i][j] = wDeck[irand][jrand];
                    wDeck[irand][jrand] = temp;

               } } }

void deal(unsigned int wDeck[][FACES],const char *wFace[],const char *wSuit[])
{

int check;

        for (int i = 0 ; i<FACES;i++)
           {
               for (int j = 0; j<SUITS;j++)
               {
                    check =    wDeck[i][j];

                    printf("%s of %s        ",wFace[check%FACES],wSuit[(check-1)/FACES]);

               }
               printf("\n");
                }


    return 0;
}



