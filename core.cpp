#include "core.h"

/**
 * @brief Constructor de la clase
 *
 * Instancia el servidor y el adapter
 */
Core::Core(){
	_server = new Server(this);
	_adapter = new Adapter(this);

}


