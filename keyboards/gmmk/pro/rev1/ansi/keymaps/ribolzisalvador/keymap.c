#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/mouse_turbo_click.h"

// Layers
enum custom_layers {
    _QWERTY = 0,
    _CMAKDH,
    _FN,
    _EXTRAS,
    _NUMPAD
};

// Custom Keycodes
enum custom_keycodes {
    FN_CT = SAFE_RANGE,
    FN_CST,
    FN_LLOCK,
    FN_TURBO_MOUSE
};

// Custom  Overrides
/* cons key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC,KC_DEL);

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL
}; */

// Tap Dance
// enum td_keycodes {
//     TD_SHIFT_CAPS
// };

// typedef enum {
//     TD_NONE,
//     TD_UNKNOWN,
//     TD_SINGLE_TAP,
//     TD_SINGLE_HOLD,
//     TD_DOUBLE_SINGLE_TAP
// } td_state_t;

// static td_state_t td_state;
// td_state_t cur_dance(qk_tap_dance_state_t *state);
// td_state_t cur_dance_hold(qk_tap_dance_state_t *state);

// void shiftcaps_finished(qk_tap_dance_state_t *state, void *user_data);
// void shiftcaps_reset(qk_tap_dance_state_t *state, void *user_data);

// qk_tap_dance_action_t tap_dance_actions[] = {
//     [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shiftcaps_finished, shiftcaps_reset)
// };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt               Rotary
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, KC_UP,   KC_END,
        MO(_EXTRAS), KC_LGUI, KC_LALT,                            KC_SPC,                         KC_LEAD, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_CMAKDH] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT, KC_X,    KC_C,    KC_V,    KC_B,    KC_Z,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, KC_UP,   KC_END,
        MO(_EXTRAS), KC_LGUI, KC_LALT,                            KC_SPC,                         KC_LEAD, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, DF(_QWERTY), DF(_CMAKDH), RESET,   _______,
        _______, _______, RGB_VAD, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,          FN_TURBO_MOUSE,   _______,
      CAPS_WORD, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,                   KC_CAPS, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [_EXTRAS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           _______,
    MO(_NUMPAD), _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_ENT,  _______, _______, _______,          _______,
        _______, _______, _______, FN_CST, FN_CT,    _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______, KC_DEL,                    _______, _______, _______,
        _______, _______, _______,                            _______,                           FN_LLOCK, _______, _______, _______, _______, _______
    ),

    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, KC_PMNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, KC_PPLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PSLS, _______, KC_PENT,                   _______,
        _______, _______, _______, _______, _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, _______,                   _______, _______, _______,
        _______, _______, _______,                            _______,                           FN_LLOCK, _______, _______, _______, _______, _______
    ),
};
// clang-format on



// td_state_t cur_dance_hold(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (!state->pressed) return TD_SINGLE_TAP;
//         else return TD_SINGLE_HOLD;
//     }

//     if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
//     else return TD_UNKNOWN;
// }

// td_state_t cur_dance(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         else return TD_SINGLE_HOLD;
//     }

//     if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
//     else return TD_UNKNOWN;
// }

// Handle the possible states for each tapdance keycode you define:
// void shiftcaps_finished(qk_tap_dance_state_t *state, void *user_data) {
//     td_state = cur_dance(state);
//     switch (td_state) {
//         case TD_SINGLE_TAP:
//             register_mods(MOD_BIT(KC_LSHIFT));
//             break;
//         case TD_SINGLE_HOLD:
//             register_mods(MOD_BIT(KC_LSHIFT));
//             break;
//         case TD_DOUBLE_SINGLE_TAP:
//             register_code16(KC_CAPS);
//             break;
//         default:
//             break;
//     }
// }
// void shiftcaps_reset(qk_tap_dance_state_t *state, void *user_data) {
//     td_state = cur_dance(state);
//     switch (td_state) {
//         case TD_SINGLE_TAP:
//             break;
//         case TD_SINGLE_HOLD:
//             unregister_mods(MOD_BIT(KC_LSHIFT));
//             break;
//         case TD_DOUBLE_SINGLE_TAP:
//             unregister_code16(KC_CAPS);
//             break;
//         default:
//             break;
//     }
// }


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_CMAKDH] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN]     = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [_EXTRAS] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [_NUMPAD] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) }
};
#endif

// // Handle the rotary encoder functions:
// #ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     uint8_t temp_mod = get_mods();
//     uint8_t temp_osm = get_oneshot_mods();
//     bool    is_ctrl  = (temp_mod | temp_osm) & MOD_MASK_CTRL;

//     if (is_ctrl) {
//         if (index == 0) {
//             clear_mods();
//             if (clockwise) {
//                 tap_code16(C(S(KC_Z)));
//             } else {
//                 tap_code16(C(KC_Z));
//             }
//             set_mods(temp_mod);
//         }
//     }

//     else if (biton32(layer_state) == _EXTRAS) {
//         if (index == 0) {
//             if (clockwise) {
//                 rgblight_increase_hue();
//             } else {
//                 rgblight_decrease_hue();
//             }
//         }
//     }
//     else {
//         if (index == 0) {
//             if (clockwise) {
//                 tap_code(KC_VOLU);
//             } else {
//                 tap_code(KC_VOLD);
//             }
//         }
//     }
//     return true;
// }
// #endif // ENCODER_ENABLE

// uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, FN_LLOCK)) { return false; }
    if (!process_mouse_turbo_click(keycode, record, FN_TURBO_MOUSE)) { return false; }

    // mod_state = get_mods();
    switch (keycode) {
        case FN_CT:
            if (record->event.pressed) {
                tap_code16(C(KC_TAB));
            }
           break;
        case FN_CST:
            if (record->event.pressed) {
                tap_code16(C(S(KC_TAB)));
            }
            break;
    }
    return true;
};
