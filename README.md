# evc_pt2259
Arduino library for using PT2259 - DIGITALLY CONTROLLED STEREO ELECTRONIC VOLUME CONTROL

Connect the EVC to the corresponding pins of your Arduino (Nano use same pins than Uno): 
https://www.arduino.cc/en/reference/wire

## Initialization
Call `pt_init()` before any other method to initalize the EVC.

## API
Attenuation is passed as **unsigned int** so you should pass a value between 0 (0dB) and 79 (-79dB).

- `void pt_init();`  
Start the I2C communication  
Call this on setup(); to ensure a reliable initialization, this will delay for 200ms.

- `void pt_setAttenuation(uint8_t dB);`  
Set the attenuation on both channels (between 0dB and -79dB)

- `void pt_setLeftAttenuation(uint8_t dB);`  
Set the attenuation on the left channel (between 0dB and -79dB)

- `void pt_setRightAttenuation(uint8_t dB);`  
Set the attenuation on the right channel (between 0dB and -79dB)

- `void pt_mute(bool shouldMute);`  
Set muted/unmuted state in both channels

- `void pt_rightMute(bool shouldMute);`
Set muted/unmuted state in right channel

- `void pt_leftMute(bool shouldMute);`
Set muted/unmuted state in left channel