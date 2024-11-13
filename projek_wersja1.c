#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>


// Funkcja do przeliczania jednostek
double przelicz(double wartosc, const char* zjednostki, const char* najednostki, const char* rodzaj) {
    if (strcmp(rodzaj, "Długość") == 0) {
        if (strcmp(zjednostki, "Kilometry") == 0 && strcmp(najednostki, "Mile") == 0) {
            return wartosc * 0.621371;
        } else if (strcmp(zjednostki, "Mile") == 0 && strcmp(najednostki, "Kilometry") == 0) {
            return wartosc / 0.621371;
        } else if (strcmp(zjednostki, "Metry") == 0 && strcmp(najednostki, "Jardy") == 0) {
            return wartosc * 1.09361;
        } else if (strcmp(zjednostki, "Jardy") == 0 && strcmp(najednostki, "Metry") == 0) {
            return wartosc / 1.09361;
        } else if (strcmp(zjednostki, "Kilometry") == 0 && strcmp(najednostki, "Metry") == 0) {
            return wartosc * 1000;
        } else if (strcmp(zjednostki, "Metry") == 0 && strcmp(najednostki, "Kilometry") == 0) {
            return wartosc / 1000;
        } else if (strcmp(zjednostki, "Centymetry") == 0 && strcmp(najednostki, "Cale") == 0) {
            return wartosc * 0.393701;
        } else if (strcmp(zjednostki, "Cale") == 0 && strcmp(najednostki, "Centymetry") == 0) {
            return wartosc / 0.393701;
        } else if (strcmp(zjednostki, "Metry") == 0 && strcmp(najednostki, "Centymetry") == 0) {
            return wartosc * 100;
        } else if (strcmp(zjednostki, "Centymetry") == 0 && strcmp(najednostki, "Metry") == 0) {
            return wartosc / 100;
        } else if (strcmp(zjednostki, "Metry") == 0 && strcmp(najednostki, "Milimetry") == 0) {
            return wartosc * 1000;
        } else if (strcmp(zjednostki, "Milimetry") == 0 && strcmp(najednostki, "Metry") == 0) {
            return wartosc / 1000;
        } else if (strcmp(zjednostki, "Centymetry") == 0 && strcmp(najednostki, "Milimetry") == 0) {
            return wartosc * 10;
        } else if (strcmp(zjednostki, "Milimetry") == 0 && strcmp(najednostki, "Centymetry") == 0) {
            return wartosc / 10;
        }


    } else if (strcmp(rodzaj, "Waga") == 0) {
        if (strcmp(zjednostki, "Kilogramy") == 0 && strcmp(najednostki, "Funt") == 0) {
            return wartosc * 2.20462;
        } else if (strcmp(zjednostki, "Funt") == 0 && strcmp(najednostki, "Kilogramy") == 0) {
            return wartosc / 2.20462;
        } else if (strcmp(zjednostki, "Gram") == 0 && strcmp(najednostki, "Uncja") == 0) {
            return wartosc * 0.035274;
        } else if (strcmp(zjednostki, "Uncja") == 0 && strcmp(najednostki, "Gram") == 0) {
            return wartosc / 0.035274;
        } else if (strcmp(zjednostki, "Kilogramy") == 0 && strcmp(najednostki, "Gram") == 0) {
            return wartosc * 1000;
        } else if (strcmp(zjednostki, "Gram") == 0 && strcmp(najednostki, "Kilogramy") == 0) {
            return wartosc / 1000;
        } else if (strcmp(zjednostki, "Funt") == 0 && strcmp(najednostki, "Uncja") == 0) {
            return wartosc * 16;
        } else if (strcmp(zjednostki, "Uncja") == 0 && strcmp(najednostki, "Funt") == 0) {
            return wartosc / 16;
        }
    } else if (strcmp(rodzaj, "Objętość") == 0) {
        if (strcmp(zjednostki, "Litry") == 0 && strcmp(najednostki, "Galony") == 0) {
            return wartosc * 0.264172;
        } else if (strcmp(zjednostki, "Galony") == 0 && strcmp(najednostki, "Litry") == 0) {
            return wartosc / 0.264172;
        } else if (strcmp(zjednostki, "Mililitry") == 0 && strcmp(najednostki, "Pint") == 0) {
            return wartosc * 0.00211338;
        } else if (strcmp(zjednostki, "Pint") == 0 && strcmp(najednostki, "Mililitry") == 0) {
            return wartosc / 0.00211338;
        } else if (strcmp(zjednostki, "Litry") == 0 && strcmp(najednostki, "Mililitry") == 0) {
            return wartosc * 1000;
        } else if (strcmp(zjednostki, "Mililitry") == 0 && strcmp(najednostki, "Litry") == 0) {
            return wartosc / 1000;
        } else if (strcmp(zjednostki, "Galony") == 0 && strcmp(najednostki, "Pint") == 0) {
            return wartosc * 8;
        } else if (strcmp(zjednostki, "Pint") == 0 && strcmp(najednostki, "Galony") == 0) {
            return wartosc / 8;
        }
    }
    return wartosc; 

}

