#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "parking.h"
#include "string.h"
#include "stdlib.h"



//int T[4];
int ServiceSelect = 0;
int statut = 0;

typedef struct{
	char cin[9];
}Cin;

Cin* AgentsAffecte = NULL;
unsigned int nAffecte = 0;
unsigned int TailleAgents = 20;


void on_Rl_buttonSupp_clicked(GtkWidget *button, gpointer user_data)
{
    GtkWidget *parkingtree = lookup_widget(button, "treeviewParking_RL");

    GtkTreeModel *model;
    GtkTreeIter iter;

    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(parkingtree));

    if (!gtk_tree_selection_get_selected(selection, &model, &iter))
    {
        
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(button)),
                                                   GTK_DIALOG_MODAL,
                                                   GTK_MESSAGE_INFO,
                                                   GTK_BUTTONS_OK,
                                                   "Aucun parking sélectionné.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    // Récupérer l'ID du parking sélectionné
    int id;
    gtk_tree_model_get(model, &iter, 0, &id, -1);

    // Demander confirmation avant suppression
    GtkWidget *confirm_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(button)),
                                                       GTK_DIALOG_MODAL,
                                                       GTK_MESSAGE_QUESTION,
                                                       GTK_BUTTONS_YES_NO,
                                                       "Voulez-vous vraiment supprimer ce parking ?");
    gint response = gtk_dialog_run(GTK_DIALOG(confirm_dialog));
    gtk_widget_destroy(confirm_dialog);

    if (response == GTK_RESPONSE_YES)
    {
        // Appeler la fonction de suppression
        int resultat = supprimer("parking.txt", id);
        if (resultat == 1)
        {
            // Afficher un message de succès
            GtkWidget *success_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(button)),
                                                               GTK_DIALOG_MODAL,
                                                               GTK_MESSAGE_INFO,
                                                               GTK_BUTTONS_OK,
                                                               "Parking supprimé avec succès !");
            gtk_dialog_run(GTK_DIALOG(success_dialog));
            gtk_widget_destroy(success_dialog);
        }
        else
        {
            // Afficher un message d'erreur
            GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(button)),
                                                             GTK_DIALOG_MODAL,
                                                             GTK_MESSAGE_ERROR,
                                                             GTK_BUTTONS_OK,
                                                             "Erreur lors de la suppression du parking.");
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
        }

        // Actualiser l'interface après suppression
        on_actualiser1_RL_clicked(button, user_data);
    }
    else
    {
        // Message d'annulation
        GtkWidget *cancel_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(button)),
                                                          GTK_DIALOG_MODAL,
                                                          GTK_MESSAGE_INFO,
                                                          GTK_BUTTONS_OK,
                                                          "Suppression annulée.");
        gtk_dialog_run(GTK_DIALOG(cancel_dialog));
        gtk_widget_destroy(cancel_dialog);
    }
}




