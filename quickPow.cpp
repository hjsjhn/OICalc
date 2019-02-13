#include "quickPow.h"
#include "calcMath.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <Qt>
#include <cstdio>

using namespace std;
typedef __int128 ll;

PowUI::PowUI (QWidget *parent) : QWidget(parent) {
    this -> setFixedSize(350, 160);
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
    Ans = new QLabel(this);
    BaseText -> setText("底数");
    IndexText -> setText("指数");
    Ans -> setText("0");
    Ans -> setFixedHeight(30);
    Ans -> setFixedWidth(320);
    Ans -> setAlignment(Qt::AlignRight);
    Ans -> setTextInteractionFlags(Qt::TextSelectableByMouse); 
}

void PowUI::createEditor () {
    Index = new QLineEdit(this);
    Base = new QLineEdit(this);
    // Index -> setText("Please Input Index");
    // Base -> setText("Please Input Base");
    Base -> setFixedWidth(180);
    Index -> setFixedWidth(120);
    connect(this -> Index, SIGNAL(returnPressed()), this, SLOT(OKPow()));
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
    Ans -> move(15, 20);
    Base -> move(15, 70);
    Index -> move(210, 70);
    this -> BtnCancel -> move(130, 110);
    this -> BtnOK -> move(240, 110);
    this -> setTabOrder(Base, Index);
    this -> setTabOrder(Index, BtnOK);
}

void PowUI::CancelPow () {
    this -> close();
}

void PowUI::OKPow () {
    if (!(this -> check())) {
        QMessageBox::warning(NULL, "Warning!", "不合法的输入", QMessageBox::Yes);
    } else {
        ll answer = quick_pow(Bs, Idx);
        char AnsStr[130], pos = 0;
        memset(AnsStr, 0, sizeof(AnsStr));
        while (answer)
            AnsStr[pos++] = (int)(answer % 10LL) + '0', answer /= 10LL;
        reverse(AnsStr, AnsStr + pos);
        QString qstr = QString(QLatin1String(AnsStr));
        Ans -> setText(qstr);
    }
}

bool PowUI::check() {
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
    str = (this -> Index -> text()).toLatin1();
    IndexStr = str.data();
    Idx = 0;
    pos = 0;
    while (IndexStr[pos]) {
        if (IndexStr[pos] < '0' || IndexStr[pos] > '9') return false;
        Idx = Idx * 10LL + (ll)(IndexStr[pos] - '0');
        ++pos;
    }
    if (pos == 0 && !IndexStr[pos]) return false;
    return true;
}
