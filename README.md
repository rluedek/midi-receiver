# midi-receiver
A C++ example and wrapper interface to receive midi event based using the rt midi library.

## Prerequisites
**Midi-Controller**: A midi controller should be connected to your hardware.

**rtmidi:** This example uses the rtmidi library. Go visit https://www.music.mcgill.ca/~gary/rtmidi/ from @thestk/rtmidi for further information. Download sources and follow the instructions for CMAKE and MAKE.

**cmake:** The project uses cmake (version 3.5 or higher)

## Build and run on Linux
- Download/clone repository
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
