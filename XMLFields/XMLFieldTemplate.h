//
//  XMLFieldTemplate.h
//  XMLFields
//
//  Created by Patrick Miron on 2022-06-17.
//


#ifndef XMLFieldTemplate_h
#define XMLFieldTemplate_h

#include "uuid.h"
#include <sstream>

using namespace std;

class Element
{
public:
    string uuid;
    string description;
    vector<pair<string,string>> attributes;
    vector<Element> elements;
    
    void add(Element someField)
    {
        elements.push_back(someField);
    }
    void print()
    {
        std::cout << description << std::endl;
        for (auto element : elements)
        {
            element.print();
        }
    }
};

//Template constructors
template <typename XMLFieldDataType>
class XMLField : public Element
{
public:
    XMLFieldDataType data;
    XMLField<XMLFieldDataType>(XMLFieldDataType data, string description);
};


template <typename XMLFieldDataType>
inline XMLField<XMLFieldDataType>::XMLField(XMLFieldDataType _data, string _description):data(_data) {
    uuid = UUID::GetNewID();
    description = _description;
};


template <typename XMLFieldDataType>
class CustomXMLField : public XMLField<XMLFieldDataType>
{
    //etc...
};

class RootXMLDocument
{
public:
    string XMLVersion;
    vector<pair<string,string>> attributes;
    Element * contentPtrs;
};

#endif /* XMLFieldTemplate_h */
