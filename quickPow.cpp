#include "quickPow.h"
#include "calcMath.h"
#include "tool.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <Qt>
#include <cstdio>

using namespace std;
typedef __int128 ll;

PowUI::PowUI (QWidget *parent) : QWidget(parent) {
    this -> setFixedSize(350, 240);
    this -> makeCenter();
    this -> createLabel();
    this -> createEditor();
    this -> createButton();
    this -> createLayout();
}

void PowUI::makeCenter () {
    auto ctr = this -> frameGeometry();
    auto cp = QDesktopWidget().availableGeometry().center();
    ctr.moveCenter(cp);
    this -> move(ctr.topLeft());
}

void PowUI::createLabel () {
    BaseText = new QLabel(this);
    IndexText = new QLabel(this);
    MODText = new QLabel(this);
    Ans = new QLabel(this);
    BaseText -> setText("底数");
    IndexText -> setText("指数");
    MODText -> setText("模数(不合法或空表示不选此项)");
    Ans -> setText("0");
    Ans -> setFixedHeight(30);
    Ans -> setFixedWidth(320);
    Ans -> setAlignment(Qt::AlignRight);
    Ans -> setTextInteractionFlags(Qt::TextSelectableByMouse); 
}

void PowUI::createEditor () {
    Index = new QLineEdit(this);
    Base = new QLineEdit(this);
    MOD = new QLineEdit(this);
    Base -> setFixedWidth(180);
    Index -> setFixedWidth(120);
    MOD -> setFixedWidth(200);
    connect(this -> Index, SIGNAL(returnPressed()), this, SLOT(OKPow()));
    connect(this -> MOD, SIGNAL(returnPressed()), this, SLOT(OKPow()));
}

void PowUI::createButton () {
    this -> BtnCancel = new QPushButton( tr("Cancel"), this);
    this -> BtnOK = new QPushButton( tr("OK"), this);
    connect(BtnCancel, SIGNAL(clicked()), this, SLOT(CancelPow()));
    connect(BtnOK, SIGNAL(clicked()), this, SLOT(OKPow()));
}

void PowUI::createLayout () {
    BaseText -> move (15, 50);
    IndexText -> move(210, 50);
    MODText -> move(15, 110);
    Ans -> move(15, 20);
    Base -> move(15, 70);
    Index -> move(210, 70);
    MOD -> move(15, 140);
    
    this -> BtnCancel -> move(130, 180);
    this -> BtnOK -> move(240, 180);
    this -> setTabOrder(Base, Index);
    this -> setTabOrder(Index, MOD);
    this -> setTabOrder(MOD, BtnOK);
}

void PowUI::CancelPow () {
    this -> close();
}

void PowUI::OKPow () {
    if (!TransQStringToLL(this -> Base -> text(), Bs) || !TransQStringToLL(this -> Index -> text(), Idx)) {
        QMessageBox::warning(NULL, "Warning!", "不合法的输入", QMessageBox::Yes);
    } else {
        if (TransQStringToLL(this -> MOD -> text(), Md))
            Ans -> setText(TransLLToQString(quick_pow(Bs, Idx, Md)));
        else
            Ans -> setText(TransLLToQString(quick_pow(Bs, Idx)));
    }
}
