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
    //Create a XML document
    string descriptionOfField = "Start of XML Document";
    string data = "Start of Document";
    XMLField<string> XMLDoc = XMLField(data, descriptionOfField);
    
    int pageNumber = 5;
    XMLField<int> pageField = XMLField(pageNumber, (string)"PageNumber");
    
    XMLDoc.add(pageField);
    
    return 0;
}
