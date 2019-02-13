#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <cstring>
#include <iostream>

using namespace std;
typedef __int128 ll;

class PowUI:public QWidget {
    Q_OBJECT
  public:
    explicit PowUI(QWidget *parent = 0);
    void makeCenter();
    void createEditor();
    void createLayout();
    void createLabel();
    void createButton();
    QLineEdit *Base, *Index, *MOD;
    QLabel *BaseText, *IndexText, *MODText, *Ans;
    QPushButton *BtnCancel, *BtnOK;
    ll Bs, Idx, Md;
    
    public slots:
        void CancelPow();
        void OKPow();
  private:
};
