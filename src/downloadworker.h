#ifndef DOWNLOADWORKER_H
#define DOWNLOADWORKER_H

#include <QObject>
#include <QList>
#include <QFile>
#include <QNetworkReply>

class DownloadWorker : public QObject
{
    Q_OBJECT

public:
    explicit DownloadWorker(QObject *parent = nullptr);

    void setIdentifier(int identifier);
    void setParamter(const QString &url, QPair<qint64, qint64> range, QFile *flle);
    qint64 getReceivedPos();

public slots:
    void doWork();
    void doStop();
    void dataReady();
    void slotFinish();
    void handleProcess(qint64, qint64);

private:
    int identifier;
    QString url;
    qint64 startPos;
    qint64 endPos;
    qint64 receivedPos = 0;
    QNetworkReply *reply;
    QNetworkAccessManager *mgr;
    QFile *file;

signals:
    void resultReady(int identifier, QByteArray data);
    void testSignals();
    void workFinished();
    void downloadProcess();

};

class DownloadController : public QObject
{
    Q_OBJECT

public:
    explicit DownloadController(QObject *parent = nullptr);
    ~DownloadController();

    void setFilename(QString filename);
    void setThreadNum(int threadNum);
    void startDownload(const QString &url);
    void stopDownload();
    qint64 getFileSize(const QString& url);
    QString replaceDomain(const QString& url, const QString domain);

private:
    int threadNum;
    QString filename;
    qint64 fileSize;
    QVector<QPair<qint64, qint64>> ranges;
    QFile *file;
    QList<DownloadWorker*> workers;
    int finish = 0;
    QVector<QString> domains;

public slots:
    void handleProcess();
    void chunkDownloadFinish();

signals:
    void errorOccur(const QString& msg);
    void downloadProcess(qint64, qint64);
    void downloadFinished();

};

#endif // FILEDOWNLOADWORKER_H
