#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>
//#include <QTextCodec>
#include <QVBoxLayout>
#include <QMessageBox>
#include "area.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Win; }
QT_END_NAMESPACE

class Win7 : public QWidget
{
    Q_OBJECT
protected:
    //QTextCodec *codec;
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход
public:
    Win7(QWidget *parent = nullptr); // конструктор
    ~Win7();
public slots:
    void begin(); // метод начальной настройки интерфейса
    void calc(); // метод реализации вычислений
private:
    Ui::Win *ui;
};

class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){}
    virtual State validate(QString &str,int &pos)const
    {
        return Acceptable; // метод всегда принимает вводимую строку
    }
};

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0):
        QLineEdit(contents,parent){}
signals:
    void tick_signal();
public slots:
    void add_one()
    {
        QString str=text();
        int r=str.toInt();
        if (r!=0 && r%5 ==0) emit tick_signal();
        r++;
        str.setNum(r);
        setText(str);
    }
};

class Win8: public QWidget
{
    Q_OBJECT
protected:
    //QTextCodec *codec;
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
public:
    Win8(QWidget *parent = 0);
};

class Win9 : public QWidget
{
protected:
    //QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
    Win9();
};

#endif // WIN_H
