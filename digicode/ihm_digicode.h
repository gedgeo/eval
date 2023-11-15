#ifndef IHM_DIGICODE_H
#define IHM_DIGICODE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

#define NBTOUCHES 12

QT_BEGIN_NAMESPACE
namespace Ui { class IHM_Digicode; }
QT_END_NAMESPACE

class IHM_Digicode : public QWidget
{
    Q_OBJECT

public:
    IHM_Digicode(QWidget *parent = nullptr);
    ~IHM_Digicode();
private slots:
    void onQPushButtonClicked();
private:
    Ui::IHM_Digicode *ui;
    QPushButton *touches[NBTOUCHES];
    QLineEdit *afficheur;
    QGridLayout *grille;
const QString
    tablesDesSymboles[NBTOUCHES]={"7","8","9","4","5","6","1","2","3","On","0","Ok"};
};
#endif // IHM_DIGICODE_H
