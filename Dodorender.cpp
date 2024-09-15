#include <iostream>

class DodoBoss {
public:
    int health;
    float detectionRange;
    float attackRange;

    DodoBoss() {
        health = 100; // DodoBoss starts with 100 health
        detectionRange = 50.0f; // Example detection range
        attackRange = 10.0f; // Example attack range
    }

    // Function to detect if the player is within range
    bool IsPlayerInRange(float playerDistance) {
        return playerDistance <= detectionRange;
    }

    // Function to attack the player
    void Attack() {
        std::cout << "DodoBoss attacks!" << std::endl;
        // Implement attack logic here
    }

    // Function to patrol or move around
    void Patrol() {
        std::cout << "DodoBoss patrols the area." << std::endl;
        // Implement patrol logic here
    }

    // Function to take damage
    void TakeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            Die();
        }
    }

    // Function to handle boss's death
    void Die() {
        std::cout << "DodoBoss has been defeated!" << std::endl;
        // Implement death logic here
    }
};
