/*
 * =========================
 * Rust + Ratatui Tutorial File
 * =========================
 * 
 * Rust:
 * - Rust is a compiled, strongly typed systems language with ownership/borrowing rules.
 * - Memory safety and data‑race freedom are enforced at compile time.
 * - Variables are immutable by default; use `mut` for mutability.
 * - Error handling uses `Result<T, E>` and `Option<T>`.
 * - Cargo is Rust's package manager and build tool.
 *
 * Ratatui (Terminal UI):
 * - Ratatui (formerly tui‑rs) is a library for building terminal user interfaces in Rust.
 * - Provides widgets: Blocks, Paragraphs, Lists, Gauges, Tables, etc.
 * - Requires a backend (e.g., crossterm) for terminal control.
 * - UI logic typically runs in a loop, rendering on every tick.
 *
 * Dependencies (Cargo.toml):
 * ```
 * [dependencies]
 * crossterm = "0.26"
 * ratatui = "0.21"
 * ```
 *
 * Compiling & Running (Console):
 * 1) Create project: `cargo new ratatui_demo`
 * 2) Add dependencies into Cargo.toml as shown above
 * 3) Copy this file into `src/main.rs`
 * 4) Build: `cargo build`
 * 5) Run: `cargo run`
 */

use std::{io, time::Duration};
use crossterm::{
    event::{self, Event, KeyCode},
    execute,
    terminal::{disable_raw_mode, enable_raw_mode, EnterAlternateScreen, LeaveAlternateScreen},
};
use ratatui::{
    backend::CrosstermBackend,
    layout::{Constraint, Direction, Layout},
    style::{Color, Style},
    text::{Span, Spans},
    widgets::{Block, Borders, List, ListItem, Paragraph},
    Terminal,
};

fn main() -> Result<(), io::Error> {
    // Terminal initialization
    enable_raw_mode()?;
    let mut stdout = io::stdout();
    execute!(stdout, EnterAlternateScreen)?;
    let backend = CrosstermBackend::new(stdout);
    let mut terminal = Terminal::new(backend)?;

    // Application state
    let mut items = vec![
        String::from("Item 1"),
        String::from("Item 2"),
        String::from("Item 3"),
    ];
    let mut selected = 0;

    // UI loop
    loop {
        terminal.draw(|f| {
            // Layout splitting
            let size = f.size();
            let chunks = Layout::default()
                .direction(Direction::Vertical)
                .margin(1)
                .constraints(
                    [
                        Constraint::Percentage(20),
                        Constraint::Percentage(60),
                        Constraint::Percentage(20),
                    ]
                    .as_ref(),
                )
                .split(size);

            // Title
            let title_block = Block::default()
                .title(Span::styled("Ratatui Example", Style::default().fg(Color::Cyan)))
                .borders(Borders::ALL);
            f.render_widget(title_block, chunks[0]);

            // Item list
            let list_items: Vec<ListItem> = items
                .iter()
                .map(|i| ListItem::new(Spans::from(Span::raw(i.clone()))))
                .collect();
            let list_widget = List::new(list_items)
                .block(Block::default().borders(Borders::ALL).title("Items"))
                .highlight_style(Style::default().fg(Color::Yellow))
                .highlight_symbol(">> ");
            f.render_stateful_widget(list_widget, chunks[1], &mut ratatui::widgets::ListState::default().select(Some(selected)));

            // Instructions
            let instructions = Paragraph::new("Up/Down: Navigate • Enter: Add Item • q: Quit")
                .block(Block::default().borders(Borders::ALL).title("Help"));
            f.render_widget(instructions, chunks[2]);
        })?;

        // Event handling
        if event::poll(Duration::from_millis(200))? {
            if let Event::Key(key) = event::read()? {
                match key.code {
                    KeyCode::Char('q') => break,           // Quit
                    KeyCode::Down => {
                        if selected < items.len() - 1 {
                            selected += 1;
                        }
                    }
                    KeyCode::Up => {
                        if selected > 0 {
                            selected -= 1;
                        }
                    }
                    KeyCode::Enter => {
                        items.push(format!("New Item {}", items.len() + 1));
                    }
                    _ => {}
                }
            }
        }
    }

    // Cleanup
    disable_raw_mode()?;
    execute!(terminal.backend_mut(), LeaveAlternateScreen)?;
    terminal.show_cursor()?;

    Ok(())
}


// In Cargo.toml
// [dependencies]
// crossterm = "0.26"
// ratatui = "0.21"

// Kompilieren & Ausführen
//# 1) Neues Projekt erzeugen
// cargo new ratatui_demo
// cd ratatui_demo

// # 2) Cargo.toml anpassen (Dependencies hinzufügen)

// # 3) Code in src/main.rs einfügen

// # 4) Build
// cargo build

// # 5) Run
// cargo run
