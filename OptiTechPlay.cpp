#include "OptiTechPlay.h"
#include "ui_OptiTechPlay.h"

OptiTechPlay::OptiTechPlay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OptiTechPlay)
{
    ui->setupUi(this);
    m_initPlayer();
    QTimer::singleShot(2000,this,SLOT(sl_play()));
}

OptiTechPlay::~OptiTechPlay()
{
    if(obj_player->state() ==  QMediaPlayer::PlayingState)
        obj_player->stop();

    delete ui;
}

void OptiTechPlay::m_initPlayer()
{
    obj_player = new QMediaPlayer;
    connect(obj_player,SIGNAL(error(QMediaPlayer::Error)),SLOT(sl_MediaError(QMediaPlayer::Error)));
    connect(obj_player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),SLOT(sl_MediaStatus(QMediaPlayer::MediaStatus)));

    obj_videoWidget = new QVideoWidget;
    obj_playlist = new QMediaPlaylist;

    ui->horizontalLayout_2->addWidget(obj_videoWidget);
    obj_playlist->addMedia(QUrl::fromLocalFile(QDir::homePath()+"/eLoco_pantograph_sparking.mp4"));
    obj_playlist->setCurrentIndex(1);
    obj_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    obj_player->setPlaylist(obj_playlist);
    obj_player->setVideoOutput(obj_videoWidget);
}


void OptiTechPlay::sl_play()
{
    if(obj_player)
        obj_player->play();
    else
    {
        m_initPlayer();
        QTimer::singleShot(2000,this,SLOT(sl_play()));
    }
}

void OptiTechPlay::sl_MediaError(QMediaPlayer::Error mError)
{
    switch (mError) {
    case QMediaPlayer::ResourceError:
        DEBUG <<CURRENT_DATETIME(__FUNCTION__)<<"Resource Error";
        break;
    case QMediaPlayer::FormatError:
        DEBUG <<CURRENT_DATETIME(__FUNCTION__)<<"Format Error";
        break;
    case QMediaPlayer::NetworkError:
        DEBUG <<CURRENT_DATETIME(__FUNCTION__)<<"Network Error";
        break;
    case QMediaPlayer::AccessDeniedError:
        DEBUG <<CURRENT_DATETIME(__FUNCTION__)<<"Access Denied Error";
        break;
    case QMediaPlayer::ServiceMissingError:
        DEBUG <<CURRENT_DATETIME(__FUNCTION__)<<"Service Missing Error";
        break;
    case QMediaPlayer::MediaIsPlaylist:
        DEBUG <<CURRENT_DATETIME(__FUNCTION__)<<"Media Is Playlist";
        break;
    default:
        break;
    }
}

void OptiTechPlay::sl_MediaStatus(QMediaPlayer::MediaStatus mStatus)
{
    switch (mStatus) {
    case QMediaPlayer::NoMedia:
        DEBUG<<CURRENT_DATETIME(__FUNCTION__)<<"NoMedia";
        break;
    case QMediaPlayer::LoadingMedia:
        DEBUG<<CURRENT_DATETIME(__FUNCTION__)<<"Loading Media";
        break;
    case QMediaPlayer::LoadedMedia:
        DEBUG<<CURRENT_DATETIME(__FUNCTION__)<<"Loaded Media";
        break;
    case QMediaPlayer::StalledMedia:
        DEBUG<<CURRENT_DATETIME(__FUNCTION__)<<"Stalled Media";
        break;
    case QMediaPlayer::BufferingMedia:
        DEBUG<<CURRENT_DATETIME(__FUNCTION__)<<"Buffering Media";
        break;
    case QMediaPlayer::BufferedMedia:
        DEBUG<<CURRENT_DATETIME(__FUNCTION__)<<"Buffered Media";
        break;
    case QMediaPlayer::EndOfMedia:
        DEBUG<<CURRENT_DATETIME(__FUNCTION__)<<"End Of Media";
        break;
    case QMediaPlayer::InvalidMedia:
        DEBUG<<CURRENT_DATETIME(__FUNCTION__)<<"Invalid Media";
        break;
    case QMediaPlayer::UnknownMediaStatus:
        DEBUG<<CURRENT_DATETIME(__FUNCTION__)<<"Unknown Media Status";
        break;
    default:
        break;
    }
}
