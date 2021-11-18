# Class Net Documentation
> Version: 1.0

- [Class Net Documentation 1.0](#class-net-documentation-10)
	- [1. Constant](#constants)
	- [2. Methods](#methods)
		- [2.1. Attributs](#attributs)
	- [3. Constructor](#constructor)
	- [4. Connection and Disconnection](#connect-and-disconnect)
	- [5. Send and Receive](#send-and-receive)
	- [6. Examples](#examples)
	- [7. Used librairies](#used-librairies)

# Constants
- `NET_CONNECTION_ERROR_NO` | No connection error
- `NET_CONNECTION_ERROR_YES` | Error during connection
- `NET_CONNECTED` | Connected to server
- `NET_DISCONNECTED` | Not connected to server

# Methods
| Type | Method | Parameters | Parameters Type | Return value |
| ---- | ------ | ---------- | --------------- | ------------ |
| Net | Constructor |
| Net | Constructor | ip, port, name, id | char \*, int, char \*, int |
| char * | getName() | | | Username |
| char * | getIp() | | | Server IP |
| int | getPort() | | | Server Port |
| int | getId() | | | User ID |
| int | getState() | | | `NET_CONNECTED` or `NET_DISCONNECTED` ([See Constants](#constants)) |
| void | setName() | name | char * |
| void | setIp() | ip | char * |
| void | setPort() | port | int |
| void | setId() | id | int |
| int | chatConnect() | | | `NET_CONNECTION_ERROR_NO` or `NET_CONNECTION_ERROR_YES` ([See Constants](#constants)) |
| void | chatDisconnect() | | | Disconnect the User |
| void | chatSend() | message, len | char *, int |
| void | charReceive() | message, len | char *, int |
> [See examples](#2-methods)

# Attributs
| Type | Length | Attribut | Usage            |
| ---- | ------ | -------- | ---------------- |
| char | 20     | name     | Username         |
| char | 15     | ip       | Server IP        |
| int  |        | port     | Server Port      |
| int  |        | id       | User ID          |
| int  |        | state    | Connection State |

# Constructor
The constructor can take parameters or not: [See Methods](#methods).<br>
+ `char *ip` is the server IP to use.<br>
+ `int port` is the server Port to use.<br>
+ `char *name` is the Username to set.<br>
+ `int id` is the User ID.<br>
> [See examples](#1-constructor)

# Connect and Disconnect
+ `int chatConnect()` allow you to connect to the server
	> Return error code ([See Methods](#methods))

+ `void chatDisconnect()` allow you to disconnect to the server

# Send and Receive
+ `void chatSend()` allow you to send message to the server.
	- `char *message` is the message to send
	- `int len` is the message's length
+ `void chatReceive()` allow you to receive message from the server.
	- `char *message` is the receiver for the message
	- `int len` is the receiver array length
	> The received message will be save in the message variable<br>The receiver variable need to be clean after usage: `fill_n(receiver, 1024, 0)`

# Examples
## 1. Constructor
```c++
#include "Net.h";
using namespace std;

int main(){
	Net a;
	Net b("127.0.0.1", 69, (char *)"Username", 1);
	return 0;
}
```

## 2. Methods

### 2.1. Basics Methods
```c++
#include "Net.h"
using namespace std;

int main(){
	Net net;
	net.setName((char *)"Username");
	cout << net.getName() << " will connect to " << net.getIp() << ":" << net.getPort() << endl;
	return 0;
}
```

### 2.2. Other
```c++
#include "Net.h"
using namespace std;

int main(){
	Net net((char *)"127.0.0.1", 69, (char *)"Username", 1);
	int resultat = net.chatConnect();

	if(resultat == NET_CONNECTION_ERROR_YES){
		cout << "Error during connection" << endl;
		return 1;
	}

	cout << net.getName() << " will connect to " << net.getIp() << ":" << net.getPort() << endl;
	char message[] = "This is a test message";
	
	if(net.getState() == NET_CONNECTED){
		net.chatSend(message, sizeof(message));

		char receiver[1024];
		net.chatReceive(receiver, sizeof(receiver));
		cout << receiver << endl;
		fill_n(receiver, 1024, 0);
	}
}
```

# Used Librairies
The *Net* class use `string.h`, `winsock2.h` and `ws2tcpip.h`.<br>
