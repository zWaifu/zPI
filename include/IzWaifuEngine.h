#ifndef IZWAIFUENGINE_H
#define IZWAIFUENGINE_H

#include <spdlog/spdlog.h>

#include <QObject>
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
protected:
    IzWaifuEngine() = default;

public:
    virtual ~IzWaifuEngine() = default;

    virtual spdlog::logger* logger() = 0;

    virtual QQmlEngine *qmlEngine() = 0;
    virtual QQuickItem *rootElement() = 0;
    virtual QList<QString> expressions() = 0;
    virtual bool setExpression(const QString &expression) = 0;

    virtual QList<QString> motionGroups() = 0;
    virtual quint32 motionCount(const QString &motionGroup) = 0;
    virtual bool setMotion(const QString &motionGroup, quint32 id, zWaifuMotionPriority motionPriority) = 0;

signals:
    virtual void characterChanged(const QString &characterName) = 0;
    virtual void expressionChanged(const QString &expression) = 0;
    virtual void motionChanged(const QString &motionGroup, int id) = 0;
};

#endif // IZWAIFUENGINE_H
