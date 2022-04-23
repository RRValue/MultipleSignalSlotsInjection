#include "Exe/Application.h"

#include "LibB/Bar.h"

#include "LibA/FooSignalProxy.h"
#include "LibB/BarSignalProxy.h"

void Application::onRun()
{
    auto bar = std::make_shared<Bar>();
    
    FooSignalProxy foo_proxy(bar);
    BarSignalProxy bar_proxy(bar);

    connect(this, &Application::callFoo, &foo_proxy, &FooSignalProxy::doSomethingFoo);
    connect(this, &Application::callBar, &bar_proxy, &BarSignalProxy::doSomethingBar);

    connect(&foo_proxy, &FooSignalProxy::callFromFoo, this, &Application::onLibCalls);
    connect(&bar_proxy, &BarSignalProxy::callFromBar, this, &Application::onLibCalls);

    emit callFoo();
    emit callBar();

    processEvents();
    processEvents();

    exit();
}

void Application::onLibCalls(QString who)
{
    qDebug() << __FUNCTION__ << " from " << who;
}