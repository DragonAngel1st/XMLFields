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

class XMLAttribute
{
public:
    pair<string,string> attribute;
    XMLAttribute(string a, string b);

};

class Element
{
public:
    string uuid;
    string description;
    vector<XMLAttribute *> attributesPtrs;
    vector<Element *> subElementsPtrs;
    
    void add(Element * someFieldPtr)
    {
        subElementsPtrs.push_back(someFieldPtr);
    }
    void add(XMLAttribute * attributePtr)
    {
        attributesPtrs.push_back(attributePtr);
    }
    
    
    void print()
    {
        std::cout << description << std::endl;
        for (auto subElementPtr : subElementsPtrs)
        {
            (*subElementPtr).print();
        }
    }
};

//Template constructors
template <typename XMLFieldDataType>
class XMLElement : public Element
{
public:
    XMLFieldDataType data;
    XMLElement<XMLFieldDataType>(XMLFieldDataType data, string description);
};


template <typename XMLFieldDataType>
inline XMLElement<XMLFieldDataType>::XMLElement(XMLFieldDataType _data, string _description):data(_data) {
    uuid = UUID::GetNewID();
    description = _description;
};


template <typename XMLFieldDataType>
class CustomXMLField : public XMLElement<XMLFieldDataType>
{
    //etc...
};

//class RootXMLDocument
//{
//public:
//    string XMLVersion;
//    vector<XMLAttribute> attributes;
//    Element * contentPtrs;
//
//};

#endif /* XMLFieldTemplate_h */
