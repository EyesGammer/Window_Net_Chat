#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>
#include <iostream>
#include "Net.h"
#pragma comment(lib, "ws2_32.lib")

using namespace std;

Net::Net(){
	strcpy_s(name, "");
	strcpy_s(ip, "127.0.0.1");
	id = 0;
	port = 69;
	state = NET_DISCONNECTED;
}
Net::Net(char *n, char *i, int p, int d){
	strcpy_s(name, n);
	strcpy_s(ip, i);
	id = d;
	port = p;
	state = NET_DISCONNECTED;
}
char *Net::getName(){
	return name;
}
char *Net::getIp(){
	return ip;
}
int Net::getPort(){
	return port;
}
int Net::getId(){
	return id;
}
int Net::getState(){
	return state;
}
void Net::setName(char *n){
	strcpy_s(name, n);
}
void Net::setIp(char *i){
	strcpy_s(ip, i);
}
void Net::setPort(int p){
	port = p;
}
void Net::setId(int d){
	id = d;
}
void Net::setState(int s){
	state = s;
}
int Net::chatConnect(){
	int result = WSAStartup(MAKEWORD(2, 0), &WSAData);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == INVALID_SOCKET){
		result = NET_CONNECTION_ERROR_YES;
		WSACleanup();
	}else{
		sin.sin_addr.s_addr = inet_addr(ip);
		sin.sin_family = AF_INET;
		sin.sin_port = htons(port);
		result = connect(sock, (SOCKADDR *)&sin, sizeof(sin));
		if(result == SOCKET_ERROR){
			result = closesocket(sock);
			if(result == SOCKET_ERROR){
				result = NET_CONNECTION_ERROR_YES;
			}
			WSACleanup();
		}else{
			state = NET_CONNECTED;
			result = NET_CONNECTION_ERROR_NO;
		}
	}
	return result;
}
void Net::chatDisconnect(){
	closesocket(sock);
	WSACleanup();
	state = NET_DISCONNECTED;
	port = 0;
	id = 0;
	delete[] &name;
	delete[] &ip;
}
void Net::chatSend(char *message, int len){
	send(sock, message, len, 0);
}
void Net::chatReceive(char *message, int len){
	recv(sock, message, 1024, 0);
}
Net::~Net(){
	closesocket(sock);
	WSACleanup();
	state = NET_DISCONNECTED;
	port = 0;
	id = 0;
	delete[] &name;
	delete[] &ip;
}