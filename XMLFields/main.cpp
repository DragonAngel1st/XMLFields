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
    XMLField<string> XMLDoc = XMLField(data, descriptionOfField);
    
    int pageNumber = 5;
    XMLField<int> pageField = XMLField(pageNumber, (string)"PageNumber");
    
    RootXMLDocument newXMLDoc;
    newXMLDoc.XMLVersion = "1.0";
    
    XMLDoc.add(pageField);
    
    XMLDoc.print();
    
    return 0;
}
