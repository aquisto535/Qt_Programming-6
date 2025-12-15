#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //시그널을 발생시키는 오브젝트, 시그널을 발생하는 종류, 이 시그널과 연결할 Slot 함수가 있는 인스턴스명, 호출할 Slot 함수
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_clicked()
{
    qDebug() << "Hello World";
}
