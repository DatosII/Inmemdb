#include "server.h"

/**
 * @brief Server::Server
 */
Server::Server(Adapter *pAdapter){
	_parameters = new Parameters();
	_parameters->_mutex = PTHREAD_MUTEX_INITIALIZER;
	_parameters->_adapter = pAdapter;
}



/**
 * @brief Método para establecer el puerto por el cual se escucharan los clientes
 *
 * @param pPort Puerto
 */
void Server::setPort(int pPort){
	_port = pPort;
}



/**
 * @brief Método para iniciar el bucle que abre el puerto por donde se escuchan los clientes
 */
void Server::initServer(){
	_runningServer = true;
	this->createServer(_parameters);
}



/**
 * @brief Método que abre el puerto por el cual se escucha a los clientes
 * Se mantiene dentro de un bucle esperando la conexión de otros clientes
 *
 * @param pParameters Struct con los parametros de la clase
 */
void Server::createServer(Parameters *pParameters){

/**Ciclo de espera de solicitudes */
	while (_runningServer){
		int puerto = _port;
		int clientes, servido, pid;
		struct sockaddr_in direc;
		socklen_t tamano;

		if ((clientes = socket(AF_INET,SOCK_STREAM,0)) < 0){
			std::cout << "Se presento un error al crear el socket" << std::endl;
			exit(1);
		}
		std::cout << "Servidor ha sido creado" << std::endl;
		direc.sin_family = AF_INET;
		direc.sin_addr.s_addr = htons(INADDR_ANY);
		direc.sin_port = htons(puerto);

		if ((bind(clientes, (struct sockaddr*)&direc, sizeof(direc))) < ZERO){
			std::cout << "Error en la conexion por Bind" << std::endl;
			close(clientes);
			exit(1);
		}

		else{
			std::cout << "Conecte el cliente...../..\../..\../..\....." << std::endl;
			listen(clientes,1);
			tamano = sizeof(direc);
			while(_runningServer){
				servido = accept(clientes, (struct sockaddr *)&direc, &tamano);
				std::cout << "Conexion con el cliente exitosa" << std::endl;
				if(servido < ZERO)
					std::cout << "ERROR en aceptar" << std::endl;
				pid = fork();
				/**Condicional que delega en un hilo al
				 *  servidor que acaba de conectar */
				if(pid == ZERO){
					close(clientes);
					pParameters->_socket = servido;
					this->attendClient(pParameters);
					exit(ZERO);
				}
			}
		}
		close(clientes);
	}
}



/**
 * @brief Método que se encarga de mantener la conexión con los clientes
 * Se mantiene dentro de un bucle enviando y recibiendo mensajes
 *
 * @param pParameters Struct con los parametros de la clase
 * @return
 */
void *Server::attendClient(Parameters *pParameters){
	/** Definimos los parametros generales que utilizaremos para la
	 * recepcion y envio de mensajes, asi como variables de tiempo */
	int _socket = pParameters->_socket;
	int _bufSize = 1024;
	bool _loopMensajeria = true;

	std::cout << "Hola mundo, yo soy el cliente numero " << _socket << std::endl;

	/** Ciclo que receibe y envia datos. Tambien Corrobora si la coneccion
	 * permanece cada cierta cantidad de tiempo  */
	while (_loopMensajeria){
		char* _buffer;
		_buffer = new char[_bufSize];
		int bytesRecieved = ZERO;
		 bytesRecieved = recv(_socket, _buffer, _bufSize, ZERO);
		 _buffer[bytesRecieved] = TRUNC;

		pthread_mutex_lock(&(pParameters->_mutex));
		send(_socket, pParameters->_adapter->incomingMessage(_buffer), _bufSize, ZERO);
		pthread_mutex_unlock(&(pParameters->_mutex));
		delete _buffer;
	}
}

