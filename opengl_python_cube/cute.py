# -*- coding: utf-8 -*-

import sys
from PyQt4 import QtGui
from PyQt4 import QtCore

# -*- coding: utf-8 -*-
import sys
from PyQt4 import QtCore, QtGui


class AgeSelector(QtGui.QWidget):
    def __init__(self,*args):
        QtGui.QWidget.__init__(self,*args)
        self.setWindowTitle(u"Вводим свой возраст")

        spinbox = QtGui.QSpinBox()
        slider = QtGui.QSlider(QtCore.Qt.Horizontal)

        spinbox.setRange(0, 130)
        slider.setRange(0, 130)

        self.connect(spinbox, QtCore.SIGNAL("valueChanged(int)"), \
                slider, QtCore.SLOT("setValue(int)"))
        self.connect(slider, QtCore.SIGNAL("valueChanged(int)"), \
                spinbox, QtCore.SLOT("setValue(int)"))
        self.connect(spinbox, QtCore.SIGNAL("valueChanged(int)"), self.log_to_console)

        spinbox.setValue(27)

        layout = QtGui.QHBoxLayout()
        layout.addWidget(spinbox)
        layout.addWidget(slider)
        self.setLayout(layout)
    
    def log_to_console(self,i):
        print i

if __name__=="__main__":
    app = QtGui.QApplication(sys.argv)
    age_sel = AgeSelector()
    age_sel.show()
    sys.exit(app.exec_())
