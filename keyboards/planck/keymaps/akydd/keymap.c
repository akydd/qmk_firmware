#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  COLEMAK_DH,
  SYM,
  NUM,
  NAV,
//  ADJUST
};

//enum planck_keycodes {
//  BACKLIT,
//  EXT_PLV
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ColemakDH
 * ,---------------------------------------------------------------------------------------------------------------------------------------.
 * |   Q         |   W       |   F       |  P         |   B      |          |      |   J       |   L  |   U       |   Y       |      '     |
 * |-------------+-----------+-----------+------------+----------+----------+------+-----------+------+-----------+-----------+------------|
 * |   LCtrl/A   |   LAlt/R  |   LCmd/S  |  T         |   G      |          |      |   M       |   N  |   RCmd/E  |   RAlt/I  |   RCtrl/O  |
 * |-------------+-----------+-----------+------------+----------+----------+------+-----------+------+-----------+-----------+------------|
 * |   LShift/Z  |   X       |   C       |  D         |   V      |          |      |   K       |   H  |    ,      |   .       |   RShift// |
 * |-------------+-----------+-----------+------------+----------+----------+------+-----------+------+-----------+-----------+------------|
 * |             |           |           |    Num/Esc |  Spc     | Nav/Tab  | Enter|  Bksp     | Sym  |           |           |            |
 * `---------------------------------------------------------------------------------------------------------------------------------------'
 */
[COLEMAK_DH] = LAYOUT_planck_grid(
    KC_Q,         KC_W,         KC_F,         KC_P,            KC_B,   _______,         _______, KC_J,    KC_L,     KC_U,         KC_Y,         KC_QUOTE,
    LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), KC_T,            KC_G,   _______,         _______, KC_M,    KC_N,     RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O),
    LSFT_T(KC_Z), KC_X,         KC_C,         KC_D,            KC_V,   _______,         _______, KC_K,    KC_H,     KC_COMMA,     KC_DOT,       RSFT_T(KC_SLSH),
    _______,      _______,      _______,      LT(NUM, KC_ESC), KC_SPC, LT(NAV, KC_TAB), KC_ENT,  KC_BSPC, OSL(SYM), _______,      _______,      _______
),

/* Symbols - green
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   +  |   [  |      |      |      |      |   ]  |   |  |   %  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   :  |   {  |   (  |   0  |      |      |   1  |   )  |   }  |   =  |   &  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   $  |   ^  |   _  |   *  |      |      |      |      |   -  |   \  |   ~  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[SYM] = LAYOUT_planck_grid(

    KC_EXLM,  KC_AT,      KC_PLUS,    KC_LBRC,           _______,   _______,    _______,    _______,   KC_RBRC,   KC_PIPE,   KC_PERC,     KC_SCLN,
    KC_GRV,   KC_COLN,    KC_LCBR,    KC_LPRN,           KC_0,      _______,    _______,    KC_1,      KC_RPRN,   KC_RCBR,   KC_PEQL,     KC_AMPR,
    KC_DLR,   KC_CIRC,    KC_UNDS,    KC_ASTR,           _______,   _______,    _______,    _______,   KC_MINS,   KC_BSLS,   KC_TILDE,    KC_HASH,
    _______,  _______,    _______,    TO(COLEMAK_DH),    _______,   TO(NUM),    _______,    _______,   TO(NAV),   _______,   _______,     _______
),
/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F2  |  F2  |  F5  |      |      |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  1   |   2  |   3  |   4  |  F6  |      |      |  F7  |   7  |   8  |   9  |  0   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   5  |      |      |      |      |   6  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[NUM] = LAYOUT_planck_grid(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,            KC_F5,      _______,    _______,    KC_F8,      KC_F9,     KC_F10,   KC_F11,   KC_F12,
    KC_1,     KC_2,     KC_3,     KC_4,             KC_F6,      _______,    _______,    KC_F7,      KC_7,      KC_8,     KC_9,     KC_0,
    _______,  _______,  _______,  KC_5,             _______,    _______,    _______,    _______,    KC_6,      _______,  _______,  _______,
    _______,  _______,  _______,  TO(COLEMAK_DH),   _______,    _______,    _______,    _______,    OSL(SYM),  _______,  _______,  _______
),

[NAV] = LAYOUT_planck_grid(
    _______,  KC_WH_U,    KC_WH_D,    _______,           _______,       _______,    _______,    _______,    KC_MPLY,       KC_VOLD,   KC_VOLU,       KC_SLEP,
    KC_MS_L,  KC_MS_U,    KC_MS_D,    KC_MS_R,           _______,       _______,    _______,    _______,    KC_LEFT,       KC_DOWN,   KC_UP,         KC_RIGHT,
    _______,  _______,    _______,    _______,           _______,       _______,    _______,    _______,    LGUI(KC_LEFT), _______,   _______,       LGUI(KC_RIGHT),
    _______,  _______,    _______,    TO(COLEMAK_DH),    KC_MS_BTN1,    KC_MS_BTN2, _______,    _______,    KC_ESC,        _______,   _______,       _______
),

/* Adjust
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
*/

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
*/

/*
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;
*/

/*
void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}
*/

/*
void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}
*/

  /*
void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}
*/

/*
bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case NUM:
    case SYM:
    case NAV:
      return false;
    default:
      return true;
  }
}
*/


  uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LALT_T(KC_R):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LGUI_T(KC_S):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RCTL_T(KC_O):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RALT_T(KC_I):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RGUI_T(KC_E):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
};

const rgblight_segment_t PROGMEM my_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_YELLOW}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_sym_layer,
    my_num_layer,
    my_nav_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    // Change underglow
    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(HSV_TRON);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
};

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, SYM));
    rgblight_set_layer_state(1, layer_state_cmp(state, NUM));
    rgblight_set_layer_state(2, layer_state_cmp(state, NAV));
    return state;
}
