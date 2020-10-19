#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
using namespace std;

#define APHASE         15                // physical pin for GPIO22
//#define AENABLE_PWM1   33                // physical pin for PWM1
#define BPHASE          7                // physical pin for GPIO4
//#define BENABLE_PWM0   12                // physical pin for PWM0
#define Enable_PWM     12

int main() {                             // must be run as root
   wiringPiSetupPhys();                  // use the physical pin numbers
   pinMode(APHASE, OUTPUT);              // controls direction
   //pinMode(AENABLE_PWM1, PWM_OUTPUT);    // speed - only on RPi B+/A+/2
   pinMode(BPHASE, OUTPUT);              // controls direction
   //pinMode(BENABLE_PWM0, PWM_OUTPUT);    // PWM output used for speed
   pwmSetMode(PWM_MODE_MS);              // use a fixed frequency
   pwmSetRange(128);                     // range is 0-128
   pwmSetClock(15);                      // gives a precise 10kHz signal

   cout << "Motor A: Rotate forward at 50% for 5 seconds" << endl;
   digitalWrite(APHASE, LOW);            // notional foward
   pwmWrite(ENABLE_PWM, 64);           // duty cycle of 50% (64/128)
   usleep(5000000);

   cout << "End of Program turn off both motors" << endl;
   pwmWrite(ENABLE_PWM, 0);            // Motor B off - duty cycle of 0%
   return 0;                             // would keep going after exit
}
