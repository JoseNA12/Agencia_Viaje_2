#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <WinSock2.h> //For win sockets
#include <string> //For std::string
#include <iostream> //For std::cout, std::endl, std::cin.getline
#include "Hilo.h"

class Cliente {
public:
	SOCKET	Connection;
	Cliente() {
		//	SOCKET Connection;//This client's connection to the server
		WSAData wsaData;
		WORD DllVersion = MAKEWORD(2, 1);
		if (WSAStartup(DllVersion, &wsaData) != 0)
		{
			cout << "falla en la conexion" << endl;
			cout << "Termine" << endl;
		}

		SOCKADDR_IN addr; //Address to be binded to our Connection socket
		int sizeofaddr = sizeof(addr); //Need sizeofaddr for the connect function
		addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //Address = localhost (this pc)
		addr.sin_port = htons(1111); //Port = 1111
		addr.sin_family = AF_INET; //IPv4 Socket

		Connection = socket(AF_INET, SOCK_STREAM, NULL); //Set Connection socket
		if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0) //If we are unable to connect...
		{
			cout << "Falla en la conexion" << endl;
			cout << "Terminado " << endl;
		}
	}

	void enviar(string mensaje) {
		SocketT aux;
		aux.enviar(Connection, mensaje);
	}
	string respuesta() {
		SocketT aux;
		return aux.recibir(Connection);
	}






};
