/**
 * @file ExampleReceiver.cpp
 * @author rico luedeke
 * @see ExampleReceiver.h
 * @date 2020-03-29
 * 
 * 
  * @copyright Copyright (c) 2020 - This code is licensed under MIT license (see LICENSE.txt for details)
 */

#include "ExampleReceiver.h"

#include <iostream> // cout

ExampleReceiver::ExampleReceiver()
{
    
}

void ExampleReceiver::onNoteOn(int keyNumber, int velocity, int midiChannel)
{
    std::cout   << "ExampleReceiver::onNoteOn: keyNumber " << keyNumber 
                << " velocity: " << velocity 
                << " channel: " << midiChannel 
                << std::endl;
}

void ExampleReceiver::onNoteOff(int keyNumber, int velocity, int midiChannel)
{
    std::cout   << "ExampleReceiver::onNoteOff: keyNumber " << keyNumber 
                << " velocity: " << velocity 
                << " channel: " << midiChannel 
                << std::endl;
}

void ExampleReceiver::onMidiEvent(std::vector<unsigned char> bytes)
{
    std::cout << "ExampleReceiver::onMidiEvent: ";

    for ( int i = 0; i < bytes.size(); i++ )
      std::cout << "Byte " << i << " = " << (int)bytes[i] << ", ";

    std::cout << std::endl;
    
}