void
on_RL_buttonMod_clicked(GtkWidget *button, gpointer user_data) {
    PARKING p;
	GtkWidget* parkingtree = lookup_widget(button, "treeviewParking_RL");

    GtkTreeModel* model;
    GtkTreeIter iter;
   
    GtkTreeSelection* selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(parkingtree));
    if(gtk_tree_selection_get_selected(selection, &model, &iter)){
		g_print("Aucune Selection\n");
	}


    int id;
    gtk_tree_model_get(model, &iter, 0, &id, -1);

    // Chercher le parking correspondant
    p = chercher("parking.txt", id);

    if (p.id_parking != -1) {
        GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8;

        // Récupérer les champs du formulaire
        input1 = lookup_widget(button, "id_Rl");
        input2 = lookup_widget(button, "nom_RL");
        input3 = lookup_widget(button, "add_RL");
        input4 = lookup_widget(button, "cap_RL");
        input5 = lookup_widget(button, "type_RL");
        input6 = lookup_widget(button, "tarif_RL");
        input7 = lookup_widget(button, "nb_RL");
        input8 = lookup_widget(button, "horaire_RL");

        // Charger les données dans le formulaire
        gtk_entry_set_text(GTK_ENTRY(input1), g_strdup_printf("%d", p.id_parking));
        gtk_entry_set_text(GTK_ENTRY(input2), p.nom_parking);
        gtk_entry_set_text(GTK_ENTRY(input3), p.adresse);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4), p.capacite);
        gtk_combo_box_set_active(GTK_COMBO_BOX(input5), p.type);
        gtk_entry_set_text(GTK_ENTRY(input6), g_strdup_printf("%.2f", p.tarif));
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7), p.nb_place);
        gtk_entry_set_text(GTK_ENTRY(input8), g_strdup_printf("%d", p.horaire));

        // Préparer le parking modifié
        PARKING p_mod;
        p_mod.id_parking = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
        strcpy(p_mod.nom_parking, gtk_entry_get_text(GTK_ENTRY(input2)));
        strcpy(p_mod.adresse, gtk_entry_get_text(GTK_ENTRY(input3)));
        p_mod.capacite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
        p_mod.type = gtk_combo_box_get_active(GTK_COMBO_BOX(input5));
        p_mod.tarif = atof(gtk_entry_get_text(GTK_ENTRY(input6)));
        p_mod.nb_place = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
        p_mod.horaire = atoi(gtk_entry_get_text(GTK_ENTRY(input8)));
        p_mod.service_off = ServiceSelect;
        p_mod.statut = statut;
        snprintf(p_mod.cin_agent, sizeof(p_mod.cin_agent), "%s", p.cin_agent);
        p_mod.moyenne = p.moyenne;

        // Lire le fichier et modifier l'entrée
        FILE *file = fopen("parking.txt", "r");
        FILE *temp = fopen("temp_parking.txt", "w");
        if (file == NULL || temp == NULL) {
            printf("Erreur lors de l'ouverture des fichiers.\n");
            return;
        }

        char line[256];
        while (fgets(line, sizeof(line), file)) {
            PARKING current;
            sscanf(line, "%d %s %s %d %d %d %d %f %s %d %f %d",
                   &current.id_parking, current.nom_parking, current.adresse,
                   &current.capacite, &current.type, &current.nb_place, &current.horaire,
                   &current.tarif, current.cin_agent, &current.service_off,
                   &current.moyenne, &current.statut);

            if (current.id_parking == id) {
                // Écrire le parking modifié
                fprintf(temp, "%d %s %s %d %d %d %d %.2f %s %d %.2f %d\n",
                        p_mod.id_parking, p_mod.nom_parking, p_mod.adresse,
                        p_mod.capacite, p_mod.type, p_mod.nb_place, p_mod.horaire,
                        p_mod.tarif, p_mod.cin_agent, p_mod.service_off,
                        p_mod.moyenne, p_mod.statut);
            } else {
                // Garder les autres lignes
                fprintf(temp, "%s", line);
            }
        }

        fclose(file);
        fclose(temp);

        // Remplacer le fichier original par le fichier temporaire
        remove("parking.txt");
        rename("temp_parking.txt", "parking.txt");

        printf("Parking modifié avec succès !\n");
    } else {
        printf("Parking introuvable.\n");
    }
}





void
on_RL_buttonAdd_clicked                (GtkWidget        *button,
                                        gpointer         user_data)
{

}




void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    int value = gtk_toggle_button_get_active(togglebutton);
	ServiceSelect = (value == 1) ? (ServiceSelect | (1)) : (ServiceSelect & ~(1));
}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	int value = gtk_toggle_button_get_active(togglebutton);
	ServiceSelect = (value == 1) ? (ServiceSelect | (1 << 3)) : (ServiceSelect & ~(1 << 3));
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	int value = gtk_toggle_button_get_active(togglebutton);
	ServiceSelect = (value == 1) ? (ServiceSelect | (1 << 1)) : (ServiceSelect & ~(1 << 1));
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	int value = gtk_toggle_button_get_active(togglebutton);
	ServiceSelect = (value == 1) ? (ServiceSelect | (1 << 2)) : (ServiceSelect & ~(1 << 2));
}


