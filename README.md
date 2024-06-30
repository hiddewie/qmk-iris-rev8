# QMK Keebio Iris rev8

## Features

- 3 layers
- symbols on top row of base layer for programming
- indicator lights through underglow

no changes to base letters

mod tap for right alt

two layers only, leader key for F keys

numbers by holding symbol keys

mouse keys in navigation layer

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
