# Git Cheat Sheet 

Dieses Cheat Sheet fasst die wichtigsten Git-Befehle und Konzepte zusammen, die wir während dieser Session behandelt haben. Es ist speziell auf Situationen mit **Submodules**, **großen Dateien** und Repository-Strukturierung abgestimmt.

---

## 1️⃣ Repository Setup

### Git Repository initialisieren
```bash
cd Uni
git init  # initialisiert ein neues Git-Repository
```

### Branch auf main setzen
```bash
git branch -M main  # erstellt/benennt Branch in 'main'
```

### Remote hinzufügen / setzen
```bash
# Remote hinzufügen
git remote add origin https://github.com/<username>/Uni.git

# Remote URL ändern
git remote set-url origin https://github.com/<username>/Uni.git
```

### Erste Commits
```bash
git add .
git commit -m "Initial commit"
```

---

## 2️⃣ Submodules

### Submodule hinzufügen
```bash
git submodule add <repo-url> <path-to-submodule>
```
Beispiel:
```bash
git submodule add https://github.com/kit-sdq/intelligrade.git Tutorials/Programmieren/meta/Grading/intelligrade
```

### Submodule aktualisieren / initialisieren
```bash
git submodule init
# oder rekursiv alle Submodules aktualisieren
git submodule update --init --recursive
```

### Submodules beim Pull berücksichtigen
```bash
git pull --recurse-submodules
```

### Submodule deinitialisieren / Git-Tracking entfernen (ohne Dateien zu löschen)
```bash
git submodule deinit -f <path-to-submodule>
git rm --cached <path-to-submodule>
rm -rf .git/modules/<path-to-submodule>
```

### Submodule vollständig entfernen (inkl. Dateien)
```bash
git submodule deinit -f <path>
git rm -f <path>
rm -rf .git/modules/<path>
rm -rf <path>
git commit -m "Remove submodule"
```

---

## 3️⃣ Große Dateien (GitHub Limit >100MB)

### Problem: Datei überschreitet Limit
```
remote: error: File <file> is XXX MB; this exceeds GitHub's file size limit
```

### Lösungen:

#### 1️⃣ Git LFS (für große Dateien)
```bash
git lfs install
git lfs track "*.pdf"
git add .gitattributes
git add <large-file>
git commit -m "Track PDF with LFS"
git push origin main
```

#### 2️⃣ Datei aus Git-History entfernen (ohne LFS)
```bash
# Mit git-filter-repo
git filter-repo --path <large-file> --invert-paths
git push origin main --force

# Mit BFG Repo-Cleaner
bfg --delete-files <large-file>
git reflog expire --expire=now --all
git gc --prune=now --aggressive
git push origin main --force
```

> Wichtig: Normales `git rm` entfernt nur die aktuelle Version, nicht die Historie.

---

## 4️⃣ Dateien aus Git entfernen (Index vs. Working Directory)

```bash
# Aus Git-Tracking entfernen, Dateien behalten
git rm --cached <file>

# Vollständig löschen
git rm <file>
git commit -m "Remove file"
```

---

## 5️⃣ Git Push / Pull Basics
```bash
# Clone Repo with submodules 
git clone --recurse-submodules <repo-url>

# If already cloned 
git submodule update --init --recursive

# Pull mit Submodules
git pull --recurse-submodules

# Push zum Remote (erstmalig oder mit -u für Upstream)
git push -u origin main

```
Note: `--recursieve-submodules is equivalent to --recursive`
---

## 6️⃣ Nützliche Tipps

- Nested Repos vermeiden; lieber Submodules oder Monorepo.
- Submodules behalten eigene Git-Historie.
- `git status` zeigt, welche Dateien/states noch vorhanden sind.
- `git log --oneline --graph --all` zeigt Commit-Historie inkl. Branches.
- Wenn du große Dateien löscht, unbedingt History bereinigen für GitHub.

---
