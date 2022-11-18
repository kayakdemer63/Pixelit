/// @file pixelix.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class pixelix

#ifndef PIXELIX_H
#define PIXELIX_H                                       /// @def PIXELIX_H

#include <QNetworkReply>                                /// @include <QNetworkReply
#include <QNetworkAccessManager>                        /// @include <QNetworkAccessManager
#include <QNetworkRequest>                              /// @include <QNetworkRequest
#include <QUrl>                                         /// @include <QUrl
#include <QtGui>                                        /// @include <QtGui
#include <QMessageBox>                                  /// @include <QMessageBox

class pixelix                                           /// @brief Définition de la classe pixelix.
{

private:
    QUrl qurl;
    /** @private @var QUrl qurl
     *  @brief Déclaration de l'Attribut. Contient l'url du pixelit.
     */

    QJsonObject jsontext;
    /** @private @var QJsonObject jsontext
     *  @brief Déclaration de l'Attribut. Contient le fichier Json du texte.
     */

    QByteArray get(QUrl url);
    /** @private @fn QByteArray get(QUrl url)
     *  @brief Déclaration de la Méthode. Fonction permettant d'obtenir l'url du pixelit.
     *  @param[in] url
     */

    QByteArray post(QUrl url, QJsonObject json);
    /** @private @fn QByteArray post(QUrl url, QJsonObject json)
     *  @brief Déclaration de la Méthode. Fonction permettant d'envoyer un fichier Json à une url.
     *  @param[in] url
     *  @param[in] json
     */

    QNetworkAccessManager m;
    /** @private @var QNetworkAccessManager m
     *  @brief Déclaration de l'Attribut.
     */

    QJsonObject jsontrame;
    /** @private @var QJsonObject jsontrame
     *  @brief Déclaration de l'Attribut. Contient le fichier Json de la trame.
     */

public:
    pixelix();
    /** @public @fn pixelix()
     *  @brief Déclaration du Constructor.
     */

    void text(QString text, QColor color, bool scroll);
    /** @public @fn void text(QString text, QColor color, bool scroll)
     *  @brief Déclaration de la Méthode. Fonction permettant d'écrire un fichier Json avec le texte, la couleur et le scroll ou non.
     *  @param[in] text
     *  @param[in] color
     *  @param[in] scroll
     */

    void set_url(QString url);
    /** @public @fn void set_url(QString url)
     *  @brief Déclaration de la Méthode. Fonction permettant de définir l'url du Pixelit.
     *  @param[in] url L'url du Pixelit.
     */

    bool envoyer_txt();
    /** @public @fn bool envoyer_txt();
     *  @brief Déclaration de la Méthode. Fonction permettant d'envoyer le fichier Json à l'url du Pixelit.
     *  @param[out] bool
     */

    QByteArray get_json_brightness();
    /** @public @fn QByteArray get_json_brightness()
     *  @brief Déclaration de la Méthode. Fonction permettant d'obtenir un fichier Json du brightness.
     */

    double get_brightness();
    /** @public @fn double get_brightness()
     *  @brief Déclaration de la Méthode. Fonction Permettant d'obtenir la brightness.
     */

    bool envoyer_trame();
    /** @public @fn bool envoyer_trame()
     *  @brief Déclaration de la Méthode. Fonction permettant d'envoyer une trame d'une image.
     */

    void Trame(QJsonArray trame);
    /** @public @fn void Trame(QJsonArray trame)
     *  @brief Déclaration de la Méthode. Fonction permettant de faire un fichier Json avec la trame de l'image.
     *  @param trame
     *  @code{.cpp}
     *
    QJsonObject jtrame;
    QJsonObject jposition;
    QJsonObject jtaille;
    int width = 8;

    jtrame["data"] = trame;
    jposition["x"] = 0;
    jposition["y"] = 0;
    jtrame["position"] = jposition;

    if (trame.size() == 256) { width = 32; }
    else if (trame.size() > 256) { width = 8; jtrame["animationDelay"] = 100; }

    jtaille["width"] = width;
    jtaille["height"] = 8;
    jtrame["size"] = jtaille;
    jsontrame["bitmap"] = jtrame;
     *  @endcode
     */

};

#endif // PIXELIX_H
