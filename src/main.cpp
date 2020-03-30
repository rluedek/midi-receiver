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
#include "rlmidi/MidiDevice.h"

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
    << "Type \"list\" to change Midi-Port." << std::endl
    << "Crtl-C or \"exit\" to exit program." << std::endl << std::endl;

    while (true)
    {
        std::cout << "Enter command: ";
        std::cin >> input;

        if (input == "list")
        {
            // list all available devices
            std::vector<rlmidi::MidiDevice> devices;
            midiIn.listDevices(devices);
            if (devices.size() > 0)
            {
                std::cout << "Available midi input devices: " << std::endl;
                for (int i = 0; i < devices.size(); i++)
                {
                    std::cout << "Port: " << devices[i].getPortNumber() << " Name: " << devices[i].getPortName() << std::endl;
                }
            }
        }
        else if (input == "exit")
        {
            std::cout << "Programm has ended..." << std::endl;
            return 0;
        }
        else
        {
            try
            {
                portNumber = std::stoi(input);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                continue;
            }

            std::cout << "Monitoring all midi channels on port " << input << std::endl;
            midiIn.runMonitoring(portNumber, MIDICHANNEL_ALL);
        }
    }

    return 0;
}