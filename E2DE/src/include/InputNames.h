#ifndef E2E_INPUT_NAMES_H_
#define E2E_INPUT_NAMES_H_

#include <SDL2/SDL_keycode.h>
#include <unordered_map>
#include <string>

#include "SDL2/SDL.h"

enum InputNames {
    KEY_0 = SDLK_0,
    KEY_1 = SDLK_1,
    KEY_2 = SDLK_2,
    KEY_3 = SDLK_3,
    KEY_4 = SDLK_4,
    KEY_5 = SDLK_5,
    KEY_6 = SDLK_6,
    KEY_7 = SDLK_7,
    KEY_8 = SDLK_8,
    KEY_9 = SDLK_9,
    KEY_A = SDLK_a,
    KEY_AC_BACK = SDLK_AC_BACK, // The back key (application contol keypad)
    KEY_AC_BOOKMARKS = SDLK_AC_BOOKMARKS, // The bookmarks key (application control keypad)
    KEY_AC_FORWARD = SDLK_AC_FORWARD, // The forward key
    KEY_AC_HOME = SDLK_AC_HOME, // The Home key
    KEY_AC_REFRESH = SDLK_AC_REFRESH, // The Refresh key
    KEY_AC_SEARCH = SDLK_AC_SEARCH, // The Search ley
    KEY_AC_STOP = SDLK_AC_STOP, // The Stop key
    KEY_AGAIN = SDLK_AGAIN, // The Redo key
    KEY_ALT_ERASE = SDLK_ALTERASE,
    KEY_QUOTE = SDLK_QUOTE, // ""
    KEY_APPLICATION = SDLK_APPLICATION, // The application / windows / super key
    KEY_AUDIO_MUTE = SDLK_AUDIOMUTE,
    KEY_AUDIO_NEXT = SDLK_AUDIONEXT,
    KEY_AUDIO_PLAY = SDLK_AUDIOPLAY,
    KEY_AUDIO_PREV = SDLK_AUDIOPREV,
    KEY_AUDIO_STOP = SDLK_AUDIOSTOP,
    KEY_B = SDLK_b,
    KEY_BACKSLASH = SDLK_BACKSLASH,
    KEY_BACKSPACE = SDLK_BACKSPACE,
    KEY_BRIGHTNESS_DOWN = SDLK_BRIGHTNESSDOWN,
    KEY_BRIGHTNESS_UP = SDLK_BRIGHTNESSUP,
    KEY_C = SDLK_c,
    KEY_CALCULATOR = SDLK_CALCULATOR,
    KEY_CANCEL = SDLK_CANCEL,
    KEY_CAPSLOCK = SDLK_CAPSLOCK,
    KEY_CLEAR = SDLK_CLEAR,
    KEY_CLEAR_AGAIN = SDLK_CLEARAGAIN,
    KEY_COMMA = SDLK_COMMA,
    KEY_COMPUTER = SDLK_COMPUTER,
    KEY_COPY = SDLK_COPY,
    KEY_CRSEL = SDLK_CRSEL,
    KEY_CURRENCY_SUB_UNIT = SDLK_CURRENCYSUBUNIT,
    KEY_CURRENCY_UNIT = SDLK_CURRENCYUNIT,
    KEY_CUT = SDLK_CUT,
    KEY_D = SDLK_d
};

static std::unordered_map<std::string, int> InputNameStr = {
    {"KEY_0", KEY_0},
    {"KEY_1", KEY_1}
};

#endif