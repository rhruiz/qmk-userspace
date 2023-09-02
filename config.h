#pragma once

#ifndef __ASSEMBLER__
#    include "layouts/wrappers.h"
#    include "layouts/base.h"
#    include "layouts/keys.h"
#endif

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define BASE_LAYERS _QWER, _CODH

#define BLINK_LED_PIN B0

#ifdef SPLIT_KEYBOARD
#    define SPLIT_TRANSACTION_IDS_USER USER_SYNC_RUNTIME_STATE, USER_SYNC_BLINK_LED
#    define SPLIT_LAYER_STATE_ENABLE
#endif

#ifdef OLED_ENABLE
#    ifdef OLED_FONT_H
#        undef OLED_FONT_H
#    endif
#    define OLED_FONT_H RHRUIZ_OLED_FONT_H
#    define OLED_SCROLL_TIMEOUT 8000
#    ifdef OLED_ROTATE
#        define OLED_SCROLL_TIMEOUT_RIGHT
#    endif
#endif

#define HOME_ROW_MODS
