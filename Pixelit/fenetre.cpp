/// @file fenetre.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class fenetre
///
#include "fenetre.h"
#include "ui_fenetre.h"

#include <QColorDialog>
#include <QColor>

fenetre::fenetre(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fenetre)
{
    ui->setupUi(this);
    afficheur.set_url(ui->urlEdit->text());
}

fenetre::~fenetre()
{
    delete ui;
}


void fenetre::telecharger_brightness()
{
    ui->telechargementButton->setEnabled(false);

    QJsonDocument documentJSON = QJsonDocument::fromJson(afficheur.get_json_brightness());
    qDebug() << documentJSON;
    double brightness = afficheur.get_brightness();
    ui->brightnessprogressBar->setValue(double(brightness/2.55));
    ui->textBrowser->setText(documentJSON.toJson());

    ui->telechargementButton->setEnabled(true);

}


void fenetre::envoyer_txt()
{
    afficheur.set_url(ui->urlEdit->text());
    afficheur.text(ui->send_txt->text(),couleur,ui->ScrollButton->isChecked());
    afficheur.envoyer_txt();

    ui->telechargementButton->setEnabled(true);
}


void fenetre::choixcouleur()
{
    couleur = QColorDialog::getColor(Qt::white,this,"Couleur du texte");
    if (couleur.isValid()){
        QString qss = QString("background-color: %1").arg(couleur.name());
        ui->couleurButton->setStyleSheet(qss);
    }
}


void fenetre::changer_url()
{
    afficheur.set_url(ui->urlEdit->text());
}

void fenetre::envoyer_Trame()
{
    afficheur.set_url(ui->urlEdit->text());

    QString tramSTR = (ui->TrameEdit->text());
    QList<int> tramList;
    //QArrayData tramArray;
    QJsonArray tramJson;

    if (ui->checkAnim->isChecked())
    {
       /** @todo Permet d'envoyer une trame d'une animation.
        *
        * for (const QString &substr : tramSTR.split(','))
        {
            tramArray.append(substr.toInt());
        }
        */
    }
    else
    {
        for (const QString &substr : tramSTR.split(','))
        {
            tramList.append(substr.toInt());
        }
        for (auto & user : tramList)
        {
            tramJson.append(user);
        }
    }

    qDebug() << tramList ;
    qDebug() << tramJson ;

    afficheur.Trame(tramJson);
    afficheur.envoyer_trame();

    ui->telechargementButton->setEnabled(true);
}
