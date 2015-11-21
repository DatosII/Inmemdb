#ifndef ADAPTER_H
#define ADAPTER_H

#include <Wrappers/wrapperjson.h>
#include "core.h"

#define JSON 'J'
#define XML 'X'
#define PROTOCOL_XML "content-type: xml"
#define PROTOCOL_JSON "content-type: json"
#define ERROR_MESSAGE "Mensaje desconocido"

/**
 * @file adapter.h
 * @brief Clase adapter que se encarga de interpretar los
 * protocolos de comunicación Xml y Json
 * @author Juan Pablo Brenes Coto
 * @date 19/11/15
 */

class Core;
class Adapter{

public:
	Adapter(Core *pCore);

	char *incomingMessage(char *pBuffer);
	char *parser(char *pBuffer);


private:
	char _protocol;

	Core *_core;
	WrapperJSON *_json;
	};

#endif // ADAPTER_H
