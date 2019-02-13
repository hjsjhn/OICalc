#include "calc.h"
#include "quickPow.h"
#include "log2.h"
#include "IntInv.h"
#include "calcMath.h"

#include <QWidget>
#include <QDesktopWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

calc::calc (QMainWindow *parent) : QMainWindow(parent) {
    initUI();
}

void calc::initUI () {
    this -> resize(400, 400);
    this -> makeCenter();
    this -> createLabel();
    this -> createButton();
    this -> createLayout();
}

void calc::makeCenter () {
    auto ctr = this -> frameGeometry();
    auto cp = QDesktopWidget().availableGeometry().center();
    ctr.moveCenter(cp);
    this -> move(ctr.topLeft());
}

void calc::createLabel () {
    Display = new QLabel( tr("<strong>OI Calculator</strong>"));
    Display -> setAlignment(Qt::AlignCenter);
    Display -> setWordWrap(true);
    QFont font;
    font.setPointSize(20);
    Display -> setFont(font);
}

void calc::createButton () {
    qpow = new QPushButton ( tr("整数快速幂"), this);
    logt = new QPushButton ( tr("Log(2)"), this);
    IntInv = new QPushButton ( tr("整数逆元"), this);
    qpow -> setFixedHeight(40);
    logt -> setFixedHeight(40);
    IntInv -> setFixedHeight(40);
    connect(qpow, SIGNAL(clicked()), this, SLOT(calcPow()));
    connect(logt, SIGNAL(clicked()), this, SLOT(calcLog()));
    connect(IntInv, SIGNAL(clicked()), this, SLOT(calcIntInv()));
}

void calc::calcPow () {
    PowUI *PowNow;
    PowNow = new PowUI();
    PowNow -> show();
}

void calc::calcLog () {
    LogtUI *LogNow;
    LogNow = new LogtUI();
    LogNow -> show();
}

void calc::calcIntInv () {
    IntInvUI *IntInvNow;
    IntInvNow = new IntInvUI();
    IntInvNow -> show();
}

void calc::createLayout () {
    vbox = new QVBoxLayout();
    
    hbox = new QHBoxLayout();
    hbox -> addWidget(this -> Display);
    Options = new QWidget();
    Options -> setLayout(hbox);
    vbox -> addWidget(Options);
    
    hbox = new QHBoxLayout();
    hbox -> addWidget(this -> qpow);
    hbox -> addWidget(this -> logt);
    Options = new QWidget();
    Options -> setLayout(hbox);
    vbox -> addWidget(Options);

    // delete hbox, Options;
    hbox = new QHBoxLayout();
    hbox -> addWidget(this -> IntInv);
    Options = new QWidget();
    Options -> setLayout(hbox);
    vbox -> addWidget(Options);

    MainWidget = new QWidget();
    MainWidget -> setLayout(vbox);
    this -> setCentralWidget(this -> MainWidget);
    
    // delete hbox, vbox;
}
