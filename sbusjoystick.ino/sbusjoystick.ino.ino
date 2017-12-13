#include <Joystick.h>
#include <SBUS.h>

#define SBUS_MIN 180
#define SBUS_MAX 1800

#define JS_MIN -127
#define JS_MAX 128

SBUS sbus(Serial1);
Joystick_ Joystick;

void setup() {
  Serial.begin(115200);

  // Initialize Joystick Library
  sbus.begin(false);

  Joystick.setXAxisRange(JS_MIN, JS_MAX);
  Joystick.setYAxisRange(JS_MIN, JS_MAX);
  Joystick.setZAxisRange(JS_MIN, JS_MAX);
  Joystick.setThrottleRange(JS_MIN, JS_MAX);
  Joystick.setRudderRange(JS_MIN, JS_MAX);
  
  Joystick.begin(false);
}

void loop() {

  sbus.process();

  int channels[16];

  for (int i=1; i<=16; i++) {
    //Serial.print("CH" + String(i) + ": " + sbus.getChannel(i));
    channels[i]=map(sbus.getChannel(i), SBUS_MIN, SBUS_MAX, JS_MIN, JS_MAX);
  }
  //Serial.println();

  Joystick.setXAxis(channels[1]);
  Joystick.setYAxis(channels[2]);
  Joystick.setZAxis(channels[4]);

  Joystick.setThrottle(channels[3]);
  Joystick.setRudder(channels[4]);

  for (int i=4; i<16; i++) {
    if (channels[i] > 0) {
      Joystick.pressButton(i-4);
    } else {
      Joystick.releaseButton(i-4);
    }
  }
  Joystick.sendState();
}

