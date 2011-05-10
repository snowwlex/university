
#ifndef _STRING_H_
#define	_STRING_H_

#include <iostream>


class String {
public:
    String();
    String(const char* chars);
    String(const String& String);
    String & operator=(const String& String);
    ~String();
public:
    const char* c_str() const;
private: //help methods
    void copyString(const char* chars);

private:
    char* myString;

    //friends:
    friend std::ostream & operator<<(std::ostream& stream, const String& string);
};




#endif	/* _STRING_H */

