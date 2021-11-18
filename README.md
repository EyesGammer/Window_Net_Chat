# Class Net Documentation 1.0
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
- NET_CONNECTION_ERROR_NO | No connection error
- NET_CONNECTION_ERROR_YES | Error during connection
- NET_CONNECTED | Connected to server
- NET_DISCONNECTED | Not connected to server

# Methods
| Type | Method | Parameters | Parameters Type | Return value |
| ---- | ------ | ---------- | --------------- | ------------ |
| Net | Constructor |
| Net | Constructor | ip, port, name, id | char \*, int, char \*, int |
| char * | getName() | | | Username |
| char * | getIp() | | | Server IP |
| int | getPort() | | | Server Port |
| int | getId() | | | User ID |
| int | getState() | | | *"NET_CONNECTED"* or *"NET_DISCONNECTED"* ([See Constants](#constants)) |
| void | setName() | name | char * |
| void | setIp() | ip | char * |
| void | setPort() | port | int |
| void | setId() | id | int |
| int | chatConnect() | | | *"NET_CONNECTION_ERROR_NO"* or *"NET_CONNECTION_ERROR_YES"* ([See Constants](#constants)) |
| void | chatDisconnect() | | | Disconnect the User |
| void | chatSend() | message, len | char *, int |
| void | charReceive() | message, len | char *, int |

## Attributs
