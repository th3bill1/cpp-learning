#include <iostream>
#include "organism.h"
#include "plant.h"
#include "flower.h"
#include "animal.h"
#include "bear.h"
#include "ecosystem.h"

void Lab10() {
    
        //PART 1
        std::cout << "PART 1" << std::endl;
        Organism o1("organism");
        Organism o2("organism");
        std::cout << o1 << std::endl << o2 << std::endl;
        {
            Organism o3("organism");
            std::cout << o3 << std::endl;
        }
        std::cout << "current population: " << o1.population() << std::endl;
    
    
        //PART 2
        std::cout << std::endl << "PART 2" << std::endl;
        Plant p1("tree");
        std::cout << p1 << std::endl;
        Organism *p2 = new Plant("grass");
        std::cout << *p2 << std::endl;
        delete p2;
        const Organism &p3 = p1;
        std::cout << p3 << std::endl;
    
    
        //PART 3
        std::cout << std::endl << "PART 3" << std::endl;
        Flower f1;
        std::cout << f1 << std::endl;
        Organism *f2 = new Flower();
        std::cout << *f2 << std::endl;
        delete f2;
        Plant *f3 = new Flower();
        std::cout << *f3 << std::endl;
        delete f3;
    
    
        //PART 4
        std::cout << std::endl << "PART 4" << std::endl;
        Animal a1("cow");
        std::cout << a1 << std::endl;
        std::cout << "We hear: " << a1.sound() << ". Hmmm, is it really a cow?" << std::endl;
        Bear a2;
        std::cout << a2 << std::endl;
        std::cout << "We hear: " << a2.sound() << ". It doesn't sound like a bear!" << std::endl;
        std::cout << "Wait, now we hear: " << a2.sound(false) << ". Now it is a bear!" << std::endl;
        std::cout << "Oh, we hear: " << a2.sound(true) << ". We have to run! The bear is dangerous!" << std::endl;
    
    
        //PART 5
        std::cout << std::endl << "PART 5" << std::endl;
        Ecosystem ecosystem;
        //Incorrect
        if(!ecosystem.initialize("something:bear ,:grass,plant,,animal:frog")) {
            std::cout << "Incorrect data 1" << std::endl;
        }
        //Incorrect
        if(!ecosystem.initialize("animal:bear,")) {
            std::cout << "Incorrect data 2" << std::endl;
        }
        //Incorrect
        if(!ecosystem.initialize("ANIMAL:bear")) {
            std::cout << "Incorrect data 3" << std::endl;
        }
        //Incorrect
        if(!ecosystem.initialize("animal:this : is correct,plant:this , is incorrect")) {
            std::cout << "Incorrect data 4" << std::endl;
        }
        //Incorrect
        if(!ecosystem.initialize("ani:bear")) {
            std::cout << "Incorrect data 5" << std::endl;
        }
        //Incorrect
        if(!ecosystem.initialize("plant:")) {
            std::cout << "Incorrect data 6" << std::endl;
        }
        //Incorrect
        if(!ecosystem.initialize("plant")) {
            std::cout << "Incorrect data 7" << std::endl;
        }
        //Incorrect
        if(!ecosystem.initialize(":bear")) {
            std::cout << "Incorrect data 8" << std::endl;
        }
        //Incorrect
        if(!ecosystem.initialize("bear")) {
            std::cout << "Incorrect data 9" << std::endl;
        }
        //Correct
        if(!ecosystem.initialize("")) {
            std::cout << "Incorrect data 10" << std::endl;
        }
        //Correct
        if(!ecosystem.initialize("animal:bear,plant:grass,plant:tree,plant:hibiscus,animal:frog")) {
            std::cout << "Incorrect data" << std::endl;
        }
    
        //PART 6
        std::cout << std::endl << "PART 6" << std::endl;
        std::cout << "Number of plants in ecosystem: " << ecosystem.countPlants() << std::endl;
    
}
