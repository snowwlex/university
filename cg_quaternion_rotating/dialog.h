#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include "glwidget.h"

class Dialog : public QDialog {
    Q_OBJECT

public:
    Dialog(GlWidget* pyramid,QWidget *parent = 0);

private:
    void createConnects();
    void createUI();

private:
    GlWidget* myGlWidget;
    QPushButton* btn;

public slots:
    void smbd();


};

#endif // DIALOG_H
