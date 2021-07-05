
#pragma once

#include <QMap>
#include <QString>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>

#include "spklogging.h"
#include "spkmainwindow.h"

/**
 * @brief SpkStore class is the core of the store client side program, it is constructed first and
 *        handling all processing after the launch. All client side data should be held by it,
 *        including preferences class, category names, request URLs, downloads status, packaging
 *        backend interfaces and so on.
 */
class SpkStore : public QObject
{
    Q_OBJECT
  public:
    static SpkStore *Instance;
    SpkStore(bool aCli, QString &aLogPath);
    ~SpkStore();

    SpkMainWindow* GetRootWindow() { return mMainWindow; }

  private:
    SpkLogger *mLogger;
    SpkMainWindow *mMainWindow = nullptr;

    QNetworkAccessManager *mNetMgr = nullptr;

  // Following are stationary signal-slot bindings between UI and Store, mostly for handling
  // API calls and resource downloading.
  public slots:

//    void RequestStoreMetadata(); ///< All required metadata the store needs when launched
//    void RequestCategoryPage(int aCategoryId);
//    void RequestApplicationMetadata(int aAppId);
//    void RequestRefreshApiUrls(QString aCustomUrl);
  signals:
    void StatusStoreMetadata(QNetworkReply::NetworkError, QString);
    void StatusCategoryPage(QNetworkReply::NetworkError, QString);
    void StatusApplicationMetadata(QNetworkReply::NetworkError, QString);
    void StatusRefreshApiUrls(QNetworkReply::NetworkError, QString);

  private:
    // Store manages all kinds of possible replies, and the caller can only get JSON they need
    QNetworkReply *mReplyStoreMetadata = nullptr,
                  *mReplyCategory = nullptr,
                  *mReplyAppMetadata = nullptr,
                  *mReplyApiUrls = nullptr;
};
