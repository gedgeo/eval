#include "ihm_digicode.h"
#include "ui_ihm_digicode.h"

IHM_Digicode::IHM_Digicode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IHM_Digicode)
{
    ui->setupUi(this);
    setFixedSize(QSize(274,446));
    int colonne=0, ligne=0;
    grille=new QGridLayout(this);
    afficheur=new QLineEdit(this);
    afficheur->setReadOnly(true);
    afficheur->setAlignment(Qt::AlignRight);
    afficheur->setEchoMode(QLineEdit::Password);
    afficheur->setMinimumHeight(80);
    afficheur->setPlaceholderText("Entrez un code");
    afficheur->setStyleSheet("background-color : #ffffff");
    // effacer le contenu de l'afficheur
    afficheur->clear();
    // ajouter l'afficheur dans le gridLayout
    grille->addWidget(afficheur,ligne,colonne,1,3);


    //creation des 12 touches
    for(int i=0;i<NBTOUCHES;i++){
        //creation des touche
        //correspondant dans la table des symboles
        touches[i]=new QPushButton(tablesDesSymboles[i]);
        //association click vaers methode
        QObject::connect(touches[i],
                         &QPushButton::clicked,
                         this,
                         &IHM_Digicode::onQPushButtonClicked
                         );
    }
    //placement des touches dans le layout
    int i=0;
    for(ligne=1;ligne<5;ligne++){
        for(colonne=0;colonne<4;colonne++)
        {
            grille->addWidget(touches[i],ligne,colonne,1,1);
            i++;
        }
    }
    this->setLayout(grille);
}

IHM_Digicode::~IHM_Digicode()
{
    delete ui;
}


void IHM_Digicode::onQPushButtonClicked()
{

}




