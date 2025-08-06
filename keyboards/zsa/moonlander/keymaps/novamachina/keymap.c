/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "action_layer.h"
#include "custom_keycodes.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "moonlander.h"
#include "process_auto_shift.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.h"
#include "tap_dance.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = myLayout(
        /*LEFT*/
        KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LEFT, \
        KC_DEL, KC_Q, KC_W, KC_E, KC_R, KC_T, TG(SYMB), \
        MO(SYMB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_HYPR, \
        KC_LCTL, KC_Z, KC_X,KC_C, KC_V, KC_B, \
        KC_GRV, CW_TOGG, OSL(MACROS), KC_LEFT, KC_RIGHT, \
        MT(MOD_LALT, KC_LGUI), \
        LT(MACROS, KC_ENTER), KC_BSPC, LCTL(KC_SEMICOLON), \
        /*RIGHT*/
        KC_RIGHT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, \
        LM(MDIA,MOD_LSFT), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, \
        KC_MEH, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, RCTL(KC_RIGHT_SHIFT), \
        KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB), \
        MT(MOD_LCTL, KC_ESCAPE), \
        KC_SPC,  KC_TAB,  LT(NAV, KC_LALT)
    ),

    [SYMB] = myLayout(
        /*LEFT*/
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, \
        _______, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, _______, \
        _______, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRAVE, _______, \
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, \
        _______, KC_COMMA, HSV_0_245_245, HSV_74_255_206, HSV_152_255_255, \
        RGB_MODE_FORWARD, \
        RGB_VAD, RGB_VAI, TOGGLE_LAYER_COLOR, \
        /*RIGHT*/
        _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, \
        _______, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12, \
        _______, KC_DOWN, KC_4, KC_5, KC_6, KC_KP_PLUS, _______, \
        _______, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS, \
        _______,  KC_DOT, KC_0, KC_EQUAL, _______, \
        RGB_TOG, \
        RGB_SLD, RGB_HUD, RGB_HUI
    ),

    [MDIA] = myLayout(
        /*LEFT*/
        AU_TOGG, _______, _______, _______, _______, _______, _______, \
        MU_TOGG, _______, _______, KC_MS_UP, _______, _______, _______, \
        MU_NEXT, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______, \
        _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, \
        _______, \
        _______, _______, _______, \
        /*RIGHT*/
        AS_TOGG, _______, _______, _______, _______, _______, QK_BOOT, \
        _______, TG(FACTORIO), _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE, \
        _______, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, _______, _______, \
        _______, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, _______, \
        _______, \
        _______, _______, KC_WWW_BACK
    ),

    [MACROS] = myLayout(
        /*LEFT*/
        GIT_COMMIT, LCTL(LSFT(KC_1)), LCTL(LSFT(KC_I)), VIM_QUIT, _______, _______, _______, \
        GIT_PUSH, _______, LSFT(KC_F6), _______, _______, _______, _______, \
        _______, _______, LCTL(KC_F9), LCTL(LSFT(KC_F10)), _______, _______, _______, \
        _______, _______, LALT(KC_ENTER), _______, _______, _______, \
        _______, _______, _______, LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)), \
        _______, \
        _______, _______, _______, \
        /*RIGHT*/
        _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, LCTL(KC_Z), LCTL(KC_Y), LCTL(KC_F), _______, _______, \
        _______, _______, LCTL(LSFT(KC_N)), LALT(KC_LEFT), LALT(KC_RIGHT), _______, _______, \
        _______, KC_F8, LSFT(KC_F8), KC_F9,_______, _______, \
        _______, _______, _______, _______, _______, \
        _______, \
        _______, _______, _______
    ),
    [FACTORIO] = myLayout(
        /*LEFT*/
        _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, \
        KC_LEFT_SHIFT, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, \
        _______, \
        _______, _______, _______, \
        /*RIGHT*/
        _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, \
        _______, \
        _______, _______, _______
    ),
    [NAV] = myLayout(
        /*LEFT*/
        _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, KC_UP, _______, _______, _______, \
        _______, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, \
        _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, \
        _______, \
        KC_LSFT, _______, _______, \
        /*RIGHT*/
        _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, \
        _______, \
        _______, _______, _______
    ),
};

// clang-format on

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case GIT_COMMIT:
                git_commit();
                return false;
            case GIT_PUSH:
                git_push();
                return false;
            case VIM_QUIT:
                vim_quit();
                return false;
            case RGB_SLD:
                if (rawhid_state.rgb_control) {
                    return false;
                }
                rgblight_mode(1);
                return false;
            case HSV_0_245_245:
                if (rawhid_state.rgb_control) {
                    return false;
                }
                rgblight_mode(1);
                rgblight_sethsv(0, 245, 245);
                return false;
            case HSV_74_255_206:
                if (rawhid_state.rgb_control) {
                    return false;
                }
                rgblight_mode(1);
                rgblight_sethsv(74, 255, 206);
                return false;
            case HSV_152_255_255:
                if (rawhid_state.rgb_control) {
                    return false;
                }
                rgblight_mode(1);
                rgblight_sethsv(152, 255, 255);
                return false;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case FACTORIO: {
            autoshift_disable();
            break;
        }
        default: {
            autoshift_enable();
            break;
        }
    }
    return state;
}

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};
