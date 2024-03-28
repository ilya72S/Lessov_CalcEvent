#ifndef COM_CALC_H
#define COM_CALC_H

#include<QPointF>

enum class eCellType
{
  EMPTY,
    ON

} ;

struct sDragData
{
  eCellType type;
  QPointF drag_pos;
};

#endif // COM_CALC_H
