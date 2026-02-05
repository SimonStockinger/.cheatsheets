#!/usr/bin/env bash 

CHEATDIR="$HOME/.cheatsheets/sheets/"

# No argument -> interactive mode
if [ $# -eq 0 ]; then
    FILE=$(ls "$CHEATDIR"/*.md | xargs -n 1 basename | sed 's/\.md$//' | fzf --prompt="Choose a cheat sheet: ")
    [ -z "$FILE" ] && exit 0
    FILE="$CHEATDIR/$FILE.md"

# Argument provided -> open directly
else
    FILE="$CHEATDIR/$1.md"
    if [ ! -f "$FILE" ]; then
        echo "Cheat sheet '$1' not found in $CHEATDIR"
        exit 1
    fi
fi

# Open with bat
bat "$FILE" --paging=always --style=numbers,changes --theme=TwoDark

export PATH="$HOME/.cheatsheets:$PATH"

