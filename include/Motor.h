#ifndef MOTOR_H
#define MOTOR_H


class c_Motor
{
    public:
        c_Motor();
        virtual ~c_Motor();
        int InitializePWM();
        int Run();
        int Shutdown();
        void ChangePWMVal(int val);
    protected:
    private:
        static const int m_OutPWM;
        static const int m_OutPosDir;
        static const int m_OutNegDir;
        int m_PWM_VALUE = 0;
};

#endif // MOTOR_H
