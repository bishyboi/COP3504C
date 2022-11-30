#pragma once

#ifndef DEFAULT_INVENTORY_SIZE
#define DEFAULT_INVENTORY_SIZE 100
#endif

using namespace std;

template <class T>
class ParticleFactory{
    private:
        T* particles;
        //Constructor
        ParticleFactory(){
            particles = new T*[DEFAULT_INVENTORY_SIZE];
        }

        //Destructor
        ~ParticleFactory(){
            delete[] particles;
        }

        //Copy Constructor
        ParticleFactory(ParticleFactory &t){
            particles = t.particles;
        }

        //Copy assignment Constructor   
        ParticleFactor& operator=(const ParticleFactory& t){}

    public:
        ParticleFactory& getInstance(){}

        T* getparticle(){}

        void returnParticle(T* element){}
}