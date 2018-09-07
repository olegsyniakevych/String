//
//  main.cpp
//  String
//
//  Created by Oleg Syniakevych on 07/09/2018.
//  Copyright © 2018 Oleg Syniakevych. All rights reserved.
//

#include <iostream>
#include "ptr/shared.h"
#include <cassert>

int main(int argc, const char * argv[]) {
    using namespace my;
    {
        auto p1 = makeShared<int>(1);
        assert(p1.number() == 1);
        auto p2 = makeShared(p1);
        assert(p1.number() == p2.number());
        assert(p1.number() == 2);
    }
    
}

