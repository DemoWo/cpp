#include "src/settings.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ImageButton redButton(nullptr);
    redButton.setFixedSize(200, 200);
    redButton.move(1000, 400);
    redButton.show();

    return app.exec();
}
