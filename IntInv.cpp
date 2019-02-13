#include "IntInv.h"
#include "calcMath.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <Qt>
#include <cstdio>

using namespace std;
typedef __int128 ll;

IntInvUI::IntInvUI (QWidget *parent) : QWidget(parent) {
    this -> setFixedSize(350, 160);
    this -> makeCenter();
    this -> createLabel();
    this -> createEditor();
    this -> createButton();
    this -> createLayout();
}

void IntInvUI::makeCenter () {
    auto ctr = this -> frameGeometry();
    auto cp = QDesktopWidget().availableGeometry().center();
    ctr.moveCenter(cp);
    this -> move(ctr.topLeft());
}

void IntInvUI::createLabel () {
    BaseText = new QLabel(this);
    MODText = new QLabel(this);
    Ans = new QLabel(this);
    BaseText -> setText("<sup>-1</sup>");
    MODText -> setText("mod: (质数)");
    Ans -> setText("0");
    Ans -> setFixedHeight(30);
    Ans -> setFixedWidth(320);
    Ans -> setAlignment(Qt::AlignRight);
    Ans -> setTextInteractionFlags(Qt::TextSelectableByMouse);
}

void IntInvUI::createEditor () {
    MOD = new QLineEdit(this);
    Base = new QLineEdit(this);
    // MOD -> setText("Please Input MOD");
    // Base -> setText("Please Input Base");
    Base -> setFixedWidth(170);
    MOD -> setFixedWidth(120);
    connect(this -> MOD, SIGNAL(returnPressed()), this, SLOT(OKIntInv()));
}

void IntInvUI::createButton () {
    this -> BtnCancel = new QPushButton( tr("Cancel"), this);
    this -> BtnOK = new QPushButton( tr("OK"), this);
    connect(BtnCancel, SIGNAL(clicked()), this, SLOT(CancelIntInv()));
    connect(BtnOK, SIGNAL(clicked()), this, SLOT(OKIntInv()));
}

void IntInvUI::createLayout () {
    BaseText -> move (190, 70);
    MODText -> move(210, 50);
    Ans -> move(15, 20);
    Base -> move(15, 70);
    MOD -> move(210, 70);
    this -> BtnCancel -> move(130, 110);
    this -> BtnOK -> move(240, 110);
    this -> setTabOrder(Base, MOD);
    this -> setTabOrder(MOD, BtnOK);
}

void IntInvUI::CancelIntInv () {
    this -> close();
}

void IntInvUI::OKIntInv () {
    if (!(this -> check())) {
        QMessageBox::warning(NULL, "Warning!", "不合法的输入", QMessageBox::Yes);
    } else {
        ll answer = quick_pow(Bs, Md - (ll)2, Md);
        char AnsStr[130], pos = 0;
        memset(AnsStr, 0, sizeof(AnsStr));
        while (answer)
            AnsStr[pos++] = (int)(answer % 10LL) + '0', answer /= 10LL;
        reverse(AnsStr, AnsStr + pos);
        QString qstr = QString(QLatin1String(AnsStr));
        Ans -> setText(qstr);
    }
}

bool IntInvUI::check() {
    QByteArray str = (this -> Base -> text()).toLatin1();
    BaseStr = str.data();
    Bs = 0;
    int pos = 0;
    while (BaseStr[pos]) {
        if (BaseStr[pos] < '0' || BaseStr[pos] > '9') return false;
        Bs = Bs * 10LL + (ll)(BaseStr[pos] - '0');
        ++pos;
    }
    if (pos == 0 && !BaseStr[pos]) return false;
    str = (this -> MOD -> text()).toLatin1();
    MODStr = str.data();
    Md = 0;
    pos = 0;
    while (MODStr[pos]) {
        if (MODStr[pos] < '0' || MODStr[pos] > '9') return false;
        Md = Md * 10LL + (ll)(MODStr[pos] - '0');
        ++pos;
    }
    if (pos == 0 && !MODStr[pos]) return false;
    return true;
}
