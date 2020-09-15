#include "mbed.h"
#define dp23 P0_0

int brojevi[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};
DigitalOut enable(dp14);
DigitalOut cifra1 (dp25);
DigitalOut cifra2 (dp24);
DigitalOut cifra3 (dp23);
BusOut display (dp26, dp27, dp5, dp6, dp28, dp4, dp18);
DigitalOut dp(dp17);
InterruptIn taster1 (dp1);
InterruptIn taster2 (dp2);
Timer timer;
Ticker osvjezi;
Timer provjera;
int stop=0, broji=0;

void IspisiBroj() {
    int broj=timer.read()*10;
    cifra1=1;
    cifra2=1;
    cifra3=1;
    if (broji==0) {
        cifra1=0; //aktiviramo samo prvu cifru
        display=127-brojevi[broj%10];
        dp=1;
        broji=1;
    }    
    else if (broji==1) {
        broj/=10;
        cifra2=0; //aktiviramo samo drugu cifru
        dp=0;
        display=127-brojevi[broj%10];
        broji=2;
    }
    else {
        broj/=100;
        cifra3=0; //aktiviramo samo treću cifru
        dp=1;
        display=127-brojevi[broj];
        broji=0;
    }
}

void Resetuj() {
    provjera.start();
    if (provjera.read_ms()>200) {
    provjera.reset();
    provjera.stop();
    timer.stop();
    timer.reset();
    }
}
void PocniZavrsiBrojanje () {
    provjera.start();
    if (provjera.read_ms()>200) {
    provjera.reset();
    provjera.stop();
    if (stop==0) {
        stop=1;
        timer.start();
        }
    else if (stop==1) {
        stop=0;
        timer.stop();
        }
    }     
}
int main() {
    //kod koji slijedi je inicijaliziranje displaya da prikazuje 00.0 na početku
    enable=1;
    osvjezi.attach(IspisiBroj, 0.0033);
    taster1.rise(&PocniZavrsiBrojanje);
    taster2.rise(&Resetuj);
    while (1) {
        
    }
}