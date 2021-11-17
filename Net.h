#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define NET_CONNECTION_ERROR_NO  4585
#define NET_CONNECTION_ERROR_YES 4586
#define NET_CONNECTED            4587
#define NET_DISCONNECTED         4588

#pragma comment(lib, "ws2_32.lib")
#pragma once

class Net {
protected:
	char name[20];
	char ip[15];
	int id;
	int port;
	int state;
private:
	WSADATA WSAData;
	SOCKET sock;
	SOCKADDR_IN sin;
public:
	Net();
	Net(char *name, char *ip, int port, int id);
	char *getName();
	char *getIp();
	int getPort();
	int getId();
	int getState();
	void setName(char *name);
	void setIp(char *ip);
	void setPort(int port);
	void setId(int id);
	void setState(int state);
	int chatConnect();
	void chatDisconnect();
	void chatSend(char *message, int len);
	void chatReceive(char *message, int len);
	~Net();
};

/*
Utiliser chatReceive
	while(a.getState() == NET_CONNECTED){
		char test[1024];
		a.chatReceive(test, 1024);
		cout << test << endl;
		if(memcmp(test, "Ok", strlen("Ok")) == 0){
			a.setState(NET_DISCONNECTED);
		}
		fill_n(test, 1024, 0);
	}
*/