#ifndef AVR_H
#define AVR_H

#include <string>
class AVR {
public:
    AVR(const std::string& port,int baudRate = 9600);
    ~AVR();
    void sendCommand(const std::string& command);
    //Power Commands
    void powerOn();
    void powerOff();
    void powerStat();

    //Master Volume Controls
    void mvUp();
    void mvDown();
    void mvStat();

    //Mute Controls
    void muteOn();
    void muteOff();
    void muteStat();

    //Source Selector
    void selPhono();
    void selCD();
    void selTuner();
    void selDVD();
    void selTV();
    void selVCR();
    void selDVR();
    void selVAUX();
    void selXM();
    void selIPod();
    void selAUX();
    void inputStatus();
private:
     int serialPort;
    bool openSerialPort(const std::string& port, int baudRate);
    
};
#endif //AVR_H