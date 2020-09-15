#include "mbed.h"
#define dp23 P0_0

DigitalOut enable(dp14);
DigitalOut red1(dp16);
DigitalOut red2(dp15);
DigitalOut red3(dp17);
DigitalOut red4(dp18);

DigitalIn kol1(dp9);
DigitalIn kol2(dp10);
DigitalIn kol3(dp11);
DigitalIn kol4(dp13);

BusOut diode(dp28, dp6, dp5, dp27, dp26, dp25, dp24, dp23);


int main() {
    enable=0;
    diode=255;
    
    while(1) {
        red1=1;
        wait(0.005);
        if(kol1) {
            while(kol1) diode=255-1;}
        else if(kol2){
            while(kol2) diode=255-2;}
        else if(kol3){
            while(kol3) diode=255-4;}
        red1=0;
        red2=1;
        wait(0.005);
        if(kol1) {
            while(kol1) diode=255-8;}
        else if(kol2){
            while(kol2) diode=255-16;}
        else if(kol3){
            while(kol3) diode=255-32;}
        red2=0;
        red3=1;
        if(kol1) {
            while(kol1) diode=255-64;}
        else if(kol2) {
            while(kol2) diode=255-128;}
        red3=0;
        diode=255;
    }
}
