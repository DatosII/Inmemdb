#include "adapter.h"

/**
 * @brief Constructor de la clase
 *
 * Instancia los wrappers de json y xml
 */
Adapter::Adapter(Core *pCore){
	_core = pCore;
	_json = new WrapperJSON();
	_protocol = NULL;

}



/**
 * @brief Método donde llegan los mensajes del servidor
 * Si no se a especificado un protocolo de comunicación, se comprueba
 * si el mensaje es el que especifica el protocolo, si ya se a
 * especificado se llama al método "parser"
 *
 * @see Adapter::parser()
 *
 * @param pBuffer Buffer del servidor
 * @return Mensaje de respuesta
 */
char *Adapter::incomingMessage(char *pBuffer){

	std::cout << pBuffer << std::endl;
	if(_protocol == NULL){
		std::string tempStr = (char const*)pBuffer;
		if(tempStr == PROTOCOL_XML)
			_protocol = XML;
		else if(tempStr == PROTOCOL_JSON)
			_protocol = JSON;
		else{
			char *error(ERROR_MESSAGE);
			return error;
		}
	}

	else{
		if(this->validate(pBuffer))
			return this->parser(pBuffer);
		else{
			char *error(ERROR_MESSAGE);
			return error;
		}
	}
}



/**
 * @brief Método que se encarga de interpretar el mensaje entrante
 *
 * Lee el mensaje entrante dependiendo del protocolo de comunicación especificado
 *
 * @param pBuffer Buffer del servidor
 * @return Mensaje de respuesta al cliente
 */
char *Adapter::parser(char *pBuffer){

}



/**
 * @brief Método que permite validar el formato del archivo recibido
 *
 * De acuerdo al protocolo de comunicación especificado, se valida
 * si los mensajes recibidos por el puerto se encuentran en el formato
 * correcto
 *
 * @param pMessage Mensaje recibido por el puerto
 *
 * @return True si el formato es valido, false en caso contrario
 */
bool Adapter::validate(char *pMessage){
	if(_protocol == JSON)
		return _json->validateFile(pMessage);

}

