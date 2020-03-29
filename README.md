# rl-midi
An C++ example on how to receive midi event based using the rt midi library.

## Prerequisites
**Midi-Controller**: A midi controller should be connected to your hardware.

**rtmidi:** This example uses the rtmidi library. Go visit https://www.music.mcgill.ca/~gary/rtmidi/ for further information. Download sources and follow the instactions for CMAKE and MAKE.

**gcc:** The software is written in C++. GCC should be suitable for compilation

**cmake:** The project uses cmake (version 3.5 or higher)

## Build and run on Linux
- Download/clown repository
- Enter "src" directory
- Run cmake
- Run make
After successful compilation you'll find the executable in the "bin"-folder.

```
cd src
cmake . 
make .
cd bin/
./rtmidi
```

## Donate
[![Donate](https://www.paypalobjects.com/en_US/DK/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=Q9WVFA67Q6RYJ)
