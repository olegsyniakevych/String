//
//  main.cpp
//  String
//
//  Created by Oleg Syniakevych on 07/09/2018.
//  Copyright © 2018 Oleg Syniakevych. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "ptr/shared.h"
#include "string/String.hpp"
#include "misc/type_name.h"

int main(int argc, const char * argv[]) {
    using namespace my;
    {
        auto p1 = makeShared<int>(1);
        assert(p1.number() == 1);
        auto p2 = makeShared(p1);
        assert(p1.number() == p2.number());
        assert(p1.number() == 2);
    }
    
    {
        char * c = new char[1000];
        strcpy(c, "string aisdajsd");
        auto s = String ( c );
        assert(strcmp(c, s.to_string().c_str()) == 0);
//        assert(c == s.to_string().c_str());
        
//        std::cout << s.to_string() << '\n';
    }
}

