#ifndef IZWAIFUCHARACTERPLUGIN_H
#define IZWAIFUCHARACTERPLUGIN_H

#include <QObject>
#include <QString>
#include "zPIGlobals.h"

class IzWaifuEngine;

class ZPI_EXPORT IzWaifuCharacterPlugin
{
public:
    virtual ~IzWaifuCharacterPlugin() = default;

    virtual QString name() = 0;
    virtual QByteArray loadFile(const QString &path) = 0;
};

#define zWaifuCharacterPluginInterface_iid "moe.poteko.zWaifu.zPI.CharacterPluginInterface"

Q_DECLARE_INTERFACE(IzWaifuCharacterPlugin, zWaifuCharacterPluginInterface_iid)

#endif // IZWAIFUCHARACTERPLUGIN_H
