#pragma once

#include <QtCore/QCoreApplication>

class Application : public QCoreApplication
{
    Q_OBJECT;

public:
    using QCoreApplication::QCoreApplication;

signals:
    void callFoo();
    void callBar();

public slots:
    void onRun();
    void onLibCalls(QString who);
};