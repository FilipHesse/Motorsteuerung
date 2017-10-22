#include <iostream>
#include "Motor.h"
#include "c_InputHandler.h"
#include <cstdio>
#include <memory>

int main()
{
    auto Motor = std::make_shared<c_Motor>();
    c_IOHandler IOHandler( Motor );

    IOHandler.WriteHeader();

    while (true)
    {
        if ( IOHandler.HandleInputs() == -1 )
            break;

        if ( Motor->Run() == 1)
        {
            std::cout<<"Motor.Run() went wrong"<<std::endl;
            return 0;
        }


    }

    return 0;
}
