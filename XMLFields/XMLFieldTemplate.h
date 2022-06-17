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

class baseXMLField
{
public:
    string uuid;
    string description;
    vector<baseXMLField> subFields;
    
    void add(baseXMLField someField)
    {
        subFields.push_back(someField);
    }
};

template <typename XMLFieldDataType>
class XMLField : public baseXMLField
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

#endif /* XMLFieldTemplate_h */
