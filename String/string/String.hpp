//
//  String.hpp
//  String
//
//  Created by Oleg Syniakevych on 07/09/2018.
//  Copyright © 2018 Oleg Syniakevych. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>
#include <string>
#include "../ptr/shared.h"

namespace my {

class String {
public:
    String(char * str); // create another char*, copy
    String(char * && kmkdz); // just take that pointer
    String(std::string const& str); // copy c_str
    String(std::string && kmkdz); // just take its c_str
    String(String const & str) = default; // just memberwise copy, sptr_ will do it's job
    String & operator=(String const & str) = default;
    
    String & operator+=(String const & str);
    
    std::string to_string() const;
    
    operator char*() const;
    operator std::string() const;
private:
    my::Shared<char> sptr_;
};

String operator+ (String const & a, String const & b);
bool operator< (String const & a, String const & b);

}

#endif /* String_hpp */
