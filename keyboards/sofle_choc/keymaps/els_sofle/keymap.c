/* Copyright 2023 Brian Low
 *
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

// // Define the Tap Dance ID
// enum {
//     TD_EQL_LAYER1 = 0
// };

// // Tap Dance Logic: 1 tap = '=', Hold = Layer 1, 3 taps = Toggle Layer 1
// // 2. Tap Dance Logic (Wrapped in IFDEF to prevent type errors)
// #ifdef TAP_DANCE_ENABLE
// void td_eql_layer1_finished(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         if (state->pressed) {
//             layer_on(1); // HOLD: Activate Layer 1
//         } else {
//             register_code(KC_EQL); // TAP: Send =
//             unregister_code(KC_EQL);
//         }
//     } else if (state->count >= 3) {
//         layer_invert(1); // TRIPLE TAP: Toggle Layer 1
//     }
// }

// void td_eql_layer1_reset(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1 && state->pressed) {
//         layer_off(1); // Release Layer 1 when the hold is released
//     }
// }

// // Associate the logic with the TD() code
// tap_dance_action_t tap_dance_actions[] = {
//     [TD_EQL_LAYER1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_eql_layer1_finished, td_eql_layer1_reset)
// };
// #endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LCMD | LALT | /Enter  /       \Space \  | RALT | RCMD | RGUI | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NUBS,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                 KC_LALT, KC_LGUI, KC_LCTL, KC_BSPC, KC_SPC,           KC_ENT,  TT(1), KC_CAPS, KC_LEFT, KC_RGHT
    ),

    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
        KC_TAB,  KC_MPRV, KC_MPLY, KC_MNXT, KC_BRIU, KC_BRID,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_BSLS,
        KC_LSFT, KC_EQL,  KC_TRNS, KC_PLUS, KC_LCBR, KC_RCBR, KC_MUTE,   KC_MPLY,   KC_HOME, KC_END,  KC_SCLN, KC_LBRC, KC_RBRC, KC_MINS,
                 KC_LALT, KC_LGUI, KC_LCTL, KC_BSPC, KC_SPC,           KC_ENT,  TO(0),   KC_TRNS, KC_DOWN, KC_UP
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(LCTL(KC_TAB), LCTL(S(KC_TAB))) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif
