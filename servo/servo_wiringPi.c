#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define PIN 1
int main(){
	if(wiringPiSetup() == -1)
		return 1;

	pinMode(PIN, PWM_OUTPUT);

	softPwmCreate(PIN, 0, 200);
	softPwmWrite(PIN, 5);
	delay(1000);
	softPwmWrite(PIN, 25);
	delay(1000);

	return 0;
}
