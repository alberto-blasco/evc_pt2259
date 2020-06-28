/**
 * evc_pt2259.h - Library for using PT2259 - DIGITALLY CONTROLLED STEREO ELECTRONIC VOLUME CONTROL
 * Created by Alberto, July 1, 2020.
 */

#include "evc_pt2259.h"

#include "Arduino.h"
#include "Wire.h"

#define PT_ADDR 0x44

/**
 * Nano/UNO Board 
 * -----------------------
 * Port A5 ==> SCL (CLK)
 * Port A4 ==> SCA (Data)
 */

void pt_init() {
  delay(200);

  Wire.begin();
  Wire.beginTransmission(PT_ADDR);
  Wire.write(0xF0);
  Wire.endTransmission();
}

void pt_setAttenuation(uint8_t dB) {
  uint8_t tens = dB / 10;
  uint8_t ones = dB % 10;

  Wire.beginTransmission(PT_ADDR);
  Wire.write(0x74);
  Wire.write(0xE0 | tens);
  Wire.write(0xD0 | ones);
  Wire.endTransmission();
}

void pt_setLeftAttenuation(uint8_t dB) {
  uint8_t tens = dB / 10;
  uint8_t ones = dB % 10;

  Wire.beginTransmission(PT_ADDR);
  Wire.write(0x74);
  Wire.write(0xB0 | tens);
  Wire.write(0xA0 | ones);
  Wire.endTransmission();
}

void pt_setRightAttenuation(uint8_t dB) {
  uint8_t tens = dB / 10;
  uint8_t ones = dB % 10;

  Wire.beginTransmission(PT_ADDR);
  Wire.write(0x74);
  Wire.write(0x30 | tens);
  Wire.write(0x20 | ones);
  Wire.endTransmission();
}

void sendMuteCmd(boolean shouldMute, String channel) {
  int muteCmd = 0x74;
  if (shouldMute) {
    if (channel == "right") {
      muteCmd = muteCmd + 1;
    } else if (channel == "left") {
      muteCmd = muteCmd + 2;
    } else {
      muteCmd = muteCmd + 3;
    }
  }

  Wire.beginTransmission(PT_ADDR);
  Wire.write(muteCmd);
  Wire.endTransmission();
}

void pt_mute(bool shouldMute) {
  sendMuteCmd(shouldMute, "all");
}

void pt_rightMute(bool shouldMute) {
  sendMuteCmd(shouldMute, "right");
}

void pt_leftMute(bool shouldMute) {
  sendMuteCmd(shouldMute, "left");
}
