//
//  uuid.h
//  XMLFields
//
//  Created by Patrick Miron on 2022-06-17.
//
#include <random>
#include <sstream>

#ifndef uuid_h
#define uuid_h

using namespace std;

//UUID generator adapted from https://stackoverflow.com/questions/24365331/how-can-i-generate-uuid-in-c-without-using-boost-library

class UUID
{
public:
    UUID(const UUID&) = delete;
    
    static UUID& Get()
    {
        static UUID instance;
        return instance;
    };
    
    static string GetNewID() { return Get().ImplementationGenerate_UUID(); };
private:
    
    UUID(){};
    
    string ImplementationGenerate_UUID() {
        random_device dev;
        mt19937 generator(dev());
        uniform_int_distribution<> distribution1(0,15);
        uniform_int_distribution<> distribution2(8,11);
        stringstream ss;
                int i;
                ss << std::hex;
                for (i = 0; i < 8; i++) {
                    ss << distribution1(generator);
                }
                ss << "-";
                for (i = 0; i < 4; i++) {
                    ss << distribution1(generator);
                }
                ss << "-4";
                for (i = 0; i < 3; i++) {
                    ss << distribution1(generator);
                }
                ss << "-";
                ss << distribution2(generator);
                for (i = 0; i < 3; i++) {
                    ss << distribution1(generator);
                }
                ss << "-";
                for (i = 0; i < 12; i++) {
                    ss << distribution1(generator);
                };
                return ss.str();
    }
};

#endif /* uuid_h */
