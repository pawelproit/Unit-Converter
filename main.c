#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

typedef enum 
{
    Milimetr,
    Centymetr,
    Metr,
    Kilometr
} JednostkaDlugosci;

typedef enum 
{
    Gram,
    Dekagram,
    Kilogram,
    Tona
} JednostkaWagi;

typedef enum 
{
    MetrowSzesciennych,
    KilometrowSzesciennych,
    DecymetrowSzesciennych,
    Litr
} JednostkaObjetosci;

const char *jednostki_dlugosc[] = {"mm", "cm", "m", "km"};
const char *jednostki_waga[] = {"g", "dag", "kg", "t"};
const char *jednostki_objetosc[] = {"m³", "km³", "dm³", "l"};

int jednostka_index(const char *nazwa, const char *tablica[], int rozmiar) 
{
    for (int i = 0; i < rozmiar; i++) 
    {
        if (strcmp(nazwa, tablica[i]) == 0) 
        {
            return i;
        }
    }
    return -1; 
}

double przelicz_dlugosc(JednostkaDlugosci jednostka_zrodlowa, JednostkaDlugosci jednostka_docelowa, double wartosc) 
{
    static const double wspolczynniki[4][4] = 
    {
        {1.0, 0.1, 0.001, 0.000001},
        {10.0, 1.0, 0.01, 0.00001},
        {1000.0, 100.0, 1.0, 0.001},
        {1000000.0, 100000.0, 1000.0, 1.0}
    };
    return wartosc * wspolczynniki[jednostka_zrodlowa][jednostka_docelowa];
}

double przelicz_waga(JednostkaWagi jednostka_zrodlowa, JednostkaWagi jednostka_docelowa, double wartosc) 
{
    static const double wspolczynniki[4][4] = 
    {
        {1.0, 0.1, 0.001, 0.000001},
        {10.0, 1.0, 0.01, 0.00001},
        {1000.0, 100.0, 1.0, 0.001},
        {1000000.0, 100000.0, 1000.0, 1.0}
    };
    return wartosc * wspolczynniki[jednostka_zrodlowa][jednostka_docelowa];
}

double przelicz_objetosc(JednostkaObjetosci jednostka_zrodlowa, JednostkaObjetosci jednostka_docelowa, double wartosc) 
{
    static const double wspolczynniki[4][4] = 
    {
        {1.0, 0.000001, 1000.0, 1000.0},
        {1000000.0, 1.0, 1000000000.0, 1000000000.0},
        {0.001, 0.000000001, 1.0, 1.0},
        {0.001, 0.000000001, 1.0, 1.0}
    };
    return wartosc * wspolczynniki[jednostka_zrodlowa][jednostka_docelowa];
}

double przelicz(double wartosc, int jednostka_zrodlowa, int jednostka_docelowa, const char *rodzaj) 
{
    if (wartosc <= 0) 
    {
        printf("Błędna wartość! Wprowadź dodatnią liczbę.\n");
        return -1;
    }
    if (strcmp(rodzaj, "Długość") == 0) 
    {
        return przelicz_dlugosc((JednostkaDlugosci)jednostka_zrodlowa, (JednostkaDlugosci)jednostka_docelowa, wartosc);
    } 
    else if (strcmp(rodzaj, "Waga") == 0) 
    {
        return przelicz_waga((JednostkaWagi)jednostka_zrodlowa, (JednostkaWagi)jednostka_docelowa, wartosc);
    } 
    else if (strcmp(rodzaj, "Objętość") == 0) 
    {
        return przelicz_objetosc((JednostkaObjetosci)jednostka_zrodlowa, (JednostkaObjetosci)jednostka_docelowa, wartosc);
    } 
}

