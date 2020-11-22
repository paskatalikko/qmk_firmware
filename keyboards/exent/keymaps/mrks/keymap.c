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
        // when keycode QMKURL is pressed
        SEND_STRING("&opt&IBM&WebSphere&AppServer&profiles&ECOM&bin&stopServer.sh server1 "SS_LSFT("6")SS_LSFT("6")" &opt&IBM&WebSphere&AppServer&profiles&ECOM&bin&startServer.sh server1");
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0: qwerty */
    [_QWERTY] = LAYOUT_65_iso(
        KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_PGUP,
        MO(_FN), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LALT,                KC_SPC,                         KC_RALT, KC_RGUI, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT), 

    [_FUNCTION] = LAYOUT_65_iso(
        KC_GRV,  KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_TRNS,
        MO(_CN), SYSTEMOUT,  KC_TRNS, KC_TRNS, RESTARTSERVER1, KC_TRNS, KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN,  KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,    SOLRLOG, REXPATH, KC_TRNS,        KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_END,  KC_TRNS, KC_INS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS,                          KC_TRNS,                               KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS), 

    [_CONTROL] = LAYOUT_65_iso(
        KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG,
        KC_TRNS, KC_NO,    KC_NO,   KC_NO,   RESET,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,    KC_NO,            KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO), 
    };