# .cheatsheets
Repository includes a script to access markdown cheatsheets via terminal command and said collection of cheatsheets.


## Repository Structure
.cheatsheets

/sheets/ -> Directory for .md cheatsheet files

/cheatsheets.sh -> Cheatsheets script
  
/install.sh -> Install shell script
  
/uninstall.sh -> Uninstall shell script
 
## Usage
**IMPORTANT:** Check if the configuration used in the scripts is compatible with your system.


### Prerequisites
- `bash` (or compatible shell)
- `fzf` for interactive selection
- `bat` for Markdown rendering

### Installation
**Cloning**

By default the script expects the `.cheatsheets` directory to be located at `$HOME/.cheatsheets`

```bash
cd ~
git clone https://github.com/SimonStockinger/.cheatsheets.git
cd cheatsheets
```

**Make the scripts runnable**
```bash
chmod +x cheatsheets install.sh uninstall.sh ./cheatsheets
```
**Installation** via `./install.sh`
**Uninstall** via `./uninstall`

### Opening cheatsheets

`cheatsheets` -> allows to choos from the cheatsheets in the defined path.

`cheatsheets cheatsheet.md` opend `cheatsheet.md` if it exists in the defined path.

## Customization
bat can be replaced by any markdown viewer of choice (f.e. mdcat, glow).

Adjust this line: `bat "$FILE" --paging=always --style=numbers,changes --theme=TwoDark` in the cheatsheets.sh script.

Additionally it is recommended to set a shortcut to opening and editing the .cheatsheets directory.

For example in `~/.zshrc` add: `alias ecs='nvim ~/.cheatsheets/sheets/'` ("edit cheatsheets")
