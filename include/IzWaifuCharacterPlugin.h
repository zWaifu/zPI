#ifndef IZWAIFUCHARACTERPLUGIN_H
#define IZWAIFUCHARACTERPLUGIN_H

#include <QObject>
#include <QString>
#include <QUuid>

#include "IzWaifuPluginBase.h"
#include "zPIGlobals.h"

class ZPI_EXPORT IzWaifuCharacterPlugin : public IzWaifuPluginBase
{
public:
    virtual ~IzWaifuCharacterPlugin() = default;

    /**
     * @brief
     * The function returns the model name of the characther, e.g. 桃瀬ひより
     * @return
     */
    virtual QString modelName() const = 0;

    /**
     * @brief
     * The function returns the model file name of the character, e.g. hiyori, which is the name part of ".moc3.json" file
     * @return
     */
    virtual QString modelFileName() const = 0;

    /**
     * @brief
     * The function loads the file under model's directory
     * @param relativePath The relative path for the file being loaded
     * @return The QByteArray of the whole file. If the file fails loading, an empty QByteArray is returned
     */
    virtual QByteArray loadFile(const QString &relativePath) const = 0;

    /**
     * @brief The function returns the unique id of the character
     * @remark The id is unique in current application.
     * It may, however, changes in different app instances
     * @return
     */
    virtual QUuid characterId() const = 0;
};

#define zWaifuCharacterPluginInterface_iid "moe.poteko.zWaifu.zPI.CharacterPluginInterface"

Q_DECLARE_INTERFACE(IzWaifuCharacterPlugin, zWaifuCharacterPluginInterface_iid)

#endif // IZWAIFUCHARACTERPLUGIN_H
