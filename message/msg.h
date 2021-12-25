
#ifndef _NETHINGS_MESAGE_H
#define _NETHINGS_MESAGE_H
#include<iostream>
#include<vector>
#include<bitset>





// 
enum msg_arm_type{
    MSG_ARM_START = 0,
    MSG_ARM_EQUIP_STATUS,   //设备状态
    MSG_ARM_DECOLLATION,    //断头
    MSG_ARM_WEAK_TWIST,     //弱捻
    MSG_ARM_VACANT,         //空置
    MSG_ARM_DDACTIVATE ,    //5  停用
    MSG_SPINDLE_SPEED,      //锭子速度

    MSG_ARM_END = 100
};

typedef struct stTime{
    unsigned char m_hour;
    unsigned char m_min;
    unsigned char m_second;
};


//define base message from arm machine
class MsgBase{
    public:
        MsgBase();
        ~MsgBase();

    public:

        unsigned char m_start;   //开始位: oxff
        unsigned char m_EquipId;  //设备id
        unsigned char m_spin;   //起始锭号,已弃用
        unsigned char  m_type; //消息类型
        unsigned char m_length;     //实际数据长度 
        unsigned short m_crc;       //校验位

        //std::vector<unsigned char> m_data;
        
};

//设备运行状态
class Machine : public MsgBase  {
    
    public:
        Machine(){} = default;
        ~Machine() = default;

    public:
        unsigned char m_status;  //设备运行状态
        unsigned short m_schedule;  //设备运行进度
        stTime m_run;       //运行时间
        stTime m_doffing;   //落纱倒记时
        unsigned short m_doffingLen;    //当落纱的纺纱长度
        unsigned short m_doffingSpeed;  //落拉速度
        unsigned short m_avgSpeed;      //平均速度
        unsigned short m_decollationQuantity;   //实时断头数量
        unsigned short m_weakQuantity;      //实时弱捻数量  
        unsigned short m_deactiveateQuantity;   //实时停用数量
        unsigned short m_vacantQuantity;        //实时空置数量



};


//断头标志位
class Decollation : public MsgBase{

    public:
        Decollation() = default;
        ~Decollation() = default;
    
    public:
        std::string m_status;   //断头位
};

//锭子速度
class SpindleSpeed : public MsgBase {
    public:
        SpindleSpeed() = default;
        ~SpindleSpeed() = default;

    public:
        std::vector<unsigned short> m_speed; //两个字节代表一锭，高字节在前
};


#endif