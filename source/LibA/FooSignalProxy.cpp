#include "LibA/FooSignalProxy.h"

#include "LibA/FooSignalInterface.h"

FooSignalProxy::FooSignalProxy(const Interface& iface) : m_Interface{iface}
{
}

FooSignalProxy::~FooSignalProxy()
{
}

void FooSignalProxy::doSomethingFoo()
{
    if(!m_Interface.expired())
        m_Interface.lock()->doSomethingFoo();

    emit callFromFoo(__FUNCTION__);
}