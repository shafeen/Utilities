/**
 * Created by Shafeen M.
 * Date: 8/8/15.
 *
 * An example demo-ing Singletons and Constructor
 * notation for use when creating objects.
 */

// Singleton object
var AnimalCreator = function () {
    var numAnimals = 0;

    var animalTypes = {
        duck: "duck",
        human: "human",
        dog: "dog",
        cat: "cat"
    };

    // Animal object constructor
    function Animal(name, numlegs, type) {
        this.animalName = name;
        this.numlegs = numlegs;
        this.animalType = type;
        this.describe = function () {
            console.log("My name is %s, I have %d legs and I'm a %s.",
                        this.animalName,
                        this.numlegs,
                        this.animalType);
        };
    }

    function createAnimal(name, numlegs, type) {
        numAnimals += 1;
        return new Animal(name, numlegs, type);
    }

    function getNumAnimals() {
        return numAnimals;
    }

    return {
        animalTypes : animalTypes,
        createAnimal : createAnimal,
        getNumAnimals : getNumAnimals
    };
}();


var donald = AnimalCreator.createAnimal("donald", 2, AnimalCreator.animalTypes.duck).describe();
console.log("%d animal(s) created.", AnimalCreator.getNumAnimals());

var daisy = AnimalCreator.createAnimal("daisy", 2, AnimalCreator.animalTypes.duck).describe();
console.log("%d animal(s) created.", AnimalCreator.getNumAnimals());

var scooby = AnimalCreator.createAnimal("scooby", 4, AnimalCreator.animalTypes.dog).describe();
console.log("%d animal(s) created.", AnimalCreator.getNumAnimals());

var felix = AnimalCreator.createAnimal("felix", 4, AnimalCreator.animalTypes.cat).describe();
console.log("%d animal(s) created.", AnimalCreator.getNumAnimals());
