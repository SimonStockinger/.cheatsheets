# Vim / Neovim Command Cheat Sheet

---

## Modi (Vim & Neovim)
- `i` – Insert
- `Esc` – Normal
- `v` – Visual
- `V` – Visual Line
- `Ctrl+v` – Visual Block
- `:` – Command-Line
- `R` – Replace Mode

---

## Navigation & Motions
- `h j k l` – Cursor bewegen
- `w` / `b` / `e` – Wort vor / zurück / Ende
- `0` / `^` / `$` – Zeilenanfang / erstes Zeichen / -ende
- `gg` / `G` – Datei Anfang / Ende
- `H M L` – Top / Mitte / Bottom des Screens
- `Ctrl+d` / `Ctrl+u` – Halbe Seite runter / hoch
- `%` – Passende Klammer

---

## Operatoren
- `d` – Delete
- `y` – Yank (Copy)
- `c` – Change
- `>` / `<` – Einrücken
- `=` – Auto-Indent

**Schema:**  
`<operator><count><motion>` → `d3w`, `y$`, `ci(`

---

## Text Objects (essentiell)
- `iw` / `aw` – Inner / a word
- `is` / `as` – Satz
- `ip` / `ap` – Absatz
- `i(` `a(` – Inner / a parentheses
- `i{` `a{` – Block
- `i"` `a"` – Quotes
- Beispiele:
  - `ci"` – Inhalt in Anführungszeichen ändern
  - `da(` – Klammern inkl. Inhalt löschen

---

## Bearbeitung
- `x` – Zeichen löschen
- `dd` – Zeile löschen
- `D` – Bis Zeilenende löschen
- `yy` – Zeile kopieren
- `p` / `P` – Einfügen nach / vor Cursor
- `u` – Undo
- `Ctrl+r` – Redo
- `.` – Letzte Änderung wiederholen

---

## Register
- `"` – Register-Präfix
- `"+y` – In System-Clipboard kopieren
- `"0` – Letztes Yank
- `"_d` – Löschen ohne Register
- `:reg` – Register anzeigen

---

## Macros
- `q<reg>` – Macro aufnehmen
- `q` – Aufnahme stoppen
- `@<reg>` – Macro ausführen
- `@@` – Letztes Macro wiederholen
- `:normal @a` – Macro auf mehrere Zeilen anwenden

---

## Suchen & Ersetzen
- `/pattern` – Vorwärts suchen
- `?pattern` – Rückwärts suchen
- `n` / `N` – Nächstes / vorheriges Ergebnis
- `:%s/alt/neu/g` – Global ersetzen
- `:%s/alt/neu/gc` – Mit Bestätigung
- `*` / `#` – Wort unter Cursor suchen

---

## Fenster & Tabs
- `:split` / `:vsplit`
- `Ctrl+w h/j/k/l` – Fenster wechseln
- `Ctrl+w =` – Fenster ausgleichen
- `:tabnew`
- `gt` / `gT` – Tabs wechseln

---

# Reines Vim (ohne Plugins)

## Dateien & Buffers
- `:e <file>` – Datei öffnen
- `:ls` – Buffer anzeigen
- `:b <nr>` – Buffer wechseln
- `:bd` – Buffer schließen

## Nützliche Optionen
- `:set number` – Zeilennummern
- `:set relativenumber`
- `:set ignorecase smartcase`
- `:syntax on`
- `:set clipboard=unnamedplus`

## Hilfe
- `:help`
- `:help motion`
- `:help text-objects`
- `Ctrl+]` – Tag folgen
- `Ctrl+t` – Zurück

---

# Neovim + Plugins

## LSP (Built-in Neovim)
- `:LspInfo` – LSP Status
- `gd` – Go to Definition
- `gD` – Go to Declaration
- `gr` – References
- `gi` – Implementation
- `K` – Hover Docs
- `<leader>rn` – Rename
- `<leader>ca` – Code Action
- `[d` / `]d` – Diagnostics wechseln

## Autocomplete (nvim-cmp)
- `Ctrl+Space` – Completion öffnen
- `Enter` – Bestätigen
- `Ctrl+n` / `Ctrl+p` – Navigieren

## Treesitter
- `:TSInstall <lang>`
- Bessere Syntax, Text Objects, Highlighting

## Telescope
- `<leader>ff` – Files suchen
- `<leader>fg` – Live Grep
- `<leader>fb` – Buffers
- `<leader>fh` – Help

## Plugin Manager (abhängig vom Setup)
- lazy.nvim: `:Lazy`
- packer.nvim: `:PackerSync`

---

## Tipps
- Lerne **Text Objects + Operatoren** → größte Produktivitätssteigerung
- Nutze `.` und Macros für Wiederholungen
- Konfiguriere Leader-Key bewusst (`let mapleader = " "`)

