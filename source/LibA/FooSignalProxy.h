#pragma once

#include "Global/global.h"

#include <QtCore/QObject>

#include <memory>

class MocFooSignalProxy : public QObject
{
    Q_OBJECT

signals:
    void callFromFoo(QString who);

public slots:
    virtual void doSomethingFoo() = 0;
};

class FooSignalInterface;

class EXPORT_API FooSignalProxy : public MocFooSignalProxy
{
private:
    using Interface = std::weak_ptr<FooSignalInterface>;

public:
    FooSignalProxy(const Interface& iface);
    virtual ~FooSignalProxy();

public:
    virtual void doSomethingFoo() final override;

private:
    Interface m_Interface;
};
