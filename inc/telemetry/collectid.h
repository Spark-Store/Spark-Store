
#pragma once

#include <QObject>
#include <QFile>

namespace SpkTelemetry
{
  void FunCollectId()
  {
#if !defined(NDEBUG) || !defined(SPARK_FORCE_TELEMETRY) // Debug builds shouldn't transmit telemetry data unless asked for
    return;
#else
    QFile idFile("/etc/machine-id");
    if(!idFile.open(QFile::ReadOnly))
      return;
    auto machineId = idFile.readAll();
#endif
  }
}