void on_RL_buttonR_clicked(GtkWidget *button, gpointer user_data) {
    
    GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8;
    GtkWidget *input9, *input10, *input11, *input12;

    
    input1 = lookup_widget(button, "id_Rl");          
    input2 = lookup_widget(button, "nom_RL");          
    input3 = lookup_widget(button, "add_RL");          
    input4 = lookup_widget(button, "cap_RL");          
    input5 = lookup_widget(button, "type_RL");         
    input6 = lookup_widget(button, "tarif_RL");       
    input7 = lookup_widget(button, "nb_RL");           
    input8 = lookup_widget(button, "horaire_RL");      
    input9 = lookup_widget(button, "checkbutton1");    
    input10 = lookup_widget(button, "checkbutton4");   
    input11 = lookup_widget(button, "checkbutton2");   
    input12 = lookup_widget(button, "checkbutton3");   

    gtk_entry_set_text(GTK_ENTRY(input1), "");         
    gtk_entry_set_text(GTK_ENTRY(input2), "");         
    gtk_entry_set_text(GTK_ENTRY(input3), "");         
    gtk_entry_set_text(GTK_ENTRY(input6), "");        
    gtk_entry_set_text(GTK_ENTRY(input8), "");         
    gtk_combo_box_set_active(GTK_COMBO_BOX(input5), 0); 
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4), 1); 
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7), 1); 
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(input9), FALSE); 
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(input10), FALSE); 
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(input11), FALSE); 
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(input12), FALSE); 
    printf("Réinitialisation complète des champs et widgets effectuée.\n");
}



void on_RL_BCom_clicked(GtkWidget *button, gpointer user_data)
{
    PARKING p;
    GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8;
    GtkWidget *message_dialog;

    // Récupérer les valeurs des entrées
    input1 = lookup_widget(button, "id_Rl");
    input2 = lookup_widget(button, "nom_RL");
    input3 = lookup_widget(button, "add_RL");
    input4 = lookup_widget(button, "cap_RL");
    input5 = lookup_widget(button, "type_RL");
    input6 = lookup_widget(button, "tarif_RL");
    input7 = lookup_widget(button, "nb_RL");
    input8 = lookup_widget(button, "horaire_RL");

    // Validation des champs obligatoires et du format de l'identifiant
    const gchar *id_text = gtk_entry_get_text(GTK_ENTRY(input1));

    // Vérifier que le champ ID n'est pas vide
    if (strlen(id_text) == 0)
    {
        message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,
                                                "L'identifiant ne peut pas être vide.");
        gtk_dialog_run(GTK_DIALOG(message_dialog));
        gtk_widget_destroy(message_dialog);
        return;
    }

    // Vérifier que l'identifiant est un entier
    char *endptr;
    long id_value = strtol(id_text, &endptr, 10);
    if (*endptr != '\0' || id_value <= 0)
    {
        message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,
                                                "L'identifiant doit être un entier valide.");
        gtk_dialog_run(GTK_DIALOG(message_dialog));
        gtk_widget_destroy(message_dialog);
        return;
    }

    p.id_parking = (int)id_value;

    // Remplir les autres champs
    strcpy(p.nom_parking, gtk_entry_get_text(GTK_ENTRY(input2)));
    strcpy(p.adresse, gtk_entry_get_text(GTK_ENTRY(input3)));
    p.capacite = gtk_spin_button_get_value_as_int((GtkSpinButton *)input4);
    p.service_off = ServiceSelect;
    p.type = gtk_combo_box_get_active((GtkComboBox *)input5);
    p.tarif = atof(gtk_entry_get_text(GTK_ENTRY(input6)));
    p.nb_place = gtk_spin_button_get_value_as_int((GtkSpinButton *)input7);
    p.horaire = atoi(gtk_entry_get_text(GTK_ENTRY(input8)));
    p.moyenne = 0;
    snprintf(p.cin_agent, sizeof(p.cin_agent), "00000000");
    p.statut = statut;

    // Vérifier si l'ID existe déjà
    PARKING cherche = chercher("parking.txt", p.id_parking);
    if (cherche.id_parking != -1)
    {
        // Parking déjà existant, demande de confirmation de modification
        GtkWidget *dialog;
        gint response;

        dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO,
                                        "Un parking avec cet identifiant existe déjà. Voulez-vous vraiment modifier ?");
        response = gtk_dialog_run(GTK_DIALOG(dialog));

        if (response == GTK_RESPONSE_YES)
        {
            strcpy(p.cin_agent, cherche.cin_agent);
            modifier("parking.txt", p.id_parking, p);
            message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
                                                    "Modification réussie.");
            gtk_dialog_run(GTK_DIALOG(message_dialog));
            gtk_widget_destroy(message_dialog);
        }
        gtk_widget_destroy(dialog);
    }
    else
    {
        // Nouveau parking, tentative d'ajout
        if (ajouter("parking.txt", p))
        {
            message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
                                                    "Ajout réussi.");
            on_comboboxParky_RL_map(GTK_COMBO_BOX(lookup_widget(button, "comboboxParky_RL")));
            on_actualiser1_RL_clicked(button, user_data);
        }
        else
        {
            message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,
                                                    "Erreur lors de l'ajout du parking.");
        }
        gtk_dialog_run(GTK_DIALOG(message_dialog));
        gtk_widget_destroy(message_dialog);
    }
}



