#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_numpad_6x4(KC_ESC, KC_TAB, KC_BSPC, MO(1), KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, KC_P7, KC_P8, KC_P9, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_P1, KC_P2, KC_P3, KC_P0, KC_PDOT, KC_PENT),
	[1] = LAYOUT_numpad_6x4(RGB_SAI, RGB_VAI, RGB_HUI, KC_TRNS, RGB_SAD, RGB_VAD, RGB_HUD, KC_NO, KC_NO, KC_NO, KC_NO, RGB_M_SW, RGB_M_G, RGB_M_K, KC_NO, RGB_M_P, RGB_M_B, RGB_M_R, KC_NO, KC_NO, RGB_TOG)
};
