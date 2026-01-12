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

// Home row mods config
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS

// Home row mods macros
#define HRM_J SFT_T(KC_J)
#define HRM_K CTL_T(KC_K)
#define HRM_L ALT_T(KC_L)
#define HRM_SCLN GUI_T(KC_SCLN)

#define HRM_F SFT_T(KC_F)
#define HRM_D CTL_T(KC_D)
#define HRM_S ALT_T(KC_S)
#define HRM_A GUI_T(KC_A)

// Symbols layer HRM

enum custom_keycodes {
    CT_LB = SAFE_RANGE,  // Ctrl on hold, ( on tap
    CT_RB,               // Ctrl on hold, ) on tap
    CT_DLR,
    CT_CIR
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CT_LB:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case CT_RB:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
        case CT_DLR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DLR);
                return false;
            }
            break;
        case CT_CIR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_CIRC);
                return false;
            }
            break;
    }
    return true;
}

#define HRM_6 SFT_T(KC_6)
#define HRM_5 CTL_T(KC_5)
#define HRM_4 ALT_T(KC_4)
#define HRM_0 GUI_T(KC_0)

#define HRM_LB SFT_T(CT_LB)
#define HRM_RB CTL_T(CT_RB)
#define HRM_DLR ALT_T(CT_DLR)
#define HRM_CIR GUI_T(CT_CIR)

// Navigation layer HRM
#define HRM_F6 SFT_T(KC_F6)
#define HRM_F5 CTL_T(KC_F5)
#define HRM_F4 ALT_T(KC_F4)
#define HRM_NOP GUI_T(XXXXXXX)

#define HRM_LE SFT_T(KC_LEFT)
#define HRM_DO CTL_T(KC_DOWN)
#define HRM_UP ALT_T(KC_UP)
#define HRM_RI GUI_T(KC_RIGHT)

// French accents
enum unicode_names {
    E_AIGU, E_GRAVE, E_CIRC, E_TREM,
    A_GRAVE, A_CIRC, C_CEDIL, U_TREM,
    U_GRAVE, U_CIRC, I_TREM, I_CIRC, O_TREM,
    O_CIRC
    // etc.
};

// FIXME: Handle Linux
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case UC_LINX:
//             if (record->event.pressed) {
//                 set_unicode_input_mode(UNICODE_MODE_LINUX);
//             }
//             return false;
//         case UC_WINC:
//             if (record->event.pressed) {
//                 set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
//             }
//             return false;
//     }
//     return true;
// }
//
void keyboard_post_init_user(void) {
    set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);  // default
}


// FIXME: Add better comments
const uint32_t unicode_map[] PROGMEM = {
    [E_AIGU]   = 0x00E9,  // é
    [E_GRAVE]  = 0x00E8,  // è
    [E_CIRC]   = 0x00EA,  // ê
    [E_TREM]   = 0x00EB,  // ë
    [A_GRAVE]  = 0x00E0,  // à
    [A_CIRC]   = 0x00E2,  // â
    [C_CEDIL]  = 0x00E7,  // ç
    [U_TREM]  = 0x00FC,  // ç
    [U_GRAVE]  = 0x00F9,  // ç
    [U_CIRC]  = 0x00FB,  // ç
    [I_TREM]  = 0x00EF,  // ç
    [I_CIRC]  = 0x00EE,  // ç
    [O_TREM]  = 0x00F6,  // ç
    [O_CIRC]  = 0x00F4,  // ç
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,   HRM_A,   HRM_S,   HRM_D,   HRM_F,    KC_G,                         KC_H,   HRM_J,   HRM_K,   HRM_L,HRM_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT,   MO(2), MO(4)
                                      //`--------------------------'  `--------------------------'

  ),

    // Home row mods disabled
    [1] = LAYOUT_split_3x6_3(
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

    // Symbols layer
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_BSLS,    KC_7,    KC_8,    KC_9,  KC_EQL,                      KC_ASTR, KC_LCBR, KC_RCBR, KC_EXLM, KC_PERC,   KC_AT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   HRM_0,   HRM_4,   HRM_5,   HRM_6, KC_MINS,                      KC_UNDS,  HRM_LB,  HRM_RB, HRM_DLR, HRM_CIR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_DOT,    KC_1,    KC_2,    KC_3, KC_PLUS,                      KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    // Navigation layer
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, HRM_NOP,  HRM_F4,  HRM_F5,  HRM_F6, _______,                      HRM_LE,  HRM_DO,  HRM_UP,  HRM_RI,  _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    // Accents layer
    // TODO
    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      UM(E_CIRC), UM(E_GRAVE), UM(E_AIGU), UM(E_TREM), _______, _______,                      _______, UM(U_GRAVE), UM(I_CIRC), UM(O_CIRC), _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      UM(A_GRAVE), UM(A_CIRC), _______, _______, _______, _______,                      _______, UM(U_CIRC), UM(I_TREM), UM(O_TREM), _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, UM(C_CEDIL), _______, _______,                      _______, UM(U_TREM), _______, _______, _______, _______,
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
