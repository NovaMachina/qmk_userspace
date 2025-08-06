#include "novamachina.h"
#include "tap_dance.h"

static tap dance_state[2];

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
    }
    if (state->count > 3) {
        tap_code16(LCTL(KC_C));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(LCTL(KC_C));
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_A));
            break;
        case DOUBLE_TAP:
            register_code16(LCTL(KC_X));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(KC_C));
            register_code16(LCTL(KC_C));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(KC_C));
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_A));
            break;
        case DOUBLE_TAP:
            unregister_code16(LCTL(KC_X));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(KC_C));
            break;
    }
    dance_state[0].step = 0;
}

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
    }
    if (state->count > 3) {
        tap_code16(LCTL(KC_V));
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(LCTL(KC_V));
            break;
        case SINGLE_HOLD:
            register_code16(KC_LEFT_CTRL);
            break;
        case DOUBLE_TAP:
            register_code16(LCTL(KC_V));
            register_code16(LCTL(KC_V));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(KC_V));
            register_code16(LCTL(KC_V));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(KC_V));
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_LEFT_CTRL);
            break;
        case DOUBLE_TAP:
            unregister_code16(LCTL(KC_V));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(KC_V));
            break;
    }
    dance_state[1].step = 0;
}
