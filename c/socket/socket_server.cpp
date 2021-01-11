#include <sys/types.h>
#include <sys/shm.h>
#include <sys/socket.h> //for socket()
#include <netinet/in.h> //for sockaddr_in
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <thread>
#include <iostream>
#include<netinet/tcp.h> //for tcp info

int main(int argc, char*argv[])
{
    //AF_INET-IPV4协议, SSOCK_STREAM-UDP/IP协议
    int sock_handel = socket(AF_INET, SOCK_STREAM, 0); //成功则返回一个socketfd
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(9900); //端口
    //INADDR_ANY代表"所有地址"即:0.0.0.0
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY); 

    if(bind(sock_handel,(struct sockaddr* )&server_sockaddr, sizeof(server_sockaddr))){
        std::cout << "[ERROR]: Socket can not bind!" << std::endl;     
        return -1;
    }
    //listen相当于一个门卫兵对连接请求做决定:是否将链接请求放到server维护的一个队列去
    if(listen(sock_handel, 20) == -1){ //最多容纳请求数20个
        std::cout << "[ERROR]: Socket listen is filed!" << std::endl;;
        return -1;
    }

    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    int conn = accept(sock_handel, (struct sockaddr*)&client_addr, &length);
    if(conn < 0){
        std::cout << "[ERROR]: accpet is filed!" << std::endl;
        return -1;
    }else{
        std::cout << "client_addr.sin_addr.s_addr: " << client_addr.sin_addr.s_addr << std::endl;
        std::cout << "client_addr.sin_family: " << client_addr.sin_family << std::endl;
        std::cout << "client_addr.sin_port: " << client_addr.sin_port << std::endl;
    }

    char buffer[1024];

    struct tcp_info info;
    int tcp_info_len=sizeof(info); 
    while(1){
        memset(buffer, 0 ,sizeof(buffer));
        int len = recv(conn, buffer, sizeof(buffer), 0);//从TCP连接的另一端接收数据。
        if(strcmp(buffer, "exit\n") == 0){//如果没有收到TCP另一端发来的数据则跳出循环不输出
            break;
        }
        getsockopt(conn, IPPROTO_TCP, TCP_INFO, &info, (socklen_t* )&tcp_info_len);
		std::cout << "info.tcpi_state: " << (int)info.tcpi_state << std::endl;
       /* if(info.tcpi_state == TCP_ESTABLISHED){
            std::cout << "[ERROR]: The TCP Client Disconnect!" << std::endl;
            break;
        }
		*/
		if(len != 0){
        std::cout << "I get buffer size: " << len << std::endl;
        std::cout << buffer;
        send(conn, buffer, len , 0);
		}else{
            std::cout << "[ERROR]: The TCP Client Disconnect!" << std::endl;
			break;
		}
    }

    std::cout << "[WARR]: Close the Socket!" << std::endl;
    close(conn);
    close(sock_handel);
    return 0;
}

