#include "LibB/Bar.h"

#include <qdebug.h>

Bar::Bar() noexcept
{
}

Bar::~Bar() noexcept
{
}

void Bar::doSomethingBar()
{
    qDebug() << __FUNCTION__;
}