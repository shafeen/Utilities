<?php
/**
 * Created by IntelliJ IDEA.
 * User: SHAFEEEENZZ
 * Date: 7/26/15
 * Time: 4:49 PM
 */

abstract class Animal {

    public function describe() {
        printf("%s! I'm a %s, and I have %d legs. My name is %s.\n",
               $this->getCall(),
               get_class($this),
               $this->getNumLegs(),
               $this->getName());
    }

    abstract function getCall();

    abstract function getNumLegs();

    abstract function getName();
}

abstract class Bird extends Animal {

    function getNumLegs() {
        return 2;
    }

    abstract function canFly();
}

class Pig extends Animal {

    function getCall() {
        return "Oink";
    }

    function getNumLegs() {
        return 4;
    }

    function getName() {
        return "Babe";
    }
}

class Duck extends Bird {

    function getCall() {
        return "Quack";
    }

    function getName() {
        return "Donald";
    }

    function canFly() {
        return true;
    }
}

class Cat extends Animal {

    function getCall() {
        return "Meow";
    }

    function getNumLegs() {
        return 4;
    }

    function getName() {
        return "Chaz";
    }
}

$duck = new Duck();
$duck->describe();

$cat = new Cat();
$cat->describe();

