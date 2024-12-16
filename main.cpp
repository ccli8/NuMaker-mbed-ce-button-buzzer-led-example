#include "mbed.h"

#if defined(TARGET_NUMAKER_PFM_NUC472)
DigitalOut    rgbled_B(LED_BLUE);       // low-active
DigitalOut    rgbled_R(LED_RED);        // low-active
DigitalOut    rgbled_G(LED_GREEN);      // low-active
DigitalOut    greenled(PG_0);           // low-active
DigitalOut    buzzer(PD_11);            // low-active
DigitalIn     button_SW1(SW1);          // press button =0
DigitalIn     button_SW2(SW2);          // press button =0
#elif defined(TARGET_NUMAKER_PFM_M453)
DigitalOut    rgbled_B(LED_BLUE);       // low-active
DigitalOut    rgbled_R(LED_RED);        // low-active
DigitalOut    rgbled_G(LED_GREEN);      // low-active
DigitalOut    greenled(PB_12);          // low-active
DigitalOut    buzzer(PE_2);             // low-active
DigitalIn     button_SW1(SW2);          // press button =0
DigitalIn     button_SW2(SW3);          // press button =0
#elif defined(TARGET_NUMAKER_PFM_M487)
DigitalOut    rgbled_B(LED_YELLOW);     // in M487, rgbled_B is yellow, not blue, low-active
DigitalOut    rgbled_R(LED_RED);        // low-active
DigitalOut    rgbled_G(LED_GREEN);      // low-active
DigitalOut    greenled(D2);             // in M487, change the pin to match real hardware, low-active
DigitalOut    buzzer(D3);               // in M487, change the pin to match real hardware, low-active
DigitalIn     button_SW1(SW2);          // in M487, button_SW1 is SW2, press button =0
DigitalIn     button_SW2(SW3);          // in M487, button_SW2 is SW3, press button =0
#elif defined(TARGET_NUMAKER_PFM_NANO130)
DigitalOut    rgbled_B(LED_YELLOW);     // in NANO130, rgbled_B is yellow, not blue, low-active
DigitalOut    rgbled_R(LED_RED);        // low-active
DigitalOut    rgbled_G(LED_GREEN);      // low-active
DigitalOut    greenled(D2);             // in NANO130, change the pin to match real hardware, low-active
DigitalOut    buzzer(D3);               // in NANO130, change the pin to match real hardware, low-active
DigitalIn     button_SW1(SW1);          // press button =0
DigitalIn     button_SW2(SW2);          // press button =0
#endif

// main() runs in its own thread in the OS
// (note the calls to Thread::wait below for d elays)
int main() {
    
    rgbled_B=1; rgbled_R=1; rgbled_G=1;
    greenled=1;
    buzzer=1;
#ifdef MBED_MAJOR_VERSION
    printf("Mbed OS version %d.%d.%d\r\n\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
#endif                      
    while (true) {
        // press SW1 will turn on greeled and RGBLED=blue
        if (button_SW1==0) {
                             greenled=0;
                             rgbled_B=0;
                           }                             
        else               {
                             greenled=1;
                             rgbled_B=1;
                           }
        // press SW2 will turn on buzzer                                  
        if (button_SW2==0) buzzer=0;
        else               buzzer=1;
    }
}
