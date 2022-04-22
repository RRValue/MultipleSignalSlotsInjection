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

    connect(&foo_proxy, SIGNAL(callFromFoo(QString)), this, SLOT(onLibCalls(QString)));
    connect(&bar_proxy, SIGNAL(callFromBar(QString)), this, SLOT(onLibCalls(QString)));

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