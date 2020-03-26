#include QMK_KEYBOARD_H
#include "version.h"

enum {
    WORKMAN = 0,
    SYM,
    NAV,
    // ..., the rest of your layers
};

#define FULL_S LCMD(KC_ENT)
#define N_TAB LCTL(KC_TAB)
#define P_TAB LCTL(LSFT(KC_TAB))
#define WIN_L LCMD(KC_LEFT)
#define WIN_R LCMD(KC_RIGHT)
#define SPOTL LCMD(LALT(KC_SPC))

#define TABNEW LCMD(KC_T)
#define TABCLOSE LCMD(KC_W)

#define SPLIT_V LCMD(KC_D)
#define SPLIT_H LCMD(LSFT(KC_D))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Workman layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | WIN_L|           |WIN_R |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   D  |   R  |   W  |   B  | ~NAV2|           |N_TAB |   J  |   F  |   U  |   P  |   ;  |   BSP  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTL   |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   '    |
 * |--------+------+------+------+------+------| ~NAV |           |P_TAB |------+------+------+------+------+--------|
 * | LCMD   |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   /  |  shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LALT |      |      |      |      |                                       |      | Left | Down | Up   | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |zoom- |zoom+ |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |FULL_S|       | SPOTL|      |      |
 *                                 | Space|Shift |------|       |------| ~SYM |Enter |
 *                                 |      |      | BKS  |       | TAB  |      |      |
 *                                 `--------------------'       `--------------------'
 */

[WORKMAN] = LAYOUT_ergodox(
  // left hand
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, WIN_L,
  KC_TAB,          KC_Q,        KC_D,          KC_R,    KC_W,    KC_B,    LCMD(KC_LALT),
  KC_LCTL,         KC_A,        KC_S,          KC_H,    KC_T,    KC_G,
  KC_LCMD,         KC_Z,        KC_X,          KC_M,    KC_C,    KC_V,    MO(NAV),
  KC_LALT,         KC_HYPR,    XXXXXXX,       XXXXXXX, XXXXXXX,
                                                   LGUI(KC_MINUS),  LGUI(KC_PLUS),
                                                                          FULL_S,
                                                         KC_SPC, KC_LSFT, KC_BSPC,
  // right hand
  WIN_R,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  N_TAB,      KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,  KC_BSPC,
              KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,     KC_QUOT,
  P_TAB,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
  XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
  XXXXXXX, XXXXXXX,
  SPOTL,
  KC_TAB, MO(SYM), KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |   <  |   >  |      |      |           |      |      |      |      |      |      |        |
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
  S(KC_SLASH), KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, SPLIT_V,
  KC_AMPR,     KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_TRNS,     KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, SPLIT_H,
  RESET,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                   S(KC_MINUS), KC_ESC, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F10, KC_TRNS,
  TABCLOSE,KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_BSPC,
           KC_COLON,KC_4,    KC_5,    KC_6,    KC_EQUAL, S(KC_QUOTE),
  TABNEW,  KC_MINUS,KC_1,    KC_2,    KC_3,    KC_BSLASH, KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_CAPS
),

/* Keymap 2: Navigation Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------| Left | Right|  Up  | Down |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
           KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS,     KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
)
};
