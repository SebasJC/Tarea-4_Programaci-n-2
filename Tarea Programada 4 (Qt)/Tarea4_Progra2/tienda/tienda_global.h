#ifndef TIENDA_GLOBAL_H
#define TIENDA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TIENDA_LIBRARY)
#  define TIENDA_EXPORT Q_DECL_EXPORT
#else
#  define TIENDA_EXPORT Q_DECL_IMPORT
#endif

#endif // TIENDA_GLOBAL_H
