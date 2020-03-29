/**
 * @file ExampleReceiver.h
 * @author rico luedeke
 * @brief An example implementaion of @class{IMidiInputlistener}
 * @date 2020-03-29
 * @see IMidiInputListener
 * 
  * @copyright Copyright (c) 2020 - This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef EXAMPLE_RECEIVER
#define EXAMPLE_RECEIVER

#include "rlmidi/IMidiInputListener.h"

class ExampleReceiver : public rlmidi::IMidiInputListener
{
public:

    //ctor
    ExampleReceiver();

    void onNoteOn(int keyNumber, int velocity, int midiChannel);

    void onNoteOff(int keyNumber, int velocity, int midiChannel);

    void onMidiEvent(std::vector<unsigned char> bytes);    
};

#endif