// Funkcja do sprawdzania poprawności jednostek dla wybranego rodzaju miary
// Funkcja do sprawdzania poprawności jednostek dla wybranego rodzaju miary
gboolean jednostki_pasujace(const char* rodzaj, const char* zjednostki, const char* najednostki) {
    if (strcmp(rodzaj, "Długość") == 0) {
        return (strcmp(zjednostki, "Kilometry") == 0 || strcmp(zjednostki, "Mile") == 0 || strcmp(zjednostki, "Metry") == 0 || strcmp(zjednostki, "Jardy") == 0) &&
               (strcmp(najednostki, "Kilometry") == 0 || strcmp(najednostki, "Mile") == 0 || strcmp(najednostki, "Metry") == 0 || strcmp(najednostki, "Jardy") == 0);
    } else if (strcmp(rodzaj, "Waga") == 0) {
        return (strcmp(zjednostki, "Kilogramy") == 0 || strcmp(zjednostki, "Funt") == 0 || strcmp(zjednostki, "Gram") == 0 || strcmp(zjednostki, "Uncja") == 0) &&
               (strcmp(najednostki, "Kilogramy") == 0 || strcmp(najednostki, "Funt") == 0 || strcmp(najednostki, "Gram") == 0 || strcmp(najednostki, "Uncja") == 0);
    } else if (strcmp(rodzaj, "Objętość") == 0) {
        return (strcmp(zjednostki, "Litry") == 0 || strcmp(zjednostki, "Galony") == 0 || strcmp(zjednostki, "Mililitry") == 0 || strcmp(zjednostki, "Pint") == 0) &&
               (strcmp(najednostki, "Litry") == 0 || strcmp(najednostki, "Galony") == 0 || strcmp(najednostki, "Mililitry") == 0 || strcmp(najednostki, "Pint") == 0);
    }
    return FALSE;
}



