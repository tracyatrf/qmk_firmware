#include QMK_KEYBOARD_H
#include "version.h"

enum {
    WORKMAN = 0,
    SYM,
    // ..., the rest of your layers
};

#define FULL_S LCTL(LCMD(KC_F))
#define N_TAB LCTL(KC_TAB)
#define P_TAB LCTL(LSFT(KC_TAB))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Workman layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   D  |   R  |   W  |   B  |      |           |      |   J  |   F  |   U  |   P  |   ;  |   BSP  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTL   |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   '    |
 * |--------+------+------+------+------+------| P_TAB|           |N_TAB |------+------+------+------+------+--------|
 * | LCMD   |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   /  |  shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LALT |      |(~MED)|      |      |                                       |      | Left | Down | Up   | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |FULL_S|      |      |      |      |
 *                                 | Space|Shift |------|       |------| ~SYM |Enter |
 *                                 |      |      | BKS  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[WORKMAN] = LAYOUT_ergodox(
  // left hand
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_TAB,          KC_Q,        KC_D,          KC_R,    KC_W,    KC_B,    XXXXXXX,
  KC_LCTL,         KC_A,        KC_S,          KC_H,    KC_T,    KC_G,
  KC_LCMD,         KC_Z,        KC_X,          KC_M,    KC_C,    KC_V,    P_TAB,
  KC_LALT,         KC_HYPR,    XXXXXXX,       XXXXXXX, XXXXXXX,
                                                                XXXXXXX,  XXXXXXX,
                                                                          FULL_S,
                                                         KC_SPC, KC_LSFT, KC_BSPC,
  // right hand
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  XXXXXXX,      KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,  KC_BSPC,
                KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,     KC_QUOT,
  N_TAB,      KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
  XXXXXXX,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  KC_TAB, MO(SYM), KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    ?    |   !  |   @  |   {  |   }  |   |  |      |           |      |   +  |   7  |   8  |   9  |   *  |   \    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    &    |   #  |   $  |   (  |   )  |   `  |------|           |------|   :  |   4  |   5  |   6  |   =  |   "    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   -  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RESET |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   _  | ESC  |------|       |------| LAYER| CAPS |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYM] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  S(KC_SLASH), KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_AMPR,     KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_TRNS,     KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
  RESET,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                   S(KC_MINUS), KC_ESC, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_BSPC,
           KC_COLON,KC_4,    KC_5,    KC_6,    KC_EQUAL, S(KC_QUOTE),
  KC_TRNS, KC_MINUS,KC_1,    KC_2,    KC_3,    KC_BSLASH, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_CAPS
)
};
