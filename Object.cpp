#include "Object.h"

ObjectCollection::ObjectCollection()
{
    this->initAllObjects();
    //this->setCurrentSpaceIndex(0);
}

void ObjectCollection::initAllObjects()
{
    uint8_t setObjIndex = 0;
    for (uint8_t space = 0; space < NB_OF_SPACES; space++)
    {
        for (uint8_t row = 0; row < LOGIC_ROWS; row++)
        {
            for (uint8_t col = 0; col < LOGIC_COLS; col++)
            {
                if (logicMaps[space][row][col] == '1'
                || logicMaps[space][row][col] == '2'
                || logicMaps[space][row][col] == '3'
                || logicMaps[space][row][col] == '4'
                || logicMaps[space][row][col] == 'a')
                {
                    Object obj;
                    obj.x = col * LOGIC_TILE_W;
                    obj.y = row * LOGIC_TILE_H;
                    obj.id = logicMaps[space][row][col];
                    obj.spaceIndex = space;
                    obj.state = 0;
                    this->objects[setObjIndex] = obj;
                    if (setObjIndex >= TOTAL_OBJECTS) return;
                    setObjIndex++;
                }
            }
        }
    }
}

Object ObjectCollection::getObject(uint8_t index)
{
    return this->objects[index];
}
