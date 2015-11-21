#ifndef WRAPPERXML_H
#define WRAPPERXML_H

#include<fstream>
#include<sstream>
#include <iostream>
#include "Wrappers/rapidxml/rapidxml.hpp"

class WrapperXml{
private:
public:
    WrapperXml();
    void readXml(const char *pRuta, const char *pRoot, const char *pSon);
};

#endif // WRAPPERXML_H
