#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets>

enum Figure{TRIANGLE, SQUARE, CIRCLE};

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(Figure figure, QWidget *parent = nullptr);

    void showWidget();
    void setFlags(Qt::WindowFlags flags_);

signals:

private:
    QLabel* lbl(Figure figure_);  // отрисовка фигур

    Figure figure_;
    QHBoxLayout *layout_;
    Qt::WindowFlags flags_;

    QColor color_;
    quint8 r_;
    quint8 g_;
    quint8 b_;

    QLabel* plbl_;


    // QWidget interface
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);  // для смены цвета фигур
};

#endif // MYWIDGET_H
