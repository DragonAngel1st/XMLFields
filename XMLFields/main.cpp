//
//  main.cpp
//  XMLFields
//
//  Created by Patrick Miron on 2022-06-17.
//

#include <iostream>
#include "uuid.h"
#include "XMLFieldTemplate.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // EXAMPLE : creating an xml document using templates.
    //Create an XML document
    string descriptionOfField = "Start of XML Document";
    string data = "1.0";
    XMLElement<string> XMLDoc = XMLElement(data, descriptionOfField);
    
    int pageNumber = 5;
    XMLElement<int> pageField = XMLElement(pageNumber, (string)"PageNumber");
    
    XMLElement<string> rootXMLDocument = XMLElement(string("XML Version="),string("1.0"));
    //newXMLDoc.XMLVersion = "1.0";
    
    XMLAttribute * attributePtr = new XMLAttribute("encoding","UTF-8");
    XMLDoc.add(attributePtr);
    
    //XMLDoc.add(pageField);
    
    XMLDoc.print();
    
    return 0;
}
