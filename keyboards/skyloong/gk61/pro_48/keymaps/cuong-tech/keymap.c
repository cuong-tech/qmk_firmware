// Copyright 2021 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    LEFT_WORD = SAFE_RANGE,
    RIGHT_WORD,
    DELETE_WORD,
    COMMAND_TAB,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LEFT_WORD:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_LEFT);
                unregister_code(KC_LALT);
            }
            break;
        case RIGHT_WORD:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_RGHT);
                unregister_code(KC_LALT);
            }
            break;
        case DELETE_WORD:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_BSPC);
                unregister_code(KC_LALT);
            }
            break;
        case COMMAND_TAB:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_TAB);
                unregister_code(KC_LGUI);
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E | R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \ │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Cap│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │   |Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   |Sft|   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Ctl│GUI│Alt│   │Spc│Mut│   │   |Spc|Alt│App│Ctl│   │Mo1|
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_all(
         KC_GRV,   KC_1,       KC_2,       KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,  KC_EQL,   KC_BSLS,
         KC_TAB,   KC_Q,       KC_W,       KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,       KC_LBRC,  KC_RBRC,  KC_BSPC,
        KC_ESC,  LCTL_T(KC_A),       LALT_T(KC_S),       LSFT_T(KC_D),     LGUI_T(KC_F),     KC_G,     KC_H,     LGUI_T(KC_J),     LSFT_T(KC_K),     LALT_T(KC_L),     LCTL_T(KC_SCLN),    KC_QUOT,            KC_ENT,
        KC_LSFT,  LGUI_T(KC_Z),       KC_X,       KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,
        KC_LALT,  KC_LCTL,    KC_LGUI,             LT(5, KC_ENT),   KC_TAB,     KC_MUTE,               LT(4, KC_SPC),  CW_TOGG,      KC_APP,     KC_RCTL,               MO(6)
    ),

    [1] = LAYOUT_all(
         KC_GRV,   KC_1,       KC_2,       KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,  KC_EQL,   KC_BSLS,
         KC_TAB,   KC_Q,       KC_W,       KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,       KC_LBRC,  KC_RBRC,  KC_BSPC,
        KC_ESC,  LGUI_T(KC_A),       LALT_T(KC_S),       LSFT_T(KC_D),     LCTL_T(KC_F),     KC_G,     KC_H,     LCTL_T(KC_J),     LSFT_T(KC_K),     LALT_T(KC_L),     LGUI_T(KC_SCLN),    KC_QUOT,            KC_ENT,
        KC_LSFT,  LGUI_T(KC_Z),       KC_X,       KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,
        KC_LCTL,  KC_LGUI,    KC_LALT,             LT(5, KC_ENT),   KC_TAB,     KC_MUTE,               LT(4, KC_SPC),  CW_TOGG,      KC_APP,     KC_RCTL,               MO(6)
    ),

    [2] = LAYOUT_all(
         KC_GRV,   KC_1,       KC_2,       KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,  KC_EQL,   KC_BSLS,
         KC_TAB,  KC_B,       KC_L,       KC_D,     KC_W,     KC_Z,     KC_QUOT,     KC_F,     KC_O,     KC_U,     KC_J,       KC_LBRC,  KC_RBRC,  KC_BSPC,
        KC_ESC,  LCTL_T(KC_N),       LALT_T(KC_R),       LSFT_T(KC_T),     LGUI_T(KC_S),     KC_G,     KC_Y,     LGUI_T(KC_H),     LSFT_T(KC_A),     LALT_T(KC_E),     LCTL_T(KC_I),    KC_SCLN,            KC_ENT,
        KC_LSFT,  KC_Q,       KC_X,       KC_M,     KC_C,     KC_V,     KC_K,     KC_P,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,
        KC_LALT,  KC_LCTL,    KC_LGUI,             LT(5, KC_BSPC),   KC_TAB,     KC_MUTE,               LT(4, KC_SPC),  CW_TOGG,      KC_APP,     KC_RCTL,               MO(6)
    ),

    [3] = LAYOUT_all(
         KC_GRV,   KC_1,       KC_2,       KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,  KC_EQL,   KC_BSLS,
         KC_TAB,  KC_B,       KC_L,       KC_D,     KC_W,     KC_Z,     KC_QUOT,     KC_F,     KC_O,     KC_U,     KC_J,       KC_LBRC,  KC_RBRC,  KC_BSPC,
        KC_ESC,  LGUI_T(KC_N),       LALT_T(KC_R),       LSFT_T(KC_T),     LCTL_T(KC_S),     KC_G,     KC_Y,     LCTL_T(KC_H),     LSFT_T(KC_A),     LALT_T(KC_E),     LGUI_T(KC_I),    KC_SCLN,            KC_ENT,
        KC_LSFT,  KC_Q,       KC_X,       KC_M,     KC_C,     KC_V,     KC_K,     KC_P,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,
        KC_LALT,  KC_LCTL,    KC_LGUI,             LT(5, KC_BSPC),   KC_TAB,     KC_MUTE,               LT(4, KC_SPC),  CW_TOGG,      KC_APP,     KC_RCTL,               MO(6)
    ),

    [4] = LAYOUT_all(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  KC_DEL,  _______,  _______,     _______,  LEFT_WORD,  KC_UP,  RIGHT_WORD,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  _______,  _______,            _______,
        _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,     _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,            _______,  _______,     _______,            _______,  _______,  _______,  _______,            _______
    ),

    [5] = LAYOUT_all(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  KC_DEL,  _______,  _______,     _______,  LEFT_WORD,  KC_UP,  RIGHT_WORD,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  _______,  _______,            _______,
        _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,     _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,            _______,  _______,     _______,            _______,  _______,  _______,  _______,            _______
    ),

    [6] = LAYOUT_all(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  RGB_TOG,  _______,  _______,  _______,  _______,     _______,  LEFT_WORD,  KC_UP,  RIGHT_WORD,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  _______,  _______,            _______,
        _______,  TO(0),    TO(1),    TO(2),  TO(3),  _______,     _______,  _______,  _______,  _______,  _______,            _______,
        QK_BOOT,  _______,  _______,            _______,  _______,     _______,            _______,  _______,  _______,  _______,            _______
    )

};

// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
//     [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
//     [1] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
//     [2] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
//     [3] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
//     [4] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
//     [5] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
//     [6] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
// };

const uint16_t PROGMEM delete_word_combo[]     = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM delete_word_combo_gra[]     = {KC_P, KC_COMM, COMBO_END};
const uint16_t PROGMEM backspace_combo[]     = {KC_9, KC_0, COMBO_END};

// check https://github.com/qmk/qmk_firmware/issues/4611
combo_t                key_combos[]            = {
    COMBO(delete_word_combo, DELETE_WORD),
    COMBO(delete_word_combo_gra, DELETE_WORD),
    COMBO(backspace_combo, KC_BSPC),
    // COMBO(delete_word_combo_gra, KC_BSPC),
};
