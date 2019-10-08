#ifndef EVALUATION_H
#define EVALUATION_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QLabel>
class Evaluation : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Evaluation(QGraphicsItem * parent = 0);

public slots:
    void move();

};

#endif // EVALUATION_H
