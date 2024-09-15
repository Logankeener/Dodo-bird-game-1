// ControllerButton.h
#pragma once

enum class ControllerButton {
    A,
    B,
    X,
    Y,
    Start,
    Back,
    LeftStick,
    RightStick,
    DPadUp,
    DPadDown,
    DPadLeft,
    DPadRight
};

enum class ControllerAxis {
    LeftStickX,
    LeftStickY,
    RightStickX,
    RightStickY
};
// ControllerInput.cpp
#include "ControllerButton.h"
#include <unordered_map>

class ControllerInput {
public:
    ControllerInput();
    void Update();
    bool IsButtonPressed(ControllerButton button) const;
    float GetAxis(ControllerAxis axis) const;

private:
    std::unordered_map<ControllerButton, bool> buttonStates;
    std::unordered_map<ControllerAxis, float> axisStates;
};

ControllerInput::ControllerInput() {
    // Initialize button and axis states
}

void ControllerInput::Update() {
    // Update button and axis states from the controller
    // This is platform-specific code; you'll need to use an input library or API
}

bool ControllerInput::IsButtonPressed(ControllerButton button) const {
    auto it = buttonStates.find(button);
    return it != buttonStates.end() && it->second;
}

float ControllerInput::GetAxis(ControllerAxis axis) const {
    auto it = axisStates.find(axis);
    return (it != axisStates.end()) ? it->second : 0.0f;
}// MenuSystem.cpp
#include "ControllerInput.h"

class MenuSystem {
public:
    void Update(const ControllerInput& controllerInput);
    void OpenInventory();
    void SaveGame();
    void NavigateMenu(float rightStickX, float rightStickY);

private:
    bool isMenuOpen = false;
    // Other menu-related variables
};

void MenuSystem::Update(const ControllerInput& controllerInput) {
    if (controllerInput.IsButtonPressed(ControllerButton::Start)) {
        OpenInventory();
    }
    if (controllerInput.IsButtonPressed(ControllerButton::Back)) {
        SaveGame();
    }

    float rightStickX = controllerInput.GetAxis(ControllerAxis::RightStickX);
    float rightStickY = controllerInput.GetAxis(ControllerAxis::RightStickY);

    NavigateMenu(rightStickX, rightStickY);
}

void MenuSystem::OpenInventory() {
    isMenuOpen = !isMenuOpen;
    // Show or hide the inventory menu
}

void MenuSystem::SaveGame() {
    // Save the game state
}

void MenuSystem::NavigateMenu(float rightStickX, float rightStickY) {
    if (isMenuOpen) {
        // Use the right stick to navigate through menu options
        if (rightStickY > 0.5f) {
            // Navigate up
        } else if (rightStickY < -0.5f) {
            // Navigate down
        }
        if (rightStickX > 0.5f) {
            // Navigate right
        } else if (rightStickX < -0.5f) {
            // Navigate left
        }
    }
}
