#include "IntFac.h"
#include "calcMath.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <Qt>
#include <cstdio>

using namespace std;
typedef __int128 ll;

IntFacUI::IntFacUI (QWidget *parent) : QWidget(parent) {
    this -> setFixedSize(350, 160);
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
    Ans = new QLabel(this);
    QFont font;
    font.setPointSize(16);
    BaseText -> setFont(font);
    BaseText -> setText("!");
    Ans -> setText("0");
    Ans -> setFixedHeight(30);
    Ans -> setFixedWidth(320);
    Ans -> setAlignment(Qt::AlignRight);
    Ans -> setTextInteractionFlags(Qt::TextSelectableByMouse); 
}

void IntFacUI::createEditor () {
    Base = new QLineEdit(this);
    // Index -> setText("Please Input Index");
    // Base -> setText("Please Input Base");
    Base -> setFixedWidth(180);
    Base -> setAlignment(Qt::AlignRight);
    connect(this -> Base, SIGNAL(returnPressed()), this, SLOT(OKIntFac()));
}

void IntFacUI::createButton () {
    this -> BtnCancel = new QPushButton( tr("Cancel"), this);
    this -> BtnOK = new QPushButton( tr("OK"), this);
    connect(BtnCancel, SIGNAL(clicked()), this, SLOT(CancelIntFac()));
    connect(BtnOK, SIGNAL(clicked()), this, SLOT(OKIntFac()));
    
}

void IntFacUI::createLayout () {
    BaseText -> move (200, 70);
    Ans -> move(15, 20);
    Base -> move(15, 70);
    this -> BtnCancel -> move(130, 110);
    this -> BtnOK -> move(240, 110);
    this -> setTabOrder(Base, BtnOK);
    this -> setTabOrder(BtnOK, BtnCancel);
}

void IntFacUI::CancelIntFac () {
    this -> close();
}

void IntFacUI::OKIntFac () {
    if (!(this -> check())) {
        QMessageBox::warning(NULL, "Warning!", "不合法的输入", QMessageBox::Yes);
    } else {
        ll answer = Fac(Bs);
        char AnsStr[1300], pos = 0;
        memset(AnsStr, 0, sizeof(AnsStr));
        while (answer)
            AnsStr[pos++] = (int)(answer % 10LL) + '0', answer /= 10LL;
        reverse(AnsStr, AnsStr + pos);
        QString qstr = QString(QLatin1String(AnsStr));
        Ans -> setText(qstr);
    }
}

bool IntFacUI::check() {
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
    return true;
}
