#ifndef DRAG_DROB_INFO_H
#define DRAG_DROB_INFO_H

#include "Com_Calc.h"


class Drag_Drob_Info
{
public:
     Drag_Drob_Info();
    ~Drag_Drob_Info();

     static Drag_Drob_Info &instance();

     bool isEmpty();

     void push(sDragData);

     sDragData pop();

     void reset();

     sDragData object() const;

private:

     sDragData mObjectInfo{eCellType::EMPTY,{0,0}};

};

#endif // DRAG_DROB_INFO_H
