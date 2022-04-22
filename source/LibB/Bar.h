#pragma once

#include "Global/global.h"

#include "LibA/Foo.h"

#include "LibB/BarSignalInterface.h"

class EXPORT_API Bar : public Foo, public BarSignalInterface
{
public:
    Bar() noexcept;
    virtual ~Bar() noexcept;

protected:
    void doSomethingBar() final override;
};
