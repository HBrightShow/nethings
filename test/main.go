package main


import(
	"fmt"
	"net"
	"unsafe"
	"time"
	"bytes"
	"encoding/binary"
	//"github.com/deckarep/golang-set"
)

type  msg_header struct {
	startFlag 		uint8
	equipId  		uint8
	msgType  		uint8
	dataLen   		uint16
}

//断头、弱捻、空置、停用 共用一个定义
type data_flag struct {
	header  	 msg_header
	actualLen   uint64
	flagData    [300]byte
}

type spindle_speed struct {
	header 			msg_header 
	spinStart		uint64
	speeds  	 	[600]uint16
}

func construct_spindleSpeed_msg() *spindle_speed {
	var sp spindle_speed
	
	sp.header.startFlag = 0xff
	sp.header.equipId = 102
	sp.header.msgType = 5
	
	sp.header.dataLen = 10
	sp.spinStart = 100

	var i uint16
	for i=0;i< 600; i++ {
		sp.speeds[i] = 'a'
	}

	return &sp
}

func construct_decapitation_msg() *data_flag {
	var df data_flag
	
	df.header.startFlag = 0xff
	df.header.equipId = 102
	df.header.msgType = 1
	df.header.dataLen = 300
	df.actualLen = 80

	var i uint16
	for i = 0; i < 80; i++ {
		df.flagData[i] = 'd'
	}

	return &df
}

func construct_weaktwist_msg() *data_flag {
	var df data_flag
	
	df.header.startFlag = 0xff
	df.header.equipId = 102
	df.header.msgType = 2
	df.header.dataLen = 300
	df.actualLen = 50

	var i uint16
	for i = 0; i < 50; i++ {
		df.flagData[i] = 'w'
	}

	return &df
}

func  Encode(obj interface{})([]byte, error) {
	buf := new(bytes.Buffer)
	if err := binary.Write(buf, binary.LittleEndian, obj); err != nil {
		return nil, err
	}

	return buf.Bytes(), nil
}

func send_spindeSpeed(conn net.Conn) {
	for {
		sp := construct_spindleSpeed_msg()
		fmt.Println("spindeSpeed data length: ", unsafe.Sizeof(*sp))

		data, err := Encode(sp);
		if err != nil {
			break;
		}

		send_len, err := conn.Write(data) // 发送数据
		fmt.Println("send spindeSpeed data length: ", send_len)

		if err != nil {
			return
		}

		time.Sleep(time.Duration(1)*time.Second)
	}
}

func send_decapitation_msg(conn net.Conn) {
	for {
		sp := construct_decapitation_msg()
		fmt.Println("decapitation data length: ", unsafe.Sizeof(*sp))

		data, err := Encode(sp);
		if err != nil {
			break;
		}

		send_len, err := conn.Write(data) // 发送数据
		fmt.Println("send decapitation data length: ", send_len)

		if err != nil {
			return
		}

		time.Sleep(time.Duration(2)*time.Second)
	}
}

func send_weaktwist_msg(conn net.Conn) {
	for {
		sp := construct_weaktwist_msg()
		fmt.Println("weaktwist data length: ", unsafe.Sizeof(*sp))

		data, err := Encode(sp);
		if err != nil {
			break;
		}

		send_len, err := conn.Write(data) // 发送数据
		fmt.Println("send weaktwist data length: ", send_len)

		if err != nil {
			return
		}

		time.Sleep(time.Duration(3)*time.Second)
	}
}

func recv_data(conn net.Conn) {

	buf := [512]byte{}
	for {

		recv_len, err := conn.Read(buf[:])
		fmt.Println("recv data length = ", recv_len)

		if err != nil {
			fmt.Println("recv failed, err:", err)
			return
		}
		fmt.Println("recv data: ", string(buf[:recv_len - 1 ]))
	}
}

func main() {
	conn,err := net.Dial("tcp", "192.168.2.65:6666")
	fmt.Printf("%T", conn)
	if err != nil{
		fmt.Println("err: ", err)
		return
	}

	defer conn.Close()

	go recv_data(conn)
	go send_spindeSpeed(conn)
	go send_decapitation_msg(conn)
	go send_weaktwist_msg(conn)

	time.Sleep(time.Duration(6000)*time.Second)
}
