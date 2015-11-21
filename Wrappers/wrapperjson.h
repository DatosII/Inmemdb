#ifndef WRAPPERJSON_H
#define WRAPPERJSON_H

#include <Wrappers/rapidjson/rapidjson.h>
#include <Wrappers/rapidjson/document.h>
#include <Wrappers/rapidjson/stringbuffer.h>
#include <Wrappers/rapidjson/writer.h>
#include <Wrappers/rapidjson/filestream.h>
#include <Wrappers/rapidjson/prettywriter.h>
#include <Wrappers/rapidjson/reader.h>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cstdio>

#define ZERO 0
#define MODES "r"

/**
 * @file wrapperjson.h
 * @brief Clase que utiliza la biblioteca rapidjson, para la creación
 * y lectura de los mensajes en formato JSON
 * @author Juan Pablo Brenes Coto
 * @date 19/11/15
 */

class WrapperJSON
	{
public:
	WrapperJSON();

	rapidjson::Document readFile(const char* pPath);
	int readIntValue(rapidjson::Document &pDocument, const char* pTag);
	void writeFile();
	bool validateFile(char *pFile);

	};

#endif // WRAPPERJSON_H
