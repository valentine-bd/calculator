#include<stdio.h>
#include<gtk/gtk.h>

#include<mainWindow.h>
#include<gestion.h>
#include<tests.h>

#define N 10  // N : taille de la chaine d'entrée en attente de l'allocation dynamique

void on_activate_entry(GtkWidget *entry, GtkWidget *result)
{
  GtkEntryBuffer *buffer;
  const char *chaine;
  char chaineRes[N];

  int valeurCursor = 0;
  int *cursor = &valeurCursor;

  buffer = gtk_entry_get_buffer(GTK_ENTRY(entry));
  chaine = gtk_entry_buffer_get_text(buffer);

  give(chaine, cursor, chaineRes);

  if(nonValide(cursor)==1)
  {
    gtk_label_set_text(GTK_LABEL(result), "Erreur : non pris en charge");
  }
  else
  {
    gtk_label_set_text(GTK_LABEL(result), chaineRes);
  }
}

void app_activate(GApplication *app)
{
  GtkWidget *win;
  GtkWidget *box;
  GtkWidget *lab;
  GtkWidget *entry;
  GtkWidget *result;

  win = gtk_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_title (GTK_WINDOW (win), "calculatrice");
  gtk_window_set_default_size (GTK_WINDOW (win), 400, 300);

  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_set_homogeneous (GTK_BOX (box), TRUE);
  gtk_window_set_child (GTK_WINDOW (win), box);

  lab = gtk_label_new("Tapez un calcul a effectuer :");
  result = gtk_label_new(NULL);

  entry = gtk_entry_new();
  g_signal_connect(entry, "activate", G_CALLBACK(on_activate_entry), result);

  gtk_box_append(GTK_BOX(box), lab);
  gtk_box_append(GTK_BOX(box), entry);
  gtk_box_append(GTK_BOX(box), result);
 
  gtk_window_present(GTK_WINDOW(win));
}