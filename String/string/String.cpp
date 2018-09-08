//
//  String.cpp
//  String
//
//  Created by Oleg Syniakevych on 07/09/2018.
//  Copyright © 2018 Oleg Syniakevych. All rights reserved.
//

#include "String.hpp"

using namespace my;

String::String(char * str)
: sptr_(str)
{
    
}
String::String(char * && kmkdz)
: sptr_(kmkdz)
{
    
}


std::string String::to_string() const {
    return sptr_.get();
}


String::String(std::string && kmkdz)
: sptr_(const_cast<char*>(kmkdz.c_str()))
{
}