//statut actif
void
on_radiobutton_RL_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    statut = 0;
}


void
on_Inactif_RL_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    statut = 1;
}


void on_RL_Affecter_clicked(GtkWidget *button, gpointer user_data) {
    GtkWidget *treeview_agents, *combobox_parking, *treeview_parkings;
    GtkTreeModel *model;
    GtkTreeIter iter;
    gchar *selected_cin_agent;
    gchar *selected_id_parking;

    // Récupérer les widgets
    treeview_agents = lookup_widget(button, "treeviewAgent_RL");
    combobox_parking = lookup_widget(button, "comboboxParky_RL");
    treeview_parkings = lookup_widget(button, "treeviewParking_RL");

    if (!treeview_agents || !combobox_parking || !treeview_parkings) {
        g_warning("Erreur : Impossible de récupérer les widgets.\n");
        return;
    }

    // Obtenir le CIN de l'agent sélectionné dans le TreeView
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview_agents));
    if (!gtk_tree_selection_get_selected(selection, &model, &iter)) {
        GtkWidget *message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,
                                                           "Erreur : Aucun agent sélectionné.");
        gtk_dialog_run(GTK_DIALOG(message_dialog));
        gtk_widget_destroy(message_dialog);
        return;
    }
    gtk_tree_model_get(model, &iter, 0, &selected_cin_agent, -1); // Colonne 0 = CIN

    // Obtenir l'ID du parking sélectionné dans le ComboBox
    selected_id_parking = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_parking));
    if (!selected_id_parking) {
        GtkWidget *message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,
                                                           "Erreur : Aucun parking sélectionné.");
        gtk_dialog_run(GTK_DIALOG(message_dialog));
        gtk_widget_destroy(message_dialog);
        g_free(selected_cin_agent);
        return;
    }

    // Mettre à jour le fichier parking.txt
    FILE *file = fopen("parking.txt", "r");
    FILE *temp = fopen("temp_parking.txt", "w");
    if (!file || !temp) {
        GtkWidget *message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,
                                                           "Erreur lors de l'ouverture des fichiers.");
        gtk_dialog_run(GTK_DIALOG(message_dialog));
        gtk_widget_destroy(message_dialog);
        g_free(selected_cin_agent);
        g_free(selected_id_parking);
        return;
    }

    PARKING parking;
    while (fscanf(file, "%d %s %s %d %d %d %d %f %s %d %f %d",
                  &parking.id_parking, parking.nom_parking, parking.adresse,
                  &parking.capacite, &parking.type, &parking.nb_place,
                  &parking.horaire, &parking.tarif, parking.cin_agent,
                  &parking.service_off, &parking.moyenne, &parking.statut) != EOF) {
        if (parking.id_parking == atoi(selected_id_parking)) {
            snprintf(parking.cin_agent, sizeof(parking.cin_agent), "%s", selected_cin_agent);
        }
        fprintf(temp, "%d %s %s %d %d %d %d %.2f %s %d %.2f %d\n",
                parking.id_parking, parking.nom_parking, parking.adresse,
                parking.capacite, parking.type, parking.nb_place, parking.horaire,
                parking.tarif, parking.cin_agent, parking.service_off,
                parking.moyenne, parking.statut);
    }

    fclose(file);
    fclose(temp);
    remove("parking.txt");
    rename("temp_parking.txt", "parking.txt");

    // Actualiser les widgets
    on_actualiser1_RL_clicked(button, user_data); // TreeView parkings
    on_comboboxParky_RL_map(GTK_COMBO_BOX(combobox_parking)); // ComboBox des parkings
    on_treeviewAgent_RL_map(GTK_TREE_VIEW(treeview_agents)); // TreeView des agents

    g_free(selected_cin_agent);
    g_free(selected_id_parking);

    // Afficher un message de confirmation
    GtkWidget *message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
                                                       "Affectation réussie !");
    gtk_dialog_run(GTK_DIALOG(message_dialog));
    gtk_widget_destroy(message_dialog);

    printf("Affectation réussie.\n");
}

