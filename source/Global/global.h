#pragma once

#include <QtCore/QtGlobal>

#define D_EXPORT 1

#ifdef D_EXPORT
#define EXPORT_API Q_DECL_EXPORT
#else
#define EXPORT_API Q_DECL_IMPORT
#endif