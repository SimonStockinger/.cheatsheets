# .cheatsheets




## Repository Structure
.cheatsheets

/sheets/ -> Directory for .md cheatsheet files

/cheatsheets.sh -> Cheatsheets script
  
/install.sh -> Install shell script
  
/uninstall.sh -> Uninstall shell script
 
## Usage
### Prerequisites
- `bash` (or compatible shell)
- `fzf` for interactive selection
- `bat` for Markdown rendering (optional; falls back to `less` if not installed)
  - `sudo pacman -S fzf bat` (On Arch Linux)
 

### Installation
**Cloning**
By default the script expects the `.cheatsheets` directory to be located at `$HOME/.cheatsheets`

```bash
cd ~
git clone https://github.com/SimonStockinger/.cheatsheets.git
cd cheatsheets
```

Make the scripts runnable
```bash
chmod +x cheatsheets install.sh uninstall.sh ./cheatsheets
```
Installation via `./install.sh`
Uninstall via `.uninstall`

### Customization
bat can be replaced by any markdown viewer of choice (f.e. mdcat, glow).

Adjust this line: `bat "$FILE" --paging=always --style=numbers,changes --theme=TwoDark` in the cheatsheets.sh script.
