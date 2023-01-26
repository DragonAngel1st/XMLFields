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

// class for universal unique identifiers
// Once class is created it uses the same static generator object (prevents multiple creation of same objects)
//For the simplicity of this study, the instance is return by dereferencing the instancePtr but please consider modifying the UUID class to return a pointer for a slight increase in efficiency;
class UUID
{
public:
    //Remove automatic Copy Constructor
    UUID(const UUID&) = delete;
    
    // Get is a satic method that returns an instance when return, if an instance already exist, then it will return that instance.
    static UUID& Get()
    {
        // If instance does not exist, create a new one.
        if (instancePtr == NULL)
        {
            // Create single instance
            instancePtr = new UUID;
        }
        return * instancePtr;
    };
    
    static string GetNewID() { return Get().ImplementationGenerate_UUID(); };
private:
    //Singleton pointer to the instance
    static UUID * instancePtr;
    //Default constructor
    UUID(){};
    
    // private method to return a random generated
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
