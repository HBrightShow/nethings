#include "msg.h"


MsgBase::MsgBase() {
    m_type = MSG_ARM_START;
    m_data.reserve(512);
    
}

MsgBase::~MsgBase() {

}
