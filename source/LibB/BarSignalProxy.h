#pragma once

#include "Global/global.h"

#include "LibB/BarSignalInterface.h"

#include <QtCore/QObject>

#include <memory>

class EXPORT_API BarSignalProxy : public QObject, public BarSignalInterface
{
    Q_OBJECT

private:
    using Interface = std::weak_ptr<BarSignalInterface>;

public:
    BarSignalProxy(const Interface& iface);
    virtual ~BarSignalProxy();

signals:
    void callFromBar(QString who);

public slots:
    virtual void doSomethingBar() final override;

private:
    Interface m_Interface;
};
