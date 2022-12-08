#pragma once

#ifndef DEFAULT_INVENTORY_SIZE
#define DEFAULT_INVENTORY_SIZE 100
#endif

template <class T>

class ParticleFactory
{
    T *inventory = nullptr;
    int count = DEFAULT_INVENTORY_SIZE;

    ParticleFactory()
    {
        inventory = new T[DEFAULT_INVENTORY_SIZE];
    }

    ~ParticleFactory()
    {
        delete[] inventory;
    }

    ParticleFactory(ParticleFactory &t) {}

    ParticleFactory &operator=(const ParticleFactory &t) {}

public:
    static ParticleFactory& getInstance()
    {
        static ParticleFactory singleton;
        return singleton;
    }

    T* getParticle()
    {
        if (count > 0)
        {
            return &(inventory[--count]);
        }
        return new T;
    }

    void returnParticle(T *element)
    {
        if (count < DEFAULT_INVENTORY_SIZE)
        {
            count++;
        }
        else
        {
            delete element;
        }
    }
};