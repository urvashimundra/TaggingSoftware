#include "mainwindow.h"
#include "dataaccess.h"
#include <QApplication>

static const QString styleSheet =
        "QMainWindow { "
        "  background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 2, stop: 0 grey, stop: 0.8 white); "
        "}"

        "QLabel#titleLabel { font: bold 12px; }"

        "QTabWidget::pane { "
        "  border: 2px solid #BB7365; "
        "  background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 2, stop: 0 pink, stop: 1 pink); "
        "  border-radius: 4px; "
        "  margin-left: 8px; "
        "  margin-right: 8px; "
        "  margin-bottom: 8px; "
        "}"

        "QTabWidget::tab-bar { "
        "  alignment: center; "
        "}"

        "QTabBar::tab { "
        "  border: 2px solid #8F8F91; "
        "  border-bottom: 0px; "
        "  border-top-left-radius: 4px; "
        "  border-top-right-radius: 4px; "
        "  min-width: 20ex; "
        "  padding: 6px; "
        "}"

        "QTabBar::tab:selected { "
        "  border-color: #BB7365; "
        "  background: #DEADA1; "
        "  margin-left: -4px; "
        "  margin-right: -4px; "
        "}"

        "QTabBar::tab:!selected { "
        "  background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #F6F7FA, stop: 1 #DADBDE); "
        "  margin-top: 2px; "
        "}"

        "QTabBar::tab:first:selected { "
        "  margin-left: 0; "
        "}"

        "QTabBar::tab:last:selected { "
        "  margin-right: 0; "
        "}"

        "QTabBar::tab:only-one { "
        "  margin: 0; "
        "}"

        "QGroupBox { "
        "  background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 2, stop: 0 #B3B3D7, stop: 1 #C2ABAB); "
        "  border: 2px solid #6B78B4; "
        "  border-radius: 5px; "
        "  padding-left: 12px; "
        "  padding-right: 12px; "
        "  padding-bottom: 12px; "
        "}"

        "QLineEdit, QListWidget, QListView, QTableView { "
        "  min-height: 20px; "
        "  border: 1px solid #6B78B4; "
        "  border-radius: 4px; "
        "}"

        "QPushButton { "
        "  border: 2px solid #8F8F91; "
        "  border-radius: 6px; "
        "  background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #F6F7FA, stop: 1 #DADBDE); "
        "  min-width: 80px;"
        "  min-height: 22px;"
        "}"

        "QPushButton:checked { "
        "  color: white; "
        "  background-color: #505050; "
        "  border: none; "
        "}"

        "QTableView { background: lightGray }"
        "QTableView::item { background-color: pink }"
        "QTableView::item:selected { background-color: palette(highlight); }"

        "QHeaderView::section {"
        "  padding: 2px; "
        "  border: 1px solid lightGray; "
        "}"
        ;


int main(int argc, char *argv[])
{

    QString datbase_name = "tags.sqlite";
    if (argc > 1)
        datbase_name = QString(argv[1]);

    QApplication app(argc, argv);
    app.setStyleSheet(styleSheet);

    DataAccess database_value(datbase_name);
    database_value.OpenOrCreate();

    MainWindow window(database_value);
    window.readPositionSettings();
    window.show();

    return app.exec();
}
