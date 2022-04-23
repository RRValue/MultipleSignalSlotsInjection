#pragma once

#include <QtCore/QtGlobal>

#ifdef D_EXPORT
#define EXPORT_API Q_DECL_EXPORT
#else
#define EXPORT_API Q_DECL_IMPORT
#endif