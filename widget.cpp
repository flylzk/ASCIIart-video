#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pPlayer=new QMediaPlayer(this);
    pVideoWidget = new QVideoWidget(this);
    pMediaPlaylist = new QMediaPlaylist(this);
    //pVideoProbe=new QVideoProbe(this);
    pPlayer->setPlaylist(pMediaPlaylist);
    pPlayer->setVideoOutput(pVideoWidget);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_open_clicked()
{
    //打开文件选择窗口
    FileName=QFileDialog::getOpenFileName(this);

}


void Widget::on_play_clicked()
{
    if(FileName!=NULL)
    {
        QWidget *newWindow = new QWidget();
        //newWindow->setParent(ui->widget);
        newWindow->resize(400, 300);
        QTextEdit *textEdit = new QTextEdit(newWindow);
        textEdit->setGeometry(0, 0, newWindow->width(), newWindow->height()); // 设置 QPlainTextEdit 大小与新窗口相同
        //textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 禁用垂直滚动条
        //禁用自动换行
        QTextOption option;
        option.setWrapMode(QTextOption::NoWrap);
        textEdit->document()->setDefaultTextOption(option);
        textEdit->setReadOnly(true);
        // 将 QPlainTextEdit 添加到新窗口的布局中
        QVBoxLayout *layout = new QVBoxLayout(newWindow);
        layout->addWidget(textEdit);

        newWindow->show();


        pPlayer->setMedia(QUrl::fromLocalFile(FileName));
        Mat img;

        QString text;

        VideoCapture video(FileName.toStdString());

        //获取视频帧率,长宽
        double fps = video.get(cv::CAP_PROP_FPS);
        int width = static_cast<int>(video.get(cv::CAP_PROP_FRAME_WIDTH));
        int height = static_cast<int>(video.get(cv::CAP_PROP_FRAME_HEIGHT));

        newWindow->resize(width, height);
        //pPlayer->play();
        //qint64 TotalASCIITime=0;
        //qint64 intervalTime =0;
        //timer = new QTimer(newWindow);
        //QElapsedTimer elapsedTimer;
        //timer->start(1000 / fps);
        //QElapsedTimer lastFrameTime;
        //elapsedTimer.start();

        while (1)
        {
            //逐帧读入图像
            video>>img;
            if(img.empty())
                break;
            //将读入图像变为灰度图
            cvtColor(img,img,COLOR_BGR2GRAY);
            //读入用户输入的数据
            QString value1=ui->lineEdit->text();
            QString value2=ui->lineEdit_3->text();
            QString value3=ui->lineEdit_4->text();
            bool half=ui->radioButton->isChecked();
            //根据用户输入设置用于显示的字符串
            QString str=value3;// "@Qo=-. " "█▉▋▌▍▎　"
            //设置字体
            QFont font("SimSun",value2.toInt(),QFont::Bold);
            textEdit->setFont(font);
            //获取字符串长度
            int length=str.length();
            int index=0;
            //根据用户输入的采样精度对图片进行缩小
            cv::resize(img,img,cv::Size(width/(21-value1.toInt()),height/(21-value1.toInt())));
            //遍历图像
            for (int x=0;x<img.rows ;x++ )
            {
                for (int y=0;y<img.cols ;y++ )
                {
                    //根据像素灰度为其分配字符
                    int color = img.at<uchar>(x,y);
                    index=color/256.0*length;
                    text +=  str[index];
                    //如果使用半角字符，添加空格以保证显示效果
                    if(half==true)
                        text += " ";
                }
                text +="\n";
            }
            //qint64 elapsed = lastFrameTime.elapsed();
            //lastFrameTime.restart();

            //输出连接好的字符串
            textEdit->setPlainText(text);


            // 计算下一次定时器启动的时间间隔
            //qint64 sleepTime = 1000/fps - elapsed;
            //if(sleepTime>0)

            //控制帧率
            waitKey(1000/fps);
            text.clear();
        }
    }

}

//ui部件对应的槽函数
void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->lineEdit->setText(QString("%1").arg(value));
}


void Widget::on_horizontalSlider_3_valueChanged(int value)
{
    ui->lineEdit_3->setText(QString("%1").arg(value));
}


void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    ui->horizontalSlider->setValue(arg1.toInt());
}


void Widget::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->horizontalSlider_3->setValue(arg1.toInt());

}

