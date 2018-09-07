//
//  shared.h
//  String
//
//  Created by Oleg Syniakevych on 07/09/2018.
//  Copyright © 2018 Oleg Syniakevych. All rights reserved.
//

#ifndef shared_h
#define shared_h

namespace my {

template <class T>
class Shared {
public:
    using value_type = T;
    using reference = T&;
    using const_reference = value_type const &;
    using pointer = T *;
    using const_pointer = T const * const;
    Shared() = delete;
    Shared(pointer p)
        : ptr_(p), numberOfShares_(new size_t(1))
    {
        // question: why can't i initialize
        // int const * const with int *
        // ? it's copied by value!
    }
    
    Shared(Shared const & o)
        : ptr_(o.ptr_), numberOfShares_(o.numberOfShares_)
    {
        ++*numberOfShares_;
    }
    
    pointer get() const {
        return ptr_;
    }
    
    size_t number() const {
        return *numberOfShares_;
    }
    
    ~Shared()
    {
        --*numberOfShares_;
        if (number() == 0)
        {
            delete ptr_;
        }
    }
private:
    pointer ptr_;
    size_t * numberOfShares_;
};


template<class T, class ... Args>
Shared<T> makeShared(Args && ... args)
{
    return Shared<T>(new T(args...));
}
    
template<class T>
Shared<T> makeShared(Shared<T> const & o) {
    return Shared<T>(o);
}

}

#endif /* shared_h */















