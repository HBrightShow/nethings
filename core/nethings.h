#ifndef XIAOZHONG_NETHINGS_H
#define XIAOZHONG_NETHINGS_H

#include "muduo/net/TcpServer.h"

// RFC 862
class NethingsServer
{
 public:
  NethingsServer(muduo::net::EventLoop* loop,
             const muduo::net::InetAddress& listenAddr);

  void start();  // calls server_.start();

 private:
  void onConnection(const muduo::net::TcpConnectionPtr& conn);

  void onMessage(const muduo::net::TcpConnectionPtr& conn,
                 muduo::net::Buffer* buf,
                 muduo::Timestamp time);

  muduo::net::TcpServer server_;
};

#endif  // XIAOZHONG_NETHINGS_H
