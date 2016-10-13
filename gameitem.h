#ifndef GAMEITEM_H
#define GAMEITEM_H


class GameItem
{
public:
    virtual void draw(GLcontext context)const =0;
};

#endif // GAMEITEM_H
