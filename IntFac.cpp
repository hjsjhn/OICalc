#include "IntFac.h"
#include "calcMath.h"
#include "tool.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <Qt>
#include <cstdio>

using namespace std;
typedef __int128 ll;

IntFacUI::IntFacUI (QWidget *parent) : QWidget(parent) {
    this -> setFixedSize(350, 240);
    this -> makeCenter();
    this -> createLabel();
    this -> createEditor();
    this -> createButton();
    this -> createLayout();
}

void IntFacUI::makeCenter () {
    auto ctr = this -> frameGeometry();
    auto cp = QDesktopWidget().availableGeometry().center();
    ctr.moveCenter(cp);
    this -> move(ctr.topLeft());
}

void IntFacUI::createLabel () {
    BaseText = new QLabel(this);
    MODText = new QLabel(this);
    Ans = new QLabel(this);
    QFont font;
    font.setPointSize(16);
    BaseText -> setFont(font);
    BaseText -> setText("!");
    MODText -> setText("模数(不合法或空表示不选此项)");
    Ans -> setText("0");
    Ans -> setFixedHeight(30);
    Ans -> setFixedWidth(320);
    Ans -> setAlignment(Qt::AlignRight);
    Ans -> setTextInteractionFlags(Qt::TextSelectableByMouse); 
}

void IntFacUI::createEditor () {
    Base = new QLineEdit(this);
    MOD = new QLineEdit(this);
    // Index -> setText("Please Input Index");
    // Base -> setText("Please Input Base");
    Base -> setFixedWidth(220);
    Base -> setAlignment(Qt::AlignRight);
    MOD -> setFixedWidth(220);
    connect(this -> Base, SIGNAL(returnPressed()), this, SLOT(OKIntFac()));
    connect(this -> MOD, SIGNAL(returnPressed()), this, SLOT(OKIntFac()));
}

void IntFacUI::createButton () {
    this -> BtnCancel = new QPushButton( tr("Cancel"), this);
    this -> BtnOK = new QPushButton( tr("OK"), this);
    connect(BtnCancel, SIGNAL(clicked()), this, SLOT(CancelIntFac()));
    connect(BtnOK, SIGNAL(clicked()), this, SLOT(OKIntFac()));
}

void IntFacUI::createLayout () {
    BaseText -> move (240, 70);
    MODText -> move(15, 110);
    Ans -> move(15, 20);
    Base -> move(15, 70);
    MOD -> move(15, 140);
    this -> BtnCancel -> move(130, 200);
    this -> BtnOK -> move(240, 200);
    this -> setTabOrder(Base, MOD);
    this -> setTabOrder(MOD, BtnOK);
    this -> setTabOrder(BtnOK, BtnCancel);
}

void IntFacUI::CancelIntFac () {
    this -> close();
}

void IntFacUI::OKIntFac () {
    if (!TransQStringToLL(this -> Base -> text(), Bs)) {
        QMessageBox::warning(NULL, "Warning!", "不合法的输入", QMessageBox::Yes);
    } else {
        if (TransQStringToLL(this -> MOD -> text(), Md))
            Ans -> setText(TransLLToQString(Fac(Bs, Md)));
        else
            Ans -> setText(TransLLToQString(Fac(Bs)));
    }
}
