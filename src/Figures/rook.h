#ifndef ROOK_H
#define ROOK_H

#include "ifigure.h"

class Rook : public IFigure
{
public:
    explicit Rook(QObject *parent = nullptr);
};

#endif // ROOK_H