// Funkcja obsługująca przycisk "Przelicz"
void on_przelicz_button_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget **widgets = (GtkWidget **) user_data;
    GtkWidget *entry = widgets[0];  // Przypisanie właściwego wskaźnika do GtkEntry
    GtkWidget *label_result = widgets[4];  // Upewnij się, że wskazuje na etykietę wyniku

    const gchar *input = gtk_entry_get_text(GTK_ENTRY(entry));  // Pobranie tekstu z GtkEntry
    double wartosc = atof(input);  // Konwersja tekstu na liczbę zmiennoprzecinkową

    // Sprawdzanie, czy wartość jest poprawna
    if (wartosc == 0 && strcmp(input, "0") != 0) {
        gtk_label_set_text(GTK_LABEL(label_result), "Błędna wartość!");
        return;
    }

    // Pobranie wybranych jednostek i rodzaju miary
    GtkComboBox *rodzaj_combo = GTK_COMBO_BOX(widgets[1]);
    GtkComboBox *combo1 = GTK_COMBO_BOX(widgets[2]);
    GtkComboBox *combo2 = GTK_COMBO_BOX(widgets[3]);

    const gchar *rodzaj = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(rodzaj_combo));
    const gchar *zjednostki = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo1));
    const gchar *najednostki = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo2));

    if (rodzaj == NULL || zjednostki == NULL || najednostki == NULL) {
        gtk_label_set_text(GTK_LABEL(label_result), "Wybierz jednostki i rodzaj.");
        return;
    }

    // Sprawdzanie poprawności jednostek względem wybranego rodzaju
    if (!jednostki_pasujace(rodzaj, zjednostki, najednostki)) {
        gtk_label_set_text(GTK_LABEL(label_result), "Niewłaściwe jednostki dla wybranego rodzaju miary.");
        return;
    }

    // Przeliczanie wartości
    double wynik = przelicz(wartosc, zjednostki, najednostki, rodzaj);

    gchar wynik_text[256];
    snprintf(wynik_text, sizeof(wynik_text), "Wynik: %.2f", wynik);
    gtk_label_set_text(GTK_LABEL(label_result), wynik_text);  // Wyświetlenie wyniku
}


// Funkcja tworząca główny interfejs
GtkWidget* create_interface() {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *rodzaj_combo, *combo1, *combo2;
    GtkWidget *entry, *button, *label_prompt, *label_result;

    // Tworzenie głównego okna
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Przelicznik Miary");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); // Wyśrodkowanie okna na ekranie

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Wyśrodkowanie siatki w oknie
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);

    // Ustawienie proporcji dla kolumn (wszystkie kolumny mają tę samą szerokość)
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    // Etykieta do wprowadzania wartości
    label_prompt = gtk_label_new("Wpisz wartość do przeliczenia:");
    gtk_grid_attach(GTK_GRID(grid), label_prompt, 0, 0, 3, 1);  // Zajmujemy całą szerokość (3 kolumny)

    // Pole tekstowe do wprowadzania wartości
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 1, 3, 1);  // Zajmujemy całą szerokość (3 kolumny)

    // Combo box dla wyboru rodzaju miary
    rodzaj_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(rodzaj_combo), "Długość");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(rodzaj_combo), "Waga");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(rodzaj_combo), "Objętość");
    gtk_grid_attach(GTK_GRID(grid), rodzaj_combo, 0, 2, 1, 1);  // Zajmujemy tylko 1 kolumnę

    // Combo box dla jednostek wejściowych
    combo1 = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Kilometry");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Mile");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Metry");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Jardy");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Kilogramy");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Funt");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Gram");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Uncja");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Litry");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Galony");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Mililitry");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo1), "Pint");
    gtk_grid_attach(GTK_GRID(grid), combo1, 1, 2, 1, 1);

    // Combo box dla jednostek wynikowych
    combo2 = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Kilometry");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Mile");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Metry");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Jardy");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Kilogramy");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Funt");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Gram");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Uncja");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Litry");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Galony");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Mililitry");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo2), "Pint");
    gtk_grid_attach(GTK_GRID(grid), combo2, 2, 2, 1, 1);

    // Przycisk do przeliczania
    button = gtk_button_new_with_label("Przelicz");
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 3, 1);  // Zajmujemy całą szerokość (3 kolumny)

    // Etykieta do wyświetlania wyniku
    label_result = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), label_result, 0, 4, 3, 1);  // Zajmujemy całą szerokość (3 kolumny)

    // Tablica wskaźników do przekazania do funkcji
    GtkWidget **widgets = g_new(GtkWidget *, 5); // Alokacja dynamiczna
    widgets[0] = entry;
    widgets[1] = rodzaj_combo;
    widgets[2] = combo1;
    widgets[3] = combo2;
    widgets[4] = label_result;

    g_signal_connect(button, "clicked", G_CALLBACK(on_przelicz_button_clicked), widgets);

    return window;
}



// Funkcja główna
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = create_interface();
    gtk_widget_show_all(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

    return 0;
}
