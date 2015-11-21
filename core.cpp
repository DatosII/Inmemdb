#include "core.h"

/**
 * @brief Constructor de la clase
 *
 * Instancia el servidor y el adapter
 */
Core::Core(){
	_adapter = new Adapter(this);
	_server = new Server(_adapter);

	WrapperJSON *json = new WrapperJSON();
	rapidjson::Document doc = json->readFile(CONFIG_FILE_PATH);
	_server->setPort(json->readIntValue(doc, MEMBER_PORT));

	_server->initServer();
}


