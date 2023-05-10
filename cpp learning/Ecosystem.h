#include <string>
#include "organism.h"
#include "Animal.h"
#include "Plant.h"

class Ecosystem {
private:
    Organism** organisms = nullptr;
    unsigned int count;
    int isAnimalOrPlant(const std::string& input, int start) const;
    int isSegment(const std::string& input, int start) const;
    bool validate(const std::string& input) const;
    void clear();
public:
    bool initialize(const std::string& input);
    unsigned int countPlants() const;
    ~Ecosystem();
};
