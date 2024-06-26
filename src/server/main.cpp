#include "chatserver.h"
#include "chatservice.h"
#include <iostream>
#include <signal.h>

using namespace std;

// 处理服务器ctrl+c结束后，重置user的状态信息
void resetHandler(int i) {
    ChatService::instance()->reset();
    exit(i);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        cerr << "command invalid! example: ./ChatServer 127.0.0.1 6000" << endl;
        exit(-1);
    }
    signal(SIGINT, resetHandler);

    // 解析通过命令行参数传递的ip和port
    char *ip = argv[1];
    uint16_t port = atoi(argv[2]);

    EventLoop loop;
    InetAddress addr(ip, port);
    ChatServer server(&loop, addr, "ChatServer");

    server.start();
    loop.loop();
    cout << "123";
    return 0;
}