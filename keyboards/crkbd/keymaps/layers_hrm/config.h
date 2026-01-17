/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

#define SPLIT_USB_DETECT

// Home row mods macros
#define HRM_J SFT_T(KC_J)
#define HRM_K CTL_T(KC_K)
#define HRM_L ALT_T(KC_L)
#define HRM_SCLN GUI_T(KC_SCLN)

#define HRM_F SFT_T(KC_F)
#define HRM_D CTL_T(KC_D)
#define HRM_S ALT_T(KC_S)
#define HRM_A GUI_T(KC_A)

// Symbols layer: Left half only
#define HRM_6 SFT_T(KC_6)
#define HRM_5 CTL_T(KC_5)
#define HRM_4 ALT_T(KC_4)
#define HRM_0 GUI_T(KC_0)

// Navigation layer HRM
#define HRM_F6 SFT_T(KC_F6)
#define HRM_F5 CTL_T(KC_F5)
#define HRM_F4 ALT_T(KC_F4)
// GUI is unbound -> Use regular GUI

#define HRM_LE SFT_T(KC_LEFT)
#define HRM_DO CTL_T(KC_DOWN)
#define HRM_UP ALT_T(KC_UP)
#define HRM_RI GUI_T(KC_RIGHT)


// Home row mods config
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

#define QUICK_TAP_TERM_PER_KEY
#define QUICK_TAP_TERM 120

// RGB
#define RGB_MATRIX_DEFAULT_ON false

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
