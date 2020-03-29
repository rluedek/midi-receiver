/**
 * @file main.cpp
 * @author rico luedeke
 * @brief Main programfor example usage
 * @date 2020-03-29
 * 
 * @copyright Copyright (c) 2020 - This code is licensed under MIT license (see LICENSE.txt for details)
 */

#include "rlmidi/MidiIn.h"
#include "rlmidi/IMidiInputListener.h"
#include "rlmidi/MidiChannelSelection.h"

#include "ExampleReceiver.h"

#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    std::string input;
    unsigned int portNumber;

    // create an instance of the midi event class
    rlmidi::MidiIn midiIn;

    // create a receiver that is able to receive midi events
    std::shared_ptr<rlmidi::IMidiInputListener> receiver = std::make_shared<ExampleReceiver>();

    // register receiver to midi input instance and wait for call backs
    midiIn.setInputListener(receiver);

    std::cout << "Midi Listener Example:" << std::endl << std::endl
    << "Usage:" << std::endl
    << "Type <Number> to change Midi-Port." << std::endl
    << "Crtl-C to exit program." << std::endl << std::endl;

    while (true)
    {
        std::cin >> input;

        try
        {
            portNumber = std::stoi(input);
            midiIn.runMonitoring(portNumber, MIDICHANNEL_ALL);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }

    }

    std::cout << std::endl << "Example ended...\n\n";

    return 0;
}