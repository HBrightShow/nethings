#include "./nethings.h"

#include "muduo/base/Logging.h"

using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;

// using namespace muduo;
// using namespace muduo::net;

NethingsServer::NethingsServer(muduo::net::EventLoop* loop,
                       const muduo::net::InetAddress& listenAddr)
  : server_(loop, listenAddr, "NethingsServer")
{
  server_.setConnectionCallback(
      std::bind(&NethingsServer::onConnection, this, _1));
  server_.setMessageCallback(
      std::bind(&NethingsServer::onMessage, this, _1, _2, _3));

  server_.setThreadNum(10);
}

void NethingsServer::start()
{
  server_.start();
}

void NethingsServer::onConnection(const muduo::net::TcpConnectionPtr& conn)
{
  LOG_INFO << "NethingsServer - " << conn->peerAddress().toIpPort() << " -> "
           << conn->localAddress().toIpPort() << " is "
           << (conn->connected() ? "UP" : "DOWN");
}

void NethingsServer::onMessage(const muduo::net::TcpConnectionPtr& conn,
                           muduo::net::Buffer* buf,
                           muduo::Timestamp time)
{
  muduo::string msg(buf->retrieveAllAsString());
  LOG_INFO << conn->name() << "  " << time.toString() << "data size: " << msg.size() 
              << " data content: " << msg;
  conn->send(msg);
}

