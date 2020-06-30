/**
 * Example for using evc_pt2259 library in Arduino
 * The sketch starts initiating the EVC
 * Then, it fades the audio, and after that it mutes the different channels.
 * 
 * Created by Alberto, July 1, 2020.
 */

#include "evc_pt2259.h"

void setup() {
  pt_init();
}

void loop() {
  // Fade IN
  for (int i = 79; i >= 0; i--) {
    pt_setAttenuation(i);
    delay(200);
  }
  
  // Fade OUT
  for (int i = 0; i < 80; i++) {
    pt_setAttenuation(i);
    delay(200);
  }

  pt_mute(false);
  pt_setAttenuation(10);
  delay(2500);

  // Mute all
  pt_mute(true);
  delay(2500);

  // Mute left
  pt_leftMute(true);
  delay(2500);

  // Mute right
  pt_rightMute(true);
  delay(2500);

  // Unmute all
  pt_mute(false);
}
