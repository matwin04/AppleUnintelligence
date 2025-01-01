#include "avr.h"
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
AVR::AVR(const std::string& port,int baudRate){
    if (!openSerialPort(port,baudRate)){
        std::cerr<<"Failed to open serial port\n";
    }
}
AVR::~AVR(){
    if (serialPort>=0){
        close(serialPort);
    }
}

bool AVR::openSerialPort(const std::string& port,int baudRate) {
    serialPort = open(port.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (serialPort < 0) {
        std::cerr << "Error opening serial port: " << strerror(errno) << std::endl;
        return false;
    }
    return true;
}
void AVR::sendCommand(const std::string& command) {
    if (serialPort >= 0) {
        std::string cmd = command + "\r";
        std::cout << "Sending command: " << cmd << std::endl;
        write(serialPort, cmd.c_str(), cmd.length());
    } else {
        std::cerr << "Serial port not open." << std::endl;
        std::cerr << "Try running - sudo ./SerialD -  " << std::endl;
    }
}


void AVR::powerOn() {
    sendCommand("PWON");
}
void AVR::powerOff(){
    sendCommand("PWSTANDBY");
}
void AVR::powerStat(){
    sendCommand("PW?");
}
void AVR::mvUp(){
    sendCommand("MVUP");
}
void AVR::mvDown(){
    sendCommand("MVDOWN");
}
