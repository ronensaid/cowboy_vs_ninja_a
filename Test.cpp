#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"

using namespace ariel;

TEST_SUITE("Point class tests")
{
    Point p1{1, 1};
    Point p2{3, 3};
    Point p3{5, 1};
    Point p4{1, -5};
    Point p5{-1, -1};

    TEST_CASE("Distance method")
    {
        CHECK_EQ(p1.distance(p2), p2.distance(p1));
        CHECK_EQ(p3.distance(p4), p4.distance(p3));
        CHECK_EQ(p5.distance(p1), p1.distance(p5));

        CHECK_EQ(p4.distance(p1), 6);
        CHECK_EQ(p1.distance(p4), 6);
        CHECK_EQ(p1.distance(p3), 4);
        CHECK_EQ(p5.distance(p5), 0);
    }

    TEST_CASE("moveTowards method")
    {
        Point source(0, 0);
        Point destination(10, 0);

        // Test case 1: When the moving distance is more than the distance between two points
        Point result = source.moveTowards(destination, 20);
        CHECK_EQ(result.distance(destination), 0);

        // Test case 2: When the moving distance is exactly the distance between two points
        result = source.moveTowards(destination, 10); // distance is exactly 10
        CHECK_EQ(result.distance(destination), 0);

        // Test case 3: When the moving distance is less than the distance between two points
        result = source.moveTowards(destination, 5);
        CHECK_EQ(result.distance(source), 5); // result should be 5 units away
    }
}

TEST_SUITE("Characters tests of Cowboy,Ninja,Youngninja,Trainedninja")
{
    TEST_CASE("Testing Character class")
    {
        Point location(0, 0);
        Character character("John", location, 100); // Assuming 100 hit points initially

        // Check initial state
        CHECK(character.getName() == "John");
        CHECK(character.getLocation().distance(location) == 0);
        CHECK(character.isAlive() == true);

        // Check hit function
        character.hit(10);                  // Assuming hit reduces hit points by the given number
        CHECK(character.isAlive() == true); // Should still be alive after 10 damage

        character.hit(90);                   // Additional 90 damage makes total damage = 100
        CHECK(character.isAlive() == false); // Should not be alive after total damage equals hit points
    }
    TEST_CASE("Testing Cowboy class")
    {
        Point location(0, 0);
        Cowboy cowboy("John", location);

        // Check initial state
        CHECK(cowboy.getName() == "John");
        CHECK(cowboy.getLocation().distance(location) == 0);
        CHECK(cowboy.isAlive() == true);
        CHECK(cowboy.hasBullets() == true);

        Point enemyLocation(10, 0);
        Character enemy("Enemy", enemyLocation, 100); // Character initialized with 100 hit points

        // Check shooting at the enemy
        for (int i = 0; i < 6; ++i)
        {
            cowboy.shoot(&enemy);
            CHECK(enemy.isAlive() == true); // Enemy should be alive until 60 damage has been dealt
        }

        cowboy.shoot(&enemy);
        CHECK(cowboy.hasBullets() == false); // Cowboy should be out of bullets

        // Check reloading
        cowboy.reload();
        CHECK(cowboy.hasBullets() == true);

        for (int i = 0; i < 4; ++i)
        {
            cowboy.shoot(&enemy);
            CHECK(enemy.isAlive() == true); // Enemy should be alive until 100 damage has been dealt
        }
        CHECK(cowboy.hasBullets() == true);
        cowboy.shoot(&enemy);
        CHECK(enemy.isAlive() == false); // Enemy should be dead after 100 damage has been dealt
    }

    TEST_CASE("Testing Ninja class and subclasses")
    {
        Point location(0, 0);
        Cowboy cowboy("Cowboy", location); // Cowboy initialized with 110 hit points and 6 bullets

        SUBCASE("Testing YoungNinja subclass")
        {
            YoungNinja youngNinja("YoungNinja", location);

            // Test initial state
            CHECK(youngNinja.getName() == "YoungNinja");
            CHECK(youngNinja.isAlive() == true);

            // Test move function
            youngNinja.move(&cowboy);                                            // assuming move will modify the location
            CHECK(youngNinja.getLocation().distance(cowboy.getLocation()) <= 1); // Ninja should be within 1 meter of the cowboy

            // Test slash function
            youngNinja.slash(&cowboy);

            CHECK(cowboy.isAlive() == true); // Cowboy should have 60 hit points left after one slash
        }

        SUBCASE("Testing TrainedNinja subclass")
        {
            TrainedNinja trainedNinja("TrainedNinja", location);

            // Test initial state
            CHECK(trainedNinja.getName() == "TrainedNinja");
            CHECK(trainedNinja.isAlive() == true);

            // Test move function
            trainedNinja.move(&cowboy);                                            // assuming move will modify the location
            CHECK(trainedNinja.getLocation().distance(cowboy.getLocation()) <= 1); // Ninja should be within 1 meter of the cowboy

            // Test slash function
            trainedNinja.slash(&cowboy);
            CHECK(cowboy.isAlive() == true); // Cowboy should have 80 hit points left after one slash
        }

        SUBCASE("Testing OldNinja subclass")
        {
            OldNinja oldNinja("OldNinja", location);

            // Test initial state
            CHECK(oldNinja.getName() == "OldNinja");
            CHECK(oldNinja.isAlive() == true);

            // Test move function
            oldNinja.move(&cowboy);                                            // assuming move will modify the location
            CHECK(oldNinja.getLocation().distance(cowboy.getLocation()) <= 1); // Ninja should be within 1 meter of the cowboy

            // Test slash function
            oldNinja.slash(&cowboy);
            CHECK(cowboy.isAlive() == false); // Cowboy should be dead by now
        }
    }
    TEST_CASE("Testing Team class")
    {
        Point location(0, 0);
        Cowboy cowboy("Cowboy", location);
        OldNinja oldNinja("OldNinja", location);
        YoungNinja youngNinja("YoungNinja", location);
        TrainedNinja trainedNinja("TrainedNinja", location);

        // Create two teams
        Team team1(&cowboy);
        Team team2(&oldNinja);

        // Add members to each team
        team1.add(&cowboy);
        team1.add(&oldNinja);
        team1.add(&youngNinja);
        team2.add(&oldNinja);
        team2.add(&youngNinja);
        team2.add(&trainedNinja);

        // Test stillAlive function
        CHECK(team1.stillAlive() == 3);
        CHECK(team2.stillAlive() == 3);

        // Attack enemy team
        team1.attack(&team2);

        // Test stillAlive function after the attack
        CHECK(team1.stillAlive() == 3); // Number of alive members in team1
        CHECK(team2.stillAlive() <= 3); // Number of alive members in team2 should be less than or equal to 3
    }
}
