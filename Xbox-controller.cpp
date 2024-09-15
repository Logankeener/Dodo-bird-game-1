void ProcessInput(XboxController& controller) {
    if (controller.Update()) {
        // Check if the A button is pressed
        if (controller.IsButtonPressed(XINPUT_GAMEPAD_A)) {
            std::cout << "A button pressed" << std::endl;
        }

        // Get the thumbstick values
        float leftX = controller.GetLeftThumbX();
        float leftY = controller.GetLeftThumbY();
        float rightX = controller.GetRightThumbX();
        float rightY = controller.GetRightThumbY();

        // Use thumbstick values for movement or other actions
        std::cout << "Left Thumbstick X: " << leftX << " Y: " << leftY << std::endl;
        std::cout << "Right Thumbstick X: " << rightX << " Y: " << rightY << std::endl;
    } else {
        std::cout << "Controller not connected" << std::endl;
    }
}
int main() {
    XboxController controller;

    while (true) {
        // Process input
        ProcessInput(controller);

        // Other game loop code...

        // Sleep or wait to control frame rate
        Sleep(16); // Roughly 60 FPS
    }

    return 0;
}void UpdatePlayerMovement(XboxController& controller, Player& player) {
    float moveX = controller.GetLeftThumbX();
    float moveY = controller.GetLeftThumbY();

    // Update player position based on thumbstick input
    player.Move(moveX, moveY);
}
