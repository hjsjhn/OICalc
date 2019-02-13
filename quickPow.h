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
    bool check();
    QLineEdit *Base, *Index;
    QLabel *BaseText, *IndexText, *Ans;
    QPushButton *BtnCancel, *BtnOK;
    char *BaseStr, *IndexStr;
    ll Bs, Idx;
    
    public slots:
        void CancelPow();
        void OKPow();
  private:
};
