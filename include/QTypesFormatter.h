#ifndef QSTRINGFORMATTER_H
#define QSTRINGFORMATTER_H

#include <string>

#include <QString>
#include <QUuid>

#include <fmt/format.h>

template <>
struct fmt::formatter<QString> : fmt::formatter<std::string> {
    template <typename FormatCtx>
    auto format(const QString& str, FormatCtx& ctx)
    {
        return fmt::formatter<std::string>::format(str.toStdString(), ctx);
    }
};

template <>
struct fmt::formatter<QUuid> : fmt::formatter<QString> {
    template <typename FormatCtx>
    auto format(const QUuid& id, FormatCtx& ctx)
    {
        return fmt::formatter<QString>::format(id.toString(), ctx);
    }
};

#endif // QSTRINGFORMATTER_H
