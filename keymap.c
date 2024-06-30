#include QMK_KEYBOARD_H


// -----------------------
// Tap dance configuration
// -----------------------

enum {
    _TD_RALT
};

tap_dance_action_t tap_dance_actions[] = {
    [_TD_RALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT)
};


// ----------------------
//  Key map configuration
// ----------------------

enum layers {
    _QWERTY, // 0
    _SYMBOLS_NAVIGATION, // 1
    _MOUSE_MEDIA, // 2
};

enum custom_keycodes {
    BOOT_K1 = SAFE_RANGE,
    BOOT_K2
};

#define SH_ENT SFT_T(KC_ENT) // tap: shift, hold: enter
#define SHLEAD SFT_T(QK_LEAD) // tap: shift, hold: leader key
#define MMLEAD LT(_MOUSE_MEDIA, QK_LEAD) // tap: leader key, hold: Mouse / media layer
#define ANT_TAB S(KC_TAB) // Anti-tab
#define WRD_L LCTL(KC_LEFT) // Word left
#define WRD_R LCTL(KC_RGHT) // Word right
#define TD_ALT TD(_TD_RALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SHLEAD,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     ANT_TAB, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,          CW_TOGG, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    TD_ALT,  KC_SPC,  KC_LCTL,                   SH_ENT,  MO(1),   MMLEAD
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOLS_NAVIGATION] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_PLUS, KC_LCBR, KC_RCBR, _______,                            _______, KC_HOME, KC_UP,   KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_EQL,  KC_LPRN, KC_RPRN, KC_PGUP,                            _______, WRD_L,   KC_DOWN, WRD_R,   _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_UNDS, KC_MINS, KC_LBRC, KC_RBRC, KC_PGDN, _______,          KC_PSCR, _______, KC_LEFT, _______, KC_RGHT, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE_MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_SLEP, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, BOOT_K1,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, _______,                            _______, KC_MPRV, KC_VOLU, KC_MNXT, _______, BOOT_K2,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP,                            _______, KC_MPLY, KC_VOLD, KC_MPLY, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, KC_PGDN, _______,          _______, _______, _______, KC_MUTE, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};


// --------------------------
//  Combo configuration
// --------------------------

const uint16_t PROGMEM boot_combo[] = {BOOT_K1, BOOT_K2, COMBO_END};
combo_t key_combos[] = {
    COMBO(boot_combo, QK_BOOT)
};


// ------------------------
// Leader key configuration
// ------------------------

void leader_start_user() {
   rgblight_set_layer_state(5, true);
}

void leader_end_user() {
    if (leader_sequence_one_key(KC_1)) { tap_code16(KC_F1); }
    if (leader_sequence_one_key(KC_2)) { tap_code16(KC_F2); }
    if (leader_sequence_one_key(KC_3)) { tap_code16(KC_F3); }
    if (leader_sequence_one_key(KC_4)) { tap_code16(KC_F4); }
    if (leader_sequence_one_key(KC_5)) { tap_code16(KC_F5); }
    if (leader_sequence_one_key(KC_6)) { tap_code16(KC_F6); }
    if (leader_sequence_one_key(KC_7)) { tap_code16(KC_F7); }
    if (leader_sequence_one_key(KC_8)) { tap_code16(KC_F8); }
    if (leader_sequence_one_key(KC_9)) { tap_code16(KC_F9); }
    if (leader_sequence_one_key(KC_0)) { tap_code16(KC_F10); }
    if (leader_sequence_one_key(KC_DEL)) { tap_code16(KC_F11); }
    if (leader_sequence_one_key(KC_ESC)) { tap_code16(KC_F12); }

   //  if (leader_sequence_one_key(KC_F)) {
   //      // Leader, f => Types the below string
   //      SEND_STRING("QMK is awesome.");
   //  } else if (leader_sequence_two_keys(KC_D, KC_D)) {
   //      // Leader, d, d => Ctrl+A, Ctrl+C
   //      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
   //  } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
   //      // Leader, d, d, s => Types the below string
   //      SEND_STRING("https://start.duckduckgo.com\n");
   //  } else if (leader_sequence_two_keys(KC_A, KC_S)) {
   //      // Leader, a, s => GUI+S
   //      tap_code16(LGUI(KC_S));
   //  }

    rgblight_set_layer_state(5, false);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MMLEAD:
            if (record->tap.count && record->event.pressed) {
                leader_start();

                // ignore further processing of key
                return false;
            }
            break;
    }
    return true;
}


// --------------------------
// Caps word configuration
// --------------------------

void caps_word_set_user(bool active) {
    rgblight_set_layer_state(4, active);
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_QUOT: // Added, for colemak ' -> o transformation
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}


