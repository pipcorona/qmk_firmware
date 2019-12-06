#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _JEDI 1
#define _NUMPAD 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  JEDI
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NUMPAD MO(_NUMPAD)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Numpad| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT) , \
   NUMPAD,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   LGUI_T(KC_SPC),  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* JEDI
 * ,-----------------------------------------------------------------------------------.
 * | 1    |   Q  |   W  |   E  |   R  |  ESC |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | 2    |   A  |   S  |   D  |   F  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | 3    |   Z  |   X  |   C  |      |   M  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |      |      |      |Lower |    Space    |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_JEDI] = LAYOUT_ortho_4x12( \
   KC_1,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_ESC,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX, \
   KC_2,     KC_A,    KC_S,    KC_D,    KC_F,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX, \
   KC_3,     KC_Z,    KC_X,    KC_C,    XXXXXXX, KC_M,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX, \
   KC_LSFT,  XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   KC_SPC,     XXXXXXX,    RAISE,      XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX  \
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   9  |   8  |   7  | Del  | Bksp |   7  |   8  |   9  |   /  |   =  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   6  |   5  |   4  | Down |  Up  |   4  |   5  |   6  |   *  |  Tab |  Up  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Nmlock|   3  |   2  |   1  | Left |Right |   1  |   2  |   3  |   -  |Enter | Down |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Numpad|   M  |   .  |   0  |Enter |Space |   0  |   0  |   .  |   +  | Left |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12( \
   KC_ESC,  KC_P9,  KC_P8,    KC_P7,    KC_DEL,    KC_BSPC,   KC_P7,    KC_P8,    KC_P9,    KC_PSLS,  KC_PEQL,   KC_BSPC, \
   KC_TAB,  KC_P6,  KC_P5,    KC_P4,    KC_DOWN,   KC_UP,     KC_P4,    KC_P5,    KC_P6,    KC_PAST,  KC_TAB,    KC_UP, \
   KC_NLCK, KC_P3,  KC_P2,    KC_P1,    KC_LEFT,   KC_RIGHT,  KC_P1,    KC_P2,    KC_P3,    KC_PMNS,  KC_PENT,   KC_DOWN , \
   _______, KC_M,   KC_PDOT,  KC_P0,    KC_PENT,   KC_SPC,    KC_P0,    KC_P0,    KC_PDOT,  KC_PPLS,  KC_LEFT,   KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Mute | Play | Play |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MUTE, KC_MPLY, KC_MPLY, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Mute | Play | Play |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MUTE, KC_MPLY, KC_MPLY, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty| Jedi |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  JEDI,    _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case JEDI:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_JEDI);
      }
      return false;
  }
  return true;
}
