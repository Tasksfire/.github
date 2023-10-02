#include <QWidget>
#include <QApplication>
#include <iostream>
#include <QString>
#include <QPushButton>
#include <QLabel>

using namespace std;

class App {
    QApplication* app;
    QWidget* main_window;
public:
    App(int argc, char* argv[]) {
        app = new QApplication(argc, argv);
        main_window = new QWidget();
    }
    void show_main_window() {
        main_window->show();
    }
    QWidget* get_main_window() {
        return main_window;
    }
    int exec() {
        return app->exec();
    }
};

class CurrentTaskLabel : public QLabel {
public:
    CurrentTaskLabel(QWidget* win) : QLabel(win) {
    }
    void set_text(string text) { 
        QString str(text.c_str());
        this->setText(str);
    }
};
