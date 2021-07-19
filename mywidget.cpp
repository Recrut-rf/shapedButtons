#include "mywidget.h"

MyWidget::MyWidget(Figure figure, QWidget *parent) : QWidget(parent),
    figure_(figure), flags_{}, color_{}
{
    QSize size;
    size.setWidth(110);
    size.setHeight(110);

    this->setMinimumSize(size);
    plbl_ = new QLabel(this);
    plbl_->setFixedSize(100, 100);
}

void MyWidget::showWidget()
{
    layout_ = new QHBoxLayout(this);
    layout_->addWidget(lbl(figure_));
    this->setLayout(layout_);

    this->show();
}

void MyWidget::setFlags(Qt::WindowFlags flags)
{
    this->setWindowFlags(flags);
}

QLabel *MyWidget::lbl(Figure figure_)
{
    QRect    rect(plbl_->contentsRect());
    QPainter painter;

    QImage sourceImage(rect.size(), QImage::Format_ARGB32_Premultiplied);
    sourceImage.fill(QColor(0, 0, 0, 0));


    switch (figure_)
    {
    case TRIANGLE:
        r_ += 100;
        g_ += 10;
        b_ += 10;
        painter.begin(&sourceImage);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(QBrush(QColor(r_, g_, b_)));
        painter.drawPolygon(QPolygon() << QPoint(0,100) << QPoint(100,100) << QPoint(100,0));
        painter.drawImage(rect, sourceImage);
        painter.end();

        plbl_->setPixmap(QPixmap::fromImage(sourceImage));
        break;

    case SQUARE:
        r_ += 10;
        g_ += 100;
        b_ += 10;
        painter.begin(&sourceImage);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(QBrush(QColor(r_, g_, b_)));
        painter.drawRect(rect);
        painter.drawImage(rect, sourceImage);
        painter.end();

        plbl_->setPixmap(QPixmap::fromImage(sourceImage));
        break;

    case CIRCLE:
        r_ += 10;
        g_ += 10;
        b_ += 100;
        painter.begin(&sourceImage);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(QBrush(QColor(r_, g_, b_)));
        painter.drawEllipse(rect);
        painter.drawImage(rect, sourceImage);
        painter.end();

        plbl_->setPixmap(QPixmap::fromImage(sourceImage));
        break;
    }

    return plbl_;
}

void MyWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    this->plbl_->clear();
    this->showWidget();
}
