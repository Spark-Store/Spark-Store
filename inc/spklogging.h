
/**
 * @brief Simple logging for Spark Store
 */

#pragma once

#pragma push_macro("signals")
#undef signals
#include <libnotify/notify.h>
#define signals DUMMY
#pragma pop_macro("signals")
#include <QString>
#include <QStringListModel>
#include <QTextStream>
#include <QFile>

class SpkLogger
{
    QStringListModel mLogData;
    QString mLogPath;
    QFile mLogFile;
    QTextStream mLogWriter;
    static SpkLogger *Instance;
    void Initialize(QString suggestPath = "");
    bool NotifyViable = false;

  public:
    SpkLogger(QString suggestPath = "");
    ~SpkLogger();
    static SpkLogger *GetInstance() { return Instance; };
    void Log(QString message);
    void Warning(QString message);
    void Error(QString message, bool pop = false);
    void Critical(QString message);
    void Notify(QString);
};

#define sLog(X) SpkLogger::GetInstance()->Log(X)
#define sWarn(X) SpkLogger::GetInstance()->Warning(X)
#define sErr(X) SpkLogger::GetInstance()->Error(X)
#define sErrPop(X) SpkLogger::GetInstance()->Error(X,true)
#define sCritical(X) SpkLogger::GetInstance()->Critical(X)
#define sNotify(X) SpkLogger::GetInstance()->Notify(X)
