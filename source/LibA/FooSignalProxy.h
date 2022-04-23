#pragma once

#include "Global/global.h"

#include "LibA/FooSignalInterface.h"

#include <QtCore/QObject>

#include <memory>

class EXPORT_API FooSignalProxy : public QObject, public FooSignalInterface
{
    Q_OBJECT

private:
    using Interface = std::weak_ptr<FooSignalInterface>;

public:
    FooSignalProxy(const Interface& iface);
    virtual ~FooSignalProxy();

signals:
    void callFromFoo(QString who);

public slots:
    virtual void doSomethingFoo() final override;

private:
    Interface m_Interface;
};
