#include "msg.h"


MsgBase::MsgBase() {
    m_type = msg_arm_type::MSG_ARM_START;
    m_content.reserve(100);
    
}

MsgBase::~MsgBase() {

}
