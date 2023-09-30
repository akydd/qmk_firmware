#include QMK_KEYBOARD_H

enum ferris_layers {
  COLEMAK_DH,
  SYM,
  NUM,
  NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[COLEMAK_DH] = LAYOUT_split_3x5_2(
        KC_Q, KC_W,         KC_F,         KC_P,            KC_B,            KC_J,    KC_L,         KC_U,         KC_Y,         KC_QUOTE,
        KC_A, LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    KC_G,            KC_M,    RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), KC_O,
        KC_Z, KC_X,         KC_C,         LGUI_T(KC_D),    KC_V,            KC_K,    RGUI_T(KC_H), KC_COMMA,     KC_DOT,       KC_SLSH,
                                          LT(NUM, KC_SPC), LT(NAV, KC_TAB), KC_BSPC, OSL(SYM)
    ),

	[SYM] = LAYOUT_split_3x5_2(
        KC_EXLM,  KC_AT,      KC_PLUS,    KC_LBRC,   _______,   _______,   KC_RBRC,   KC_PIPE,   KC_PERC,     KC_SCLN,
        KC_GRV,   KC_COLN,    KC_LCBR,    KC_LPRN,   KC_0,      KC_1,      KC_RPRN,   KC_RCBR,   KC_PEQL,     KC_AMPR,
        KC_DLR,   KC_CIRC,    KC_UNDS,    KC_ASTR,   _______,   _______,   KC_MINS,   KC_BSLS,   KC_TILDE,    KC_HASH,
                                          KC_ESC,    KC_ENT,    _______,   TO(NAV)
    ),

    [NUM] = LAYOUT_split_3x5_2(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,      KC_F8,      KC_F9,     KC_F10,   KC_F11,   KC_F12,
        KC_1,     KC_2,     KC_3,     KC_4,      KC_F6,      KC_F7,      KC_7,      KC_8,     KC_9,     KC_0,
        _______,  _______,  _______,  KC_5,      _______,    _______,    KC_6,      _______,  _______,  _______,
                                      _______,   _______,    _______,    OSL(SYM)
    ),

	[NAV] = LAYOUT_split_3x5_2(
        _______,  KC_WH_U,    KC_WH_D,    _______,           _______,       KC_PGDN,    KC_MPLY,             KC_VOLD,         KC_VOLU,       KC_SLEP,
        KC_MS_L,  KC_MS_U,    KC_MS_D,    KC_MS_R,           _______,       _______,    KC_LEFT,             KC_DOWN,         KC_UP,         KC_RIGHT,
        _______,  _______,    _______,    _______,           _______,       KC_PGUP,    LCTL(LALT(KC_LEFT)), LCTL(KC_DOWN),   LCTL(KC_UP),   LCTL(LALT(KC_RIGHT)),
                                          TO(COLEMAK_DH),    KC_MS_BTN1,    KC_MS_BTN2, KC_ESC
    ),
};

// combos
const uint16_t PROGMEM test_combo1[] = {LT(NAV, KC_TAB), KC_BSPC, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, KC_ENT),
};
