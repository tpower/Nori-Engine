#include "AudioEngine.h"

AudioEngine::AudioEngine()
{
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        exit(-1);
    }
}

AudioEngine::~AudioEngine()
{
    Mix_CloseAudio();
}

void AudioEngine::process(vector<Object*> objects)
{
    vector<AudibleObject*> audibleObjects;
    for(int i = 0; i < (int)objects.size(); i++)
    {
        int type = objects[i]->getType();

        if(isTypeAudible(type))
            audibleObjects.push_back(dynamic_cast<AudibleObject*>(objects[i]));
    }

    for(int i = 0; i < (int)audibleObjects.size(); i++)
    {
        audibleObjects[i]->processSound();
    }
}

bool AudioEngine::isTypeAudible(int type)
{
    if(type >= 10000) type -= 10000;
    if(type >= 1000)  type -= 1000;
    if(type >= 100)   type -= 100;
    if(type >= 10)    type -= 10;
    if(type >= 1)     return true;
    return false;
}
