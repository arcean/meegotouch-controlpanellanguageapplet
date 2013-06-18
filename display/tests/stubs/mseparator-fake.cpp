#include "mseparator.h"

MSeparator::MSeparator(QGraphicsItem *, Qt::Orientation)
{
}

MSeparator::~MSeparator()
{
}

Qt::Orientation MSeparator::orientation()
{
    return model()->orientation();
}

void MSeparator::setOrientation(Qt::Orientation)
{
}

