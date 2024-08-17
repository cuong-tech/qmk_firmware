// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    LEFT_WORD = SAFE_RANGE,
    RIGHT_WORD,
    DELETE_WORD,
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
    }
    return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [0] = LAYOUT( /* Base Mac */
        KC_GRV,   KC_1,       KC_2,       KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,  KC_EQL,   KC_BSLS,   KC_MUTE,
        KC_TAB,   KC_Q,       KC_W,       KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,       KC_LBRC,  KC_RBRC,  KC_BSPC,   KC_DEL,
        KC_ESC,  LCTL_T(KC_A),       LALT_T(KC_S),       LSFT_T(KC_D),     LGUI_T(KC_F),     KC_G,     KC_H,     LGUI_T(KC_J),     LSFT_T(KC_K),     LALT_T(KC_L),     LCTL_T(KC_SCLN),    KC_QUOT,            KC_ENT,    KC_PGUP,
        KC_LSFT,  LGUI_T(KC_Z),       KC_X,       KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,            KC_UP,     KC_PGDN,
        KC_LALT,  KC_LCTL,    LGUI_T(KC_ENT),                        LT(4, KC_SPC),                       CW_TOGG,  MO(5),                KC_LEFT,            KC_DOWN,   KC_RGHT
        ),

    [1] = LAYOUT( /* Base */
        KC_GRV,   KC_1,       KC_2,       KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,  KC_EQL,   KC_BSLS,   KC_MUTE,
        KC_TAB,   KC_Q,       KC_W,       KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,       KC_LBRC,  KC_RBRC,  KC_BSPC,   KC_DEL,
        KC_ESC,  LGUI_T(KC_A),       LALT_T(KC_S),       LSFT_T(KC_D),     LCTL_T(KC_F),     KC_G,     KC_H,     LCTL_T(KC_J),     LSFT_T(KC_K),     LALT_T(KC_L),     LGUI_T(KC_SCLN),    KC_QUOT,            KC_ENT,    KC_PGUP,
        KC_LSFT,  LCTL_T(KC_Z),       KC_X,       KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,            KC_UP,     KC_PGDN,
        KC_LCTL,  KC_LGUI,    LALT_T(KC_ENT),                        LT(4, KC_SPC),                       CW_TOGG,  MO(5),                KC_LEFT,            KC_DOWN,   KC_RGHT
        ),

    [2] = LAYOUT( /* Base Mac */
        KC_GRV,   KC_1,       KC_2,       KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,  KC_EQL,   KC_BSLS,   KC_MUTE,
        KC_TAB,   KC_B,       KC_L,       KC_D,     KC_W,     KC_Z,     KC_QUOT,     KC_F,     KC_O,     KC_U,     KC_J,       KC_LBRC,  KC_RBRC,  KC_BSPC,   KC_DEL,
        KC_ESC,  LCTL_T(KC_N),       LALT_T(KC_R),       LSFT_T(KC_T),     LGUI_T(KC_S),     KC_G,     KC_Y,     LGUI_T(KC_H),     LSFT_T(KC_A),     LALT_T(KC_E),     LCTL_T(KC_I),    KC_SCLN,            KC_ENT,    KC_PGUP,
        KC_LSFT,  LGUI_T(KC_Q),       KC_X,       KC_M,     KC_C,     KC_V,     KC_K,     KC_P,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,            KC_UP,     KC_PGDN,
        KC_LALT,  KC_LCTL,    LGUI_T(KC_ENT),                        LT(4, KC_SPC),                       CW_TOGG,  MO(5),                KC_LEFT,            KC_DOWN,   KC_RGHT
        ),

    [3] = LAYOUT( /* Base */
        KC_GRV,   KC_1,       KC_2,       KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,       KC_MINS,  KC_EQL,   KC_BSLS,   KC_MUTE,
        KC_TAB,   KC_B,       KC_L,       KC_D,     KC_W,     KC_Z,     KC_QUOT,     KC_F,     KC_O,     KC_U,     KC_J,       KC_LBRC,  KC_RBRC,  KC_BSPC,   KC_DEL,
        KC_ESC,  LGUI_T(KC_N),       LALT_T(KC_R),       LSFT_T(KC_T),     LCTL_T(KC_S),     KC_G,     KC_Y,     LCTL_T(KC_H),     LSFT_T(KC_A),     LALT_T(KC_E),     LGUI_T(KC_I),    KC_SCLN,            KC_ENT,    KC_PGUP,
        KC_LSFT,  LCTL_T(KC_Q),       KC_X,       KC_M,     KC_C,     KC_V,     KC_K,     KC_P,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,            KC_UP,     KC_PGDN,
        KC_LCTL,  KC_LGUI,    LALT_T(KC_ENT),                        LT(4, KC_SPC),                       CW_TOGG,  MO(5),                KC_LEFT,            KC_DOWN,   KC_RGHT
        ),
    [4] = LAYOUT( /* FN */
        KC_GRV,   KC_F1,      KC_F2,      KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,   _______,   _______,
        _______,  CW_TOGG,    KC_MS_UP,    KC_ESC,  QK_REP,  _______,  _______,  LEFT_WORD,  KC_UP,  RIGHT_WORD,  KC_BSPC,    KC_HOME,  KC_SCRL,  _______,   KC_INS,
        _______, KC_MS_LEFT,  KC_MS_DOWN,      KC_MS_RIGHT,  KC_BSPC,  KC_DEL,  KC_MS_WH_UP,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_RIGHT,    KC_PSCR,            _______,   KC_PAUSE,
        KC_LSFT,  TO(0),    TO(1),    TO(2),  TO(3),  _______,  KC_MS_WH_DOWN,  KC_MS_BTN1,  KC_MS_BTN2,  _______,  _______,    _______,            _______,   _______,
        QK_BOOT,  GU_TOGG,    _______,                        EE_CLR,                       CW_TOGG,  _______,              _______,            RGB_TOG,   _______
        ),
    [5] = LAYOUT( /* FN */
        KC_GRV,   KC_F1,      KC_F2,      KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,   _______,   _______,
        _______,  _______,    KC_TAB,    KC_ESC,  QK_REP,  _______,  _______,  KC_DEL,  KC_UP,  KC_BSPC,  _______,    KC_HOME,  KC_SCRL,  _______,   KC_INS,
        _______, _______,  _______,      _______,  _______,  _______,  KC_LEFT,  LEFT_WORD,  KC_DOWN,  RIGHT_WORD,  KC_RIGHT,    KC_PSCR,            _______,   KC_PAUSE,
        _______,  TO(0),    TO(1),    TO(2),  TO(3),  _______,  _______,  _______,  _______,  _______,  _______,    _______,            _______,   _______,
        QK_BOOT,  GU_TOGG,    _______,                        EE_CLR,                       _______,  _______,              _______,            RGB_TOG,   _______
        ),
};

// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_ENT):
        case LGUI_T(KC_ENT):
            return TAPPING_TERM - 55;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM enter_combo[]           = {KC_COMM, KC_DOT, COMBO_END};
// const uint16_t PROGMEM caps_word_combo[]       = {KC_Z, KC_X, COMBO_END};
// const uint16_t PROGMEM caps_word_combo_gra[]   = {KC_Q, KC_X, COMBO_END};
// const uint16_t PROGMEM tab_combo[]             = {KC_X, KC_C, COMBO_END};
// const uint16_t PROGMEM tab_combo_gra[]         = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM backspace_combo_1[]     = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM backspace_combo_2[]     = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM backspace_combo_2_gra[] = {KC_P, KC_COMM, COMBO_END};
combo_t                key_combos[]            = {
    // COMBO(enter_combo, KC_ENT),
    // COMBO(caps_word_combo, CW_TOGG),
    // COMBO(tab_combo, KC_TAB),
    // COMBO(tab_combo_gra, KC_TAB),
    COMBO(backspace_combo_1, DELETE_WORD),
    COMBO(backspace_combo_2, DELETE_WORD),
    COMBO(backspace_combo_2_gra, DELETE_WORD),
};
