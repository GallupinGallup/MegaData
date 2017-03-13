//
//  FoodItem.cpp
//  MegaData
//
//  Created by Gallup, Tyler on 3/13/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//


#include "foodItem.hpp"

FoodItem :: FoodItem()
{
    this->calories = 666;
    this->foodName = "poop";
    this->cost = 676767767.44;
    this->delicious = false;
}

FoodItem :: FoodItem(string name)
{
    this->cost = 676767767.44;
    this->delicious = false;
    this->calories = 999;
    this->foodName = name;
}


int FoodItem :: getCalories()
{
    return calories;
}

double FoodItem :: getCost()

{
    return cost;
}

string FoodItem :: getFoodName()

{
    return foodName;
}

bool FoodItem :: isDelicious()

{
    return delicious;
}

void FoodItem :: setCalories(int calories)
{
    this->calories = calories;
}

void FoodItem :: setFoodName(string foodName)
{
    this->foodName = foodName;
}

void FoodItem :: isDelicious(bool delicious)
{
    this->delicious = delicious;
}

void FoodItem :: setCost(double cost)
{
    this->cost= cost;
}