void
on_RL_Annuler_clicked                  (GtkWidget        *button,
                                        gpointer         user_data)
{

}
void on_actualiser1_RL_clicked(GtkWidget *button, gpointer user_data) {
    GtkWidget *treeview;

    // Locate the treeview widget by its name
    treeview = lookup_widget(button, "treeviewParking_RL");

    if (treeview) {
        // Clear and repopulate the treeview with the updated data
        on_treeviewParking_RL_map(GTK_TREE_VIEW(treeview));
        gtk_widget_show_all(treeview); // Forcer l'affichage de la TreeView actualisée
        printf("TreeView updated successfully.\n");
    } else {
        printf("Error: Could not find treeviewParking_RL.\n");
    }
}




void
on_actualiserAffec_RL_clicked         (GtkWidget *button, gpointer user_data) {
    GtkWidget *combobox = lookup_widget(button, "comboboxParkingSansAgent");

    if (combobox) {
        on_comboboxParky_RL_map(GTK_COMBO_BOX(combobox));
        printf("ComboBox mis à jour avec les ID des parkings sans agent.\n");
    } else {
        printf("Erreur : Impossible de trouver le ComboBox.\n");
    }



}
void on_chercher_RL_clicked(GtkWidget *button, gpointer user_data) {
    PARKING p;
    GtkWidget *idEntry;
    GtkWidget *treeview;
    GtkTreeModel *model;
    GtkTreeIter iter;
    int r;
    gboolean valid;
    gboolean id_found = FALSE;

    // Get the ID entered by the user
    idEntry = lookup_widget(button, "idRecherche_RL");
    r = atoi(gtk_entry_get_text(GTK_ENTRY(idEntry)));

    // Search for the parking entry with the given ID
    p = chercher("parking.txt", r);

    // Check if the ID exists in the file
    if (p.id_parking == -1) {
        // Display an error message
        GtkWidget *message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,
                                                           "L'identifiant recherché n'existe pas.");
        gtk_dialog_run(GTK_DIALOG(message_dialog));
        gtk_widget_destroy(message_dialog);
        return;
    }

    // Get the TreeView widget
    treeview = lookup_widget(button, "treeviewParking_RL");
    model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));

    // Iterate through the TreeView model to find the matching ID
    valid = gtk_tree_model_get_iter_first(model, &iter);
    while (valid) {
        int id_parking;

        // Get the ID from the current row
        gtk_tree_model_get(model, &iter, 0, &id_parking, -1);

        // Check if the ID matches
        if (id_parking == r) {
            // Select the matching row
            GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
            gtk_tree_selection_select_iter(selection, &iter);
            id_found = TRUE;
            break;
        }

        // Move to the next row
        valid = gtk_tree_model_iter_next(model, &iter);
    }

    // Display an error message if the ID was not found in the TreeView
    if (!id_found) {
        GtkWidget *message_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,
                                                           "L'identifiant recherché n'est pas affiché dans la liste.");
        gtk_dialog_run(GTK_DIALOG(message_dialog));
        gtk_widget_destroy(message_dialog);
    }
}