// --------------------------
// RGB Lighting configuration
// --------------------------

/*

LED index mapping:

           (1)               (4)               (7)                                    (  )              (  )              (  )
┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
│0       │2       │3       │5       │6       │7       │                          │        │        │        │        │        │        │
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
│8       │9       │10      │11      │12      │13      │                          │        │        │        │        │        │        │
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
│14      │15      │16      │17      │18      │19      │                          │        │        │        │        │        │        │
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
│20      │21      │22      │23      │25      │26      │29      │        │        │        │        │        │        │        │        │
└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                               │33      │32      │30      │                 │        │        │        │
                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
          (24)              (27)              (31)                                    (  )              (  )              (  )

*/

const rgblight_segment_t PROGMEM BASE_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {0, 34, HSV_BLACK}
    // right side
   //  {0, 34, HSV_BLACK}
);

const rgblight_segment_t PROGMEM QWERTY_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {1, 1, HSV_PURPLE}, // underglow
    {4, 1, HSV_PURPLE}, // underglow
    {7, 1, HSV_PURPLE}, // underglow
    {24, 1, HSV_PURPLE}, // underglow
    {27, 1, HSV_PURPLE}, // underglow
    {31, 1, HSV_PURPLE}  // underglow
    // right side
   //  {1+34, 1, HSV_PURPLE}, // underglow
   //  {4+34, 1, HSV_PURPLE}, // underglow
   //  {7+34, 1, HSV_PURPLE}, // underglow
   //  {24+34, 1, HSV_PURPLE}, // underglow
   //  {27+34, 1, HSV_PURPLE}, // underglow
   //  {31+34, 1, HSV_PURPLE}  // underglow
);

const rgblight_segment_t PROGMEM SYMBOLS_NAVIGATION_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {1, 1, HSV_RED}, // underglow
    {4, 1, HSV_RED}, // underglow
    {7, 1, HSV_RED}, // underglow
    {24, 1, HSV_RED}, // underglow
    {27, 1, HSV_RED}, // underglow
    {31, 1, HSV_RED}  // underglow
   //  // right side
   //  {1+34, 1, HSV_RED}, // underglow
   //  {4+34, 1, HSV_RED}, // underglow
   //  {7+34, 1, HSV_RED}, // underglow
   //  {24+34, 1, HSV_RED}, // underglow
   //  {27+34, 1, HSV_RED}, // underglow
   //  {31+34, 1, HSV_RED}  // underglow
);

const rgblight_segment_t PROGMEM MOUSE_MEDIA_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {1, 1, HSV_GOLD}, // underglow
    {4, 1, HSV_GOLD}, // underglow
    {7, 1, HSV_GOLD}, // underglow
    {24, 1, HSV_GOLD}, // underglow
    {27, 1, HSV_GOLD}, // underglow
    {31, 1, HSV_GOLD}  // underglow
    // right side
   //  {1+34, 1, HSV_GOLD}, // underglow
   //  {4+34, 1, HSV_GOLD}, // underglow
   //  {7+34, 1, HSV_GOLD}, // underglow
   //  {24+34, 1, HSV_GOLD}, // underglow
   //  {27+34, 1, HSV_GOLD}, // underglow
   //  {31+34, 1, HSV_GOLD}  // underglow
);

const rgblight_segment_t PROGMEM CAPS_WORD_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
   //  {0, 1, HSV_WHITE},
   //  {32, 2, HSV_GOLD},
    {31, 1, HSV_GOLD} // underglow
//    {31+34, 1, HSV_GOLD}, // underglow
//     {32+34, 2, HSV_GOLD}
);

const rgblight_segment_t PROGMEM LEADER_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    {31, 1, HSV_WHITE} // underglow
);

const rgblight_segment_t* const PROGMEM LIGHT_LAYERS[] = RGBLIGHT_LAYERS_LIST(
    BASE_LIGHT_LAYER,
    QWERTY_LIGHT_LAYER,
    SYMBOLS_NAVIGATION_LIGHT_LAYER,
    MOUSE_MEDIA_LIGHT_LAYER,
    CAPS_WORD_LIGHT_LAYER,
    LEADER_LIGHT_LAYER
);

void keyboard_post_init_user(void) {
    rgblight_layers = LIGHT_LAYERS;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, true);
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _SYMBOLS_NAVIGATION));
    rgblight_set_layer_state(3, layer_state_cmp(state, _MOUSE_MEDIA));
    rgblight_set_layer_state(4, is_caps_word_on());
    rgblight_set_layer_state(5, leader_sequence_active());
    return state;
}
