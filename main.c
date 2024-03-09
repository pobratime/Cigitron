#include <gtk/gtk.h>

static void sign_button_clicked (GtkWidget *button, GtkWidget *calculator_display){

    char *clicked_button_sign = gtk_button_get_label(GTK_BUTTON(button));

    gtk_entry_set_text(calculator_display, clicked_button_sign);
}

static void number_button_clicked (GtkWidget *button, GtkWidget *calculator_display){

    char *clicked_number_value = gtk_button_get_label(GTK_BUTTON(button));

    gtk_entry_buffer_insert_text(gtk_entry_get_buffer(calculator_display), 0, clicked_number_value, -1);

    

}

static void activate (GtkApplication *app, gpointer user_data){

    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *addition_button;
    GtkWidget *subtraction_button;
    GtkWidget *multiply_button;
    GtkWidget *divide_button;
    GtkWidget *calculator_display;
    GtkWidget *button_1, *button_2, *button_3, *button_4, *button_5, *button_6, *button_7, *button_8, *button_9, *button_0;
    GtkWidget *entry;

    /* create a new window, and set its title */
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "CCalculator");
    gtk_container_set_border_width (GTK_CONTAINER (window), 120);

    /* Here we construct the container that is going pack our buttons */
    grid = gtk_grid_new ();

    /* Pack the container in the window */
    gtk_container_add (GTK_CONTAINER (window), grid);

    //Display Bar Start

    calculator_display = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(calculator_display), FALSE);  // Read-only
    gtk_entry_set_visibility(calculator_display, TRUE);


    gtk_grid_attach(GTK_GRID(grid), calculator_display, 0, 0, 6, 1);


    //Display Bar End


    //Nunber Buttons Start

    //Number 1
    button_1 = gtk_button_new_with_label("1");
    g_signal_connect (button_1, "clicked", G_CALLBACK (number_button_clicked), calculator_display);
    gtk_grid_attach (GTK_GRID (grid), button_1, 0, 3, 1, 1);

    //Number 2
    button_2 = gtk_button_new_with_label("2");
    g_signal_connect (button_2, "clicked", G_CALLBACK (number_button_clicked), calculator_display);
    gtk_grid_attach (GTK_GRID (grid), button_2, 1, 3, 1, 1);

    //Number 3
    button_3 = gtk_button_new_with_label("3");
    g_signal_connect (button_3, "clicked", G_CALLBACK (number_button_clicked), calculator_display);
    gtk_grid_attach (GTK_GRID (grid), button_3, 2, 3, 1, 1);

    //Number 4
    button_4 = gtk_button_new_with_label("4");
    g_signal_connect (button_4, "clicked", G_CALLBACK (number_button_clicked), calculator_display);
    gtk_grid_attach (GTK_GRID (grid), button_4, 0, 2, 1, 1);

    //Number 5
    button_5 = gtk_button_new_with_label("5");
    g_signal_connect (button_5, "clicked", G_CALLBACK (number_button_clicked), calculator_display);
    gtk_grid_attach (GTK_GRID (grid), button_5, 1, 2, 1, 1);

    //Number 6
    button_6 = gtk_button_new_with_label("6");
    g_signal_connect (button_6, "clicked", G_CALLBACK (number_button_clicked), calculator_display);
    gtk_grid_attach (GTK_GRID (grid), button_6, 2, 2, 1, 1);

    //Number 7
    button_7 = gtk_button_new_with_label("7");
    g_signal_connect (button_7, "clicked", G_CALLBACK (number_button_clicked), calculator_display);
    gtk_grid_attach (GTK_GRID (grid), button_7, 0, 1, 1, 1);

    //Number 8
    button_8 = gtk_button_new_with_label("8");
    g_signal_connect (button_8, "clicked", G_CALLBACK (number_button_clicked), calculator_display);
    gtk_grid_attach (GTK_GRID (grid), button_8, 1, 1, 1, 1);

    //Number 9
    button_9 = gtk_button_new_with_label("9");
    g_signal_connect (button_9, "clicked", G_CALLBACK (number_button_clicked), calculator_display);
    gtk_grid_attach (GTK_GRID (grid), button_9, 2, 1, 1, 1);

    //Number 0
    button_0 = gtk_button_new_with_label("0");
    g_signal_connect (button_0, "clicked", G_CALLBACK (number_button_clicked), calculator_display);
    gtk_grid_attach (GTK_GRID (grid), button_0, 3, 3, 2, 1);

    //Number Buttons End

    //Sign Buttons Start

    //Addition Button
    addition_button = gtk_button_new_with_label (" + ");
    //Addition Button usage
    g_signal_connect (addition_button, "clicked", G_CALLBACK (sign_button_clicked), calculator_display);
    //Addition Button location
    gtk_grid_attach (GTK_GRID (grid), addition_button, 3, 1, 1, 1);

    //Subtraction Button
    subtraction_button = gtk_button_new_with_label (" - ");
    //Subtraction Button usage
    g_signal_connect (subtraction_button, "clicked", G_CALLBACK (sign_button_clicked), calculator_display);
    //Subtraction Button location
    gtk_grid_attach (GTK_GRID (grid), subtraction_button, 4, 1, 1, 1);

    //Multiply Button
    multiply_button = gtk_button_new_with_label (" * ");
    //Multiply Button usage
    g_signal_connect (multiply_button, "clicked", G_CALLBACK (sign_button_clicked), calculator_display);
    //Multiply Button location
    gtk_grid_attach (GTK_GRID (grid), multiply_button, 3, 2, 1, 1);

    //Divide Button
    divide_button = gtk_button_new_with_label (" / ");
    //Divide Button usage
    g_signal_connect (divide_button, "clicked", G_CALLBACK (sign_button_clicked), calculator_display);
    //Divide Button
    gtk_grid_attach (GTK_GRID (grid), divide_button, 4, 2, 1, 1);

    //Sign Buttons End


    gtk_widget_show_all (window);
}

int main (int argc, char **argv){
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