void
on_treeviewAgent_RL_realize            (GtkWidget       *widget,
                                        gpointer         user_data)
{

}


void on_treeviewParking_RL_map(GtkTreeView *treeview) {
    GtkListStore *store;
    GtkTreeIter iter;

	if(AgentsAffecte == NULL){
		AgentsAffecte = (Cin*)malloc(sizeof(Cin) * 20);
		memset(AgentsAffecte, '0', TailleAgents * sizeof(Cin));
	}

    // Clear all existing columns before adding new ones
    GList *columns = gtk_tree_view_get_columns(treeview);
    for (GList *iter = columns; iter != NULL; iter = iter->next) {
        gtk_tree_view_remove_column(treeview, GTK_TREE_VIEW_COLUMN(iter->data));
    }
    g_list_free(columns);

    store = GTK_LIST_STORE(gtk_tree_view_get_model(treeview));
    if (!store) {
        // Create the list store if it doesn't exist
        store = gtk_list_store_new(11, 
            G_TYPE_INT,    // ID Parking
            G_TYPE_STRING, // Nom Parking
            G_TYPE_STRING, // Adresse
            G_TYPE_INT,    // Capacité
            G_TYPE_STRING,    // Type
            G_TYPE_INT,    // Places
            G_TYPE_INT,    // Horaire
            G_TYPE_FLOAT,  // Tarif
            G_TYPE_STRING, // CIN Agent
            G_TYPE_FLOAT,  // Moyenne
            G_TYPE_STRING     // Statut
        );
    } else {
        gtk_list_store_clear(store);
    }

    FILE *f = fopen("parking.txt", "r");
    if (!f) {
        printf("Erreur : Impossible d'ouvrir le fichier parking.txt\n");
        return;
    }

    PARKING parking;

    while (fscanf(f, "%d %s %s %d %d %d %d %f %s %d %f %d",
                  &parking.id_parking, parking.nom_parking, parking.adresse,
                  &parking.capacite, &parking.type, &parking.nb_place,
                  &parking.horaire, &parking.tarif, parking.cin_agent,
                  &parking.service_off, &parking.moyenne, &parking.statut) != EOF) {

        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 
            0, parking.id_parking,
            1, parking.nom_parking,
            2, parking.adresse,
            3, parking.capacite,
            4, parking.type ? "Prive" : "Public",
            5, parking.nb_place,
            6, parking.horaire,
            7, parking.tarif,
            8, parking.cin_agent,
            9, parking.moyenne,
            10, parking.statut ? "Inactif" : "Actif",
            -1);

		if(strcmp(parking.cin_agent, "00000000")){
			int tr = 0;
			for(unsigned int i = 0; i < nAffecte; i++){
				if(!strcmp(parking.cin_agent, AgentsAffecte[i].cin)){
					tr = 1;
					break;
				}
			}
			if(tr == 1){
				continue;
			}
			strcpy(AgentsAffecte[nAffecte].cin, parking.cin_agent);
			nAffecte++;
			if(nAffecte == TailleAgents){
				Cin* nv = realloc(AgentsAffecte, TailleAgents * 2);
				if(nv == NULL){
					g_print("Memoire indisponible\n");
					return;
				}
				AgentsAffecte = nv;
				TailleAgents *= 2;
			}
		}
    }

    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));

    // Add columns to the tree view
    GtkCellRenderer *renderer;

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("ID Parking", renderer, "text", 0, NULL));

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("Nom Parking", renderer, "text", 1, NULL));

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("Adresse", renderer, "text", 2, NULL));

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("Capacité", renderer, "text", 3, NULL));

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("Type", renderer, "text", 4, NULL));

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("Places", renderer, "text", 5, NULL));

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("Horaire", renderer, "text", 6, NULL));

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("Tarif", renderer, "text", 7, NULL));

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("CIN Agent", renderer, "text", 8, NULL));

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("Moyenne", renderer, "text", 9, NULL));

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), 
        gtk_tree_view_column_new_with_attributes("Statut", renderer, "text", 10, NULL));
}

