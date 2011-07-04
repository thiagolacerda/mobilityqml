#include "accelerometerreader.h"

#include <QtGui/QApplication>
#include <QtDeclarative>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView view;

    QDeclarativeEngine *engine = view.engine();

    AccelerometerReader reader;

    engine->rootContext()->setContextProperty("accelerometerReader", &reader);

    view.setSource(QUrl("qrc:/Gui.qml"));
    view.setResizeMode(QDeclarativeView::SizeRootObjectToView);

#if defined(Q_WS_MAEMO_5) || defined(Q_OS_SYMBIAN) || defined(Q_WS_SIMULATOR)
    view.setGeometry(QApplication::desktop()->screenGeometry());
    view.showFullScreen();
#else
    view.setGeometry((QRect(100, 100, 800, 480)));
    view.show();
#endif

    return app.exec();
}
