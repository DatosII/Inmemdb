#include "wrapperjson.h"

/**
 * @brief Constructor de la clase
 */
WrapperJSON::WrapperJSON(){
}






/**
 * @brief Método que abre un archivo en formato JSON y lo carga en memoria
 *
 * @param pPath Ubicación del archivo
 *
 * @return Documento en donde se cargo el archivo
 */
rapidjson::Document WrapperJSON::readFile(const char *pPath){
	FILE *file = fopen(pPath, MODES);
	rapidjson::FileStream is(file);
	rapidjson::Document document;
	document.ParseStream<ZERO>(is);
	fclose(file);

	return document;


}



/**
 * @brief Método para leer un int dentro de un documento Json
 * Valida si el documento tiene cargado un json, si tiene un
 * miembro con el nombre de pMember y si es de tipo int
 *
 * @param pDocument Documento que tiene el json cargado
 * @param pMember Nombre del miembro que tiene el int a leer
 *
 * @return Int dentro de json
 */
int WrapperJSON::readIntValue(rapidjson::Document &pDocument, const char *pMember){
	if(pDocument.IsObject()){
		if(pDocument.HasMember(pMember)){
			if(pDocument[pMember].IsInt())
				return pDocument[pMember].GetInt();
		}
		else return ZERO;
	}
	else return ZERO;
}




void WrapperJSON::writeFile(){
	rapidjson::StringBuffer s;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);//escritura en json
	writer.StartObject();
	writer.String("messageType");
	writer.String("createScheme");

	writer.String("shemeName");
	writer.String("person");
	writer.String("RAID");
	writer.Int(01);

	writer.String("data");
	writer.StartObject();
	writer.String("dataType");
	writer.String("String");
	writer.String("dataName");
	writer.String("name");
	writer.String("dataLenght");
	writer.Int(32);
	writer.EndObject();

	writer.String("data");
	writer.StartObject();
	writer.String("dataType");
	writer.String("int");
	writer.String("dataName");
	writer.String("age");
	writer.String("dataLenght");
	writer.Int(4);
	writer.EndObject();

	writer.EndObject();


	std::cout << s.GetString() << std::endl;//imprime el json


}



/**
 * @brief Método que permite validar un archivo JSON
 * Recibe un puntero char con el texto del archivo, este
 * se almacena en un objeto tipo Document de la biblioteca
 * rapidjon y luego se parsea a formato JSON, para luego
 * comprobar si es valido o no
 *
 * @param pFile Archivo JSON
 *
 * @return True si es un formato valido, false en caso contrario
 */
bool WrapperJSON::validateFile(char *pFile){
	rapidjson::Document document;
	document.Parse<0>(pFile);
	if(document.IsObject()) return true;
	else return false;
}

