#include "keyboard.h"

Keyboard::Keyboard():fild(4,5,30)
{
    _init_Cels_();


}

void Keyboard::_init_Cels_()
{
    Vec_Fields.resize(Lines*Columns);


    Vec_Fields[0]=0;
    Vec_Fields[1]=1;
    Vec_Fields[2]=2;
    Vec_Fields[3]=3;
    Vec_Fields[4]=4;
    Vec_Fields[5]=5;
    Vec_Fields[6]=6;
    Vec_Fields[7]=7;
    Vec_Fields[8]=8;
    Vec_Fields[9]=9;
    Vec_Fields[10]=".";
    Vec_Fields[11]= "+";
    Vec_Fields[12]= "-";
    Vec_Fields[13]= "*";
    Vec_Fields[14]= "/";

}

bool Keyboard::highlight_Key()
{
    return mHover = true;
    QGraphicsItem::update();

}
