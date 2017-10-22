#include <iostream>
#include "Motor.h"
#include <wiringPi.h>
#include <softPwm.h>


// CONSTANTS
const int c_Motor::m_OutPWM       = 0;
const int c_Motor::m_OutNegDir    = 1;
const int c_Motor::m_OutPosDir    = 2;


c_Motor::c_Motor()
{
    InitializePWM();
}

c_Motor::~c_Motor()
{
    Shutdown();
}

/**
*   @brief Initializes WiringPi and PWM
*/
int c_Motor::InitializePWM()
{
    if (wiringPiSetup() == -1)
    {
        std::cout<<"WiringPiSetup went wrong"<<std::endl;
        return 1;
    }

    pinMode( m_OutPWM,       OUTPUT );
    pinMode( m_OutNegDir,    OUTPUT );
    pinMode( m_OutPosDir,    OUTPUT );

    digitalWrite( m_OutPWM,      LOW );
    digitalWrite( m_OutNegDir,   HIGH );
    digitalWrite( m_OutPosDir,   LOW );

    if (softPwmCreate( m_OutPWM, 0, 100 ) == -1  )
    {
        std::cout<<"softPwmCreate went wrong"<<std::endl;
        return 1;
    }
    return 0;
}

int c_Motor::Shutdown()
{
    digitalWrite( m_OutPWM,      LOW );
    digitalWrite( m_OutNegDir,   LOW );
    digitalWrite( m_OutPosDir,   LOW );
}

void c_Motor::ChangePWMVal(int val)
{
    m_PWM_VALUE = val;
}


/**
*   @brief Runs Motor
*/
int c_Motor::Run()
{
    softPwmWrite(m_OutPWM, m_PWM_VALUE);
    return 0;
}
