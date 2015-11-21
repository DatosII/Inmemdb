#include "wrapperxml.h"

/**
 * @brief WrapperXml::WrapperXml, constructor de la clase
 */
WrapperXml::WrapperXml(){

}
/**
 * @brief WrapperXml::readXml, metodo para realizar la lectura del xml
 * @param pRuta, directorio del documento
 * @param pRoot, raiz del documento
 * @param pSon, hijo del documento
 */
void WrapperXml::readXml(const char* pRuta, const char* pRoot, const char* pSon){
    std::ifstream file(pRuta);
    std::stringstream buffer;
    if(file){
        buffer << file.rdbuf();
        file.close();

        std::string content = buffer.str();

        rapidxml::xml_document<> xml;
        xml.parse<0>((char*)&content[0]);
        rapidxml::xml_node<> * root_node = xml.first_node(pRoot);
        if(root_node == 0)
            return ;
        std::cout << "Found node: " << root_node->name() << std::endl;

        rapidxml::xml_node<> * resources_node = root_node->first_node(pSon);
        std::cout << "Found node: " << resources_node->name() << std::endl;
    }
}
