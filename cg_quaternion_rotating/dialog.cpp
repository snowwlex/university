#include "dialog.h"
#include <QApplication>

Dialog::Dialog(GlWidget* glwidget, QWidget *parent) : QDialog(parent), myGlWidget(glwidget) {
    createUI();
    createConnects();
}


void Dialog::createUI() {
    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);
    btn = new QPushButton("asd");
    layout->addWidget( btn );
}

void Dialog::createConnects() {
    connect(btn, SIGNAL(clicked()), this, SLOT(smbd()));
    //connect(this, SIGNAL(, qApp, SLOT(quit()));
}

void Dialog::smbd() {
    this->myGlWidget->resize(500,500);
}
