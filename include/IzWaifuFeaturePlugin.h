#ifndef IZWAIFUFEATUREPLUGIN_H
#define IZWAIFUFEATUREPLUGIN_H

#include <QObject>

#include "IzWaifuPluginBase.h"
#include "zPIGlobals.h"

class ZPI_EXPORT IzWaifuFeaturePlugin : public IzWaifuPluginBase
{
public:
    virtual ~IzWaifuFeaturePlugin() = default;

    enum class FeatureType : std::uint32_t
    {
        ActiveWithGui = 0x01,
        ActiveWithoutGui = 0x02,
        PassiveWithGui = 0x04,
        PassiveWithoutGui = 0x08,
    };

    virtual FeatureType featureType() = 0;

    /**
     * @brief
     * The function activates this feature. Only applies to plugin which is a Active-type feature
     * @return Whether the feature has been activated successfully
     */
    virtual bool activate() = 0;


    /**
     * @brief
     * The function deactivates this feature. Only applies to plugin which is a Active-type feature
     * @return Whether the feature has been deactivated successfully
     */
    virtual bool deactivate() = 0;

    /**
     * @brief
     * The function returns the name of this feature. The name will be used in activate button in UI as well
     * @return The name of this feature
     */
    virtual QString featureName() = 0;

    /**
     * @brief
     * This function returns a unique ID of this feature
     * @return
     */
    virtual QUuid featureId() = 0;
};

#define zWaifuFeaturePluginInterface_iid "moe.poteko.zWaifu.zPI.FeaturePluginInterface"

Q_DECLARE_INTERFACE(IzWaifuFeaturePlugin, zWaifuFeaturePluginInterface_iid)


#endif // IZWAIFUFEATUREPLUGIN_H
