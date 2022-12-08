#pragma once

#ifndef DEFAULT_INVENTORY_SIZE
#define DEFAULT_INVENTORY_SIZE 100
#endif

using namespace std;

template <class T>
class ParticleFactory{
    private:
        // Pointer to all particles in inventory
        T* particles=nullptr;
        int used_elements=0;

        ParticleFactory(){
            particles = new T[DEFAULT_INVENTORY_SIZE];
        }

        //Destructor
        ~ParticleFactory(){
            delete[] particles;
        }

        // Copy Constructor
        ParticleFactory(ParticleFactory& t){}

        // Copy Assignment Constructor   
        ParticleFactory& operator=(const ParticleFactory& t){}

        
    public:

        // Singleton factory
        static ParticleFactory& getInstance(){
            static ParticleFactory particle_factory;
            return particle_factory;
        }

        // Returns a pointer to an instance of T. If the inventory has available elements, an element should be removed from 
        // the inventory and returned; if the inventory is empty, a new instance of T should be allocated and returned. 
        T* getParticle(){
            if(used_elements>DEFAULT_INVENTORY_SIZE){
                return &(particles[used_elements++]);
            }else{
                return new T;
            }
        }

        // Accepts a pointer to an instance of T for recycling, which should be stored in the inventory for later use.
        void returnParticle(T* element){
            if(used_elements<=0){
                delete element;
            }else{
                used_elements--;
            }
        }
};