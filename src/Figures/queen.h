#ifndef QUEEN_H
#define QUEEN_H

#include "ifigure.h"

class Queen : public IFigure
{
public:
    explicit Queen(QObject *parent = nullptr);
};

#endif // QUEEN_H
