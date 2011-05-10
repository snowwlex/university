#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}


class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QApplication* app, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int counterButtons,
        counterEdits,
        counterLabels;
private slots: //slots made by UI Designer
    void on_actionCreateLabel_activated();
    void on_actionCreateLineEdit_activated();
    void on_actionCreateButton_activated();
    void on_actionAboutMe_activated();
private slots: // my slots
    void slot_containerButton_clicked();
    void slot_containerLineEdit_changed(QString string);
    void slot_contextMenuShow(QPoint);

};

#endif // MAINWINDOW_H
