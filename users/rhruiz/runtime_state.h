void reset_runtime_state(void);
bool needs_runtime_state_sync(void);
void set_needs_runtime_state_sync(bool value);
void set_nav_keys_index(uint8_t value);
uint8_t nav_keys_index(void);
uint8_t default_layer_index(void);
void set_default_layer_index(uint8_t index);
#ifdef SPLIT_KEYBOARD
#ifdef CAPS_WORD_ENABLE
void set_caps_word_enabled(bool enabled);
bool caps_word_enabled(void);
#endif
#endif
