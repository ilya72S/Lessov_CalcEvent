#include "drag_drob_info.h"

Drag_Drob_Info::Drag_Drob_Info()
{

}

Drag_Drob_Info::~Drag_Drob_Info()
{

}

Drag_Drob_Info &Drag_Drob_Info::instance()
{
    static Drag_Drob_Info res;
    return res;
}

bool Drag_Drob_Info::isEmpty()
{
    return mObjectInfo.type == eCellType::EMPTY;
}

void Drag_Drob_Info::push(sDragData aInfo)
{
    mObjectInfo = aInfo;
}

sDragData Drag_Drob_Info::pop()
{
    sDragData res = mObjectInfo;
    reset();
    return res;
}

void Drag_Drob_Info::reset()
{
    mObjectInfo.type = eCellType::EMPTY;
}

sDragData Drag_Drob_Info::object() const
{
    return mObjectInfo;
}
