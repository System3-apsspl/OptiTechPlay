#ifndef OPTITECHPLAY_H
#define OPTITECHPLAY_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QTimer>
#include <QDir>
#include <QDebug>
#include <QDateTime>

#define CURRENT_DATETIME(func)      QDateTime::currentDateTime().toString("yyyyMMdd hh:mm:ss ")+func+" -> "
#define DEBUG                       qDebug().noquote()

namespace Ui {
class OptiTechPlay;
}

class OptiTechPlay : public QMainWindow
{
    Q_OBJECT

public:
    explicit OptiTechPlay(QWidget *parent = 0);
    ~OptiTechPlay();
public slots:
    void sl_play();
    void sl_MediaError(QMediaPlayer::Error mError);
    void sl_MediaStatus(QMediaPlayer::MediaStatus mStatus);
private:
    Ui::OptiTechPlay *ui;
    QMediaPlayer *obj_player = 0;
    QMediaPlaylist *obj_playlist = 0;
    QVideoWidget *obj_videoWidget = 0;
    void m_initPlayer();

};

#endif // OPTITECHPLAY_H
