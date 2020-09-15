#include "mbed.h"
#define dp23 P0_0
 
BusOut prikaz1(dp26,dp25,dp24,dp23);
BusOut prikaz2(dp28,dp6,dp5,dp27);
 
DigitalOut enable(dp14);
DigitalIn taster(dp1);
 
const float T(0.2);
int brojac1(0);
int brojac2(0);
 
int main()
{
    enable=0;
    prikaz1=brojac1;
    prikaz2=brojac2;
 
    while(1) {
        wait(T);
        brojac1=(brojac1+1)%16;
        if (taster) brojac2=(brojac2+1)%16;
 
        prikaz1=brojac1;
        prikaz2=brojac2;
 
    }
}