#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <time.h>
#include "Adapter/adapter.h"

#define TRUNC '\0'

/**
 * @file server.h
 * @brief Clase servidor para la comunicación con los clientes
 * @author Juan Pablo Brenes Coto
 * @date 19/11/15
 */

class Adapter;
struct Parameters{
	int _socket;
	pthread_mutex_t _mutex;
	unsigned char *mensaje;
	Adapter *_adapter;
	void *server = this;
};


class Server{
public:
	Server(Adapter *pAdapter);
	Adapter *_adapter;
	void setPort(int pPort);
	void initServer();



private:
	bool _runningServer;
	int _port;
	Parameters *_parameters;

	void createServer(Parameters *pParameters);
	void* attendClient(Parameters *pParameters);
	};

#endif // SERVER_H
