#pragma once

#include "Global/global.h"

#include "LibA/Foo.h"

#include "LibB/BarSignalInterface.h"

class EXPORT_API Bar : public BarSignalInterface, public Foo
{
public:
    Bar() noexcept;
    virtual ~Bar() noexcept;

protected:
    void doSomethingBar() final override;
};