void on_treeviewAgent_RL_map(GtkTreeView *treeview) {
    GtkListStore *store;
    GtkTreeIter iter;

	    // Clear all existing columns before adding new ones
    GList *columns = gtk_tree_view_get_columns(treeview);
    for (GList *iter = columns; iter != NULL; iter = iter->next) {
        gtk_tree_view_remove_column(treeview, GTK_TREE_VIEW_COLUMN(iter->data));
    }
    g_list_free(columns);
		
    store = GTK_LIST_STORE(gtk_tree_view_get_model(treeview));
    if (!store) {
        // Create the list store if it doesn't exist
        store = gtk_list_store_new(3, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    }else{
        //clear_list_store(store);
        gtk_list_store_clear(store);
    }


   
    FILE* f = fopen("Agent.txt", "r");

    Agent agent;

    while(fscanf(f,"%s %s %s %s %u %s %s %d %u %i \n",
                agent.CIN, agent.nom, agent.prenom, agent.email, &agent.sexe, agent.date_naissance, agent.lieu_naissance, &agent.num_banque,
                &agent.etat_civil, &agent.nombre_enfant) != EOF){
		int tr = 0;
		for(unsigned int i = 0; i < nAffecte; i++){
			if(!strcmp(agent.CIN, AgentsAffecte[i].cin)){
				tr = 1;
				break;
			}
		}
		if(tr == 1){
			continue;
		}
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 0, agent.CIN, 1, agent.nom, 2, agent.prenom, -1);
    }

    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));

    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
   
    //
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", 1, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", 2, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
    




    fclose(f);

}




void on_comboboxParky_RL_map(GtkComboBox *combobox) {
    GtkListStore *store;
    GtkTreeIter iter;

    // Récupérer le modèle existant
    store = GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(combobox)));

    if (!store) {
        // Créer le modèle s'il n'existe pas
        store = gtk_list_store_new(1, G_TYPE_STRING); // Une seule colonne pour les ID
        gtk_combo_box_set_model(GTK_COMBO_BOX(combobox), GTK_TREE_MODEL(store));
    } else {
        // Nettoyer le modèle existant
        gtk_list_store_clear(store);
    }

    // Ouvrir le fichier parking.txt
    FILE *f = fopen("parking.txt", "r");
    if (!f) {
        g_warning("Erreur : Impossible d'ouvrir parking.txt\n");
        return;
    }

    PARKING parking;
    while (fscanf(f, "%d %*s %*s %*d %*d %*d %*d %*f %s %*d %*f %*d", 
                  &parking.id_parking, parking.cin_agent) != EOF) {
        // Vérifier si le parking n'a pas d'agent affecté
        if (strcmp(parking.cin_agent, "00000000") == 0) {
            gchar id_str[10];
            sprintf(id_str, "%d", parking.id_parking);
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, 0, id_str, -1);
        }
    }
    fclose(f);

    // Configurer le rendu du ComboBox
    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    gtk_cell_layout_clear(GTK_CELL_LAYOUT(combobox)); // Supprimer les colonnes existantes
    gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combobox), renderer, TRUE);
    gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(combobox), renderer, "text", 0);
}



