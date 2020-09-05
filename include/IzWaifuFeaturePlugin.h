#ifndef IZWAIFUFEATUREPLUGIN_H
#define IZWAIFUFEATUREPLUGIN_H

#include <QObject>
#include "zPIGlobals.h"

class IzWaifuEngine;

class ZPI_EXPORT IzWaifuFeaturePlugin
{
public:
    virtual ~IzWaifuFeaturePlugin() = default;

    virtual bool initialize(IzWaifuEngine *zWaifuEngine) = 0;
};

#define zWaifuFeaturePluginInterface_iid "moe.poteko.zWaifu.zPI.FeaturePluginInterface"

Q_DECLARE_INTERFACE(IzWaifuFeaturePlugin, zWaifuFeaturePluginInterface_iid)


#endif // IZWAIFUFEATUREPLUGIN_H