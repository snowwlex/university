

#include <cmath>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

#include "maindialog.h"

MainDialog::MainDialog(QWidget *parent) :  QDialog(parent) {
    createUI();
    createConnects();
    interpolatingData.coef = 0;
}

MainDialog::~MainDialog() {

}

void MainDialog::createUI() {
    setWindowTitle("Computer Graphic: Rotation using quaternion's calculating");
    createWidgets();
    locateWidgets();
}

void MainDialog::createWidgets() {
    myGLWidget = new GlWidget();
    userPanel = new QWidget();
    lblParams = new QLabel("<center>Enter parameters:</center>");
    lblVector = new QLabel("Enter vector:");
    lblAngle  = new QLabel("Enter angle:");
    leditVectorX = new QLineEdit("X");
    leditVectorY = new QLineEdit("Y");
    leditVectorZ = new QLineEdit("Z");
    leditAngle = new QLineEdit("0");
    lblListQuaternions = new QLabel("List of rotations:");
    listQuaternions = new QListWidget();
    btnAddToList = new QPushButton("Add to list");
    btnRotate = new QPushButton("Rotate!");
    btnClearList = new QPushButton("Clear list");
    btnInterpolate = new QPushButton("Interpolate!");
    btnAbout = new QPushButton("About program");
}

void MainDialog::locateWidgets() {
    QHBoxLayout* layout = new QHBoxLayout();
    //QVBoxLayout* glLayout = new QVBoxLayout();
    QVBoxLayout* userLayout = new QVBoxLayout();
    this->setLayout(layout);

    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    //glLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    //glLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    layout->addWidget(myGLWidget);
    layout->addWidget(userPanel);
    userPanel->setLayout(userLayout);
    userLayout->setAlignment(Qt::AlignTop);
    userLayout->setSizeConstraint(QLayout::SetFixedSize);
    userLayout->addWidget( lblParams );

    QHBoxLayout* l = new QHBoxLayout();
    l->addWidget(lblVector);
    l->addWidget(leditVectorX);
    l->addWidget(leditVectorY);
    l->addWidget(leditVectorZ);
    userLayout->addLayout(l);

    l = new QHBoxLayout();
    l->addWidget(lblAngle);
    l->addWidget(leditAngle);
    userLayout->addLayout(l);

    userLayout->addWidget(btnAddToList);
    userLayout->addSpacing(20);
    userLayout->addWidget(lblListQuaternions);
    userLayout->addWidget(listQuaternions);
    userLayout->addWidget(btnClearList);

    userLayout->addSpacing(20);
    l = new QHBoxLayout();
    userLayout->addLayout(l);
    l->addWidget(btnRotate);
    l->addWidget(btnInterpolate);

    userLayout->addSpacing(40);
    userLayout->addWidget(btnAbout);
    userPanel->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
    userPanel->setFixedWidth(200);

//    myGLWidget->setSizePolicy(QSizePolicy(QSizePolicy::QSizePolicy::Maximum));
    myGLWidget->setMinimumSize(600,600);
    myGLWidget->setMaximumSize(1000,1000);
}

void MainDialog::createConnects() {
    connect(btnAddToList, SIGNAL(clicked()), this, SLOT(addToList()));
    connect(btnClearList, SIGNAL(clicked()), this, SLOT(clearList()));
    connect(btnRotate, SIGNAL(clicked()), this, SLOT(rotate()));
    connect(btnInterpolate, SIGNAL(clicked()), this, SLOT(interpolate()));
    connect(btnAbout, SIGNAL(clicked()), this, SLOT(showAbout()));

}

void MainDialog::addToList() {
    bool ok1,ok2,ok3,ok4;
    double x = leditVectorX->text().toDouble(&ok1);
    double y = leditVectorY->text().toDouble(&ok2);
    double z = leditVectorZ->text().toDouble(&ok3);
    double angle = leditAngle->text().toDouble(&ok4);
    if ( (ok1 && ok2 && ok3 && ok4) == false) {
        QMessageBox(QMessageBox::Warning, "Error!", "Params you had typed are incorrect!", QMessageBox::Ok ).exec();
        return;
    }
    RotateQuaternion q(angle, Vector3D(x,y,z));
    curListRotates.append(q);
    listQuaternions->addItem(QString("Rotating around (%1;%2;%3) on %4 degrees").arg(x).arg(y).arg(z).arg(angle));

}

void MainDialog::rotate() {
    curRotate = countResultRotate();
    makeRotate(curRotate);
}

RotateQuaternion MainDialog::countResultRotate() const {
    RotateQuaternion result = curRotate;
    for (int i=0; i<curListRotates.length(); ++i) {
        result *= curListRotates.at(i);
    }
    return result;
}


void MainDialog::clearList() {
    curListRotates.clear();
    listQuaternions->clear();
}

void MainDialog::interpolate() {

    if (curListRotates.length() == 0) {
        return;
    }

    const int updTime = 50;
    const double step = 0.05;

    if (interpolatingData.coef > 1) {
        curRotate = interpolatingData.dest;
        makeRotate(curRotate);
        interpolatingData.coef = 0;
        userPanel->setEnabled(true);
        return;
    }

    if (interpolatingData.coef == 0) {
        interpolatingData.init = curRotate;
        interpolatingData.dest = countResultRotate();
        userPanel->setEnabled(false);
    }

    RotateQuaternion result = RotateQuaternion::interpolate(interpolatingData.init, interpolatingData.dest, interpolatingData.coef);
    makeRotate(result);

    interpolatingData.coef += step;
    QTimer::singleShot(updTime, this, SLOT(interpolate()));
}

void MainDialog::makeRotate(const RotateQuaternion& quaternion) {
    double m[16];
    quaternion.toRotateMatrix(m);
    myGLWidget->setMatrix(m);
    myGLWidget->updateGL();
}

void MainDialog::showAbout() {
    QMessageBox(QMessageBox::Information,
               "About program",
               "<p style='font-weight:bold'>This program shows how quaternions are used for implemention of rotating.</p><p>Made by:</p><p>Turkin Alexander, Nesterov Maxim (group 7372, SPB ETU)</p>", QMessageBox::Ok ).exec();
}

