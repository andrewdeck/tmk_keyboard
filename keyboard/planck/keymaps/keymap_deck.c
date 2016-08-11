
#include "planck.h"
#include "backlight.h"

#define QWERTY 0
// #define GAMING 1
// #define GAMING_NUMBERS 2
#define MODIFIER 3
#define FUNCTION 4
#define TENKEY 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = { /* Qwerty */
  {KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,    KC_Y,    KC_U,         KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,         KC_G,    KC_H,    KC_J,         KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,    KC_N,    KC_M,         KC_COMM, KC_DOT,  KC_SLSH, KC_ENT},
  {KC_DELETE, KC_LCTL, KC_LALT, KC_LGUI, MO(MODIFIER), KC_SPC,  KC_SPC,  MO(FUNCTION), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[MODIFIER] = { /* Modifiers */
  {KC_TRNS,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     KC_7,    KC_8,     KC_9,    KC_0,    KC_TRNS},
  {KC_GRV,    KC_EXLM, KC_AT,   KC_MINS, KC_PLUS, KC_UNDS,  KC_EQL,   KC_LPRN, KC_RPRN,  KC_LCBR, KC_RCBR, KC_PIPE},
  {KC_TILD,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LBRC, KC_RBRC,  KC_TRNS, KC_TRNS, KC_BSLS},
  {KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS}
},
[FUNCTION] = { /* Functions */
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS},
  {RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F14,  KC_F15,  BL_DEC,  BL_INC}
},
[TENKEY] = { /* TENKEY */
  {KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_KP_7,    KC_KP_8,  KC_KP_9,  KC_P,    KC_BSPC},
  {KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_KP_4,    KC_KP_5,  KC_KP_6,  KC_SCLN, KC_QUOT},
  {KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_KP_1,    KC_KP_2,  KC_KP_3,  KC_SLSH, KC_ENT},
  {KC_DELETE, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_SPC,  KC_SPC,  KC_KP_0,    KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) 
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:   
        if (record->event.pressed) {
          register_code(KC_RSFT);
          backlight_step();
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      } 
    return MACRO_NONE;
};
