
#ifndef _NETHINGS_MESAGE_H
#define _NETHINGS_MESAGE_H
#include<iostream>
#include<vector>





enum class msg_arm_type{
    MSG_ARM_START = 0,

    MSG_ARM_END = 100
};




//define base message from arm machine
class MsgBase{
    public:
        MsgBase();
        ~MsgBase();

    public:
    enum class::msg_arm_type  m_type;
    uint32_t m_nlength;
    std::vector<char> m_content;
    










};



#endif