#include "mbed.h"

DigitalOut led_time(LED3);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalIn button(BUTTON1);

Thread led_thread;

// to calculate time
void led_blink() {
    while (1) {
        led_time = !led_time;
        ThisThread::sleep_for(3s);
    }
}
int main() {
    int count = 0;

    led_thread.start(led_blink);

    while (1) {
            led1 = 0;
            led2 = 0;
            count = 0;
            // to see the count in the 3s
            for (int i = 0; i < 30; i++) {
                if (button == 0) count++;
                else count = count;
                wait_us(100000);  
            } 
            if (count > 3) {
                led1 = 1; 
                led2 = 0;
                printf("1\n\r");
            }
            else {
                led2 = 1;
                led1 = 0;
                printf("0\n\r");
            }  
    }
    
}
