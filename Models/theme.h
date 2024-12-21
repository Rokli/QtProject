#ifndef THEME_H
#define THEME_H
#include <QString>

class Theme
{
public:
    QString GetDarkTheme();
    QString GetWhiteTheme();
private:
    QString darkTheme =  R"(
    font: 300 11pt 'Comfortaa';
    background-color: #121212;
    color: white;
    QPushButton {
        background-color: #333333;
        color: white;
        border: 2px solid #555555;
        border-radius: 6px;
        padding: 8px 16px;
        font-size: 14px;
        font-weight: bold;
        transition: all 0.3s ease;
    }

    QPushButton:hover {
        background-color: #555555;
        border-color: #777777;
    }

    QPushButton:pressed {
        background-color: #222222;
        border-color: #444444;
    }

    QTextEdit {
        background-color: #333333;
        color: white;
        border: 2px solid #555555;
        border-radius: 6px;
        padding: 8px;
        font-size: 14px;
        transition: all 0.3s ease;
    }

    QTextEdit:hover {
        border-color: #777777;
    }

    QTextEdit:focus {
        border-color: #3498db;
        background-color: #2e2e2e;
    }

    QLineEdit {
        background-color: #333333;
        color: white;
        border: 2px solid #555555;
        border-radius: 6px;
        padding: 5px;
        font-size: 14px;
        transition: all 0.3s ease;
    }

    QLineEdit:hover {
        border-color: #777777;
    }

    QLineEdit:focus {
        border-color: #3498db;
        background-color: #2e2e2e;
    }

    QTableView {
        background-color: #2c2c2c;
        gridline-color: #555555;
        color: white;
        border: 1px solid #555555;
        selection-background-color: #3e8ef7;
        selection-color: #ffffff;
        font-size: 14px;
        transition: all 0.3s ease;
    }

    QHeaderView::section {
        background-color: #444444;
        color: white;
        border: 1px solid #555555;
        padding: 4px;
        font-weight: bold;
    }

    QTableView::item:hover {
        background-color: #555555;
    }

    QComboBox {
        background-color: #333333;
        color: white;
        border: 2px solid #555555;
        border-radius: 6px;
        padding: 5px 8px;
        font-size: 14px;
        transition: all 0.3s ease;
    }

    QComboBox:hover {
        border-color: #777777;
    }

    QComboBox QAbstractItemView {
        background-color: #333333;
        border: 1px solid #555555;
        selection-background-color: #3e8ef7; /
        selection-color: #ffffff;
    }

    QComboBox::drop-down {
        border: none;
        background: #444444;
        border-left: 1px solid #555555;
    }

    QComboBox::down-arrow {
        image: url(down_arrow.png);
        width: 10px;
        height: 10px;
    }
        )";
    QString whiteTheme = R"(
        /* QPushButton - Стиль для кнопки */
        QPushButton {
            background-color: #f0f0f0; /* Светло-серый фон */
            color: #333333; /* Темно-серый текст */
            border: 2px solid #dcdcdc; /* Светлая граница */
            border-radius: 6px; /* Скругленные углы */
            padding: 8px 16px; /* Внутренние отступы */
            font-size: 14px; /* Размер шрифта */
            font-weight: bold; /* Полужирный шрифт */
            transition: all 0.3s ease; /* Анимация при изменении */
        }

        QPushButton:hover {
            background-color: #e6e6e6; /* Более темный серый при наведении */
            border-color: #bfbfbf; /* Темнее граница при наведении */
        }

        QPushButton:pressed {
            background-color: #cccccc; /* Темно-серый фон при нажатии */
            border-color: #a6a6a6; /* Граница становится темнее */
        }

        /* QTableView - Стиль для таблицы */
        QTableView {
            background-color: #ffffff; /* Белый фон */
            gridline-color: #dcdcdc; /* Цвет линий сетки */
            color: #333333; /* Цвет текста */
            border: 1px solid #dcdcdc; /* Граница таблицы */
            selection-background-color: #d1e7fd; /* Голубой фон для выделенных строк */
            selection-color: #000000; /* Черный текст для выделенных строк */
            font-size: 14px; /* Размер шрифта */
        }

        QHeaderView::section {
            background-color: #f8f8f8; /* Светло-серый фон заголовков */
            color: #333333; /* Цвет текста заголовков */
            border: 1px solid #dcdcdc; /* Граница между секциями */
            padding: 4px; /* Отступы в заголовках */
            font-weight: bold; /* Полужирный шрифт */
        }

        QTableView::item:hover {
            background-color: #f2f2f2; /* Светлый фон при наведении на ячейку */
        }

        /* QComboBox - Стиль для выпадающего списка */
        QComboBox {
            background-color: #ffffff; /* Белый фон */
            color: #333333; /* Цвет текста */
            border: 2px solid #dcdcdc; /* Граница */
            border-radius: 6px; /* Скругленные углы */
            padding: 5px 8px; /* Внутренние отступы */
            font-size: 14px; /* Размер шрифта */
            transition: all 0.3s ease; /* Анимация при изменении */
        }

        QComboBox:hover {
            border-color: #a6a6a6; /* Темнее граница при наведении */
        }

        QComboBox QAbstractItemView {
            background-color: #ffffff; /* Белый фон списка */
            border: 1px solid #dcdcdc; /* Граница */
            selection-background-color: #d1e7fd; /* Голубой фон для выделенных элементов */
            selection-color: #000000; /* Черный текст для выделенных элементов */
        }

        /* Стиль для стрелки раскрытия */
        QComboBox::drop-down {
            border: none;
            background: #f0f0f0; /* Фон кнопки раскрытия */
            border-left: 1px solid #dcdcdc; /* Разделительная линия */
        }

        QComboBox::down-arrow {
            image: url(down_arrow.png); /* Замените на путь к изображению стрелки */
            width: 10px;
            height: 10px;
        }

        /* QLineEdit - Стиль для текстового поля */
        QLineEdit {
            background-color: #ffffff; /* Белый фон */
            color: #333333; /* Цвет текста */
            border: 2px solid #dcdcdc; /* Светлая граница */
            border-radius: 6px; /* Скругленные углы */
            padding: 5px; /* Внутренние отступы */
            font-size: 14px; /* Размер шрифта */
            transition: all 0.3s ease; /* Анимация при изменении */
        }

        QLineEdit:hover {
            border-color: #a6a6a6; /* Темнее граница при наведении */
        }

        QLineEdit:focus {
            border-color: #3498db; /* Голубая граница при фокусе */
            background-color: #f7fbff; /* Легкий голубой оттенок фона */
        }

        /* Анимации через свойства */
        QPushButton, QComboBox, QLineEdit {
            transition: all 0.2s ease;
        }
    )";
};

#endif // THEME_H
