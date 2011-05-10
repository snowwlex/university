#ifndef PARAMSWINDOW_H
#define PARAMSWINDOW_H

#include <QDialog>

namespace Ui {
    class ParamsDialog;
}


class ParamsDialog : public QDialog {
    Q_OBJECT
    public: //constructors
        ParamsDialog(QWidget *parent = 0);
        ~ParamsDialog();
    public: //data getters
        QString getObjectText();
        int getObjectsQuantity();
    private:
        Ui::ParamsDialog *ui;
    private:
        int myQuantityObjects;


    private slots: // slots made by qt creator
        void on_btnOpenFile_clicked();
    private slots: //my slots
        void slot_radioButtonClicked();
};

#endif // PARAMSWINDOW_H
