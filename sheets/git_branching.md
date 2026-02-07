# Git Branching Cheatsheet
Ein kompaktes, modernes Git-Spickzettelchen  
(Fokus: Branching, Switch, Reset, Revert, Rettung)

---

## Grundbegriffe
- **HEAD** → zeigt auf den aktuellen Commit
- **Branch** → beweglicher Zeiger auf einen Commit
- **origin/*** → Remote-Branch
- **detached HEAD** → HEAD zeigt direkt auf Commit, nicht auf Branch

---

## Branches

### Branch anzeigen
```bash
git branch
git branch -a        # inkl. remote
```
### Neuen Branch erstellen
```bash
```

### Branch wechseln (empfohlen)
```bash
git switch <branch>
```

### Branch erstellen & wechseln
```bash
git switch -c <new-branch>
```

---

## Commits & Verlauf
### Commit-Historie
```bash
git log # ausführlich
git log --oneline --graph --decorate --all # gekürzt 
```

### Einzelnen Commit ansehen
```bash
git show <commit>
```

---

## Reset / Revert / Recover

### Hard Reset (VORSICHT)
```bash
git reset --hard <commit>
```
- setzt HEAD, Index & Working Tree
- löscht lokale Änderungen

### Revert (sicher)
```bash 
git revert <commit>
```
- erstellt neuen Commit
- safe für gepushte Branches

### reflog
```bash
git reflog
```
**Zurückspringen:**
```bash
git reset --hard HEAD@{1}
```

### Merge vs. Überschreiben
Normaler Merge
```bash
git merge other-branch
```
*Merge, aber immer Version des anderen Branches*
```bash 
git merge other-branch -X theirs
```

#### Alles überschreiben (Branch angleichen)
```bash
git fetch origin
git reset --hard origin/other-branch
```

### Dateien aus anderem Branch übernehmen
```bash
git checkout other-branch -- .
```
Modern:
```bash
git restore --source other-branch .
```

### Detached HEAD
**Commit auschecken (nur anschauen)**
```bash
git switch --detach <commit>
```

**Dort weiterarbeiten (Branch retten)**
```bash
git switch -c rescue-branch
```

---

## switch vs checkout
Aufgabe | switch	checkout
Branch wechseln	✅	✅
Neuen Branch	✅	✅
Commit anschauen	✅
Dateien holen	❌	✅
Empfehlung switch 

➡️ Best Practice:

git switch → Branches

git restore → Dateien

git checkout → nur wenn nötig


