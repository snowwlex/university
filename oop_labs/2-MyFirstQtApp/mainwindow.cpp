#include <QtGui>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paramsdialog.h"

MainWindow::MainWindow(QApplication* app, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    counterButtons(0),
    counterEdits(0),
    counterLabels(0)
{
    ui->setupUi(this);

    //connect to slots:
    connect(ui->actionAboutQt,SIGNAL(triggered()),app,SLOT(aboutQt()));
    connect(ui->actionExit, SIGNAL(triggered()), SLOT(close()));
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), SLOT(slot_contextMenuShow(QPoint)));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::slot_containerButton_clicked() {
   QMessageBox("Info", sender()->objectName(), QMessageBox::Information, QMessageBox::Ok,0,0).exec();
}

void MainWindow::slot_containerLineEdit_changed(QString string) {
    string = "name: " + sender()->objectName()+ ", value: " + string;
    ui->statusBar->showMessage(string,3000);
}


void MainWindow::on_actionAboutMe_activated()
{
     QMessageBox("About me", "Made by\nTurkin Alexander", QMessageBox::Information, QMessageBox::Ok,0,0).exec();
}

void MainWindow::on_actionCreateButton_activated()
{
    QWidget* newWidget;
    QString name,content;
    ParamsDialog* pParamsDialog = new ParamsDialog;
    if (pParamsDialog->exec() == QDialog::Accepted) {
        content = "Button: " + pParamsDialog->getObjectText();
        for (int i=0; i < pParamsDialog->getObjectsQuantity(); ++i) {
            name = "btn" + QString::number(counterButtons++);
            newWidget = new QPushButton(content);
            connect(newWidget, SIGNAL(clicked()),SLOT(slot_containerButton_clicked()));
            newWidget->setObjectName(name);
            ui->layoutContainer->addWidget( newWidget );
        }
    }
    delete pParamsDialog;
}

void MainWindow::on_actionCreateLineEdit_activated()
{
    QWidget* newWidget;
    QString name,content;
    ParamsDialog* pParamsDialog = new ParamsDialog;
    if (pParamsDialog->exec() == QDialog::Accepted) {
        content = "Line Edit: " + pParamsDialog->getObjectText();
        for (int i=0; i < pParamsDialog->getObjectsQuantity(); ++i) {
            name = "lineEdit" + QString::number(counterEdits++);
            newWidget = new QLineEdit(content);
            connect(newWidget, SIGNAL(textChanged(QString)),SLOT( slot_containerLineEdit_changed(QString) ) );
            newWidget->setObjectName(name);
            ui->layoutContainer->addWidget( newWidget );
        }
    }
    delete pParamsDialog;
}

void MainWindow::on_actionCreateLabel_activated()
{
    QWidget* newWidget;
    QString name,content;
    ParamsDialog* pParamsDialog = new ParamsDialog;
    if (pParamsDialog->exec() == QDialog::Accepted) {
        content = "Label: " + pParamsDialog->getObjectText();
        for (int i=0; i < pParamsDialog->getObjectsQuantity(); ++i) {
            name = "lbl" + QString::number(counterLabels++);
            newWidget = new QLabel(content);
            newWidget->setObjectName(name);
            ui->layoutContainer->addWidget( newWidget );
        }
    }
    delete pParamsDialog;
}

void MainWindow::slot_contextMenuShow(QPoint position) {
    ui->menuCreate->exec(position);
}
