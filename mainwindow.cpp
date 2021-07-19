#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    myWidgetCircle = new MyWidget(Figure::CIRCLE, this);
    myWidgetSquare = new MyWidget(Figure::SQUARE, this);
    myWidgetTriangle = new MyWidget(Figure::TRIANGLE, this);


    circlePix_ = new QPixmap(":/images/circle.png");
    squarePix = new QPixmap(":/images/square.png");
    trianglePix = new QPixmap(":/images/triangle.png");

    // создаём кнопки
    addButton(circlePix_, ui->circleButton);
    addButton(squarePix, ui->squareButton);
    addButton(trianglePix, ui->triangleButton);

    connect(ui->circleButton, &QPushButton::clicked, [&]()
    {
        myWidgetCircle->setFlags(Qt::Window | Qt::Dialog);  // устанавливаем флаги влияющие на отображение окна
        myWidgetCircle->showWidget();
    });

    connect(ui->squareButton, &QPushButton::clicked, [&]()
    {
        myWidgetSquare->setWindowFlags(Qt::Window | Qt::Dialog); // устанавливаем флаги влияющие на отображение окна
        myWidgetSquare->showWidget();
    });

    connect(ui->triangleButton, &QPushButton::clicked, [&]()
    {
        myWidgetTriangle->setWindowFlags(Qt::Window | Qt::Dialog); // устанавливаем флаги влияющие на отображение окна
        myWidgetTriangle->showWidget();
    });

    connect(ui->pushButtonClear, &QPushButton::clicked, [&]()
    {
        myWidgetCircle->close();
        myWidgetSquare->close();
        myWidgetTriangle->close();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addButton(QPixmap *pix, QPushButton *button)
{
    button->setCursor(Qt::PointingHandCursor); // устанавливаем курсор (указывающий перст)
    button->setToolTip("Click me!");           // всплывающая подсказка
    button->setIcon(*pix);                     // картинка в качестве фона кнопки
    button->setIconSize(QSize(pix->width(), pix->height())); // размеры кнопки == размерам картинки
    button->setFixedSize(button->iconSize());
    button->setFlat(true);
}
