#include "MainForm.h"

#include <QDebug>

MainForm::MainForm() {
    widget.setupUi(this);
    connect(widget.calculateButton, &QAbstractButton::pressed, this, &MainForm::calculation);
}

ContainerStringElem MainForm::parseString(const QString& inputString) const
{
    qDebug() << __func__;
    ContainerStringElem operandsOperators;
    //int pos = 0;
    QStringList list{};
    // пока оставить "([+-]?(?:\\d+(?:\\.\\d*)?|\\.\\d+)(?:[eE][+-]?\\d+)?(?![iI.\\d]))"
    QRegExp rx("([+-]?(?:\\d+(?:\\.\\d*)?|\\.\\d+)(?:[eE][+-]?\\d+)?(?![iI.\\d]))");
    int pos = rx.indexIn(inputString, pos);
    qDebug() << "!!! " << pos;
    while ((pos = rx.indexIn(inputString, pos)) != -1)
    {
        qDebug() << pos;
        list << rx.cap(1);
        list << rx.cap(3);
        pos += rx.matchedLength();
    }
    qDebug() << list;
    qDebug() << list;
    
    return operandsOperators;
}

void MainForm::calculation()
{
    ContainerStringElem ops = parseString(widget.fieldInput->text());
    qDebug() << __func__;
}

MainForm::~MainForm() {
}
