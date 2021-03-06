#include "GraphicsEngine.h"

#include "GraphicalObject.h"

GraphicsEngine::GraphicsEngine()
{
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);

    if(!screen)
    {
        exit(-1);
    }
}

GraphicsEngine::~GraphicsEngine()
{
    SDL_FreeSurface(screen);
}

void GraphicsEngine::process(vector<Object*> objects)
{
    vector<GraphicalObject*> GraphicalObjects;
    for(int i = 0; i < (int)objects.size(); i++)
    {
        int type = objects[i]->getType();

        if(isTypeDrawable(type))
            GraphicalObjects.push_back(dynamic_cast<GraphicalObject*>(objects[i]));
    }

    sortByLayer(GraphicalObjects);

    for(int i = 0; i < (int)GraphicalObjects.size(); i++)
    {
        GraphicalObjects[i]->draw(screen);
    }

    SDL_Flip(screen);
}

bool GraphicsEngine::isTypeDrawable(int type)
{
    if(type >= 10000) type -= 10000;
    if(type >= 1000)  return true;
    return false;
}

/*****************************************************************************
void GraphicsEngine::sortByLayer(vector<GraphicalObject*>& images)
{
    for(int i = 0; i < (int)images.size(); i++)
    {
        for(int j = 0; j < (int)images.size() - 1; j++)
        {
            if(images[j]->getLayer() >  images[j+1]->getLayer())
            {
                GraphicalObject* temp = images[j];
                images[j] = images[j+1];
                images[j+1] = temp;
            }
        }
    }
}
*******************************************************************************/

void GraphicsEngine::sortByLayer(vector<GraphicalObject*>& list)
{
    quickSort(list, 0, list.size()-1);
}

void GraphicsEngine::quickSort(vector<GraphicalObject*>& vec, int start, int end)
{
    if(start <= end)
    {
        int p = partition(vec, start, end);
        quickSort(vec, start, p-1);
        quickSort(vec, p+1, end);
    }
}

int GraphicsEngine::partition(vector<GraphicalObject*>& vec, int start, int end)
{
	int pivotValue = vec[start]->getLayer();
	int pivotPos = start;

	for( int pos = start+1; pos <= end; pos++)
	{
		if( vec[pos]->getLayer() < pivotValue )
		{
			swap( vec[pivotPos+1], vec[pos]);
			swap( vec[pivotPos], vec[pivotPos+1]);
			pivotPos++;
		}
	}
	return pivotPos;
}

