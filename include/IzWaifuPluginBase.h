#ifndef IZWAIFUPLUGINBASE_H
#define IZWAIFUPLUGINBASE_H

#include <QSharedPointer>

#include "zPIGlobals.h"

class AzWaifuEngine;

class ZPI_EXPORT IzWaifuPluginBase
{
public:
    virtual ~IzWaifuPluginBase() = default;
    virtual void initialize(QSharedPointer<AzWaifuEngine> engine) = 0;
};

#define zWaifuPluginBaseInterface_iid "moe.poteko.zWaifu.zPI.PluginBaseInterface"

Q_DECLARE_INTERFACE(IzWaifuPluginBase, zWaifuPluginBaseInterface_iid)

#endif // IZWAIFUPLUGINBASE_H
