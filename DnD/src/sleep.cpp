#include <QTimer>
#include <QEventLoop>

void sleep(qint64 msec) {
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()));
    loop.exec();
}
