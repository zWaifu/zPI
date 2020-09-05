#ifndef IZWAIFUENGINE_H
#define IZWAIFUENGINE_H

#include <spdlog/spdlog.h>

#include <QObject>
#include <QList>
#include <QString>

#include "zPIGlobals.h"

class QQmlEngine;
class QQuickItem;

enum class zWaifuMotionPriority {
    PriorityNone = 0,
    PriorityIdle = 1,
    PriorityNormal = 2,
    PriorityForce = 3
};

class ZPI_EXPORT AzWaifuEngine : public QObject
{
    Q_OBJECT

protected:
    AzWaifuEngine() = default;

public:
    virtual ~AzWaifuEngine() = default;

    virtual spdlog::logger* logger() const = 0;

    virtual QQmlEngine *qmlEngine() = 0;
    virtual QQuickItem *rootElement() = 0;

    virtual QString currentCharacter() const = 0;
    virtual QList<QString> characters() const = 0;
    virtual bool setCharacter(const QString &character) = 0;

    virtual QList<QString> expressions() const = 0;
    virtual bool setExpression(const QString &expression) = 0;

    virtual QList<QString> motionGroups() const = 0;
    virtual quint32 motionCount(const QString &motionGroup) const = 0;
    virtual bool setMotion(const QString &motionGroup, quint32 id, zWaifuMotionPriority motionPriority) = 0;

signals:
    void characterChanged(const QString &characterName);
    void expressionChanged(const QString &expression);
    void motionChanged(const QString &motionGroup, int id);
};

#endif // IZWAIFUENGINE_H
