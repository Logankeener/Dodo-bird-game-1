#include <iostream>
#include <cmath>

// Forward declarations for player class and other components
class Player;

class Boss {
public:
    Boss(float x, float y) : positionX(x), positionY(y), health(100), attackRange(10.0f), isAggressive(false) {}

    // Method to check if the player is within range
    bool IsPlayerInRange(const Player& player) const;

    // Method to execute attack behavior
    void Attack(Player& player);

    // Method to patrol between waypoints
    void Patrol();

    // Method to update boss behavior
    void Update(const Player& player);

    // Method to apply damage to the boss
    void TakeDamage(int damage);

    // Check if the boss is defeated
    bool IsDefeated() const;

    // Accessors and mutators
    float GetX() const { return positionX; }
    float GetY() const { return positionY; }
    void SetPosition(float x, float y) { positionX = x; positionY = y; }

    void SetAggressive(bool aggressive) { isAggressive = aggressive; }

private:
    float positionX, positionY;  // Boss's position
    int health;                  // Boss's health
    float attackRange;           // Range within which the boss will attack
    bool isAggressive;           // State indicating whether the boss is aggressive or not
};#include <cmath>

// Mock Player class for demonstration
class Player {
public:
    Player(float x, float y) : positionX(x), positionY(y), health(100) {}

    float GetX() const { return positionX; }
    float GetY() const { return positionY; }

    void TakeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        std::cout << "Player takes " << damage << " damage. Remaining health: " << health << std::endl;
    }

private:
    float positionX, positionY;
    int health;
};

bool Boss::IsPlayerInRange(const Player& player) const {
    float distance = std::sqrt(std::pow(player.GetX() - positionX, 2) + std::pow(player.GetY() - positionY, 2));
    return distance <= attackRange;
}

void Boss::Attack(Player& player) {
    std::cout << "Boss attacks!" << std::endl;
    player.TakeDamage(10);  // Example damage value
}

void Boss::Patrol() {
    std::cout << "Boss patrols the area." << std::endl;
    // Implement patrol logic here
}

void Boss::Update(const Player& player) {
    if (IsDefeated()) {
        std::cout << "Boss is defeated and cannot act." << std::endl;
        return;
    }

    if (IsPlayerInRange(player)) {
        Attack(player);
    } else {
        Patrol();
    }
}

void Boss::TakeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    std::cout << "Boss takes " << damage << " damage. Remaining health: " << health << std::endl;
}

bool Boss::IsDefeated() const {
    return health <= 0;
}#include <iostream>

int main() {
    // Create a player and a boss
    Player player(15.0f, 20.0f);
    Boss boss(10.0f, 10.0f);

    // Simulate the game loop
    for (int i = 0; i < 5; ++i) {
        std::cout << "Round " << i + 1 << std::endl;
        boss.Update(player);
        player.TakeDamage(10);  // Simulate player taking damage from the boss
        boss.TakeDamage(10);    // Simulate boss taking damage from the player

        if (boss.IsDefeated()) {
            std::cout << "Boss is defeated!" << std::endl;
            break;
        }
    }

    return 0;
}
