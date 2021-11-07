#ifndef _MAINFORM_H
#define _MAINFORM_H

#include <QPushButton>

#include <QRegularExpression>

#include "ui_MainForm.h"


#include "utils.h"

class MainForm : public QDialog {
    Q_OBJECT
std::map<std::string, Complex (*)(Complex, Complex)> m_ops
{
    {"+", [](Complex a, Complex b) { return a + b; }},
    {"-", [](Complex a, Complex b) { return a - b; }},
    {"*", [](Complex a, Complex b) { return a * b; }},
    {"/", [](Complex a, Complex b) { return a / b; }},
    //{"^", [](double a, double b) { return pow(a, b); }},
    //{"%", [](double a, double b) { return fmod(a, b); }},
};
    
public:
    MainForm();
    ContainerStringElem parseString(const QString& inputString) const;
    virtual ~MainForm();
private slots:
    void calculation();
private:
    //std::stack<ContainerStringElem> m_solutionStack; // храняться операторы и операнды
    Ui::MainForm widget;
};

#endif /* _MAINFORM_H */
