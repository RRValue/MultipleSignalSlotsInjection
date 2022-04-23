#include "LibB/BarSignalProxy.h"

BarSignalProxy::BarSignalProxy(const Interface& iface) : m_Interface{iface}
{
}

BarSignalProxy::~BarSignalProxy()
{
}

void BarSignalProxy::doSomethingBar()
{
    if(!m_Interface.expired())
        m_Interface.lock()->doSomethingBar();

    emit callFromBar(__FUNCTION__);
}