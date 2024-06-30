# QMK Keebio Iris rev8

## Building

Link this directory in a Git clone of https://github.com/qmk/qmk_firmware.

```shell
git clone git@github.com:qmk/qmk_firmware.git
cd qmk_firmware
ln -s $THIS_REPOSITORY_PATH $(pwd)/keyboards/keebio/iris/rev8/hiddewie
```

Build the firmware with
```shell
util/docker_build.sh keebio/iris/rev8:hiddewie
```

This should result in a file `keebio_iris_rev8_hiddewie.uf2` in the root of the `qmk_firmware` repository.

Put the keyboard in bootloader mode by pressing the reset key on the bottom of the keyboard. Copy the file `keebio_iris_rev8_hiddewie.uf2` into the mounted filesystem. Wait until the keyboard has rebooted, and repeat for the other half of the keyboard.
