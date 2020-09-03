#ifndef ZPIGLOBALS_H
#define ZPIGLOBALS_H

#include <QtCore/qglobal.h>

#if defined(ZPI_LIBRARY)
#  define ZPI_EXPORT Q_DECL_EXPORT
#else
#  define ZPI_EXPORT Q_DECL_IMPORT
#endif

#endif // ZPIGLOBALS_H
