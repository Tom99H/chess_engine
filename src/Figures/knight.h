#ifndef KNIGHT_H
#define KNIGHT_H

#include "ifigure.h"

class Knight : public IFigure
{
public:
    explicit Knight(QObject *parent = nullptr);
};

#endif // KNIGHT_H
