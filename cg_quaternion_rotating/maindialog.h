#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QList>
#include "quaternion.h"
#include "glwidget.h"


struct InterpolatingData {
    RotateQuaternion init;
    RotateQuaternion dest;
    double coef;
};

class MainDialog : public QDialog {
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

private:
    void createConnects();
    void createUI();
    void createWidgets();
    void locateWidgets();
    void updateList();
    RotateQuaternion countResultRotate() const;
    void makeRotate(const RotateQuaternion& quaternion);

private:

    GlWidget* myGLWidget;
    QWidget* userPanel;
    QLabel*  lblParams;
    QLabel*  lblVector;
    QLabel*  lblAngle;
    QLabel* lblListQuaternions;
    QLineEdit* leditVectorX;
    QLineEdit* leditVectorY;
    QLineEdit* leditVectorZ;
    QLineEdit* leditAngle;
    QListWidget* listQuaternions;
    QPushButton* btnAddToList;
    QPushButton* btnRotate;
    QPushButton* btnClearList;
    QPushButton* btnInterpolate;
    QPushButton* btnAbout;


private:
    InterpolatingData interpolatingData;
    RotateQuaternion curRotate;
    QList<RotateQuaternion> curListRotates;


public slots:
    void addToList();
    void rotate();
    void clearList();
    void interpolate();
    void showAbout();


};

#endif // MAINDIALOG_H
