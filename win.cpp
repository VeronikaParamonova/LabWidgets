#include "win.h"
#include "ui_win.h"

Win7::Win7(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Win)
{
    ui->setupUi(this);
    //codec = QTextCodec::codecForName("Windows-1251");
    setWindowTitle(tr("Возведение в квадрат"));
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);
    inputLabel = new QLabel(tr("Введите число:"),this);
    inputEdit = new QLineEdit("",this);
    StrValidator *v=new StrValidator(inputEdit);
    inputEdit->setValidator(v);
    outputLabel = new QLabel(tr("Результат:"),this);
    outputEdit = new QLineEdit("",this);
    nextButton = new QPushButton(tr("Следующее"),this);
    exitButton = new QPushButton(tr("Выход"),this);
    // компоновка приложения выполняется согласно рисунку 2
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin();
    connect(exitButton,&QPushButton::clicked,this,&Win7::close);
    connect(nextButton,&QPushButton::clicked,this,&Win7::begin);
    connect(inputEdit,&QLineEdit::returnPressed,this,&Win7::calc);
}
    void Win7::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}
    void Win7::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();
    a=str.toDouble(&Ok);
    if (Ok)
    {
        r=a*a;
        str.setNum(r);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
                tr("Возведение в квадрат."),
                tr("Введено неверное значение."),
                QMessageBox::Ok);
        msgBox.exec();
        }
}

Win7::~Win7()
{
    delete ui;
}

Win8::Win8(QWidget *parent):QWidget(parent)
{
//codec = QTextCodec::codecForName("Windows-1251");
//this->setWindowTitle(codec->toUnicode("Счетчик"));
setWindowTitle(tr("Счётчик"));
label1 = new QLabel(tr("Cчет по 1"),this);
label2 = new QLabel(tr("Cчет по 5"),this);
edit1 = new Counter("0",this);
edit2 = new Counter("0",this);
calcbutton=new QPushButton("+1",this);
exitbutton=new QPushButton(tr("Выход"),this);
QHBoxLayout *layout1 = new QHBoxLayout();
layout1->addWidget(label1);
layout1->addWidget(label2);
QHBoxLayout *layout2 = new QHBoxLayout();
layout2->addWidget(edit1);
layout2->addWidget(edit2);
QHBoxLayout *layout3 = new QHBoxLayout();
layout3->addWidget(calcbutton);
layout3->addWidget(exitbutton);
QVBoxLayout *layout4 = new QVBoxLayout(this);
layout4->addLayout(layout1);
layout4->addLayout(layout2);
layout4->addLayout(layout3);
// связь сигнала нажатия кнопки и слота закрытия окна
connect(calcbutton,&QPushButton::clicked,edit1,&Counter::add_one);
connect(edit1,&Counter::tick_signal,edit2,&Counter::add_one);
connect(exitbutton,&QPushButton::clicked,this,&Win8::close);
}

Win9::Win9()
{
//codec = QTextCodec::codecForName("Windows-1251");
this->setWindowTitle(tr("Обработка событий"));
area = new Area( this );
btn = new QPushButton(tr("Завершить"),this );
QVBoxLayout *layout = new QVBoxLayout(this);
layout->addWidget(area);
layout->addWidget(btn);
connect(btn, &QPushButton::clicked,this,&Win9::close);
}
