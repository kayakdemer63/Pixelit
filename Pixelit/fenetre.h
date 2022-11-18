/// @file fenetre.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class fenetre

#ifndef FENETRE_H
#define FENETRE_H                           /// @def FENETRE_H

#include <QMainWindow>                      /// @include <QMainWindow
#include <QNetworkReply>                    /// @include <QNetworkReply
#include <QNetworkAccessManager>            /// @include <QNetworkAccessManager
#include <QNetworkRequest>                  /// @include <QNetworkRequest
#include <QUrl>                             /// @include <QUrl
#include <QtGui>                            /// @include <QtGui
#include <QMessageBox>                      /// @include <QMessageBox
#include "pixelix.h"                        /// @include "pixelix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class fenetre; }             /// @namespace Ui
QT_END_NAMESPACE

class fenetre : public QMainWindow          /// @brief Définition de la classe fenetre et de la composition publique.
{
    Q_OBJECT

public:
    fenetre(QWidget *parent = nullptr);
    /** @public @fn fenetre(QWidget *parent = nullptr)
     *  @brief Déclaration du Constructor.
     *  @param[in] parent
     */

    ~fenetre();
    /** @public @fn ~fenetre()
     *  @brief Déclaration du Destructor.
     */

    QColor couleur = Qt::white;
    /** @public @var QColor couleur
     *  @brief Déclaration de l'Attribut.
     */

private slots:
    void telecharger_brightness();
    /** @private @fn telecharger_brightness()
     *  @brief Déclaration de la Méthode. Fonction permettant de télécharger un fichier Json indiquant la brightness().
     */

    void envoyer_txt();
    /** @private @fn envoyer_txt()
     *  @brief Déclaration de la Méthode. Fonction permettant d'envoyer le fichier Json permettant au pixelit d'écrire un texte.
     */

    void choixcouleur();
    /** @private @fn choixcouleur()
     *  @brief Déclaration de la Méthode. Fonction permettant de choisir la couleur du texte.
     */

    void changer_url();
    /** @private @fn changer_url()
     *  @brief Déclaration de la Méthode. Fonction permettant de récuperer le noouveau url.
     */

    void envoyer_Trame();
    /** @private @fn envoyer_Trame()
     *  @brief Déclaration de la Méthode. Fonction permettant d'envoyer un fichier Json contenant une trame pour afficher une image.
     */


private:
    Ui::fenetre *ui;
    /** @private @var Ui::fenetre *ui
     *  @brief Déclaration de l'Attribut.
     */

    bool erreurTrouvee = false;
    /** @private @var bool erreurTrouvee
     *  @brief Déclaration de l'Attribut.
     */

    pixelix afficheur;
    /** @private @var pixelix afficheur
     *  @brief Déclaration de l'Attribut.
     */

};
#endif // FENETRE_H
