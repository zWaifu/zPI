#ifndef IZWAIFUENGINE_H
#define IZWAIFUENGINE_H

#include <QList>
#include <QString>

class QQmlEngine;
class QQuickItem;

enum class zWaifuMotionPriority {
    PriorityNone = 0,
    PriorityIdle = 1,
    PriorityNormal = 2,
    PriorityForce = 3
};

class IzWaifuEngine
{
public:
    virtual ~IzWaifuEngine() = default;

    virtual QQmlEngine *qmlEngine() = 0;
    virtual QQuickItem *rootElement() = 0;

    virtual QList<QString> expressions() = 0;
    virtual bool setExpression(const QString &expression) = 0;

    virtual QList<QString> motionGroups() = 0;
    virtual quint32 motionCount(const QString &motionGroup) = 0;
    virtual bool setMotion(const QString &motionGroup, quint32 id, zWaifuMotionPriority motionPriority) = 0;
};

#endif // IZWAIFUENGINE_H
