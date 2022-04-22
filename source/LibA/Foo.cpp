#include "LibA/Foo.h"

#include <qdebug.h>

Foo::Foo()
{
}

Foo::~Foo()
{
    
}

void Foo::doSomethingFoo()
{
    qDebug() << __FUNCTION__;
}