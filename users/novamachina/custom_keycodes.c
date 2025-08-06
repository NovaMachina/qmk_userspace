#include "custom_keycodes.h"
#include "action.h"
#include "keycodes.h"
#include "quantum.h"

void git_commit(void) {
    SEND_STRING("git add .");
    tap_code(KC_ENTER);
    SEND_STRING("git commit");
    tap_code(KC_ENTER);
}

void git_push(void) {
    SEND_STRING("git push");
    tap_code(KC_ENTER);
}

void vim_quit(void) {
    SEND_STRING(":wq");
    tap_code(KC_ENTER);
}
