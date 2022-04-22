#pragma once

#include "Global/global.h"

#include "LibA/FooSignalInterface.h"

class EXPORT_API Foo : public FooSignalInterface
{
public:
    Foo();
    virtual ~Foo();

protected:
    void doSomethingFoo() final override;
};
