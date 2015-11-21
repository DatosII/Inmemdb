#ifndef CORE_H
#define CORE_H

#include <Adapter/adapter.h>
#include "Server/server.h"

#define CONFIG_FILE_PATH "/home/pablo/Memdb/config.json"
#define MEMBER_PORT "port"

/**
 * @file core.h
 * @brief Clase principal del inmemdb
 * @author Juan Pablo Brenes Coto
 * @date 19/11/15
 */

class Adapter;
class Server;
class Core{

public:
	Core();


private:
	Adapter *_adapter;
	Server *_server;
	};

#endif // CORE_H
