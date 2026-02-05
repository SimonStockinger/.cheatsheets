#!/usr/bin/env bash

DEST="/usr/local/bin/cheatsheets"

if [[ -L "$DEST" ]]; then
    sudo rm "$DEST"
    echo "Cheatsheets uninstalled from global PATH."
else
    echo "No global installation found at $DEST"
fi

