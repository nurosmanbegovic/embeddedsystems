#include "mbed.h"
#define dp23 P0_0


BusOut diode(dp26, dp27, dp5, dp6, dp28, dp4, dp18);

DigitalOut D2 (dp23);
DigitalOut D3 (dp24);
DigitalOut D4 (dp25);
DigitalOut enable (dp14);

DigitalIn taster1(dp1);
DigitalIn taster2(dp2);

int c[] = {64,121,36,48,25,18,2,120,0,16};



void ispisicifru(int poz, int cifra){
    if(poz==1) D4=0;
    else if(poz==2) D3=0;
    else if(poz==3) D2=0;
    
    if(cifra==0) diode=64;
    else if(cifra==1) diode=121;
    else if(cifra==2) diode=36;
    else if(cifra==3) diode=48;
    else if(cifra==4) diode=25;
    else if(cifra==5) diode=18;
    else if(cifra==6) diode=2;
    else if(cifra==7) diode=120;
    else if(cifra==8) diode=0;
        else if(cifra==9) diode=16;
        wait(0.001);
diode=127;
D4=D3=D2=1;
}

int main() {
    enable = 1;
    diode=127;
    int i(0);
    int cjedinica, cdesetica, cstotica;
    int pom=0, pom1=0;
    D2=D3=D4=1;
    ispisicifru(1,127);
    wait(0.005);
    ispisicifru(2,127);
    wait(0.005);
    ispisicifru(3,127);
    wait(0.005);
    while(1) {
        if(taster1 && !pom){
            if(i==999) i=0;
            else i++;
            pom=1;
            }
   else if(pom && !taster1) pom=0;
    else if(taster2 && !pom1){
        if(i==0) i=999;
        else i--;
        pom1=1;
        }
    else if(pom1 && !taster2) pom1=0;
    cjedinica=i%10;
    ispisicifru(1,cjedinica);
    cdesetica= (i/10)%10;
    ispisicifru(2, cdesetica);
    cstotica=(i/100)%10;
    ispisicifru(3, cstotica);


    }
    }