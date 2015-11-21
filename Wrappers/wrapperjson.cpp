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
		else return NULL;
	}
	else return NULL;
}




void WrapperJSON::writeFile(){
	rapidjson::StringBuffer s;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);//escritura en json
	writer.StartObject();
	writer.String("esquema");
	writer.String("estudiante");
	writer.String("Nombre");
	writer.String("Jairo");
	writer.String("Carnet");
	writer.Int(2014043224);
	writer.String("Ponderado General");
	writer.Int(70);
	writer.String("Ponderado Semestral");
	writer.Int(75);
	writer.EndObject();

	std::cout << s.GetString() << std::endl;//imprime el json


}

