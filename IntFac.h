#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <cstring>
#include <iostream>

using namespace std;
typedef __int128 ll;

class IntFacUI:public QWidget {
    Q_OBJECT
  public:
    explicit IntFacUI(QWidget *parent = 0);
    void makeCenter();
    void createEditor();
    void createLayout();
    void createLabel();
    void createButton();
    QLineEdit *Base, *MOD;
    QLabel *BaseText, *MODText, *Ans;
    QPushButton *BtnCancel, *BtnOK;
    ll Bs, Md;
    
    public slots:
        void CancelIntFac();
        void OKIntFac();
  private:
};
