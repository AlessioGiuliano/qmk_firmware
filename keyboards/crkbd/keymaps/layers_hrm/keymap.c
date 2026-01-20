/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY_HRM,
    _QWERTY_STD,
    _SYMBOLS,
    _NAVIGATION,
    _ACCENTS
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Avoid triggering f twice in vim when looking for capital letter
        case HRM_F:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

// Accents via US-International AltGr
#define E_AIGU RALT(KC_E)    // é
#define A_GRV RALT(KC_A)    // à
#define U_GRV RALT(KC_U)    // ù
#define C_CED RALT(KC_C)    // ç
#define I_GRV RALT(KC_I)    // î

#define ACC_GRV RALT(KC_GRV)
#define ACC_AIG RALT(KC_QUOT)
#define ACC_CIR RALT(KC_CIRC)
#define ACC_TRE RALT(KC_DQT)

enum custom_keycodes {
    PIX4D = SAFE_RANGE,
    E_GRV,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PIX4D:
        if (record->event.pressed) {
            SEND_STRING("pix4d");
        }
        return false;
    case E_GRV:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("`") "e");
        }
        return false;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY_HRM] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, LM_TOGG,    _______,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,   HRM_A,   HRM_S,   HRM_D,   HRM_F,    KC_G, _______,    _______,    KC_H,   HRM_J,   HRM_K,   HRM_L,HRM_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(_NAVIGATION),  KC_SPC,     KC_ENT,   MO(_SYMBOLS), MO(_ACCENTS)
                                      //`--------------------------'  `--------------------------'

  ),

    // Home row mods disabled
    [_QWERTY_STD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_S,    KC_D,    KC_F, _______,                      _______,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______,  _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_PIPE,    KC_7,    KC_8,    KC_9,  KC_EQL, LM_NEXT,  LM_BRIU,    KC_ASTR, KC_LCBR, KC_RCBR, KC_EXLM, KC_PERC,   KC_AT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG,   HRM_0,   HRM_4,   HRM_5,   HRM_6, KC_MINS, LM_PREV,  LM_BRID,   KC_UNDS, KC_LPRN, KC_RPRN,  KC_DLR, KC_CIRC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_DOT,    KC_1,    KC_2,    KC_3, KC_PLUS,                      KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI,  HRM_F4,  HRM_F5,  HRM_F6,  KC_F11,                      HRM_LE,  HRM_DO,  HRM_UP,  HRM_RI,  _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_ACCENTS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ACC_GRV, _______,   E_GRV,  E_AIGU, ACC_GRV, _______,                      _______, U_GRV,  I_GRV,  _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  A_GRV,  _______, _______, ACC_AIG, ACC_TRE,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______,   C_CED, ACC_CIR, _______,                      _______, _______, _______, _______, _______, PIX4D,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
 )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
