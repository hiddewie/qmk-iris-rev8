# QMK Keebio Iris rev8

## Features

### Layers

This keymap contains three layers: a base layer, a keyboard navigation layer and a music/mouse navigation layer.

#### Base layer

The base layer contains the alphabetic characters, symbols for programming, the escape, tab, anti-tab, backspace and delete keys, and modifiers including layer switching.

Numbers are included by long-pressing the symbols.

Function keys are included by using the leader key and pressing the numeric keys (expanded with escape and delete for F11 and F12).

#### Keyboard navigation layer

The keyboard navigation layer contains the arrow keys, expanded with word and line movement and selection keys.

The top row contains numeric keys for typing numbers quickly.

#### Music and mouse navigation layer

The left side contains mouse navigation and mouse buttons for mouseless computer usage. The escape button makes the computer go to sleep.

The right side contains music controls like volume control, play/pause and previous/next track.

Finally, there are buttons to reset the keyboard and increase/decrease the tap-hold duration dynamically.

### Alpha characters

The alpha characters are not modified in any way. They can be used to type efficiently without waiting for delays of tap dances or tap-hold combinations.

The keyboard layout output by the keyboard is QWERTY. Other layouts can be configured on the operating system level, to map the QWERTY layout to for example the Colemak layout.

### Symbols

The numbers on the base layer have been mapped to symbols to reduce the need for modifier keys to type the symbols. In particular brackets, parenthesis and braces have been mapped to the numbers directly above the home row to avoid moving the hands in a sideways motion.

### Function keys

The function keys are typed by tapping the leader key and pressing the numbers 1 until 0 for F1 until F10, delete for F11 and escape for F12.

### *Shift* combined with *Enter*

The *shift* and *enter* keys are combined in a single key. A tap becomes *enter* while holding the key becomes *shift*.

This key is duplicated on both the right thumb cluster (for normal typing) and on the left side of the keyboard (shortcuts that need *shift*).

Both keys can be used to type *shift* and *enter* together.

### Anti-tab

The lower left key on the base layer contains the *anti-tab* key which is equivalent to pressing the *tab* key with *shift* pressed.

The usage of the anti-tab is to allow quick cycling through windows and tabs when switching programs or in the browser.

In addition, the anti-tab deindents a piece of code.

### Double-tap alt

Double pressing the alt key on the base layer makes it a *right-alt* key instead.

This key can be used to combine/create complex unicode characters in the operating system. For example, double pressing and holding the alt key, then pressing *d*, then pressing *o* would output *ö*.

### Caps-word

Caps-lock is a useless function of a keyboard. Instead the caps-word feature is used to type a single word where characters are replaced with their uppercase variants, and dashes are replaced with underscores.

This layout also includes `;` as a key that does not stop the caps-word functionality, because the QWERTY semicolon is mapped to the Colemak `o`.

### Indicator lighting

The underglow LED lights on the keyboard provide indicator lighting. While the layers are not complex, it can be useful to see what state the keyboard is in, when something does not work as expected.

The base layer has purple lighting. The keyboard navigation layer has red lighting. The music and mouse navigation layer has green lighting.

Activating the leader key makes the underglow white around the thumb clusters. Activating caps-word makes the lighting green around the thumb clusters.

## Building

Clone the QMK firmware Git repository from https://github.com/qmk/qmk_firmware:
```shell
git clone git@github.com:qmk/qmk_firmware.git
cd qmk_firmware
```

Build the firmware with:
```shell
docker run --rm -it \
    --user $(id -u):$(id -g) \
    -w /qmk_firmware \
    -v "$PWD:/qmk_firmware" \
    -v "$THIS_REPOSITORY_PATH:/qmk_firmware/keyboards/keebio/iris/rev8/keymaps/hiddewie" \
    -e ALT_GET_KEYBOARDS=true \
    -e "SKIP_GIT=$SKIP_GIT" \
    -e "MAKEFLAGS=$MAKEFLAGS" \
    ghcr.io/qmk/qmk_cli \
    make keebio/iris/rev8:hiddewie
```

This should result in a file `keebio_iris_rev8_hiddewie.uf2` in the root of the `qmk_firmware` repository.

Put the keyboard in bootloader mode by pressing the reset key on the bottom of the keyboard. Copy the file `keebio_iris_rev8_hiddewie.uf2` into the mounted filesystem. Wait until the keyboard has rebooted, and repeat for the other half of the keyboard.
