#pragma once

#include "Global/global.h"

#include <QtCore/QObject>

#include <memory>

class MocBarSignalProxy : public QObject
{
    Q_OBJECT

signals:
    void callFromBar(QString who);

public slots:
    virtual void doSomethingBar() = 0;
};

class BarSignalInterface;

class EXPORT_API BarSignalProxy : public MocBarSignalProxy
{
private:
    using Interface = std::weak_ptr<BarSignalInterface>;

public:
    BarSignalProxy(const Interface& iface);
    virtual ~BarSignalProxy();

public:
    virtual void doSomethingBar() final override;

private:
    Interface m_Interface;
};
