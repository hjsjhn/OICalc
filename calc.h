#include <QLabel>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class calc:public QMainWindow {
    Q_OBJECT
  public:
    explicit calc(QMainWindow *parent = 0);
    QLabel *Display;
    QWidget *MainWidget, *Options;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QPushButton *qpow, *logt, *IntInv;
    void initUI();
    void makeCenter();
    void createLabel();
    void createButton();
    void createLayout();

    public slots:
        void calcPow();
        void calcLog();
        void calcIntInv();
  private:
};
