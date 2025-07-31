#ifndef PAWN_H
#define PAWN_H

#include "ifigure.h"

class Pawn : public IFigure
{
public:
    explicit Pawn(QObject *parent = nullptr);
};

#endif // PAWN_H
