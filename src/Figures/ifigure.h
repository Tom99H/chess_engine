#ifndef IFIGURE_H
#define IFIGURE_H

#include <QObject>

class IFigure : public QObject
{
    Q_OBJECT
public:
    explicit IFigure(QObject *parent = nullptr);

    virtual QString Spawn(unsigned char col, unsigned char row);
    virtual QString Despawn();
    virtual void Move(unsigned char col, unsigned char row){m_position = row*8 + col;};
    virtual unsigned char GetPosition(){return m_position;}

    static QString toAlgebraic(unsigned char col, unsigned char row){
        if (col > 7 || row > 7) return "";  // Invalid
        return QString(QChar('a' + col)) + QString::number(row + 1);
    }
private:
    unsigned char m_position;
signals:
};

#endif // IFIGURE_H
