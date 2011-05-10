#include <QtGui>
#include "paramsdialog.h"
#include "ui_paramsdialog.h"

ParamsDialog::ParamsDialog(QWidget *parent) :
     QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint),
    ui(new Ui::ParamsDialog),
    myQuantityObjects(0)
{

    ui->setupUi(this);

    connect(ui->rbtnChoose1,SIGNAL(clicked()),SLOT(slot_radioButtonClicked()));
    connect(ui->rbtnChoose2,SIGNAL(clicked()),SLOT(slot_radioButtonClicked()));
    connect(ui->rbtnChoose3,SIGNAL(clicked()),SLOT(slot_radioButtonClicked()));
    connect(ui->rbtnChoose4,SIGNAL(clicked()),SLOT(slot_radioButtonClicked()));

    ui->rbtnChoose1->click();
}


ParamsDialog::~ParamsDialog()
{
 delete ui;
}


void ParamsDialog::on_btnOpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Opening file", "", "Text files (*.txt)");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    ui->editObjectText->setText(file.readLine());
    file.close();
}

QString ParamsDialog::getObjectText() {
    return ui->editObjectText->text();
}

int ParamsDialog::getObjectsQuantity() {
    return myQuantityObjects;
}

void ParamsDialog::slot_radioButtonClicked() {
    if (ui->rbtnChoose1->isChecked()) {
        myQuantityObjects = 1;
    } else if (ui->rbtnChoose2->isChecked()) {
        myQuantityObjects = 2;
    } else if (ui->rbtnChoose3->isChecked()) {
        myQuantityObjects = 3;
    } else if (ui->rbtnChoose4->isChecked()){
        myQuantityObjects = 4;
    }
}
