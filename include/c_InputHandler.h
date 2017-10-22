#ifndef C_INPUTHANDLER_H
#define C_INPUTHANDLER_H
#include<memory>
#include "Motor.h"

class c_IOHandler
{
    public:
        c_IOHandler(std::shared_ptr<c_Motor> motor);
        virtual ~c_IOHandler();
        void WriteHeader();
        int HandleInputs();
    protected:
    private:
        std::shared_ptr<c_Motor> m_Motor;
};

#endif // C_INPUTHANDLER_H
