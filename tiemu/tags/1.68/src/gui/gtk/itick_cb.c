#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "itick_cb.h"
#include "itick_dbox.h"
#include "support.h"

#include "platform.h"
#include "struct.h"
#include "ticalc.h"
#include "main.h"

gint tmp_cyclerate, tmp_tickrate, tmp_itick;

gint display_tickrate_dbox()
{
  GtkWidget *dbox;
  gpointer user_data;
  gchar buffer[MAXCHARS];

  dbox = create_tickrate_dbox();
  
  user_data = gtk_object_get_data(GTK_OBJECT(dbox), "entry7");
  tmp_tickrate = (options.params)->tick_rate;
  g_snprintf(buffer, MAXCHARS, "%lu", (options.params)->tick_rate);
  gtk_entry_set_text((GtkEntry *)user_data, buffer);

  gtk_widget_show_all(dbox);
  return 0;
}


void
on_entry7_changed                      (GtkEditable     *editable,
                                        gpointer         user_data)
{
  gchar *s;
  
  s = gtk_editable_get_chars((GtkEditable *)(user_data), 0, -1);
  if(sscanf(s, "%i", &tmp_tickrate) < 1)
    tmp_tickrate = 40000;
  
  g_free(s);
}

void
on_button33_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  (options.params)->tick_rate = tmp_tickrate;
  gtk_widget_destroy(user_data);
}


void
on_button34_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_destroy(user_data);
}


void
on_tickrate_dbox_destroy               (GtkObject       *object,
                                        gpointer         user_data)
{
  unhalt();
}

/*--*/

gint display_cyclerate_dbox()
{
  GtkWidget *dbox;
  gpointer user_data;
  gchar buffer[MAXCHARS];

  dbox = create_cyclerate_dbox();
  
  user_data = gtk_object_get_data(GTK_OBJECT(dbox), "entry8");
  tmp_cyclerate = (options.params)->cycle_rate;
  g_snprintf(buffer, MAXCHARS, "%lu", (options.params)->cycle_rate);
  gtk_entry_set_text((GtkEntry *)user_data, buffer);

  gtk_widget_show_all(dbox);
  return 0;
}


void
on_entry8_changed                      (GtkEditable     *editable,
                                        gpointer         user_data)
{
  gchar *s;

  s = gtk_editable_get_chars((GtkEditable *)(user_data), 0, -1);
  if(sscanf(s, "%i", &tmp_cyclerate) < 1)
    tmp_cyclerate = 40000;

  g_free(s);
}


void
on_button35_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  (options.params)->cycle_rate = tmp_cyclerate;

  gtk_widget_destroy(user_data);
}


void
on_button36_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_destroy(user_data);
}


void
on_cyclerate_dbox_destroy              (GtkObject       *object,
                                        gpointer         user_data)
{
  unhalt();
}

/* -- */

gint display_itick_dbox()
{
  GtkWidget *dbox;
  gpointer user_data;
  gchar buffer[MAXCHARS];

  dbox = create_itick_dbox();
  
  user_data = gtk_object_get_data(GTK_OBJECT(dbox), "entry9");
  tmp_itick = (options.params)->i_tick;
  g_snprintf(buffer, MAXCHARS, "%i", (options.params)->i_tick);
  gtk_entry_set_text((GtkEntry *)user_data, buffer);

  gtk_widget_show_all(dbox);
  return 0;
}


void
on_entry9_changed                      (GtkEditable     *editable,
                                        gpointer         user_data)
{
  gchar *s;

  s = gtk_editable_get_chars((GtkEditable *)(user_data), 0, -1);
  if(sscanf(s, "%i", &tmp_itick) < 1)
    tmp_itick = 640;

  g_free(s);
}


void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  (options.params)->i_tick = tmp_itick;

  gtk_widget_destroy(user_data);
}


void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_destroy(user_data);
}


void
on_itick_dbox_destroy                  (GtkObject       *object,
                                        gpointer         user_data)
{
  unhalt();
}

/* */



