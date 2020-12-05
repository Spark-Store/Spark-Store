TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = third-party/QtNetworkService \
    src/spark-store.pro
    
spark-store.depends = third-party/QtNetworkService