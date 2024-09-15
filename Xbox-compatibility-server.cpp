#include <iostream>
#include <XInput.h>

class XboxController {
public:
    XboxController() {
        ZeroMemory(&state, sizeof(XINPUT_STATE));
    }

    bool Update() {
        ZeroMemory(&state, sizeof(XINPUT_STATE));
        return XInputGetState(0, &state) == ERROR_SUCCESS;
    }

    bool IsButtonPressed(WORD button) {
        return (state.Gamepad.wButtons & button) != 0;
    }

    float GetLeftThumbX() {
        return state.Gamepad.sThumbLX / 32767.0f;
    }

    float GetLeftThumbY() {
        return state.Gamepad.sThumbLY / 32767.0f;
    }

    float GetRightThumbX() {
        return state.Gamepad.sThumbRX / 32767.0f;
    }

    float GetRightThumbY() {
        return state.Gamepad.sThumbRY / 32767.0f;
    }

private:
    XINPUT_STATE state;
};
