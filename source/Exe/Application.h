#pragma once

#include <QtCore/QCoreApplication>

class Application : public QCoreApplication
{
public:
    using QCoreApplication::QCoreApplication;

public slots:
    void onRun();
};