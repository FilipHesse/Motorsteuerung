#include "c_InputHandler.h"
#include <string>
#include <iostream>

c_IOHandler::c_IOHandler(std::shared_ptr<c_Motor> motor)
: m_Motor(motor)
{
    //ctor
}

c_IOHandler::~c_IOHandler()
{
    //dtor
}

int c_IOHandler::HandleInputs()
{
    std::string c("");
    std::cin>>c;

    int newPWM;

    try
    {
        newPWM = std::stoi(c);
        m_Motor->ChangePWMVal(newPWM);
    }
    catch( std::invalid_argument )
    {
        if (c=="end")
        {
            return -1;
        }
        else
        {
            std::cout<<"Invalid entry";
        }

    }
}

void c_IOHandler::WriteHeader()
{
    std::cout<<"==========================================="<<std::endl;
    std::cout<<"==   MOTORSTEUERUNG"<<std::endl<<"=="<<std::endl;
    std::cout<<"==   Befehle:"<<std::endl;
    std::cout<<"==   - Zum Verändern der PWM-Pulsdauer eine Zahl zwischen 0 und 100 eingeben"<<std::endl;
    std::cout<<"==   - Beenden: end"<<std::endl<<"=="<<std::endl;
    std::cout<<"==========================================="<<std::endl;
}
