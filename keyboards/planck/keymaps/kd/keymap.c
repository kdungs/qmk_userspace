// QMK keymap for Drop x Planck
//
// Author: kdungs
// Date: 2021-10-24
//
// The idea of this keymap is to re-use muscle memory as much as possible and
// have an easy to remember layout on top of that.
//
// I'm using KC_TRNS (_______) instead of KC_NO throughout because sometimes I
// keep my fingers on a modifier key for too long.

/**
 * TODO:
 *  - LED and sound settings on dedicated layer with meaningful layout
 *  - Media keys
 *  - Maybe also add mouse support?
 *  - Use `users` directory instead for multiple keyboards that share code https://beta.docs.qmk.fm/using-qmk/software-features/feature_userspace
 *
 *  KC_F13-24 also exist but are not supported by every OS
 *  KC_PWR, KC_SLEP, KC_WAKE for power control
 *  KC_MNXT, KC_MPRV, KC_MSTP, KC_MPLY for media controls (+KC_MFFD, KC_MRWD, KC_MSEL, KC_EJCT)
 *  KC_BRIU, KC_BRID for brightness controls
 */

#include QMK_KEYBOARD_H

enum _Layers {
  _BASE,
  _LOWER,
  _RAISE,
  _FN,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_1x2uC(
    KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D, KC_F,  KC_G,   KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_DEL,
    KC_LCTL, KC_LALT, KC_LGUI, FN,   LOWER,    KC_SPC,     RAISE, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
  ),
  [_LOWER] = LAYOUT_planck_1x2uC(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,   _______, _______, _______, _______,      _______,     _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),
  [_RAISE] = LAYOUT_planck_1x2uC(
    _______, KC_TILD, KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_DQUO, KC_PIPE,
    _______, KC_GRV,  KC_MINS, KC_LPRN, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_RPRN, KC_EQL,  KC_QUOT, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
  ),
  [_FN] = LAYOUT_planck_1x2uC(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,     _______, _______, KC_VOLD, KC_VOLU, KC_MUTE
  ),
  [_ADJUST] = LAYOUT_planck_1x2uC(
    RESET,   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,
    RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______,
    _______, _______,  _______, _______, _______,     _______,      _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
