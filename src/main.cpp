#include <deque>
#include "filer.cpp"
#include "gui.cpp"
#include <iostream>

using namespace std;

class TasksList {
private:
    deque<string> tasks;
public:
    int add_not_important_task(string task) {
        try {
            tasks.push_back(task);
            return 0;
        }
        
        catch (const std::exception e) {
            cerr << e.what() << '\n';
            return 1;
        }
    }
    int add_important_task(string task) {
        try {
            tasks.push_front(task);
            return 0;
        }
        
        catch (const std::exception e) {
            cerr << e.what() << '\n';
            return 1;
        }
    }
    const deque<string> get_deque() { return tasks; }
};

int main(int argc, char* argv[]) {
    TasksList tl;
    Filer fl;
    App app(argc, argv);
    CurrentTaskLabel cl(app.get_main_window());
    cl.setText(QString("aboba"));
    app.get_main_window()->show();
    app.get_main_window()->setWindowTitle("Tasksfire");
    return app.exec();
}
