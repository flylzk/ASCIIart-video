#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QImage>
#include <QUrl>
//#include <QVideoProbe>
#include <QColor>
//#include <QVideoFrame>
#include <opencv2/opencv.hpp>
//#include <QPainter>
#include <QPlainTextEdit>
//#include <QElapsedTimer>
//#include <QTimer>
//#include <QtGlobal>


using namespace cv;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }

QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
//槽函数
    void on_open_clicked();

    void on_play_clicked();


    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;

    QMediaPlayer* pPlayer;
    QVideoWidget *pVideoWidget;
    QMediaPlaylist *pMediaPlaylist;
    Widget *pTextWidget ;
    //QPainter *pPainter;
    QString FileName;
    //QTimer *timer;
    //QVideoProbe *pVideoProbe;

};

/*class CustomWidget : public QWidget {
    Q_OBJECT

public:
    explicit CustomWidget(QWidget *parent = nullptr);

    // 公共方法，用于设置要绘制的文本及其位置
 void setTextToDraw(const QString &text, const QPointF &position, const QFont &font, const QColor &color);
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QString textToDraw;
    QPointF textPosition;
    QFont textFont;
    QColor textColor;
};*/

#endif // WIDGET_H
