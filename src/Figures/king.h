#ifndef KING_H
#define KING_H

#include "ifigure.h"

class King : public IFigure
{
public:
    explicit King(QObject *parent = nullptr);
};

#endif // KING_H
