#include "mbed.h"
# define dp23 P0_0
#include "stdio.h"
#include "SPI_TFT_ILI9341.h"
#include "string"
#include "Arial12x12.h"
//#include "Arial24x23.h"
//#include "Arial28x28.h"
#include "font_big.h"


SPI_TFT_ILI9341 TFT ( dp2 , dp1 , dp6 , dp24 , dp23 , dp25 ," TFT ");
// mosi , miso , sclk , cs , reset , dc

AnalogIn ain(dp9);
DigitalOut enable(dp14);

float ocitajN(){
    return ain.read()*3300;
}

float ocitajT(){
    return ain.read()*330;
}

int pikseli(float temperatura){
    int pix;
    int a=(int)temperatura;
    int c1=a/10;
    int c2=a%10;
    int c22=c2*10;
    float b=temperatura-a;
    if(c1==2){
    pix=30+c22+(int)(b*10);}
    else if(c1==3){
        pix=130+c22+int(b*10);}
    
   
    return pix;
}
int main () {
    enable = 1;
    int t =0;
    // Inicijalizacija ;
    TFT . claim ( stdout );
    TFT . set_orientation (1);
    TFT . background ( White );
    TFT . foreground ( Black );
    TFT . cls ();
    TFT . set_font (( unsigned char *) Arial12x12);
    float napon, temperatura;
  //  int x=20; int y=30;
        while (1) {
             napon = ocitajN();
             temperatura = ocitajT();

            TFT.locate(320/2,240-12);
            printf("Napon:%fmV",napon);
            TFT.locate(320/2,240-26);
            printf("Temp:%fC",temperatura);
            TFT.locate(320/2,240-40);
            printf("Vrijeme:%fsec",t);
            TFT.line(20,30,20,230,Black);
            TFT.line(20,30,320,30,Black);

            TFT.locate(20,30);printf("20");
            TFT.locate(20,130);printf("30");
            TFT.locate(20,230);printf("40");

            TFT.circle(20+t,pikseli(temperatura),2,Black);

            int x=20; int y=30;

            TFT.line(x,y,20+t,pikseli(temperatura),Red);
            x=20+t; y=pikseli(temperatura);

            wait(1); 
            t++;
        }
}




/*#include "mbed.h"
#include "lpc1114etf.h"
#include "stdio.h"
#include "SPI_TFT_ILI9341.h"
#include "string"
#include "Arial12x12.h"
//#include "Arial24x23.h"
//#include "Arial28x28.h"
#include "font_big.h"

SPI_TFT_ILI9341 lcd(dp2,dp1,dp6,dp24,dp23,dp25,"TFT");
AnalogIn senzor(dp9);
DigitalOut enable(dp14);

int main()
{
    enable=1;
     //lcd.claim(stdout);
     lcd.set_orientation(1);
     lcd.background(Blue);
     lcd.foreground(White);
     lcd.set_font((unsigned char*) Arial12x12);
     lcd.cls();
     float srednji=0;
     int vrijeme=0;
     char buffer[5];
     while(1) {
         lcd.locate(10,10);
         lcd.pixel(10,10,Red);
     }
     
}*/

