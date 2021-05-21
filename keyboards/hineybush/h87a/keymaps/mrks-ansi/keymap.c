/* Copyright 2018 Josh Hinnebusch

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// LAYERS
#define _QWERTY 0      // QWERTY layer
#define _QW _QWERTY

#define _FUNCTION 1    // Function layer
#define _FN _FUNCTION

#define _CONTROL 2     // Control layer
#define _CN _CONTROL

enum custom_keycodes {
  SYSTEMOUT = SAFE_RANGE,
  SOLRLOG,
  RESTARTSERVER1,
  REXPATH
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYSTEMOUT:
      // when keycode SYSTEMOUT is pressed
      // SystemOut.log location under ECOM profile
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("7")"opt"SS_LSFT("7")"IBM"SS_LSFT("7")"WebSphere"SS_LSFT("7")"AppServer"SS_LSFT("7")"profiles"SS_LSFT("7")"ECOM"SS_LSFT("7")"logs"SS_LSFT("7")"server1"SS_LSFT("7")"SystemOut.log");
      }
      break;
    case SOLRLOG:
      // when keycode SOLRLOG is pressed
      // Path to SOLR logs
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("7")"opt"SS_LSFT("7")"IBM"SS_LSFT("7")"WebSphere"SS_LSFT("7")"CommerceServer"SS_LSFT("7")"logs"SS_LSFT("7"));
      }
      break;
    case REXPATH:
      // when keycode SYSTEMOUT is pressed
      // REX dataload path
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("7")"opt"SS_LSFT("7")"dataload"SS_LSFT("7")"rex"SS_LSFT("7"));
      }
      break;
    case RESTARTSERVER1:
      // when keycode RESTARTSERVER1 is pressed
      // restarts the server1 under ECOM profile
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING("&opt&IBM&WebSphere&AppServer&profiles&ECOM&bin&stopServer.sh server1 "SS_LSFT("6")SS_LSFT("6")" &opt&IBM&WebSphere&AppServer&profiles&ECOM&bin&startServer.sh server1");
      } else {
        // when keycode is released
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_tkl_ansi_wkl(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,     KC_F11,     KC_F12,       KC_PSCR, KC_SLCK, KC_PAUS,
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,     KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,      KC_DEL,  KC_END,  KC_PGDN,
    MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,                KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,                                       KC_UP,
    KC_LCTL, KC_LALT,                   KC_SPC,                                      KC_RALT,           KC_RGUI,                              KC_LEFT, KC_DOWN, KC_RGHT),

  [_FUNCTION] = LAYOUT_tkl_ansi_wkl(
    XXXXXXX, KC_F1,     KC_F2,   KC_F3,   KC_F4,          KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GRV,  KC_F1,     KC_F2,   KC_F3,   KC_F4,          KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,    XXXXXXX, XXXXXXX, KC_VOLU,
    MO(_CN), SYSTEMOUT, XXXXXXX, XXXXXXX, RESTARTSERVER1, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN,  KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MPLY, KC_MNXT, KC_VOLD,
    _______, XXXXXXX,   SOLRLOG, REXPATH, XXXXXXX,        XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, KC_END,  XXXXXXX, KC_INS,  XXXXXXX,  XXXXXXX, KC_RSFT,                              XXXXXXX, 
    XXXXXXX, XXXXXXX,                     XXXXXXX,                                   XXXXXXX,           XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX ),

  [_CONTROL] = LAYOUT_tkl_ansi_wkl(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD,  RGB_SAI, RGB_VAD, RGB_VAI,                     KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,             XXXXXXX, XXXXXXX, KC_VOLU,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN,  KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,            KC_MPLY, KC_MNXT, KC_VOLD,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  XXXXXXX, KC_INS,  XXXXXXX,  XXXXXXX, KC_RSFT,                              XXXXXXX,
    XXXXXXX,          XXXXXXX,                            XXXXXXX,                                      XXXXXXX,          XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX ),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}
