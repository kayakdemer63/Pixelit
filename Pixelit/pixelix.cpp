/// @file pixelix.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class pixelix

#include "pixelix.h"

pixelix::pixelix()
{

}

void pixelix::text(QString text, QColor color, bool scroll)
{
    // Creation de json text pour Pixelit
    QJsonObject jtext;
    QJsonObject jcolor;
    QJsonObject jposition;

    jtext["textString"] = text;
    jtext["bigFont"] = false;
    jtext["scrollText"] = scroll;
    jtext["scrollTextDelay"] = 100;
    jtext["centerText"] = false;
    jposition["x"] = 8;
    jposition["y"] = 0;
    jtext["position"] = jposition;
    jtext["hexColor"] = color.name();
    jsontext["text"] = jtext;
}

void pixelix::set_url(QString url)
{
    qurl = QUrl(url);
}

bool pixelix::envoyer_txt()
{
    QUrl url = qurl;
    url.setPath("/api/screen");
    QByteArray p = post(url, jsontext);

    QString good_response = "OK";
    if (p.contains(good_response.toUtf8())){
        return true;
    }
    else {
        return false;
    }

}

double pixelix::get_brightness()
{
    QUrl url = qurl;
    url.setPath("/api/brightness");

    //la reponse de l'api est stockée dans un json
    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url));

    //on transforme le json en objet json
    QJsonObject objetJSON = documentJSON.object();

    //on cherche la clé "brightness" et on vérifie que la valeur est un double
    if(objetJSON.value("brightness").isDouble())
    {
        return objetJSON.value("brightness").toDouble();
    }
    else
    {
        return 0;
    }
}

QByteArray pixelix::get(QUrl url)
{

    QNetworkRequest requete(url);

//    //Pour la gestion de la connexion sécurisée SSL (HTTPS)
//    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
//    config.setProtocol(QSsl::TlsV1_2);
//    requete.setSslConfiguration(config);

    QNetworkReply *reply = m.get(requete);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();

    return read;

}

QByteArray pixelix::post(QUrl url, QJsonObject json)
{
    QNetworkRequest requete(url);
    requete.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m.post(requete, QJsonDocument(json).toJson());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }
    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();
    return read;
}


QByteArray pixelix::get_json_brightness()
{
    QUrl url = qurl;
    url.setPath("/api/brightness");
    return get(url);

}

void pixelix::Trame(QJsonArray trame)
{
    // Creation de json trame pour Pixelit
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

}

bool pixelix::envoyer_trame()
{
    QUrl url = qurl;
    url.setPath("/api/screen");
    QByteArray p = post(url, jsontrame);

    QString good_response = "OK";
    if (p.contains(good_response.toUtf8())){
        return true;
    }
    else {
        return false;
    }

}