void on_przelicz_button_clicked(GtkButton *button, gpointer user_data) 
{
    GtkWidget **widgets = (GtkWidget **) user_data;
    GtkWidget *entry = widgets[0];
    GtkWidget *label_result = widgets[4];

    const gchar *input = gtk_entry_get_text(GTK_ENTRY(entry));

    char *endptr;
    double wartosc = strtod(input, &endptr);

    GtkComboBox *rodzaj_combo = GTK_COMBO_BOX(widgets[1]);
    GtkComboBox *combo1 = GTK_COMBO_BOX(widgets[2]);
    GtkComboBox *combo2 = GTK_COMBO_BOX(widgets[3]);

    const gchar *rodzaj = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(rodzaj_combo));
    const gchar *zjednostki = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo1));
    const gchar *najednostki = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo2));

    if (rodzaj == NULL || zjednostki == NULL || najednostki == NULL) 
    {
        gtk_label_set_text(GTK_LABEL(label_result), "Wybierz jednostki.");
        return;
    }

    if (*endptr != '\0' || wartosc <= 0) 
    {
        gtk_label_set_text(GTK_LABEL(label_result), "Błędna wartość! Wprowadź dodatnią liczbę.");
        return;
    }

    int jednostka_zrodlowa, jednostka_docelowa;

    if (strcmp(rodzaj, "Długość") == 0) 
    {
        jednostka_zrodlowa = jednostka_index(zjednostki, jednostki_dlugosc, 4);
        jednostka_docelowa = jednostka_index(najednostki, jednostki_dlugosc, 4);
    } 
    else if (strcmp(rodzaj, "Waga") == 0) 
    {
        jednostka_zrodlowa = jednostka_index(zjednostki, jednostki_waga, 4);
        jednostka_docelowa = jednostka_index(najednostki, jednostki_waga, 4);
    } 
    else if (strcmp(rodzaj, "Objętość") == 0) 
    {
        jednostka_zrodlowa = jednostka_index(zjednostki, jednostki_objetosc, 4);
        jednostka_docelowa = jednostka_index(najednostki, jednostki_objetosc, 4);
    } 
    else 
    {
        gtk_label_set_text(GTK_LABEL(label_result), "Błędny rodzaj miary.");
        return;
    }

    double wynik = przelicz(wartosc, jednostka_zrodlowa, jednostka_docelowa, rodzaj);

    gchar wynik_text[256];
    snprintf(wynik_text, sizeof(wynik_text), "Wynik: %.4f %s", wynik, najednostki);
    gtk_label_set_text(GTK_LABEL(label_result), wynik_text);
}


void ustaw_jednostki(GtkComboBoxText *combo1, GtkComboBoxText *combo2, const char* jednostki[], int rozmiar) 
{
    gtk_combo_box_text_remove_all(combo1);
    gtk_combo_box_text_remove_all(combo2);
    for (int i = 0; i < rozmiar; i++) 
    {
        gtk_combo_box_text_append_text(combo1, jednostki[i]);
        gtk_combo_box_text_append_text(combo2, jednostki[i]);
    }
}

void on_rodzaj_combo_changed(GtkComboBox *combo, gpointer user_data) 
{
    GtkWidget **widgets = (GtkWidget **) user_data;
    GtkComboBoxText *combo1 = GTK_COMBO_BOX_TEXT(widgets[2]);
    GtkComboBoxText *combo2 = GTK_COMBO_BOX_TEXT(widgets[3]);

    const gchar *rodzaj = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo));

    if (strcmp(rodzaj, "Długość") == 0) 
    {
        ustaw_jednostki(combo1, combo2, jednostki_dlugosc, 4);
    } else if (strcmp(rodzaj, "Waga") == 0) 
    {
        ustaw_jednostki(combo1, combo2, jednostki_waga, 4);
    } else if (strcmp(rodzaj, "Objętość") == 0) 
    {
        ustaw_jednostki(combo1, combo2, jednostki_objetosc, 4);
    }
}

GtkWidget* create_interface() 
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *rodzaj_combo, *combo1, *combo2;
    GtkWidget *entry, *button, *label_prompt, *label_result;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Przelicznik Miary");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);

    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    label_prompt = gtk_label_new("Wpisz wartość do przeliczenia:");
    gtk_grid_attach(GTK_GRID(grid), label_prompt, 0, 0, 3, 1);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 1, 3, 1);

    rodzaj_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(rodzaj_combo), "Długość");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(rodzaj_combo), "Waga");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(rodzaj_combo), "Objętość");
    gtk_grid_attach(GTK_GRID(grid), rodzaj_combo, 0, 2, 1, 1);

    combo1 = gtk_combo_box_text_new();
    combo2 = gtk_combo_box_text_new();
    gtk_grid_attach(GTK_GRID(grid), combo1, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), combo2, 2, 2, 1, 1);

    button = gtk_button_new_with_label("Przelicz");
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 3, 1);

    label_result = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), label_result, 0, 4, 3, 1);

    GtkWidget **widgets = g_new(GtkWidget *, 5);
    widgets[0] = entry;
    widgets[1] = rodzaj_combo;
    widgets[2] = combo1;
    widgets[3] = combo2;
    widgets[4] = label_result;

    g_signal_connect(button, "clicked", G_CALLBACK(on_przelicz_button_clicked), widgets);

    g_signal_connect(rodzaj_combo, "changed", G_CALLBACK(on_rodzaj_combo_changed), widgets);

    gtk_combo_box_set_active(GTK_COMBO_BOX(rodzaj_combo), 0); 

    return window;
}

int main(int argc, char *argv[]) 
{
    gtk_init(&argc, &argv);

    GtkWidget *window = create_interface();
    gtk_widget_show_all(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

    return 0;
}
