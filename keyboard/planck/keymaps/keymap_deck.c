#include "keymap_common.h"
#include "backlight.h"
#include "debug.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = { /* Qwerty */
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT},
  {M(0),    KC_LCTL, KC_LALT, KC_LGUI, FUNC(1), KC_SPC,  KC_SPC,  FUNC(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[1] = { /* Modifiers */
  {KC_GRV,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_MINS,    S(KC_EQL), KC_LBRC,    KC_RBRC,  KC_BSLS},
  {S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),  S(KC_6),  S(KC_7),    S(KC_8),   S(KC_9),    S(KC_0), S(KC_BSLS)},
  {KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, FUNC(3), KC_TRNS,  KC_TRNS,  S(KC_MINS), KC_EQL,    S(KC_LBRC), S(KC_RBRC), KC_TRNS},
  {KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  FUNC(2),    KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS}
},
[2] = { /* Functions */
  {KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,  KC_MPRV,  KC_MNXT,  KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_VOLD,   KC_VOLU,   KC_MUTE,   KC_F10,  KC_TRNS},
  {RESET, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(1),   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_MPLY}
},
[3] = { /* TENKEY */
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_P,   KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_SCLN,  KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_KP_1,    KC_KP_2,    KC_KP_3,  KC_SLSH, KC_ENT},
  {KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,    KC_SPC,   KC_SPC, KC_KP_0,   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT}
}
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(2),  // to RAISE
    [2] = ACTION_LAYER_MOMENTARY(3),  // to LOWER

    [3] = ACTION_DEFAULT_LAYER_SET(0), 
    [4] = ACTION_DEFAULT_LAYER_SET(1),

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
