#ifndef IZWAIFUFUNCTIONPLUGIN_H
#define IZWAIFUFUNCTIONPLUGIN_H

#include <QObject>

class IzWaifuEngine;

class IzWaifuFunctionPlugin
{
public:
    virtual ~IzWaifuFunctionPlugin() = default;

    virtual bool initialize(IzWaifuEngine *zWaifuEngine) = 0;
};

#define zWaifuFunctionPluginInterface_iid "moe.poteko.zWaifu.zPI.FunctionPluginInterface"

Q_DECLARE_INTERFACE(IzWaifuFunctionPlugin, zWaifuFunctionPluginInterface_iid)

#endif // IZWAIFUFUNCTIONPLUGIN_H
