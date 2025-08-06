#pragma once

#include "quantum_keycodes.h"

enum custom_keycodes {
    RGB_SLD = SAFE_RANGE,
    VRSN,
    HSV_0_245_245,
    HSV_74_255_206,
    HSV_152_255_255,
    GIT_COMMIT,
    GIT_PUSH,
    VIM_QUIT,
};

void git_commit(void);
void git_push(void);
void vim_quit(void);
