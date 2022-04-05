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

type  msg_header struct{
	start_flag uint8
	equip_id  uint8
	msg_type  uint8
	spin      uint8
	data_len   uint8
}


type spindleSpeed struct{
	header msg_header
	//speed  mapset.Set 
	speeds   [100]uint16
}


func construct_spindleSpeed_msg() *spindleSpeed {
	var sp spindleSpeed
	
	sp.header.start_flag = 0xff
	sp.header.equip_id = 102
	sp.header.msg_type = 5
	sp.header.spin = 0
	sp.header.data_len = 10
	//sp.speed = mapset.NewSet(14,25,36,45,78)
	var i uint16
	for i=0;i< 100; i++ {
		sp.speeds[i] = 'a'
	}

	return &sp
}

func (obj *spindleSpeed) Encode()([]byte, error) {
	buf := new(bytes.Buffer)
	if err := binary.Write(buf, binary.LittleEndian, obj); err != nil {
		return nil, err
	}

	return buf.Bytes(), nil
}


func main() {
	conn,err := net.Dial("tcp", "192.168.2.65:6666")
	if err != nil{
		fmt.Println("err: ", err)
		return
	}

	defer conn.Close()


	for {
	
		sp := construct_spindleSpeed_msg()
	

		fmt.Println("data length: ", unsafe.Sizeof(*sp))

		fmt.Println("1+++++++++++++++")

		data, err := sp.Encode();
		if err != nil {
			fmt.Println("2+++++++++++++++")
			break;
		}
		fmt.Println("3+++++++++++++++")
		send_len, err := conn.Write(data) // 发送数据
		fmt.Println("send data length: ", send_len)

		if err != nil {
			return
		}

		buf := [512]byte{}
		recv_len, err := conn.Read(buf[:])
		fmt.Println("recv data length = ", recv_len)

		if err != nil {
			fmt.Println("recv failed, err:", err)
			return
		}
		fmt.Println("recv data: ", string(buf[:recv_len - 1 ]))

		time.Sleep(time.Duration(60)*time.Second)

	}
}
