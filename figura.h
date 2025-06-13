#ifndef FIGURA_H
#define FIGURA_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class figura; }
QT_END_NAMESPACE

class figura
{
protected:
    int x,y,halflen,dx,dy,r;
    virtual void draw(QPainter *Painter)=0;
public:
    figura(int X,int Y,int Halflen):
        x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter);
};

class MyLine:public figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyLine(int x,int y,int halflen):figura(x,y,halflen){}
};
class MyRect:public figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyRect(int x,int y,int halflen):figura(x,y,halflen){}
};


#endif // FIGURA_H
