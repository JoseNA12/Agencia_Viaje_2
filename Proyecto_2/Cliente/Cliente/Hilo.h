#pragma once
#include <winsock.h>
#include <string>
#include <iostream>

using namespace std;
class SocketT
{
public:
	SocketT();
	~SocketT();

	void enviar(SOCKET auxiliar, string mensaje);
	string recibir(SOCKET auxiliar);

	SOCKET socketConeccion;

};
