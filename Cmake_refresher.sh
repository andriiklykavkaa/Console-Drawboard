#!/usr/bin/env bash

ROOT_DIR="$(pwd)"
SRC_DIR="$ROOT_DIR/source"
CMAKE_FILE="$ROOT_DIR/CMakeLists.txt"

echo "Watching $SRC_DIR for new .h/.cpp files..."

LAST_PROCESSED=""

fswatch -0 --event Created --recursive "$SRC_DIR" | while IFS= read -r -d "" FILEPATH; do
    NEW_FILE="$(basename "$FILEPATH")"

    # ---- filters ----
    # ignore editor backups and system junk
    [[ "$NEW_FILE" == *~ ]] && continue
    [[ "$NEW_FILE" == .DS_Store ]] && continue
    [[ "$NEW_FILE" == *.swp ]] && continue
    [[ "$NEW_FILE" == *.tmp ]] && continue

    # only track C++ source/header files
    case "$NEW_FILE" in
      *.h|*.hpp|*.cpp) ;;
      *) continue ;;
    esac

    # prevent duplicate spam
    if [[ "$NEW_FILE" == "$LAST_PROCESSED" ]]; then
        continue
    fi
    LAST_PROCESSED="$NEW_FILE"

    echo "New file detected: $NEW_FILE"

    LAST_LINE="$(tail -n 1 "$CMAKE_FILE")"

    if [[ -n "$LAST_LINE" && "$LAST_LINE" != message* ]]; then
        echo "" >> "$CMAKE_FILE"
    fi

    if [[ "$LAST_LINE" == message* ]]; then
        # replace last line with new message
        sed -i '' -e "\$s/.*/message(\"$NEW_FILE\")/" "$CMAKE_FILE"
    else
        # append message
        echo "message(\"$NEW_FILE\")" >> "$CMAKE_FILE"
    fi

    echo "CMakeLists.txt updated with message(\"$NEW_FILE\")"
done
