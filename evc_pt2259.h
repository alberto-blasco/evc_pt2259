/**
 * evc_pt2259.h - Library for using PT2259 - DIGITALLY CONTROLLED STEREO ELECTRONIC VOLUME CONTROL
 * Created by Alberto, July 1, 2020.
 */

#ifndef evc_pt2259_h
#define evc_pt2259_h

#include "Arduino.h"

void pt_init();
void pt_setAttenuation(uint8_t dB);
void pt_setLeftAttenuation(uint8_t dB);
void pt_setRightAttenuation(uint8_t dB);
void pt_mute(bool shouldMute);
void pt_rightMute(bool shouldMute);
void pt_leftMute(bool shouldMute);

#endif