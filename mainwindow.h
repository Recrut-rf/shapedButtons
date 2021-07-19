#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "mywidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // картинки с фигурами - будут как фон для кнопок
    QPixmap *circlePix_;
    QPixmap *squarePix;
    QPixmap *trianglePix;

    // виджеты с фигурами
    MyWidget *myWidgetCircle;
    MyWidget *myWidgetSquare;
    MyWidget *myWidgetTriangle;


    // функция создания кнопки из картинки
    void addButton(QPixmap *pix, QPushButton *button);
};
#endif // MAINWINDOW_H
