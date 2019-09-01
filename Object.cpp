#include "Object.h"

ObjectCollection::ObjectCollection()
{
    this->initAllObjects();
}
void ObjectCollection::reset()
{
  this->initAllObjects();
}

void ObjectCollection::initAllObjects()
{
    uint8_t objIndex = 0;
    for (uint8_t space = 0; space < NB_OF_SPACES; space++)
    {
        for (uint8_t row = 0; row < LOGIC_ROWS; row++)
        {
            for (uint8_t col = 0; col < LOGIC_COLS; col++)
            {
                if (logicMaps[space][row][col] != 's'
                && logicMaps[space][row][col] != 'd'
                && logicMaps[space][row][col] != ' '
                &&logicMaps[space][row][col] != '&')
                {
                    Object obj;
                    obj.x = col * LOGIC_TILE_W;
                    obj.y = row * LOGIC_TILE_H;
                    obj.id = logicMaps[space][row][col];
                    obj.spaceIndex = space;
                    obj.state = 0;
                    this->objects[objIndex] = obj;
                    if (objIndex >= TOTAL_OBJECTS) break;
                    objIndex++;
                }
            }
        }
    }
}

Object ObjectCollection::getObject(uint8_t index)
{
    return this->objects[index];
}

Object ObjectCollection::checkCharacterObjectOverlap(uint8_t x, uint8_t y, uint8_t currentSpaceIndex)
{
  Object obj;
  obj.id = '0';
    for (uint8_t i = 0; i < TOTAL_OBJECTS; i++)
    {
        uint8_t charLeft = x;
        uint8_t charRight = x + CHARACTER_W;
        uint8_t charTop = y;
        uint8_t charBottom = y + CHARACTER_H;

        uint8_t objLeft = this->objects[i].x;
        uint8_t objRight = objLeft + OBJECT_W;
        uint8_t objTop = this->objects[i].y;
        uint8_t objBottom = objTop + OBJECT_H;

        bool objectAvailable = this->objects[i].state == 0 && this->objects[i].spaceIndex == currentSpaceIndex;

        if (charLeft <= objRight
        && charRight >= objLeft
        && charTop <= objBottom
        && charBottom >= objTop
        && objectAvailable)
        {
            obj = this->objects[i];
            break;
        }
    }
    return obj;
}

void ObjectCollection::setState(Object obj, bool state)
{
    for (uint8_t i = 0; i < TOTAL_OBJECTS; i++)
    {
        if (this->objects[i].id == obj.id)
        {
            this->objects[i].state = state;
            return;
        }
    }
}

void ObjectCollection::dropObject(uint8_t x, uint8_t y, uint8_t id, uint8_t spaceIndex, bool toContainer)
{
    for (uint8_t i = 0; i < TOTAL_OBJECTS; i++)
    {
        if (this->objects[i].id == id)
        {
            this->objects[i].state = toContainer ? 2 : 0;//available on ground
            this->objects[i].x = x;
            this->objects[i].y = y;
            this->objects[i].spaceIndex = spaceIndex;
            return;
        }
    }
}
