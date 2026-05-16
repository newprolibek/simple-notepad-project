#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "spell_checker.h"
#include "text_transform.h"

#include <QDialog>
#include <QMainWindow>
#include <QPoint>
#include <QString>
#include <QTextDocument>
#include <QTextEdit>
#include <QColorDialog>
#include <memory>
#include <set>
#include <string>
#include <vector>

namespace Ui {
class find_replace_dialog;
class word_frequency_dialog;
}

class spell_checker_highlighter;

class main_window : public QMainWindow {
public:
    main_window();
    ~main_window() override;

private:
    void load_words();

    void setup_file_menu();
    void setup_edit_menu();
    void setup_format_menu();
    void setup_format_toolbar();
    void setup_search_menu();
    void setup_tools_menu();
    void setup_view_menu();
    void setup_status_bar();

    void open_file();
    void save_file();
    void save_file_as();
    void update_title();

    void setup_context_menu(const QPoint& pos);

    void apply_transform(const text_transform& transform) const;

    void change_color();

    void show_find_replace_dialog();
    void find_next(const QString& term, QTextDocument::FindFlags flags = QTextDocument::FindFlags()) const;
    void replace_current(const QString& term, const QString& replacement,
        QTextDocument::FindFlags flags = QTextDocument::FindFlags()) const;
    void replace_all(const QString& term, const QString& replacement,
        QTextDocument::FindFlags flags = QTextDocument::FindFlags()) const;

    void show_word_frequency();

    QTextEdit* editor { nullptr };
    qreal default_font_point_size { 0 };
    QString current_file;
    std::vector<std::unique_ptr<text_transform>> transforms;

    QDialog* find_replace_dlg { nullptr };
    std::unique_ptr<Ui::find_replace_dialog> find_replace_ui;

    QColorDialog* text_color_dlg { nullptr };

    std::set<std::string> words;
    std::unique_ptr<spell_checker> checker;

    spell_checker_highlighter* highlighter { nullptr };
};

#endif // MAIN_WINDOW_H
